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
public class Contact {
    private String name;
    private int loyalty;
    private int connection;
    private String favor;
    
    
    Contact(String name, int loyalty, int connection, String favor) {
        this.name = name;
        this.loyalty = loyalty;
        this.connection = connection;
        this.favor = favor;
    }
    
    String prepareForDB() {
        return name + ":" + loyalty + ":" + connection + ":" + favor;
    }
    
    public String getName() {
        return this.name;
    }

    public int getLoyalty() {
        return loyalty;
    }

    public int getConnection() {
        return connection;
    }

    public String getFavor() {
        return favor;
    }
    
    
    
}
