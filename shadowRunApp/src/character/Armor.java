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
public class Armor {
    String name;
    int rating;
    String notes;
    
    Armor(String name, int rating, String notes) {
        this.name = name;
        this.rating = rating;
        this.notes = notes;
    }
    
    public String prepareForDB() {
        return name + ":" + rating + ":" + notes;
    }

    public String getName() {
        return name;
    }

    public int getRating() {
        return rating;
    }

    public String getNotes() {
        return notes;
    }
    
    
}
