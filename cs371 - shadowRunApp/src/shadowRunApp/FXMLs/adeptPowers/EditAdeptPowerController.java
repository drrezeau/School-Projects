/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shadowRunApp.FXMLs.adeptPowers;

import character.AdeptPower;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import shadowRunApp.ShadowRunApp;

/**
 * FXML Controller class
 *
 * @author c
 */
public class EditAdeptPowerController implements Initializable {

    
    @FXML TextField name;
    @FXML TextField rating;
    @FXML TextArea notes;
    
    
    public void submit() {
        String name1, notes1;
        int rating1;
        
        name1 = name.getText();
        notes1 = notes.getText();
        rating1 = Integer.parseInt(rating.getText());
        
        new ShadowRunApp().getCharacter().addAdeptPower(name1, rating1, notes1);
        new ShadowRunApp().getCharacter().sortAdeptPowers();
        
        try {
        new ShadowRunApp().createAdeptScene();
        } catch (Exception e) {
            e.printStackTrace();
        }
        
    }
    
    public void setText(AdeptPower ap) {
        name.setText(ap.getName());
        notes.setText(ap.getNotes());
        rating.setText(Integer.toString(ap.getRating()));
        new ShadowRunApp().getCharacter().deleteAdeptPower(ap.getName());
    }
    
    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }    
    
}
