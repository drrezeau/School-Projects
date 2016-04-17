function isOutOfBounds(tank){

            if(tank.position.x > X_SIZE + 75){
                return true;
            }
            if(tank.position.z > Z_SIZE + 75){
                return true;
            }
            if(tank.position.x < -75){
                return true;
            }
            if(tank.position.z < -75){
                return true;
            }
            return false;
        }

/*******************************************************************************************************************************
* Space
*
*
*******************************************************************************************************************************/  
function keyboardShoot(tank, tankMovement) {
    if (!tank.reload) {
        var bullet = new Bullet(mainBullet.model);

        if(tank.isGiantBullet){bullet.model.scale.set(1, 1, 1);}

        bullet.speed = tank.shootSpeed;
        //Sets the bullet Angle
        bulletAngle = tankMovement.shootAngle;

        //Sets the position of the bullet to fire from where the tank is
        bullet.model.position.set(tank.position.x, tank.position.y + 2.5, tank.position.z);
        //console.log("BULLET ANGLE -- " + bulletAngle);
        bullet.model.rotation.y = bulletAngle;
        //sets the name of the bullet to its spot in the array
        bullet.model.name = tank.bullets.length;

        //Set the bounding box tied to the given bullet
        bullet.bulletBox = new THREE.Box3(new THREE.Vector3(), new THREE.Vector3());
        bullet.bulletBox.setFromObject(bullet.model);

        //Add to the Array on tank01
        tank.bullets.push(bullet);

        //Sets reload to true to make the shooting slower
        tank.reload = true;

        scene.add(bullet.model);
        var audio = new Audio('sounds/shoot.mp3');
        audio.volume = .5;
        audio.play();
        setTimeout(function(){
            tank.reload = false;
        }, tank.reloadSpeed);
        //scene.add(bullet.model);
    }
}

/*******************************************************************************************************************************
* Up
*
*
*******************************************************************************************************************************/  
  function keyboardUp(tank, tankMovement, otherTank) {

    for (var a = 0; a < parkingGarages.length; a++){
        if(tank.tankBox.intersectsBox(parkingGarages[a])){return;}
    }
    for ( var b = 0; b < brickWalls.length; b++){
        if(tank.tankBox.intersectsBox(brickWalls[b])){return;}
    }

    if(tank.tankBox.intersectsBox(otherTank.tankBox)){return;}


    if(isOutOfBounds(tank)){
        tank.health -= 1;
        updateHealth(tank)

        if(tank.health < 1){
            if(!otherTank.isThirdPerson){keyboardChangeCamera(otherTank);}

            var audio = new Audio('sounds/explode.mp3');
                audio.volume = .75;
                audio.play();

                setTimeout(function(){
                    console.log(tank.name + "Died");
                    scene.remove(tank);
                    tank.tankBox.setFromObject(theVoid);

                    explosion.position.set(tank.position.x, tank.position.y, tank.position.z);
                    explosion.scale.set(.25,.25,.25);
                    scene.add(explosion);
                }, 50);
        }else {
            tank.position.set(Math.random() * X_SIZE ,0, Math.random() * Z_SIZE);
        }
    }

    if (healthPackOn) {
        //Health Pack
        if (tank.tankBox.intersectsBox(healthPackBox)) {
            if (tank.health < 3) {

                tank.health += 1;
                updateHealth(tank);

                //Remove from scene
                scene.remove(healthPack);
                scene.remove(healthPackBox);
                healthPackBox.setFromObject(theVoid);
            }

        }
    }


    if (bulletBoostOn) {
        //bullet speed boost
        if (tank.tankBox.intersectsBox(bulletSpeedBoostBox)) {
            tank.shootSpeed = 12;
            tank.reloadSpeed = 250;

            setTimeout(function () {
                //Return speed to normal
                tank.shootSpeed = 8;
                tank.reloadSpeed = 500;
            }, 10000);

            //Remove from scene
            scene.remove(bulletSpeedBoost);
            scene.remove(bulletSpeedBoostBox);
            bulletSpeedBoostBox.setFromObject(theVoid);

            setTimeout(function () {
                bulletSpeedBoost.position.set(Math.random() * X_SIZE, 2.5, Math.random() * Z_SIZE);
                scene.add(bulletSpeedBoost);
                scene.add(bulletSpeedBoostBox);
                bulletSpeedBoostBox.setFromObject(bulletSpeedBoost);
            }, 25000);
        }
    }

    if (speedBoostOn) {
        //Speed Boost
        if (tank.tankBox.intersectsBox(speedBoostBox)) {
            //Boost their speed
            tankMovement.speed = 3;
            tankMovement.turnSpeed = .04;

            setTimeout(function () {
                //Return speed to normal
                tankMovement.speed = 1;
                tankMovement.turnSpeed = .02;
            }, 10000);

            //Remove from scene
            scene.remove(speedBoost);
            scene.remove(speedBoostBox);
            speedBoostBox.setFromObject(theVoid);

            setTimeout(function () {
                speedBoost.position.set(Math.random() * X_SIZE, 2.5, Math.random() * Z_SIZE);
                scene.add(speedBoost);
                scene.add(speedBoostBox);
                speedBoostBox.setFromObject(speedBoost);
            }, 25000);
        }
    }

    if (ultPowerOn) {
        if (tank.tankBox.intersectsBox(goldenSnitchBox)) {
            //Remove all other power ups
            scene.remove(speedBoost);
            scene.remove(speedBoostBox);
            speedBoostBox.setFromObject(theVoid);

            scene.remove(healthPack);
            scene.remove(healthPackBox);
            healthPackBox.setFromObject(theVoid);

            scene.remove(bulletSpeedBoost);
            scene.remove(bulletSpeedBoostBox);
            bulletSpeedBoostBox.setFromObject(theVoid);


            tank.isGiantBullet = true;
            tank.shootSpeed = 12;
            tank.reloadSpeed = 250;
            tankMovement.speed = 4;
            tankMovement.turnSpeed = .06;
            tank.health = 3;
            updateHealth(tank);
            scene.remove(goldenSnitch);
            scene.remove(goldenSnitchBox);
            goldenSnitchBox.setFromObject(theVoid);
        }
    }

    tank.position.x += Math.sin(-tankMovement.driveAngle) * tankMovement.speed;
    tank.position.z += Math.cos(-tankMovement.driveAngle) * tankMovement.speed;
  }

