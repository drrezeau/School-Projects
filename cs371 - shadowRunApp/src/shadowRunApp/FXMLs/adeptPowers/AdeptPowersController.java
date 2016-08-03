/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shadowRunApp.FXMLs.adeptPowers;

import character.AdeptPower;
import character.Armor;
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
 * @author c
 */
public class AdeptPowersController implements Initializable {

    @FXML
    private TextArea display;
    
    @FXML
    public void add(ActionEvent event) {
        try {
            new ShadowRunApp().addAdeptScene();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public void edit(ActionEvent event) {
       //Dialog box that allows the user to input something.
       TextInputDialog dialog = new TextInputDialog();
       dialog.setTitle("Adept Power to Edit");   
       dialog.setHeaderText("Adept Powers");
       dialog.setContentText("Please enter the adept power to edit:");
       String name;
       // Traditional way to get the response value.
       Optional<String> result = dialog.showAndWait();
       name = result.get();
       
       name = name.toLowerCase();
       ArrayList<AdeptPower> other = new ShadowRunApp().getCharacter().getAdeptPowers();
       for (int i = 0; i < other.size(); i++) {
           String temp = other.get(i).getName();
           if (temp.toLowerCase().equals(name)) {
               
                try {
                    new ShadowRunApp().editAdeptScene(other.get(i));
                } catch (Exception e) {
                    e.printStackTrace();
                }
           }
       }
    }
    public void delete() {
        //Dialog box that allows the user to input something.
       TextInputDialog dialog = new TextInputDialog();
       dialog.setTitle("Adept Power to Delete");   
       dialog.setHeaderText("Adept Powers");
       dialog.setContentText("Please enter the adept power to delete:");
       String name;
       // Traditional way to get the response value.
       Optional<String> result = dialog.showAndWait();
       name = result.get();
       
       new ShadowRunApp().getCharacter().deleteAdeptPower(name);
       
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
        text2Display += "--- ADEPT POWERS ---\n";
        text2Display += new ShadowRunApp().getCharacter().createAdeptPowersString();
        display.setText(text2Display);
    }    
    
}
