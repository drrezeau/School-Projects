/**
 * Created by david_000 on 3/16/2016.
 */


function gameSettings() {
    fogOn = $("#FogOn:checked").length > 0;
    fogIntensity = $("#FogInt")[0].value;
    if(fogIntensity == "") {
        console.log(fogIntensity);
        fogIntensity = 1;
    }
    lightIntensity = $("#lightInt")[0].value;
    healthPackOn = $("#health:checked").length > 0;
    speedBoostOn = $("#speed:checked").length > 0;
    bulletBoostOn = $("#bullet:checked").length > 0;
    ultPowerOn = $("#ult:checked").length > 0;
    numWalls = $("#numWalls")[0].value;
    X_SIZE = parseInt($("#arenaSize")[0].value);
    Z_SIZE = X_SIZE;
    
    init();
    animate();
}

function controller(pad, tank, tankMovement, otherTank) {
    if (pad.buttons[7] != undefined && pad.buttons[7].pressed == true ) {
        keyboardShoot(tank, tankMovement);
    }
    if (pad.buttons[12] != undefined && pad.buttons[12].pressed == true ) {
        keyboardUp(tank, tankMovement, otherTank);
    }
    if (pad.buttons[13] != undefined && pad.buttons[13].pressed == true ) {
        keyboardDown(tank, tankMovement);
    }
    if (pad.buttons[14] != undefined && pad.buttons[14].pressed == true ) {
        keyboardLeft(tank, tankMovement);
    }
    if (pad.buttons[15] != undefined && pad.buttons[15].pressed == true ) {
        keyboardRight(tank, tankMovement);
    }
    if (pad.buttons[1] != undefined && pad.buttons[1].pressed == true ) {
        keyboardChangeCamera(tank);
    }
//    if(pad.buttons[9] != undefined && pad.buttons[9].pressed){
//        location.reload();   
//    }
}
