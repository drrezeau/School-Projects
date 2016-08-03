/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shadowRunApp.FXMLs.vehicle;

import character.Vehicle;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import shadowRunApp.ShadowRunApp;

/**
 * FXML Controller class
 *
 * @author david_000
 */
public class VehicleController implements Initializable {

    @FXML
    TextField name;
    @FXML
    TextField handling;
    @FXML
    TextField acceleration;
    @FXML
    TextField speed;
    @FXML
    TextField pilot;
    @FXML
    TextField body;
    @FXML
    TextField armor;
    @FXML
    TextField sensor;
    @FXML
    TextArea notes;
    
    
    public void submit() {
        if (name.getText().isEmpty()) {
            showAlert("name");
        }
        if (handling.getText().isEmpty()) {
            showAlert("handling");
        }
        if (acceleration.getText().isEmpty()) {
            showAlert("acceleration");
        }
        if (speed.getText().isEmpty()) {
            showAlert("speed");
        }
        if (pilot.getText().isEmpty()) {
            showAlert("pilot");
        }
        if (body.getText().isEmpty()) {
            showAlert("body");
        }
        if (armor.getText().isEmpty()) {
            showAlert("armor");
        }
        if (sensor.getText().isEmpty()) {
            showAlert("sensor");
        }

        
        String name1, notes1;
        int hand, accel, spd, plt, bod, arm, snr;
        
        name1 = name.getText();
        notes1 = notes.getText();
        hand = Integer.parseInt(handling.getText());
        accel = Integer.parseInt(acceleration.getText());
        spd = Integer.parseInt(speed.getText());
        plt = Integer.parseInt(pilot.getText());
        bod = Integer.parseInt(body.getText());
        arm = Integer.parseInt(armor.getText());
        snr = Integer.parseInt(sensor.getText());
        
        new ShadowRunApp().getCharacter().getVehicle().setVehicle(name1, hand, accel, spd, plt, bod, arm, snr, notes1);
        
        try {
            new ShadowRunApp().createMainMenu();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    void showAlert(String error) {
        Alert alert = new Alert(AlertType.INFORMATION);
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
        
        Vehicle v = new ShadowRunApp().getCharacter().getVehicle();
        
        name.setText(v.getName());
        handling.setText(Integer.toString(v.getHandling()));
        acceleration.setText(Integer.toString(v.getAcceleration()));
        speed.setText(Integer.toString(v.getSpeed()));
        pilot.setText(Integer.toString(v.getPilot()));
        body.setText(Integer.toString(v.getBody()));
        armor.setText(Integer.toString(v.getArmor()));
        sensor.setText(Integer.toString(v.getSensor()));
        notes.setText(v.getNotes());
        
    }
    
}
