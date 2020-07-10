#include "./PolygonalOperations.hpp"

bool op::intersect(Line& l1, Line& l2)
{
    Vector l1_base = l1.toVector();
    Vector l1_lower = Vector(*l1.start, *l2.start);
    Vector l1_upper = Vector(*l1.start, *l2.end);

    double l1_base_lower = op::crossR2(l1_base, l1_lower);
    double l1_base_upper = op::crossR2(l1_base, l1_upper);

    Vector l2_base = l2.toVector();
    Vector l2_lower = Vector(*l2.start, *l1.start);
    Vector l2_upper = Vector(*l2.start, *l1.end);

    double l2_base_lower = op::crossR2(l2_base, l2_lower);
    double l2_base_upper = op::crossR2(l2_base, l2_upper);

    bool l1_ok = l1_base_lower * l1_base_upper < 0;
    bool l2_ok = l2_base_lower * l2_base_upper < 0;

    return l1_ok && l2_ok;
}

std::vector<double> op::baricentricCoordnates(Point& point, Triangle& triangle)
{
    double triangle_area = triangle.area();

    Triangle t1 = Triangle(point, *triangle[1], *triangle[2]);
    double delta1 = t1.area() / triangle_area;
    
    Triangle t2 = Triangle(*triangle[0], point, *triangle[2]);
    double delta2 = t2.area() / triangle_area;

    Triangle t3 = Triangle(*triangle[0], *triangle[1], point);
    double delta3 = t3.area() / triangle_area;

    return { delta1, delta2, delta3 };
}

bool op::isInside(Point& point, Triangle& triangle)
{
    std::vector<double> deltas = op::baricentricCoordnates(point, triangle);
    return deltas[0] > 0 && deltas[1] > 0 && deltas[2] > 0;
}

bool op::equal(Wedge& e1, Wedge& e2)
{
    return e1.start == e2.start && e1.end == e2.end;
}

Face makeFirstFace(std::vector<Point *>& sortedPoints)
{
    Point* pYMin = sortedPoints.back();

    Point pYMinProjX = Point(pYMin->x + 1, pYMin->y, pYMin->z);
    Point pYMinProjZ = Point(pYMin->x, pYMin->y, pYMin->z - 1);

    Face fYMin = Face(*pYMin, pYMinProjZ, pYMinProjX);

    double minAngularValue = INFINITY;
    int pFoundPos = -1;

    for (int i=0; i < sortedPoints.size(); i++)
    {
        if(sortedPoints[i] != pYMin) 
        {
            Face fCandidate = Face(*pYMin, *sortedPoints[i], pYMinProjX);

            double angularValue = 1 - op::dot(fYMin.normal, fCandidate.normal);
            
            if(angularValue < minAngularValue)
            {
                pFoundPos = i;
                minAngularValue = angularValue;
            }
        }
    }

    if(pFoundPos < 0)
    {
        throw "Unable to create hull. Please check if your point coordinates make this operation valid.";
    }

    Point* pFirstEncountered = sortedPoints[pFoundPos];

    Face preFace1 = Face(*pYMin, *pFirstEncountered, pYMinProjX);

    minAngularValue = INFINITY;
    pFoundPos = -1;

    for (int i=0; i < sortedPoints.size(); i++)
    {
        if(sortedPoints[i] != pYMin && sortedPoints[i] != pFirstEncountered) 
        {
            Face fCandidate = Face(*pYMin, *sortedPoints[i], *pFirstEncountered);
            
            double angularValue = 1 - op::dot(preFace1.normal, fCandidate.normal);
            if(angularValue < minAngularValue)
            {
                pFoundPos = i;
                minAngularValue = angularValue;
            }
        }
    }

    if(pFoundPos < 0)
    {
        throw "Unable to create hull. Please check if your point coordinates make this operation valid.";
    }

    Point* pSecondEncountered = sortedPoints[pFoundPos];

    Face firstFace = Face(*pYMin, *pSecondEncountered, *pFirstEncountered);

    return firstFace;
}

Face wrapASide(std::vector<Point *>& sortedPoints, Wedge& edge)
{
    double minAngularValue = INFINITY;
    int pFoundPos = -1;

    Face* face = edge.getFcw();

    for (int i=0; i < sortedPoints.size(); i++)
    {
        if(sortedPoints[i] != edge.start && sortedPoints[i] != edge.end) 
        {
            Face fCandidate = Face(*edge.end, *edge.start, *sortedPoints[i]);
            
            double angularValue = 1 - op::dot(face->normal, fCandidate.normal);

            if(angularValue < minAngularValue)
            {
                pFoundPos = i;
                minAngularValue = angularValue;
            }
        }
    }

    if(pFoundPos < 0)
    {
        throw "Unable to create hull. Please check if your point coordinates make this operation valid.";
    }

    Face selectedFace = Face(*edge.end, *edge.start, *sortedPoints[pFoundPos]);

    return selectedFace;
}

