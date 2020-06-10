import * as THREE from './node_modules/three/build/three.module.js';
import { OrbitControls } from './node_modules/three/examples/jsm/controls/OrbitControls.js';

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

    camera.position.z = 1;

    controls.update();
 
    scene = new THREE.Scene();
 
    geometry = new THREE.BoxGeometry( 0.2, 0.2, 0.2 );
    material = new THREE.MeshNormalMaterial();
 
    mesh = new THREE.Mesh( geometry, material );
    scene.add( mesh );
}
 
function animate() {
 
    requestAnimationFrame( animate );
 
    mesh.rotation.x += 0.01;
    mesh.rotation.y += 0.02;

    controls.update();
 
    renderer.render( scene, camera );
 
}