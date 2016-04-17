/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package character;

/**
 *
 * @author David
 */
public class MeleeWeapon {
    String name;
    int reach;
    int damage;
    int accuracy;
    int armorPierce;
    
    MeleeWeapon(String name, int reach, int damage, int accuracy, int armorPierce) {
        this.name = name;
        this.reach = reach;
        this.damage = damage;
        this.accuracy = accuracy;
        this.armorPierce = armorPierce;   
    }
    
    String prepareForDB() {
        return name + ":" + reach + ":" + damage + ":" + accuracy + ":" + armorPierce;
    }
    
    public String getName() {
        return this.name;
    }

    public int getReach() {
        return reach;
    }

    public int getDamage() {
        return damage;
    }

    public int getAccuracy() {
        return accuracy;
    }

    public int getArmorPierce() {
        return armorPierce;
    }
    
    
}
