/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shadowRunApp.FXMLs.augmentations;

import character.Augmentation;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import shadowRunApp.ShadowRunApp;

/**
 * FXML Controller class
 *
 * @author c
 */
public class EditAugmentationController implements Initializable {

    @FXML TextField name;
    @FXML TextArea notes;
    @FXML TextField rating;
    @FXML TextField essenceCost;
    
    public void submit() {
        String name1, notes1;
        int rating1;
        float essenceCost1;
        
        if (name.getText().isEmpty()) {
            showAlert("name");
            return;
        }
        if (rating.getText().isEmpty()) {
            showAlert("rating");
            return;
        }
        if (essenceCost.getText().isEmpty()) {
            showAlert("essence cost");
            return;
        }
        if (notes.getText().isEmpty()) {
            showAlert("notes");
        }
        
        name1 = name.getText();
        notes1 = notes.getText();
        rating1 = Integer.parseInt(rating.getText());
        essenceCost1 = Float.parseFloat(essenceCost.getText());
        
        new ShadowRunApp().getCharacter().addAugmentation(name1, rating1, notes1, essenceCost1);
        new ShadowRunApp().getCharacter().sortAugmentations();
        
        try {
        new ShadowRunApp().createAugmentationScene();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    void showAlert(String error) {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setContentText("No " + error + " entered.");
        alert.setHeaderText("Error");
        alert.setTitle("Error");
        alert.showAndWait();
    }
    
    public void setText(Augmentation aug) {
        name.setText(aug.getName());
        rating.setText(Integer.toString(aug.getRating()));
        notes.setText(aug.getNotes());
        essenceCost.setText(Float.toString(aug.getEssenceCost()));
        
        new ShadowRunApp().getCharacter().deleteAugmentation(aug.getName());
        
    }
    
    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }    
    
}
