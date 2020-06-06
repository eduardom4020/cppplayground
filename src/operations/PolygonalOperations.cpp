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

Face wrapASide(std::vector<Point *>& sortedPoints, Wedge& edge)
{
    double minAngularValue = INFINITY;
    int pFoundPos = -1;

    Face* facePointer = edge.getFcw();
    Face face = facePointer->toCW();

    for (int i=0; i < sortedPoints.size(); i++)
    {
        if(sortedPoints[i] != edge.start && sortedPoints[i] != edge.end) 
        {
            Face fCandidate = Face(*edge.start, *sortedPoints[i], *edge.end);

            // Angle angle = Angle(face->normal, fCandidate.normal);
            // std::cout << "face\t\t" << face->toString() << std::endl;
            // std::cout << "face\t\t" << face.toString() << std::endl;
            // std::cout << "fCandidate\t\t" << fCandidate.toString() << std::endl;
            // double angularValue = angle.orientedValue();
            double angularValue = 1 - op::dot(face.normal, fCandidate.normal);
            // std::cout << "angularValue\t\t" << angularValue << std::endl;

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

    // TODO: Aparentemente esta mudança deu certo. Agora o que bugou foi a lógica das arestas livres?
    Face selectedFace = Face(*edge.start, *sortedPoints[pFoundPos], *edge.end);
    // std::cout << "selectedFace\t\t" << selectedFace.toString() << selectedFace.isCCW() << std::endl;

    return selectedFace;
}

std::vector<Face> op::giftWrap3D(std::vector<Point *> points)
{
    std::cout << "op::giftWrap3D DEBUG" << std::endl;

    std::vector<Face> hull = {};
    std::vector<Wedge> edges = {};
    std::vector<Wedge *> freeEdges = {};
    std::vector<Point *> sortedPoints = op::sortPoints(points);
    
    Point* pYMin = sortedPoints.back();
    std::cout << "sortedPoints\t\t" << std::endl;
    for(auto* point : sortedPoints)
    {
        std::cout << point->toString() << std::endl;
    }

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
            
            // Angle angle = Angle(fYMin.normal, fCandidate.normal);
            // std::cout << "fYMin\t\t" << fYMin.toString() << std::endl;
            // std::cout << "fCandidate\t\t" << fCandidate.toString() << std::endl;
            // double angularValue = angle.orientedValue();
            double angularValue = 1 - op::dot(fYMin.normal, fCandidate.normal);
            // std::cout << "angularValue\t\t" << angularValue << std::endl;
            
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
    // sortedPoints.erase(sortedPoints.begin() + pFoundPos);

    Face preFace1 = Face(*pYMin, *pFirstEncountered, pYMinProjX);

    minAngularValue = INFINITY;
    pFoundPos = -1;

    for (int i=0; i < sortedPoints.size(); i++)
    {
        if(sortedPoints[i] != pYMin && sortedPoints[i] != pFirstEncountered) 
        {
            Face fCandidate = Face(*pYMin, *sortedPoints[i], *pFirstEncountered);
            
            // Angle angle = Angle(preFace1.normal, fCandidate.normal);
            // double angularValue = angle.orientedValue();
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
    // sortedPoints.erase(sortedPoints.begin() + pFoundPos);

    Face f1 = Face(*pYMin, *pSecondEncountered, *pFirstEncountered);
    hull.push_back(f1);

    std::cout << "f1\t\t" << hull.back().toString() << std::endl;
    
    edges.push_back(Wedge(*f1[0], *f1[1]));
    edges.push_back(Wedge(*f1[1], *f1[2]));
    edges.push_back(Wedge(*f1[2], *f1[0]));

    edges[0].setFcw(f1);
    edges[1].setFcw(f1);
    edges[2].setFcw(f1);

    freeEdges.push_back(&edges[0]);
    freeEdges.push_back(&edges[1]);
    // freeEdges.push_back(&edges[2]);

    while(!freeEdges.empty())
    {
        // double minDot3 = INFINITY;
        // int pFoundPos3 = -1;

        Wedge* edge = freeEdges.back();
        freeEdges.pop_back();

        std::cout << "edge\t\t" << edge->start->toString() << edge->end->toString() << std::endl;
        Face selectedFace = wrapASide(sortedPoints, *edge);
        
        hull.push_back(selectedFace);
        std::cout << "hull updated\t\t" << hull.back().toString() << std::endl;
        edge->setFccw(hull.back());

        Wedge e2 = Wedge(*selectedFace[1], *selectedFace[2]);
        Wedge e3 = Wedge(*selectedFace[2], *selectedFace[0]);

        bool isE2New = true;
        bool isE3New = true;

        for(auto someEdge : edges)
        {
            if(op::equal(someEdge, e2))
            {
                isE2New = false;
            }

            if(op::equal(someEdge, e3))
            {
                isE3New = false;
            }
            
        }

        if(isE2New)
        {
            edges.push_back(e2);
            edges.back().setFcw(hull.back());
            // freeEdges.push_back(&edges.back());
        }

        if(isE3New)
        {
            edges.push_back(e3);
            edges.back().setFcw(hull.back());
            // freeEdges.push_back(&edges.back());
        }
    }

    return hull;
}