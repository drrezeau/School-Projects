/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shadowRunApp;

import java.net.URL;
import java.util.Optional;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.control.TextInputDialog;

/**
 * FXML Controller class
 *
 * @author c
 */
public class IDsAndCurrencyController implements Initializable {

    @FXML
    TextField lifestyle;
    @FXML
    TextField nuyen;
    @FXML 
    TextArea licenses;
    
    @FXML
    public void submit(ActionEvent event) {
        String myLifestyle;
        Integer myNuyen;
        
        //Validation
        if (lifestyle.getText().isEmpty()) {
            showAlert("lifestyle");
            return;
        }
        if (nuyen.getText().isEmpty()) {
            showAlert("Nuyen");
            return;
        }

        myLifestyle = lifestyle.getText();
        myNuyen = Integer.parseInt(nuyen.getText());
        
        new ShadowRunApp().getCharacter().addLifestyleMoney(myLifestyle, myNuyen);
        
        try {
        new ShadowRunApp().createMainMenu();
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
    
    @FXML
    public void back(ActionEvent event) {
        try {
            new ShadowRunApp().back();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    @FXML
    public void addLicense() {
        try {
            new ShadowRunApp().addLicenseScene();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    @FXML
    public void deleteLicense() {
       TextInputDialog dialog = new TextInputDialog();
       dialog.setTitle("License to Delete");   
       dialog.setHeaderText("Licenses");
       dialog.setContentText("Please enter the license to edit:");
       String name;
       // Traditional way to get the response value.
       Optional<String> result = dialog.showAndWait();
       name = result.get();
       
       new ShadowRunApp().getCharacter().deleteLicense(name);
       this.initialize(null, null);
    }
    
    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
        
        character.Character me = new ShadowRunApp().getCharacter();
        
        lifestyle.setText(me.getLifestyle());
        nuyen.setText(Integer.toString(me.getNuyen()));
        licenses.setText(new ShadowRunApp().getCharacter().creataLicenseString());
    }    
    
}
