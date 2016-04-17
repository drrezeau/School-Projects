/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shadowRunApp.FXMLs.skills;

import character.Skill;
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
public class EditSkillController implements Initializable {

    
    @FXML
    TextField name;
    @FXML
    TextField rating;
    
    
    public void setText(Skill skill) {
        name.setText(skill.getSkill());
        rating.setText(Integer.toString(skill.getRating()));
        
         new ShadowRunApp().getCharacter().deleteSkill(skill.getSkill());
    }
    @FXML 
    public void submit() {
        String name1;
        int rating1;
        
        if (name.getText().isEmpty()) {
            Alert alert = new Alert(AlertType.INFORMATION, "No name entered");
            alert.setHeaderText("Missing Information");
            alert.show();
            return;
        }
        if (rating.getText().isEmpty()) {
            Alert alert = new Alert(AlertType.INFORMATION, "No rating entered");
            alert.setHeaderText("Missing Information");
            alert.show();
            return;
        }
        
        name1 = name.getText();
        rating1 = Integer.parseInt(rating.getText());
        new ShadowRunApp().getCharacter().addSkill(name1, rating1);
        new ShadowRunApp().getCharacter().sortSkills();
        
        //Goes back to the skill menu
        try {
            new ShadowRunApp().createSkillScene();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        
    }    
    
}
