/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shadowRunApp.FXMLs.skills;

import character.Contact;
import character.Skill;
import java.net.URL;
import java.util.ArrayList;
import java.util.Optional;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextInputDialog;
import shadowRunApp.ShadowRunApp;

/**
 * FXML Controller class
 *
 * @author david_000
 */
public class SkillsController implements Initializable {

    @FXML
    private TextArea skillsDisplay;
    
    @FXML
    public void add(ActionEvent event) {
        try {
            new ShadowRunApp().addSkillScene();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    @FXML
    public void edit() {
       TextInputDialog dialog = new TextInputDialog();
       dialog.setTitle("Skill to Edit");   
       dialog.setHeaderText("Skills");
       dialog.setContentText("Please enter the skill to edit:");
       String name;
       // Traditional way to get the response value.
       Optional<String> result = dialog.showAndWait();
       name = result.get();
       
       name = name.toLowerCase();
       ArrayList<Skill> skills = new ShadowRunApp().getCharacter().getSkills();
       for (int i = 0; i < skills.size(); i++) {
           String temp = skills.get(i).getSkill();
           if (temp.toLowerCase().equals(name)) {
               
               try {
                    new ShadowRunApp().editSkillScene(skills.get(i));
              
                } catch (Exception e) {
                    e.printStackTrace();
                }
           }
       }
    }
    @FXML
    public void delete() {
       TextInputDialog dialog = new TextInputDialog();
       dialog.setTitle("Skill to Delete");   
       dialog.setHeaderText("Skills");
       dialog.setContentText("Please enter the skill to edit:");
       String name;
       // Traditional way to get the response value.
       Optional<String> result = dialog.showAndWait();
       name = result.get();
       
       new ShadowRunApp().getCharacter().deleteSkill(name);
       this.initialize(null, null);
       
    }
    @FXML
    public void back(ActionEvent event) {
        try {
            new ShadowRunApp().back();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        String text2Display = "";
        text2Display += "--- SKILLS ---\n";
        text2Display += new ShadowRunApp().getCharacter().createSkillString();
        
        skillsDisplay.setText(text2Display);
        
    }    
    
    
}
