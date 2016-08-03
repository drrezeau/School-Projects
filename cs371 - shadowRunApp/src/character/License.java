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
public class License {
    String name;
    Integer rating;
    
    License(String newName, Integer newRating) {
        name = newName;
        rating = newRating;
    }

    
    public String prepareForDB() {
        String text2Return = "";
        
        text2Return += this.name + ":" + rating;
        return text2Return;
    }
    
    //GETTERS AND SETTERS
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public Integer getRating() {
        return rating;
    }
    public void setRating(Integer rating) {
        this.rating = rating;
    }
    
    
}
