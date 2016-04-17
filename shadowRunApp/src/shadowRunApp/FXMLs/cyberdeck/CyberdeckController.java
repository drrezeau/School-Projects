/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shadowRunApp.FXMLs.cyberdeck;

import character.CyberDeck;
import java.net.URL;
import java.util.ArrayList;
import java.util.Optional;
import java.util.ResourceBundle;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.TextField;
import javafx.scene.control.TextInputDialog;
import shadowRunApp.ShadowRunApp;

/**
 * FXML Controller class
 *
 * @author david_000
 */
public class CyberdeckController implements Initializable {

    @FXML
    TextField name;
    @FXML
    TextField deviceRating;
    @FXML
    TextField attack;
    @FXML
    TextField sleaze;
    @FXML
    TextField dataProcessing;
    @FXML
    TextField firewall;
    @FXML
    TextField matrixConditionMonitor;
    
    
    
    @FXML
    public void submit() {
        String deck;
        int rating, atk, sze, DP, fwl,MCM;
        
        if(deviceRating.getText().isEmpty()) {
            showAlert("device rating");
        }
        if(attack.getText().isEmpty()) {
            showAlert("attack");
        }
        if(sleaze.getText().isEmpty()) {
            showAlert("sleaze");
        }
        if(dataProcessing.getText().isEmpty()) {
            showAlert("data processing");
        }
        if(firewall.getText().isEmpty()) {
            showAlert("firewall");
        }
        if(matrixConditionMonitor.getText().isEmpty()) {
            showAlert("matrix condition monitor");
        }
        
        deck = name.getText();
        rating = Integer.parseInt(deviceRating.getText());
        atk = Integer.parseInt(attack.getText());
        sze = Integer.parseInt(sleaze.getText());
        DP = Integer.parseInt(dataProcessing.getText());
        fwl = Integer.parseInt(firewall.getText());
        MCM = Integer.parseInt(matrixConditionMonitor.getText());
        
        new ShadowRunApp().getCharacter().getCyberdeck().setCyberDeck(deck, rating, atk, sze, DP, fwl, MCM);
        
        try {
            new ShadowRunApp().createMainMenu();
        } catch (Exception e) {
            e.printStackTrace();
        }
       
    }
    public void seePrograms() {
        ArrayList<String> programs = new ShadowRunApp().getCharacter().getCyberdeck().getPrograms();
        String toDisplay = "";
        
        for (int i = 0; i < programs.size(); i++) {
            toDisplay += programs.get(i) + '\n';
        }
        
        Alert alert = new Alert(AlertType.INFORMATION);
        alert.setContentText(toDisplay);
        alert.setHeaderText("Programs");
        alert.setTitle("Programs");
        alert.showAndWait();
    }
    public void addProgram() {
       TextInputDialog dialog = new TextInputDialog();
       dialog.setTitle("Adding a Program");   
       dialog.setHeaderText("Programs");
       dialog.setContentText("Please enter the program to add.");
       String name;
       // Traditional way to get the response value.
       Optional<String> result = dialog.showAndWait();
       name = result.get();
       
       boolean success = new ShadowRunApp().getCharacter().getCyberdeck().addProgram(name);
       
       if (success) {
           Alert alert = new Alert(AlertType.INFORMATION);
           alert.setContentText("Program Added.");
           alert.setHeaderText("Success");
           alert.setTitle("Programs");
           alert.show();
       } else {
           Alert alert = new Alert(AlertType.INFORMATION);
           alert.setContentText("Program Not Added.");
           alert.setHeaderText("Failed");
           alert.setTitle("Programs");
           alert.show();
       }
       
    }
    public void deleteProgram() {
       TextInputDialog dialog = new TextInputDialog();
       dialog.setTitle("Deleting a Program");   
       dialog.setHeaderText("Programs");
       dialog.setContentText("Please enter the program to delete.");
       String name;
       // Traditional way to get the response value.
       Optional<String> result = dialog.showAndWait();
       name = result.get().toLowerCase();
       ArrayList<String> programs = new ShadowRunApp().getCharacter().getCyberdeck().getPrograms();
       for (int i = 0; i < programs.size(); i++) {
           if (name.equals(programs.get(i).toLowerCase())) {
               programs.remove(i);
               Alert alert = new Alert(AlertType.INFORMATION);
               alert.setContentText("Program Deleted.");
               alert.setHeaderText("Success");
               alert.setTitle("Programs");
               alert.show();
               break;
           }
       }
       
    }
    
    void showAlert(String temp) {
        Alert alert = new Alert(AlertType.ERROR);
        alert.setHeaderText("Error in data");
        alert.setContentText("No " + temp + " entered");
        alert.setHeaderText("Error");
        alert.showAndWait();
    }
    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
        
        CyberDeck deck = new CyberDeck(new ShadowRunApp().getCharacter().getCyberdeck());
        name.setText(deck.getName());
        deviceRating.setText(Integer.toString(deck.getDeviceRating()));
        attack.setText(Integer.toString(deck.getAttack()));
        sleaze.setText(Integer.toString(deck.getSleaze()));
        dataProcessing.setText(Integer.toString(deck.getDataProcessing()));
        firewall.setText(Integer.toString(deck.getFirewall()));
        matrixConditionMonitor.setText(Integer.toString(deck.getMatrixConditionMonitor()));
    }    
    
}
