/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shadowRunApp.FXMLs.armor;

import character.Armor;
import character.Contact;
import java.net.URL;
import java.util.ArrayList;
import java.util.Optional;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextInputDialog;
import shadowRunApp.ShadowRunApp;

/**
 * FXML Controller class
 *
 * @author david_000
 */
public class ArmorController implements Initializable {

    @FXML
    private TextArea display;
    
    @FXML
    public void add(ActionEvent event) {
        try {
            new ShadowRunApp().addArmorScene();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public void edit(ActionEvent event) {
       //Dialog box that allows the user to input something.
       TextInputDialog dialog = new TextInputDialog();
       dialog.setTitle("Armor to Edit");   
       dialog.setHeaderText("Armor");
       dialog.setContentText("Please enter the piece of armor to edit:");
       String name;
       // Traditional way to get the response value.
       Optional<String> result = dialog.showAndWait();
       name = result.get();
       
       name = name.toLowerCase();
       ArrayList<Armor> armor = new ShadowRunApp().getCharacter().getArmor();
       for (int i = 0; i < armor.size(); i++) {
           String temp = armor.get(i).getName();
           if (temp.toLowerCase().equals(name)) {
               
                try {
                    new ShadowRunApp().editArmorScene(armor.get(i));
                } catch (Exception e) {
                    e.printStackTrace();
                }
           }
       }
    }
    public void delete() {
        //Dialog box that allows the user to input something.
       TextInputDialog dialog = new TextInputDialog();
       dialog.setTitle("Armor to Delete");   
       dialog.setHeaderText("Armor");
       dialog.setContentText("Please enter the piece of armor to delete:");
       String name;
       // Traditional way to get the response value.
       Optional<String> result = dialog.showAndWait();
       name = result.get();
       
       new ShadowRunApp().getCharacter().deleteArmor(name);
       
       this.initialize(null, null);
    }
    
    @FXML
    public void back(ActionEvent event) {
        try {
            new ShadowRunApp().back();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    
    
    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
        
         String text2Display = "";
        text2Display += "--- Armor ---\n";
        text2Display += new ShadowRunApp().getCharacter().createArmorString();
        
        display.setText(text2Display);
    }    
    
}
