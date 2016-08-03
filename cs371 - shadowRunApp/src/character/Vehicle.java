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
public class Vehicle {
    String name;
    int handling;
    int acceleration;
    int speed;
    int pilot;
    int body;
    int armor;
    int sensor;
    String notes;

    public Vehicle() {
        name = "no vehicle";
        handling = acceleration = speed = pilot = body = armor = sensor = 0;
        notes = "";
    }

    public Vehicle(String name, int handling, int acceleration, int speed, int pilot, int body, int armor, int sensor, String notes) {
        this.name = name;
        this.handling = handling;
        this.acceleration = acceleration;
        this.speed = speed;
        this.pilot = pilot;
        this.body = body;
        this.armor = armor;
        this.sensor = sensor;
        this.notes = notes;
    }
    
    public Vehicle(Vehicle copy) {
        this.name = copy.name;
        this.handling = copy.handling;
        this.acceleration = copy.acceleration;
        this.speed = copy.speed;
        this.pilot = copy.pilot;
        this.body = copy.body;
        this.armor = copy.armor;
        this.sensor = copy.sensor;
        this.notes = copy.notes;
    }
    
    public void setVehicle(String name, int handling, int acceleration, int speed, int pilot, int body, int armor, int sensor, String notes) {
        this.name = name;
        this.handling = handling;
        this.acceleration = acceleration;
        this.speed = speed;
        this.pilot = pilot;
        this.body = body;
        this.armor = armor;
        this.sensor = sensor;
        this.notes = notes;
    }
    
    public String prepareForDB() {
        String rtn = "";
        rtn += name + ":" + handling + ":" + acceleration + ":" + speed + ":" 
                + pilot + ":" + body + ":" + armor + ":" + sensor + ":" + notes;
        return rtn;
    }
    
    public String toDisplay() {
        String rtn = "";
        
        rtn += name + " | Handling: " + handling + " | Acceleration: " + acceleration 
                + " | Speed: " + speed + " | Pilot: " + pilot + " | Body: " 
                + body + " | Armor: " + armor + " | Sensors: " + sensor + " | Notes: " + notes + '\n';
        
        return rtn;
    }
    /*****************************************************
     * Getters and Setters
     *************************************************/
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public int getHandling() {
        return handling;
    }
    public void setHandling(int handling) {
        this.handling = handling;
    }
    public int getAcceleration() {
        return acceleration;
    }
    public void setAcceleration(int acceleration) {
        this.acceleration = acceleration;
    }
    public int getSpeed() {
        return speed;
    }
    public void setSpeed(int speed) {
        this.speed = speed;
    }
    public int getPilot() {
        return pilot;
    }
    public void setPilot(int pilot) {
        this.pilot = pilot;
    }
    public int getBody() {
        return body;
    }
    public void setBody(int body) {
        this.body = body;
    }
    public int getArmor() {
        return armor;
    }
    public void setArmor(int armor) {
        this.armor = armor;
    }
    public int getSensor() {
        return sensor;
    }
    public void setSensor(int sensor) {
        this.sensor = sensor;
    }
    public String getNotes() {
        return notes;
    }
    public void setNotes(String notes) {
        this.notes = notes;
    }    
}
