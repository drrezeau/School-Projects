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
public class Gear {
    String name;
    int rating;
    String notes;

    public Gear(String name, int rating, String notes) {
        this.name = name;
        this.rating = rating;
        this.notes = notes;
    }
    
    public String prepareForDB() {
        String rtn = "";
        rtn += name + ":";
        rtn += rating + ":";
        rtn += notes;
        
        return rtn;
    }
    
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public int getRating() {
        return rating;
    }
    public void setRating(int rating) {
        this.rating = rating;
    }
    public String getNotes() {
        return notes;
    }
    public void setNotes(String notes) {
        this.notes = notes;
    }
    
}