int findEdgeIndex(std::vector<Wedge>& edges, Wedge& edge)
{
    for(int i=0; i < edges.size(); i++)
    {
        if(edges[i] == edge)
        {
            return i;
        }
    }

    return -1;
}

int findFaceIndex(std::vector<Face>& hull, Face& face)
{
    for(int i=0; i < hull.size(); i++)
    {
        if(hull[i] == face)
        {
            return i;
        }
    }

    return -1;
}

int findFreeEdgeIndex(std::vector<Wedge *>& freeEdges, Wedge& edge)
{
    for(int i=0; i < freeEdges.size(); i++)
    {
        if(*freeEdges[i] == edge)
        {
            return i;
        }
    }

    return -1;
}

bool isEdgeNew(std::vector<Wedge>& edges, Wedge& edge)
{
    int index = findEdgeIndex(edges, edge);
    return index == -1;
}

bool isFreeEdgeNew(std::vector<Wedge *>& freeEdges, Wedge& edge)
{
    int index = findFreeEdgeIndex(freeEdges, edge);
    return index == -1;
}

bool isFaceNew(std::vector<Face>& hull, Face& face)
{
    int index = findFaceIndex(hull, face);
    return index == -1;
}

std::vector<Face> op::giftWrap3D(std::vector<Point *> points)
{
    std::vector<Point *> sortedPoints = op::sortPoints(points);
    
    // Euler formula
    std::vector<Face> hull = {};
    hull.reserve(2 * sortedPoints.size());
    std::vector<Wedge> edges = {};
    edges.reserve(3 * sortedPoints.size());
    std::vector<Wedge *> freeEdges = {};
    freeEdges.reserve(3 * sortedPoints.size());

    Face firstFace = makeFirstFace(sortedPoints);
    hull.push_back(firstFace);
    
    Wedge e1 = Wedge(*hull.back()[0], *hull.back()[1], hull.back());
    Wedge e2 = Wedge(*hull.back()[1], *hull.back()[2], hull.back());
    Wedge e3 = Wedge(*hull.back()[2], *hull.back()[0], hull.back());

    edges.push_back(e1);
    edges.push_back(e2);
    edges.push_back(e3);

    freeEdges.push_back(&edges[0]);
    freeEdges.push_back(&edges[1]);
    freeEdges.push_back(&edges[2]);

    int stop = 0;

    while(!freeEdges.empty())
    {
        Wedge* edge = nullptr;

        do
        {
            edge = freeEdges.back();
            freeEdges.pop_back();
        }
        while(edge->getFccw() != nullptr);

        Face selectedFace = wrapASide(sortedPoints, *edge);

        bool isNewFace = isFaceNew(hull, selectedFace);

        if(isNewFace)
        {
            hull.push_back(selectedFace);

            edge->setFccw(hull.back());

            Wedge E1 = Wedge(*hull.back()[0], *hull.back()[1], hull.back());
            Wedge E2 = Wedge(*hull.back()[1], *hull.back()[2], hull.back());
            Wedge E3 = Wedge(*hull.back()[2], *hull.back()[0], hull.back());
            
            bool IsE1New = isEdgeNew(edges, E1);
            bool IsE2New = isEdgeNew(edges, E2);
            bool IsE3New = isEdgeNew(edges, E3);

            if(IsE1New)
            {
                edges.push_back(E1);
                freeEdges.push_back(&edges.back());
            }
            
            if(IsE2New)
            {
                edges.push_back(E2);
                freeEdges.push_back(&edges.back());
            }
            
            if(IsE3New)
            {
                edges.push_back(E3);
                freeEdges.push_back(&edges.back());
            }
        }
    }
    
    return hull;
}

bool op::intersect(Line line, Face face)
{
    Vector v1 = op::sub(*face[1], *face[0]);
    Vector v2 = op::sub(*face[2], *face[0]);

    Vector origin = Vector(*line.start);
    Vector direction = Vector(*line.end);

    Vector pvec = op::cross(direction, v2);
    double det = op::dot(v1, pvec);
    
    if(det > - 0.00001 && det < 0.00001) return false;

    double inverseDet = 1 / det;

    Vector tvec = op::sub(origin, *face[0]);
    double u = op::dot(tvec, pvec) * inverseDet;
    if (u < 0 || u > 1) return false; 

    Vector qvec = op::cross(tvec, v1);
    double v = op::dot(direction, qvec) * inverseDet;
    
    if (v < 0 || u + v > 1) return false;

    double t = op::dot(v2, qvec) * inverseDet;

    if(line.length <= t) return false;
    return true;
}

