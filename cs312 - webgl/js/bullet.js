/**
 * Created by david_000 on 2/8/2016.
 */
"use strict";

class Bullet {
    constructor(object) {
        this.model = object.clone();
        this.speed = 8;
        this.distance = 0;
    }

    advance() {
        this.model.translateZ(-this.speed);
        this.distance += this.speed;
        //this.model.updateMatrix();
    }

    remove(scene) {
        scene.remove(this.model);
    }
}

function updateBullet(tank, otherTank) {
    //pass in bullet object
    
    if (tank.bullets[tank.bulletsRemoved] != undefined) {
        //goes through the entire array of bullets
        for (var i = tank.bulletsRemoved; i < tank.bullets.length; i++) {

            tank.bullets[i].bulletBox.setFromObject(tank.bullets[i].model);

            for (var a = 0; a < parkingGarages.length; a++){
                if(tank.bullets[i].bulletBox.intersectsBox(parkingGarages[a])){
                    var tmp = tank.bullets[i];
                    //increment my bulletsRemoved to know where to start next time in the array.
                    tank.bulletsRemoved++;
                    scene.remove(tmp.model);
                }
            }
            //MODIFICATION
            for ( var b = 0; b < brickWalls.length; b++){
                if(tank.bullets[i].bulletBox.intersectsBox(brickWalls[b])){

                    if(!tank.isGiantBullet){
                        var tmp = tank.bullets[i];
                        //increment my bulletsRemoved to know where to start next time in the array.
                        tank.bulletsRemoved++;
                        scene.remove(tmp.model);
                    }else{
                        scene.remove(brickWall);
                        scene.remove(parkingGarage);
                        for(var i = 0; i < brickWalls.length; i++){
                            brickWalls[i].setFromObject(theVoid);
                        }
                        for(var j = 0; j < parkingGarages.length; j++){
                            parkingGarages[j].setFromObject(theVoid);
                        }
                    }

                    var tmp = tank.bullets[i];
                    //increment my bulletsRemoved to know where to start next time in the array.
                    tank.bulletsRemoved++;
                    scene.remove(tmp.model);
                }
            }
            
            if(tank.bullets[i].bulletBox.intersectsBox(otherTank.tankBox)){

                console.log("You hit " + otherTank.name + "!");
                otherTank.health--;
                
                if(otherTank.name == "Tank1"){
                    switch(otherTank.health) {
                        case 2: 
                            document.getElementById("tank01Health").style.width = "66.66%";
                            break;
                        case 1:
                            document.getElementById("tank01Health").style.width = "33.33%";
                            break;
                        case 0:
                            document.getElementById("tank01Health").style.width = "0%";
                            break;
                    }
                }else{
                    switch(otherTank.health) {
                        case 2: 
                            document.getElementById("tank02Health").style.width = "66.66%";
                            break;
                        case 1:
                            document.getElementById("tank02Health").style.width = "33.33%";
                            break;
                        case 0:
                            document.getElementById("tank02Health").style.width = "0%";
                            break;
                    }
                }
                
                console.log(otherTank.health);
                if (otherTank.health <= 0) {
                    if(!otherTank.isThirdPerson){keyboardChangeCamera(otherTank);}

                    var audio = new Audio('sounds/explode.mp3');
                    audio.volume = .75;
                    audio.play();
                    
                    setTimeout(function(){
                        console.log(otherTank.name + "Died");

                        scene.remove(otherTank);
                        otherTank.tankBox.setFromObject(theVoid);

                        explosion.position.set(otherTank.position.x,otherTank.position.y,otherTank.position.z);
                        explosion.scale.set(.25,.25,.25);
                        scene.add(explosion); 
                    }, 50);
                    
                } else { 
                    //Random respawn
                    otherTank.position.set(Math.random() * X_SIZE ,0, Math.random() * Z_SIZE);
                }
                
                var tmp = tank.bullets[i];
                //increment my bulletsRemoved to know where to start next time in the array.
                tank.bulletsRemoved++;
                scene.remove(tmp.model);       
            }

            //If bullet distance is farther than 1000, remove it from the scene
            if (tank.bullets[i].distance > 10000) {
                var tmp = tank.bullets[i];
                //increment my bulletsRemoved to know where to start next time in the array.
                tank.bulletsRemoved++;
                scene.remove(tmp.model);
            }
        }
    }
}
