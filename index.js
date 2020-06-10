import * as THREE from './node_modules/three/build/three.module.js';
import { OrbitControls } from './node_modules/three/examples/jsm/controls/OrbitControls.js';

var sceneData = fetch('./build/convex-hull.hull')
    .then(response => response.text())
    .then(text => text.split('\n'));

var pointsCloud = sceneData
    .then(lines => lines.filter(line => line[0] == 'p').map(pointDescription => pointDescription.split(' ')))
    .then(pointsDescription => pointsDescription.map(pointTokens => ({ x: Number(pointTokens[1]), y: Number(pointTokens[2]), z: Number(pointTokens[3]) })));

var hulls = sceneData
    .then(lines => {
        var hullsFacesFlat = lines.filter(line => (line.trim() === 'hull' || line[0] == 'f'));
        var hullsFaces = hullsFacesFlat.reduce((acc, curr) => {
            if(curr.trim() === 'hull') {
                return [...acc, []];
            } else {
                let currHulls = [...acc];
                currHulls[currHulls.length - 1].push(curr.split(' '));
                return currHulls;
            }
        }, []);

        return hullsFaces;
    })
    .then(hullsDescription => hullsDescription.map(faces => faces.map(face => ({ p1: Number(face[1]) - 1, p2: Number(face[2]) - 1, p3: Number(face[3]) - 1 }))));

var camera, scene, renderer, controls;
var geometries = [];
var materials = [];
var meshes = [];

window.meshes = meshes;
window.materials = materials;
window.geometries = geometries;
 
init();
animate();

function init() {
    renderer = new THREE.WebGLRenderer( { antialias: true } );
    renderer.setSize( window.innerWidth, window.innerHeight );
    document.body.appendChild( renderer.domElement );

    camera = new THREE.PerspectiveCamera( 70, window.innerWidth / window.innerHeight, 0.01, 10 );
    controls = new OrbitControls( camera, renderer.domElement );

    camera.position.z = 5;
    camera.position.x = 2;
    camera.position.y = 2;

    controls.update();
 
    scene = new THREE.Scene();

    var dotGeometry = new THREE.Geometry();
    
    return pointsCloud.then(points => {
        points.forEach(point => dotGeometry.vertices.push(new THREE.Vector3(point.x, point.y, point.z)));
        return points;
    })
    .then(points => {
        var dotMaterial = new THREE.PointsMaterial( { size: 5, sizeAttenuation: false } );
        var dot = new THREE.Points( dotGeometry, dotMaterial );
        scene.add( dot );
        return points
    }).then(points => hulls.then(hullsFaces => hullsFaces.map(hull => {
        geometries.push( new THREE.Geometry() );

        points.forEach(point => geometries[geometries.length - 1].vertices.push(new THREE.Vector3(point.x, point.y, point.z)));
        hull.forEach(face => geometries[geometries.length - 1].faces.push( new THREE.Face3( face.p1, face.p2, face.p3 ) ));

        geometries[geometries.length - 1].computeBoundingSphere();

        materials.push( new THREE.MeshBasicMaterial( { color: 0x787878 } ) );
    
        meshes.push( new THREE.Mesh( geometries[geometries.length - 1], materials ) );

        scene.add( meshes[meshes.length - 1] );
    })));
}
 
function animate() {
 
    requestAnimationFrame( animate );
 
    // mesh.rotation.x += 0.01;
    // mesh.rotation.y += 0.02;

    controls.update();
 
    renderer.render( scene, camera );
 
}