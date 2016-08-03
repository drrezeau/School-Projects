/**
 * Created by david_000 on 2/17/2016.
 */
var mesh,
    start = Date.now(),
    fov = 30;

function explosion() {

    // grab the container from the DOM
    // create a scene
    // create a camera the size of the browser window
    // and place it 100 units away, looking towards the center of the scene
    // create a wireframe material
    material = new THREE.ShaderMaterial({

        uniforms: {
            tExplosion: {
                type: "t",
                value: THREE.ImageUtils.loadTexture('images/explosion.png')
            },
            time: { // float initialized to 0
                type: "f",
                value: 0.0
            }
        },
        vertexShader: document.getElementById('vertexShader').textContent,
        fragmentShader: document.getElementById('fragmentShader').textContent

    });

    // create a sphere and assign the material
    mesh = new THREE.Mesh(
        new THREE.IcosahedronGeometry(20, 4),
        material
    );
    mesh.name = 'explosion';
    return mesh;
}
var explosionScale = 0, explosionDying = false;
function updateExplosion() {
    if (explosionDying) {

    } else {
        explosion.scale.set(explosionScale, explosionScale, explosionScale);
        explosionScale += .01;
    }
    if (explosionScale >= 1) {
        scene.remove(explosion);
        explosionDying = true;
    }
}