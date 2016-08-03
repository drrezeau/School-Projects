/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shadowRunApp.FXMLs.qualities;

import character.Quality;
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
public class QualitiesController implements Initializable {

    
    @FXML
    private TextArea display;
    
    @FXML
    public void back(ActionEvent event) {
        try {
            new ShadowRunApp().back();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    @FXML
    public void add(ActionEvent event) {
        try {
            new ShadowRunApp().addQualityScene();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    @FXML 
    public void edit() {
       TextInputDialog dialog = new TextInputDialog();
       dialog.setTitle("Quality to Edit");   
       dialog.setHeaderText("Qualities");
       dialog.setContentText("Please enter the quality to edit:");
       String name;
       // Traditional way to get the response value.
       Optional<String> result = dialog.showAndWait();
       name = result.get();
       
       name = name.toLowerCase();
       ArrayList<Quality> qualities = new ShadowRunApp().getCharacter().getQualities();
       for (int i = 0; i < qualities.size(); i++) {
           String temp = qualities.get(i).getName();
           if (temp.toLowerCase().equals(name)) {
               
               try {
                    new ShadowRunApp().editQualityScene(qualities.get(i));
                } catch (Exception e) {
                    e.printStackTrace();
                }
           }
       }
    }
    
    @FXML
    public void delete() {
       TextInputDialog dialog = new TextInputDialog();
       dialog.setTitle("Quality to Delete");   
       dialog.setHeaderText("Qualities");
       dialog.setContentText("Please enter the quality to delete:");
       String name;
       // Traditional way to get the response value.
       Optional<String> result = dialog.showAndWait();
       name = result.get();
       
       new ShadowRunApp().getCharacter().deleteQuality(name);
       
       this.initialize(null, null);
    }
    
    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        String text2Display = "";
        text2Display += "--- QUALITIES ---\n";
        text2Display += new ShadowRunApp().getCharacter().createQualityString();
        
        display.setText(text2Display);
    }    
    
}
