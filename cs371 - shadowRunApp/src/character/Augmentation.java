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
public class Augmentation {
    String name, notes;
    int rating;
    float essenceCost;

    public Augmentation(String name, String notes, int rating, float essenceCost) {
        this.name = name;
        this.notes = notes;
        this.rating = rating;
        this.essenceCost = essenceCost;
    }

    public String prepareForDB() {
        return name + ":" + rating + ":" + notes + ":" + essenceCost;
    }
    
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String getNotes() {
        return notes;
    }
    public void setNotes(String notes) {
        this.notes = notes;
    }
    public int getRating() {
        return rating;
    }
    public void setRating(int rating) {
        this.rating = rating;
    }
    public float getEssenceCost() {
        return essenceCost;
    }
    public void setEssenceCost(float essenceCost) {
        this.essenceCost = essenceCost;
    }
    
    
    
}
