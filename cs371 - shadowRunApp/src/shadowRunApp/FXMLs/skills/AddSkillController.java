/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shadowRunApp.FXMLs.skills;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.TextField;
import shadowRunApp.ShadowRunApp;
import shadowRunApp.ShadowRunApp;

/**
 * FXML Controller class
 *
 * @author david_000
 */
public class AddSkillController implements Initializable {

    @FXML TextField name;
    @FXML TextField rating;
    
    
    @FXML
    public void submit(ActionEvent event) {
        //creates the variables needed to add a skill
        String skill = "";
        int number = 0;
        
        //checks to see if either the name field or rating field
        if (name.getText().isEmpty()) {
            showAlert("name");
            return;
        } 
        skill = name.getText();
        
        if (rating.getText().isEmpty()) {
            showAlert("rating");
            return;
        }
        number = Integer.parseInt(rating.getText());
        
        //Adds the skill to the character
        new ShadowRunApp().getCharacter().addSkill(skill, number);

        new ShadowRunApp().getCharacter().sortSkills();
        //Goes back to the skill menu
        try {
            new ShadowRunApp().createSkillScene();
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