bool op::intersect(Face f1, Face f2)
{
    int f1Intersections = 0;
    f1Intersections += int( op::intersect( Line(*f1[0], *f1[1]), f2 ) );
    f1Intersections += int( op::intersect( Line(*f1[1], *f1[2]), f2 ) );
    f1Intersections += int( op::intersect( Line(*f1[2], *f1[0]), f2 ) );

    int f2Intersections = 0;
    f2Intersections += int( op::intersect( Line(*f2[0], *f2[1]), f1 ) );
    f2Intersections += int( op::intersect( Line(*f2[1], *f2[2]), f1 ) );
    f2Intersections += int( op::intersect( Line(*f2[2], *f2[0]), f1 ) );

    return f1Intersections == 2 || f2Intersections == 2 || ( f1Intersections == 1 && f2Intersections == 1);
}

double op::dist(Point point, Face face)
{
    double distance = op::dist(point, face.center);
    return distance;
}

bool op::isVertexOfFace(Point* point, Face face)
{
    return face[0] == point
    || face[1] == point
    || face[2] == point;
}

struct RankElement {
    int value;
    int index;
};

bool rankingOrderCondition(RankElement a, RankElement b) { return (a.value < b.value); }

bool pointIsValid(Face face, Point point, std::vector<Face> solid)
{
    Face f1 = Face(*face[0], *face[1], point);
    Face f2 = Face(*face[1], *face[2], point);
    Face f3 = Face(*face[2], *face[0], point);

    for(auto& currFace : solid)
    {
        bool f1Intersect = op::intersect(f1, currFace);
        if(f1Intersect) return false;

        bool f2Intersect = op::intersect(f2, currFace);
        if(f2Intersect) return false;

        bool f3Intersect = op::intersect(f3, currFace);
        if(f3Intersect) return false;
    }

    return true;
}

std::vector<RankElement> pointsRanking(std::vector<Point *> points, Face face)
{
    std::vector<RankElement> ranking = {};
    ranking.reserve(points.size());
    
    for(int i=0; i < points.size(); i++)
    {
        if(!op::isVertexOfFace(points[i], face))
        {
            RankElement toRank;
            toRank.value = op::dist(*points[i], face);
            toRank.index = i;

            ranking.push_back(toRank);
        }
    }

    std::sort(ranking.begin(), ranking.end(), rankingOrderCondition);

    return ranking;
}

std::vector<Face> op::frontierAdvance3D(std::vector<Point *> points)
{
    std::vector<Face> hull = op::giftWrap3D(points);

    std::vector<Face> solid = {};
    solid.reserve(5 * points.size());

    std::vector<Face> facesQueue = {};
    facesQueue.reserve(5 * points.size());

    for(auto& face : hull)
    {
        solid.push_back(face);
        facesQueue.push_back(face);
    }

    while(facesQueue.size() > 0)
    {
        Face currFace = facesQueue.back();
        facesQueue.pop_back();

        std::vector<RankElement> ranking = pointsRanking(points, currFace);

        bool choosenPointIndex = -1;

        while(choosenPointIndex == -1 || ranking.size() != 0)
        {
            RankElement rank = ranking.back();
            Point* currPoint = points[rank.index];
            ranking.pop_back();

            if( pointIsValid(currFace, *currPoint, solid) )
            {
                // std::cout << "point is valid" << std::endl;
                choosenPointIndex = rank.index;
            }
        }

        if(choosenPointIndex == -1)
        {
            throw "Unable to create solid. It's not tessellable.";
        }
        else
        {
            Point* currPoint = points[choosenPointIndex];

            // std::cout << "Point choosen " << currPoint->toString() << std::endl;

            Face f1 = Face(*currFace[0], *currFace[1], *currPoint);
            Face f2 = Face(*currFace[1], *currFace[2], *currPoint);
            Face f3 = Face(*currFace[2], *currFace[0], *currPoint);

            if(isFaceNew(solid, f1))
            {
                std::cout << "New f1 " << f1.toString() << std::endl;
                solid.push_back(f1);
                facesQueue.push_back(f1);
            }

            if(isFaceNew(solid, f2))
            {
                std::cout << "New f2 " << f2.toString() << std::endl;
                solid.push_back(f2);
                facesQueue.push_back(f2);
            }

            if(isFaceNew(solid, f3))
            {
                std::cout << "New f3 " << f3.toString() << std::endl;
                solid.push_back(f3);
                facesQueue.push_back(f3);
            }

            // points.erase(points.begin() + choosenPointIndex);
        }

    }

    return solid;

}