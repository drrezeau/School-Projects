var parkingGarage = new THREE.Object3D();
var parkingGarages = [];

var loader = new THREE.TextureLoader();

// load a resource
loader.load(
    // resource URL
    'images/concrete.jpg',
    // Function when resource is loaded
    function ( texture ) {
        // do something with the texture
        var material = new THREE.MeshLambertMaterial( {
            map: texture
         } );

        var geometry = new THREE.BoxGeometry( 5, 20, 5 );

        //pillars in the y direction (UP)
        for (var i = 0; i < 4; i++){
            //pillars in the x direction (LEFT)
            for (var j = 0; j < 4; j++){
                //pillars in the z direction (BACK);
                for ( var k = 0; k < 4; k++) {
                    var pillar = new THREE.Mesh( geometry, material );
                    pillar.position.set(j * 25, 21 * i, k * 25);

                    //Only create the bounding boxes for the first floor
                    if (i == 0) {
                        pillarBox = new THREE.Box3(new THREE.Vector3(), new THREE.Vector3());
                        pillarBox.setFromObject(pillar);
                        parkingGarages.push(pillarBox);
                    }

                    parkingGarage.add(pillar);
                }
            }
        }

        for(var l = 0; l < 4; l++){
            geometry = new THREE.BoxGeometry(5, 1, 80);
            var floor = new THREE.Mesh( geometry, material );

            floor.scale.x = 16;
            floor.position.set(37.5, (10.5 * 2 * l) + 10.5 , 37.5);
            parkingGarage.add(floor);
        }

        
        parkingGarage.position.set(0, 10, 0);
    },
    // Function called when download progresses
    function ( xhr ) {
        console.log( (xhr.loaded / xhr.total * 100) + '% loaded' );
    },
    // Function called when download errors
    function ( xhr ) {
        console.log( 'An error happened' );
    }
);