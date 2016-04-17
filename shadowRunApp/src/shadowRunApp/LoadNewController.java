/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shadowRunApp;

import java.net.URL;
import java.util.ArrayList;
import java.util.Optional;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.TextInputDialog;
import shadowRunApp.ShadowRunApp;
import static shadowRunApp.ShadowRunApp.character;
//import character.*;
/**
 * FXML Controller class
 *
 * @author david_000
 */
public class LoadNewController implements Initializable {
    
     @FXML
    private void load(ActionEvent event) {
        ShadowRunApp main = new ShadowRunApp();
        boolean success = main.loadCharacter();
        
        if (success) {
            try {
                main.createMainMenu();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    
    }
    
    @FXML
    private void newCharacter(ActionEvent event) {
        try {
        new ShadowRunApp().createNewCharacter();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    public void deleteCharacter() {
        ArrayList<String> myList = character.getAllCharacterNames();
        String displayNames = "List of Characters in Database:\n";
       int k = 0;
       for (String i : myList) {
           displayNames += i + ", ";
           k++;
           if ((k % 5) == 0) {
               displayNames += '\n';
           }
       }
        TextInputDialog dialog = new TextInputDialog();
        dialog.setTitle("Character to Delete");   
        dialog.setHeaderText(displayNames);
        dialog.setContentText("Please enter the character you want to delete from the database:\n");
        String name;
        // Traditional way to get the response value.
        Optional<String> result = dialog.showAndWait();
        name = result.get();
        
        if (new ShadowRunApp().getCharacter().deleteFromDB(name)) {
            Alert alert = new Alert(AlertType.INFORMATION);
            alert.setContentText("Character successfully deleted from database");
            alert.setHeaderText("Delete Successful");
            alert.setTitle("Deletion Successful");
            alert.showAndWait();
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
