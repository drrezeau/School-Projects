/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shadowRunApp.FXMLs.armor;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import shadowRunApp.ShadowRunApp;

/**
 * FXML Controller class
 *
 * @author david_000
 */
public class AddArmorController implements Initializable {

    @FXML
    TextField name;
    @FXML
    TextField rating;
    @FXML
    TextArea notes;
    
    @FXML
    public void submit() {
        String name1;
        int rating1;
        String notes1;
        
        if (name.getText().isEmpty()) {
            Alert alert = new Alert(AlertType.ERROR);
            alert.setContentText("No name entered.");
            alert.setHeaderText("Error");
            alert.setTitle("Error");
            alert.show();
            return;
        }
        if (rating.getText().isEmpty()) {
            Alert alert = new Alert(AlertType.ERROR);
            alert.setContentText("No rating entered.");
            alert.setHeaderText("Error");
            alert.setTitle("Error");
            alert.show();
            return;
        }
        name1 = name.getText();
        rating1 = Integer.parseInt(rating.getText());
        notes1 = notes.getText();
        
        new ShadowRunApp().getCharacter().addArmor(name1, rating1, notes1);
        new ShadowRunApp().getCharacter().sortArmor();
        
        try {
        new ShadowRunApp().createArmorScene();
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
    }    
    
}
