/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shadowRunApp.FXMLs.qualities;

import character.Quality;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.CheckBox;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import shadowRunApp.ShadowRunApp;

/**
 * FXML Controller class
 *
 * @author david_000
 */
public class EditQualityController implements Initializable {

    
     @FXML
    TextField name;
    @FXML
    CheckBox isPositive;
    @FXML
    TextArea notes;
    
    public void setText(Quality quality) {
        name.setText(quality.getName());
        if (quality.isPositive() == "Negative")
            isPositive.setSelected(true);
        else
            isPositive.setSelected(false);
        notes.setText(quality.getNote());
        
        new ShadowRunApp().getCharacter().deleteQuality(quality.getName());
    }
    
    @FXML
    public void submit(ActionEvent event) {
        String quality;
        String positive = "Positive";
        String note;
        
        if (name.getText().isEmpty()) {
            showAlert("name");
            return;
        } 
        else if (notes.getText().isEmpty()) {
            showAlert("notes");
            return;
        }
        quality = name.getText();
        note = notes.getText();
        if (isPositive.isSelected()) {
            positive = "Negative";
        }
        new ShadowRunApp().getCharacter().addQuality(quality,note,positive);
        new ShadowRunApp().getCharacter().sortQualities();
        
        try {
            new ShadowRunApp().createQualityScene();
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
    
    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }    
    
}
