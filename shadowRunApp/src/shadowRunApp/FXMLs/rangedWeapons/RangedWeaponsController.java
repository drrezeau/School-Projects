/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shadowRunApp.FXMLs.rangedWeapons;

import character.Contact;
import character.RangedWeapon;
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
public class RangedWeaponsController implements Initializable {

    @FXML
    private TextArea display;
    
    @FXML
    public void addWeapon(ActionEvent event) {
        try {
            new ShadowRunApp().addRangedWeaponScene();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public void editWeapon(ActionEvent event) {
       //Dialog box that allows the user to input something.
       TextInputDialog dialog = new TextInputDialog();
       dialog.setTitle("Weapon to Edit");   
       dialog.setHeaderText("Ranged Wepaons");
       dialog.setContentText("Please enter the weapon to edit:");
       String name;
       // Traditional way to get the response value.
       Optional<String> result = dialog.showAndWait();
       name = result.get();
       
       name = name.toLowerCase();
       ArrayList<RangedWeapon> rw = new ShadowRunApp().getCharacter().getRangedWeapons();
       for (int i = 0; i < rw.size(); i++) {
           String temp = rw.get(i).getName();
           if (temp.toLowerCase().equals(name)) {
               
                try {
                    new ShadowRunApp().editRangedWeaponScene(rw.get(i));
                } catch (Exception e) {
                    e.printStackTrace();
                }
           }
       }
    }
    public void deleteWeapon() {
        //Dialog box that allows the user to input something.
       TextInputDialog dialog = new TextInputDialog();
       dialog.setTitle("Weapon to Delete");   
       dialog.setHeaderText("Ranged Weapons");
       dialog.setContentText("Please enter the weapon to delete:");
       String name;
       // Traditional way to get the response value.
       Optional<String> result = dialog.showAndWait();
       name = result.get();
       
       new ShadowRunApp().getCharacter().deleteRangedWeapon(name);
       
       this.initialize(null, null);
    }
    
    /***********************************************************
     * Not using these right now.
     * ********************************************************/
    @FXML
    public void addAmmo(ActionEvent event) {
        try {
//            new ShadowRunApp().addRangedWeaponScene();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public void editAmmo(ActionEvent event) {
       //Dialog box that allows the user to input something.
       TextInputDialog dialog = new TextInputDialog();
       dialog.setTitle("Weapon ammo to Edit");   
       dialog.setHeaderText("Ranged Wepaons Ammo");
       dialog.setContentText("Please enter the weapon ammo to edit:");
       String name;
       // Traditional way to get the response value.
       Optional<String> result = dialog.showAndWait();
       name = result.get();
       
       name = name.toLowerCase();
       ArrayList<RangedWeapon> rw = new ShadowRunApp().getCharacter().getRangedWeapons();
       for (int i = 0; i < rw.size(); i++) {
           String temp = rw.get(i).getName();
           if (temp.toLowerCase().equals(name)) {
               
                try {
//                    new ShadowRunApp().editRangedWeaponScene(rw.get(i));
                } catch (Exception e) {
                    e.printStackTrace();
                }
           }
       }
    }
    public void deleteAmmo() {
        //Dialog box that allows the user to input something.
       TextInputDialog dialog = new TextInputDialog();
       dialog.setTitle("Weapon ammo to Delete");   
       dialog.setHeaderText("Ranged Weapons Ammo");
       dialog.setContentText("Please enter the weapon ammo to delete:");
       String name;
       // Traditional way to get the response value.
       Optional<String> result = dialog.showAndWait();
       name = result.get();
       
//       new ShadowRunApp().getCharacter().deleteContact(name);
       
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
        text2Display += "\n--- RANGED WEAPONS ---\n";
        text2Display += new ShadowRunApp().getCharacter().createRangedWeaponsString();
//        text2Display += "\n--- RANGED WEAPONS AMMO ---\n";
//        text2Display += me.createRangedWeaponsString();
        display.setText(text2Display);
    }    
    
}
