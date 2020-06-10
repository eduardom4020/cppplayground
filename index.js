import * as THREE from './node_modules/three/build/three.module.js';
import { OrbitControls } from './node_modules/three/examples/jsm/controls/OrbitControls.js';

var sceneData = fetch('./build/convex-hull.hull')
    .then(response => response.text());

var pointsCloud = sceneData
    .then(text => text.split('\n').filter(line => line[0] == 'p').map(pointDescription => pointDescription.split(' ')))
    .then(pointsDescription => pointsDescription.map(pointTokens => ({ x: Number(pointTokens[1]), y: Number(pointTokens[2]), z: Number(pointTokens[3]) })));

var camera, scene, renderer, controls;
var geometry, material, mesh;
 
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
 
    geometry = new THREE.BoxGeometry( 0.2, 0.2, 0.2 );
    material = new THREE.MeshNormalMaterial();
 
    mesh = new THREE.Mesh( geometry, material );

    var dotGeometry = new THREE.Geometry();
    pointsCloud.then(points => points.map(
        point => dotGeometry.vertices.push(new THREE.Vector3(point.x, point.y, point.z))
    ))
    .then(() => {
        var dotMaterial = new THREE.PointsMaterial( { size: 5, sizeAttenuation: false } );
        var dot = new THREE.Points( dotGeometry, dotMaterial );
        scene.add( dot );
    });
}
 
function animate() {
 
    requestAnimationFrame( animate );
 
    // mesh.rotation.x += 0.01;
    // mesh.rotation.y += 0.02;

    controls.update();
 
    renderer.render( scene, camera );
 
}