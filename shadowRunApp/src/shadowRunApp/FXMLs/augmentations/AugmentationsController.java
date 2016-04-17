/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shadowRunApp.FXMLs.augmentations;

import character.Armor;
import character.Augmentation;
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
public class AugmentationsController implements Initializable {

    @FXML
    private TextArea display;
    
    @FXML
    public void add(ActionEvent event) {
        try {
            new ShadowRunApp().addAugmentationScene();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public void edit(ActionEvent event) {
       //Dialog box that allows the user to input something.
       TextInputDialog dialog = new TextInputDialog();
       dialog.setTitle("Augmentation to Edit");   
       dialog.setHeaderText("Augmentation");
       dialog.setContentText("Please enter the augmentation to edit:");
       String name;
       // Traditional way to get the response value.
       Optional<String> result = dialog.showAndWait();
       name = result.get();
       
       name = name.toLowerCase();
       ArrayList<Augmentation> aug = new ShadowRunApp().getCharacter().getAugmentations();
       for (int i = 0; i < aug.size(); i++) {
           String temp = aug.get(i).getName();
           if (temp.toLowerCase().equals(name)) {
               
                try {
                    new ShadowRunApp().editAugmentationScene(aug.get(i));
                } catch (Exception e) {
                    e.printStackTrace();
                }
           }
       }
    }
    public void delete() {
        //Dialog box that allows the user to input something.
       TextInputDialog dialog = new TextInputDialog();
       dialog.setTitle("Augmentation to Delete");   
       dialog.setHeaderText("Augmentation");
       dialog.setContentText("Please enter the augmentation to delete:");
       String name;
       // Traditional way to get the response value.
       Optional<String> result = dialog.showAndWait();
       name = result.get();
       
       new ShadowRunApp().getCharacter().deleteAugmentation(name);
       
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
        text2Display += "--- AUGMENTATIONS ---\n";
        text2Display += new ShadowRunApp().getCharacter().createAugmentationsString();
        display.setText(text2Display);
    }    
    
}
