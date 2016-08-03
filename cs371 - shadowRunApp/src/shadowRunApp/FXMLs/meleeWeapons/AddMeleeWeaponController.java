/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shadowRunApp.FXMLs.meleeWeapons;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.TextField;
import shadowRunApp.ShadowRunApp;

/**
 * FXML Controller class
 *
 * @author david_000
 */
public class AddMeleeWeaponController implements Initializable {

    @FXML
    TextField name;
    @FXML
    TextField reach;
    @FXML
    TextField damage;
    @FXML
    TextField accuracy;
    @FXML
    TextField armorPierce;
    
    @FXML
    public void submit() {
        if (name.getText().isEmpty()) {
            showAlert("name");
            return;
        }
        if (reach.getText().isEmpty()) {
            showAlert("reach");
            return;
        }
        if (damage.getText().isEmpty()) {
            showAlert("damage");
            return;
        }
        if (accuracy.getText().isEmpty()) {
            showAlert("accuracy");
            return;
        }
        if (armorPierce.getText().isEmpty()) {
            showAlert("armorPierce");
            return;
        }
        
        String name1;
        int reach1, damage1, accuracy1, AP;
        
        name1 = name.getText();
        reach1 = Integer.parseInt(reach.getText());
        damage1 = Integer.parseInt(damage.getText());
        accuracy1 = Integer.parseInt(accuracy.getText());
        AP = Integer.parseInt(armorPierce.getText());
        
        new ShadowRunApp().getCharacter().addMeleeWeapon(name1, reach1, damage1, accuracy1, AP);
        
        new ShadowRunApp().getCharacter().sortMeleeWeapons();
        
        try {
        new ShadowRunApp().createMeleeWeaponsScene();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    void showAlert(String errorSpot) {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setContentText("No " + errorSpot +" entered");
        alert.setHeaderText("Error");
        alert.setTitle("Error");
        alert.show();
    }
    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }    
    
}
