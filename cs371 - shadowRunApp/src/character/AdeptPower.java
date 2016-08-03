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
public class AdeptPower {
    String name, notes;
    int rating;

    public AdeptPower() {
        this.name = "";
        this.notes = "";
        this.rating = 0;
    }
    public AdeptPower(String name, String notes, int rating) {
        this.name = name;
        this.notes = notes;
        this.rating = rating;
    }
    
    public String prepareForDB() {
        return name + ":" + rating + ":" + notes;
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
    
    
}
