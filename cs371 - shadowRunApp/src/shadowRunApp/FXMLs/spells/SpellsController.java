/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shadowRunApp.FXMLs.spells;

import character.Quality;
import character.Spell;
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
public class SpellsController implements Initializable {

    @FXML
    private TextArea display;
    
    @FXML
    public void back(ActionEvent event) {
        try {
            new ShadowRunApp().back();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    @FXML
    public void add(ActionEvent event) {
        try {
            new ShadowRunApp().addSpellScene();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    @FXML 
    public void edit() {
       TextInputDialog dialog = new TextInputDialog();
       dialog.setTitle("Spell to Edit");   
       dialog.setHeaderText("Spells");
       dialog.setContentText("Please enter the spell to edit:");
       String name;
       // Traditional way to get the response value.
       Optional<String> result = dialog.showAndWait();
       name = result.get();
       
       name = name.toLowerCase();
       ArrayList<Spell> spells = new ShadowRunApp().getCharacter().getSpells();
       for (int i = 0; i < spells.size(); i++) {
           String temp = spells.get(i).getName();
           if (temp.toLowerCase().equals(name)) {
               
               try {
                    new ShadowRunApp().editSpellScene(spells.get(i));
                } catch (Exception e) {
                    e.printStackTrace();
                }
           }
       }
    }
    
    @FXML
    public void delete() {
       TextInputDialog dialog = new TextInputDialog();
       dialog.setTitle("Spell to Delete");   
       dialog.setHeaderText("Spells");
       dialog.setContentText("Please enter the spell to delete:");
       String name;
       // Traditional way to get the response value.
       Optional<String> result = dialog.showAndWait();
       name = result.get();
       
       new ShadowRunApp().getCharacter().deleteSpell(name);
       
       this.initialize(null, null);
    }
    
    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
        String text2Display = "";
        text2Display += "--- SPELLS ---\n";
        text2Display += new ShadowRunApp().getCharacter().createSpellsString();
        display.setText(text2Display);    
    }    
    
}
