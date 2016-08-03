/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package character;

/**
 *
 * @author c
 */
public class Spell {
    String name, type, range, duration;
    int drain;

    public Spell(String name, String type, String range, String duration, int drain) {
        this.name = name;
        this.type = type;
        this.range = range;
        this.duration = duration;
        this.drain = drain;
    }
    
    public String prepareForDB() {
        return name + ":" + type + ":" + range + ":" + duration + ":" + drain;
    }

    public String getName() {
        return name;
    }
    public String getType() {
        return type;
    }
    public String getRange() {
        return range;
    }
    public String getDuration() {
        return duration;
    }
    public int getDrain() {
        return drain;
    }
    
    
    
}
