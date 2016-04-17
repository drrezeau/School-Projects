/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shadowRunApp.FXMLs.licenses;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.TextField;
import shadowRunApp.ShadowRunApp;

/**
 * FXML Controller class
 *
 * @author david_000
 */
public class AddLicenseController implements Initializable {

    
    @FXML
    TextField name;
    @FXML
    TextField rating;
    
    @FXML
    public void submit(ActionEvent event) {
        if (name.getText().isEmpty()) {
            showAlert("name");
            return;
        }
        if (rating.getText().isEmpty()) {
            showAlert("rating");
            return;
        }
        
        String name1 = name.getText();
        int rating1 = Integer.parseInt(rating.getText());
        
        new ShadowRunApp().getCharacter().addLicense(name1, rating1);
        new ShadowRunApp().getCharacter().sortLicenses();
        
        try {
            new ShadowRunApp().createIDAndCurrency();
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
