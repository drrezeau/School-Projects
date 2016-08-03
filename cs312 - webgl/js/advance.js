/**
 * Created by david_000 on 2/8/2016.
 */

function advance(tank) {
    // fire a laser
    var length = tank.bullets.length;
    if (tank.bullets[0] != undefined) {
        for (var i = 0; i < length; i++) {
            var tmp = scene.getObjectByName(tank.bullets[i].model.name);
            if (tmp != undefined) {
                tank.bullets[i].advance();
            }
        }
    }
}