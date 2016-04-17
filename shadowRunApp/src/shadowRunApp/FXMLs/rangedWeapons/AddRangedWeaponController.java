/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shadowRunApp.FXMLs.rangedWeapons;

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
public class AddRangedWeaponController implements Initializable {

    @FXML
    TextField name;
    @FXML
    TextField damage;
    @FXML
    TextField accuracy;
    @FXML
    TextField armorPierce;
    @FXML
    TextField recoil;
    @FXML
    TextField mode;
    @FXML
    TextArea notes;
    
    
    @FXML
    public void submit() {
        if (name.getText().isEmpty()) {
            showAlert("name");
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
            showAlert("armor piercing");
            return;
        }
        if (recoil.getText().isEmpty()) {
            showAlert("recoil");
            return;
        }
        if (mode.getText().isEmpty()) {
            showAlert("mode");
            return;
        }

        String name1, mode1, notes1;
        int damage1, accuracy1, AP, recoil1;
        
        name1 = name.getText();
        mode1 = mode.getText();
        damage1 = Integer.parseInt(damage.getText());
        accuracy1 = Integer.parseInt(accuracy.getText());
        AP = Integer.parseInt(armorPierce.getText());
        recoil1 = Integer.parseInt(recoil.getText());
        notes1 = notes.getText();
        
        new ShadowRunApp().getCharacter().addRangedWeapon(name1, mode1, damage1, accuracy1, AP, recoil1, notes1);
        new ShadowRunApp().getCharacter().sortRangedWeapons();
        
        try {
        new ShadowRunApp().createRangedWeaponsScene();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    void showAlert(String error) {
        Alert alert = new Alert(AlertType.ERROR);
        alert.setContentText("No " + error + " entered.");
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
