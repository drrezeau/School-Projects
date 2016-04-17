/**
 * Created by david_000 on 2/8/2016.
 */
"use strict";
class loadBullet {
    constructor() {

        var me = this;
        var loader = new THREE.ObjectLoader();
        loader.load("/webgl/objects/bullet.json", function (obj) {
            obj.name = "bullet";

            me.model = obj;

            me.model.rotation.y = 180*(Math.PI/180);
            me.model.scale.set(.1,.1,.1)
        });

    }
}