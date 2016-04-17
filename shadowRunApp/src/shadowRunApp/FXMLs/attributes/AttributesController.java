/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shadowRunApp.FXMLs.attributes;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.TextField;
import shadowRunApp.ShadowRunApp;

/**
 * FXML Controller class
 *
 * @author david_000
 */
public class AttributesController implements Initializable {

    
    
    @FXML
    TextField body;
    @FXML
    TextField agility;
    @FXML
    TextField reaction;
    @FXML
    TextField strength;
    @FXML
    TextField willpower;
    @FXML
    TextField logic;
    @FXML
    TextField intuition;
    @FXML
    TextField charisma;
    @FXML
    TextField edge;
    
    
    @FXML
    public void submit(ActionEvent event) {
        int body1, agility1, reaction1, strength1, willpower1, logic1, intuition1, charisma1, edge1; 
        
        body1 = Integer.parseInt(this.body.getText());
        agility1 = Integer.parseInt(this.agility.getText());
        reaction1 = Integer.parseInt(this.reaction.getText());
        strength1 = Integer.parseInt(this.strength.getText());
        willpower1 = Integer.parseInt(this.willpower.getText());
        logic1 = Integer.parseInt(this.logic.getText());
        intuition1 = Integer.parseInt(this.intuition.getText());
        charisma1 = Integer.parseInt(this.charisma.getText());
        edge1 = Integer.parseInt(this.edge.getText());
        
        new ShadowRunApp().getCharacter().editAttributes(body1, agility1, reaction1, strength1, willpower1, logic1, intuition1, charisma1, edge1);
        
        try {
            new ShadowRunApp().back();
        } catch (Exception e) {
            e.printStackTrace();
        }
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
        // TODO
        character.Character me = new ShadowRunApp().getCharacter();
        this.body.setText(Integer.toString(me.getBody()));
        agility.setText(Integer.toString(me.getAgility()));
        reaction.setText(Integer.toString(me.getReaction()));
        strength.setText(Integer.toString(me.getStrength()));
        willpower.setText(Integer.toString(me.getWillpower()));
        logic.setText(Integer.toString(me.getLogic()));
        intuition.setText(Integer.toString(me.getIntuition()));
        charisma.setText(Integer.toString(me.getCharisma()));
        edge.setText(Integer.toString(me.getEdge()));
    }    
    
}