/*******************************************************************************************************************************
* Down
*
*
*******************************************************************************************************************************/  
function keyboardDown(tank, tankMovement) {

    if(isOutOfBounds(tank)){
        tank.health -= 1;
        updateHealth(tank);

        if(tank.health < 1){
            var audio = new Audio('sounds/explode.mp3');
                audio.volume = .75;
                audio.play();

                setTimeout(function(){
                    console.log(tank.name + "Died");
                    scene.remove(tank);
                    tank.tankBox.setFromObject(theVoid);

                    explosion.position.set(tank.position.x, tank.position.y, tank.position.z);
                    explosion.scale.set(.25,.25,.25);
                    scene.add(explosion);
                }, 50);
        }else {
            tank.position.set(Math.random() * X_SIZE ,0, Math.random() * Z_SIZE);
        }
    }

    tank.position.x -= Math.sin(-tankMovement.driveAngle) * tankMovement.speed;
    tank.position.z -= Math.cos(-tankMovement.driveAngle) * tankMovement.speed;
}

/*******************************************************************************************************************************
* Left
*
*
*******************************************************************************************************************************/  
  function keyboardLeft(tank, tankMovement) {
    tank.rotation.y += tankMovement.turnSpeed;
    tankMovement.driveAngle -= tankMovement.turnSpeed;
    tankMovement.shootAngle -= tankMovement.turnSpeed;
  }

/*******************************************************************************************************************************
* Right
*
*
*******************************************************************************************************************************/    
function keyboardRight(tank, tankMovement) {
    tank.rotation.y -= tankMovement.turnSpeed;
    tankMovement.driveAngle += tankMovement.turnSpeed;
    tankMovement.shootAngle += tankMovement.turnSpeed;
}

/*******************************************************************************************************************************
* Change Camera
*
*
*******************************************************************************************************************************/ 
function keyboardChangeCamera(tank) {
    var cam;

    if(tank.canChangeCamera){
        if(tank.name == "Tank1"){cam = camera; cam.name = "Tank1";}else{cam = camera2; cam.name = "tank2";}
        if(tank.isThirdPerson){
            if(cam.name == "Tank1"){
                cam.position.set(0, 3, 1);
                cam.rotation.x -= 15 * Math.PI/180;
            }else {
                cam.position.set(0, 4, 0);
                cam.rotation.x += 15 * Math.PI/180;
            }
                tank.isThirdPerson = false;
       }else{
            if(cam.name == "Tank1"){
                console.log("passed test");
                cam.position.set( 0, 25, -50 );
            }else {
                cam.position.set( 0, 25, 50 );
            }

            cam.lookAt( new THREE.Vector3( 0, 0, 0 ) );
            tank.isThirdPerson = true;
       }
        tank.canChangeCamera = false;
        setTimeout(function(){
            tank.canChangeCamera = true;
        }, 500);
    }
}
/*******************************************************************************************************************************
* a
*   Rotates the tanks barrel
*   Adjusts the shoot angle
*   TODO make it tank independant
*
*******************************************************************************************************************************/  
function keyboardA() {
    tank01.traverse( function ( child )
        {
            child.children[5].rotation.z += 2 * Math.PI/180;
            tank01Movement.shootAngle -= 2 * Math.PI/180;
            tank01Box.setFromObject(tank01);
        });
}

/*******************************************************************************************************************************
* d
*   Rotates the tanks barrel
*   Adjusts the shoot angle
*   TODO make it tank independant
*
*******************************************************************************************************************************/  
function keyboardD() {
    tank01.traverse( function ( child )
        {
            child.children[5].rotation.z -= 2 * Math.PI/180;
            tank01Movement.shootAngle += 2 * Math.PI/180;
            tank01Box.setFromObject(tank01);
        });
}

/*******************************************************************************************************************************
* updateHealth
*
******************************************************************************************************************************/
function updateHealth(tank) {
        if(tank.name == "Tank1"){
            switch(tank.health) {
            case 3:
                        document.getElementById("tank01Health").style.width = "100%";
                        break;
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
                switch(tank.health) {
                    case 3:
                        document.getElementById("tank02Health").style.width = "100%";
                        break;
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
}
/*******************************************************************************************************************************
* Extra Code Snippets
*
******************************************************************************************************************************/
//        tank01.traverseVisible( function ( child )
//            {
//                bullet = tank01.getObjectByName("bullet").clone();
//                bullet.visible = true;
//                scene.add(bullet);
//                
//            });
