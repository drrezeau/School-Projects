/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shadowRunApp.FXMLs.spells;

import java.net.URL;
import java.util.ResourceBundle;
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
public class AddSpellController implements Initializable {

    
    @FXML TextField name;
    @FXML TextField type;
    @FXML TextField range;
    @FXML TextField duration;
    @FXML TextField drain;
    
    
    public void submit() {
        String name1, type1, range1, duration1;
        int drain1;
        
        if(name.getText().isEmpty()) {
            showAlert("name");
            return;
        }
        else if(type.getText().isEmpty()) {
            showAlert("type");
            return;
        }
        else if(range.getText().isEmpty()) {
            showAlert("range");
            return;
        }
        else if(duration.getText().isEmpty()) {
            showAlert("duration");
            return;
        }
        else if(drain.getText().isEmpty()) {
            showAlert("drain");
            return;
        }
        
        name1 = name.getText();
        type1 = type.getText();
        range1 = range.getText();
        duration1 = duration.getText();
        drain1 = Integer.parseInt(drain.getText());
        
        new ShadowRunApp().getCharacter().addSpell(name1, type1, range1, duration1, drain1);
        
        try {
        new ShadowRunApp().createSpellScene();
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
