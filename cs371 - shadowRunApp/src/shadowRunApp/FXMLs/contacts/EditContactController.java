/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shadowRunApp.FXMLs.contacts;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import shadowRunApp.ShadowRunApp;

/**
 * FXML Controller class
 *
 * @author david_000
 */
public class EditContactController implements Initializable {

    @FXML
    private TextField name;
    @FXML
    private TextField loyalty;
    @FXML
    private TextField connection;
    @FXML
    private TextArea favor;

    
    
     public void setEdit(String name, int loyalty, int connection, String favor) {
        this.name.setText(name);
        this.loyalty.setText(Integer.toString(loyalty));
        this.connection.setText(Integer.toString(connection));
        this.favor.setText(favor);
        
        new ShadowRunApp().getCharacter().deleteContact(name);
    }
    
    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }    

    @FXML
    private void submit(ActionEvent event) {
        String name1;
        int loyalty1, connection1;
        String favor1;
        if (name.getText().isEmpty()) {
            showAlert("name");
            return;
        } else if (loyalty.getText().isEmpty()) {
            showAlert("loyalty");
            return;
        } else if (connection.getText().isEmpty()) {
            showAlert("connection");
            return;
        }
        name1 = name.getText();
        loyalty1 = Integer.parseInt(loyalty.getText());
        connection1 = Integer.parseInt(connection.getText());
        favor1 = favor.getText();
        
        new ShadowRunApp().getCharacter().addContact(name1, loyalty1, connection1, favor1);
        new ShadowRunApp().getCharacter().sortContacts();
        
        try {
        new ShadowRunApp().createContactScene();
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
    
}
