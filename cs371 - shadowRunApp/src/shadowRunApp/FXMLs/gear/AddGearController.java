/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shadowRunApp.FXMLs.gear;

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
 * @author david_000
 */
public class AddGearController implements Initializable {

    
    @FXML
    TextField name;
    @FXML
    TextField rating;
    @FXML
    TextArea notes;
    
    
    public void submit() {
        
        if (name.getText().isEmpty()) {
            showAlert("name");
            return;
        }
        if (rating.getText().isEmpty()) {
            showAlert("rating");
            rating.setText("0");
        }
        if (notes.getText().isEmpty()) {
            showAlert("notes");
            notes.setText("");
        }
        
        String name1, notes1;
        int rating1;
        
        name1 = name.getText();
        notes1 = notes.getText();
        rating1 = Integer.parseInt(rating.getText());
        
        new ShadowRunApp().getCharacter().addGear(name1, rating1, notes1);
        new ShadowRunApp().getCharacter().sortGear();
        
        try {
            new ShadowRunApp().createGearScene();
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
