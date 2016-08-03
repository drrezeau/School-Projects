/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package character;

import java.util.ArrayList;
/**
 *
 * @author c
 */
public class RangedWeapon {
    String name;
    String mode;
    int damage;
    int accuracy;
    int armorPierce;
    int recoil;
    String notes;

    public RangedWeapon(String name, String mode, int damage, int accuracy, int armorPierce, int recoil, String notes) {
        this.name = name;
        this.mode = mode;
        this.damage = damage;
        this.accuracy = accuracy;
        this.armorPierce = armorPierce;
        this.recoil = recoil;
        this.notes = notes;
    }
    
    public String prepareForDB() {
        return name + ":" + damage + ":" + accuracy + ":" + armorPierce + ":" + mode + ":" + recoil + ":" + notes;
    }
    
    public String getName() {
        return name;
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

    public int getRecoil() {
        return recoil;
    }    
    public String getMode() {
        return mode;
    }
    public String getNotes() {
        return notes;
    }
    
}
