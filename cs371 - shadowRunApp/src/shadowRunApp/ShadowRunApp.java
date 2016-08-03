/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shadowRunApp;

import shadowRunApp.FXMLs.contacts.EditContactController;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import character.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Optional;
import javafx.geometry.Rectangle2D;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.TextInputDialog;
import javafx.stage.Screen;
import shadowRunApp.FXMLs.adeptPowers.EditAdeptPowerController;
import shadowRunApp.FXMLs.armor.EditArmorController;
import shadowRunApp.FXMLs.augmentations.EditAugmentationController;
import shadowRunApp.FXMLs.gear.EditGearController;
import shadowRunApp.FXMLs.meleeWeapons.EditMeleeWeaponController;
import shadowRunApp.FXMLs.qualities.EditQualityController;
import shadowRunApp.FXMLs.rangedWeapons.EditRangedWeaponController;
import shadowRunApp.FXMLs.skills.EditSkillController;
import shadowRunApp.FXMLs.spells.EditSpellController;
/**
 *
 * @author david_000
 */
public class ShadowRunApp extends Application {
    
    static character.Character character = new character.Character();;
    
    static Stage primaryStage;
    @Override
    public void start(Stage stage) throws Exception {
        primaryStage = stage;
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/loadNew.fxml"));
        Parent main = (Parent) loader.load();
        
        Scene scene = new Scene(main);
        
        primaryStage.setScene(scene);
        primaryStage.show();
        
        centerStage();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }
    /*******************************************************
    ******************* ButtonControls *********************
    ********************************************************/
    
    /**
     * @throws java.lang.Exception
     */
    public void createLoadScene() throws Exception {
         FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/loadNew.fxml"));
        Parent main = (Parent) loader.load();
        
        Scene scene = new Scene(main);
        
        primaryStage.setScene(scene);
        
        centerStage();
    }
    public void createNewCharacter() throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/newCharacter.fxml"));
        Parent main = (Parent) loader.load();
        
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();
    }
    public void createMainMenu() throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/mainMenu.fxml"));
        Parent main = (Parent) loader.load();
        
        
        MainMenuController controller = loader.getController();
        
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();
    }   
    public void createIDAndCurrency() throws Exception {
         FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/IDs&currency.fxml"));
        Parent main = (Parent) loader.load();

        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();
    }
    public void createAttributeScene() throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/attributes/attributes.fxml"));
        Parent main = (Parent) loader.load();
        
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();
    }
    public void createSkillScene() throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/skills/skills.fxml"));
        Parent main = (Parent) loader.load();
        
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();
    }
    public void createQualityScene() throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/qualities/qualities.fxml"));
        Parent main = (Parent) loader.load();
        
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();
    }
    public void createContactScene() throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/contacts/contacts.fxml"));
        Parent main = (Parent) loader.load();
        
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();
    }
    public void createArmorScene() throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/armor/armor.fxml"));
        Parent main = (Parent) loader.load();
        
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();
    }
    public void createMeleeWeaponsScene() throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/meleeWeapons/meleeWeapons.fxml"));
        Parent main = (Parent) loader.load();
        
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();
    }
    public void createRangedWeaponsScene() throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/rangedWeapons/rangedWeapons.fxml"));
        Parent main = (Parent) loader.load();
        
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();
    }
    public void createCyberDeckScene() throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/cyberdeck/cyberdeck.fxml"));
        Parent main = (Parent) loader.load();
        
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();
    }
    public void createVehicleScene() throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/vehicle/vehicle.fxml"));
        Parent main = (Parent) loader.load();
        
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();
    }
    public void createGearScene() throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/gear/gear.fxml"));
        Parent main = (Parent) loader.load();
        
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();
    }
    public void createSpellScene() throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/spells/spells.fxml"));
        Parent main = (Parent) loader.load();
        
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();
    }
    public void createAugmentationScene() throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/augmentations/augmentations.fxml"));
        Parent main = (Parent) loader.load();
        
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();
    }
    public void createAdeptScene() throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/adeptPowers/adeptPower.fxml"));
        Parent main = (Parent) loader.load();
        
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();
    }
    
    
    public void back() throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/mainMenu.fxml"));
        Parent main = (Parent) loader.load();

        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();
    }
    
    /*******************************************************
    ******************** Scenes for Adding *****************
    ********************************************************/
    public void addLicenseScene() throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/licenses/addLicense.fxml"));
        Parent main = (Parent) loader.load();
        
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();//centers the window
    }
    public void addSkillScene() throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/skills/addSkill.fxml"));
        Parent main = (Parent) loader.load();
        
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();
    }
    public void addQualityScene() throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/qualities/addQuality.fxml"));
        Parent main = (Parent) loader.load();
        
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();//centers the window
    }
    public void addContactScene() throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/contacts/addContact.fxml"));
        Parent main = (Parent) loader.load();
        
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();//centers the window
    }
    public void addArmorScene() throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/armor/addArmor.fxml"));
        Parent main = (Parent) loader.load();
        
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();//centers the window
    }
    public void addMeleeWeaponScene() throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/meleeWeapons/addMeleeWeapon.fxml"));
        Parent main = (Parent) loader.load();
        
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();//centers the window
    }
    public void addRangedWeaponScene() throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/rangedWeapons/addRangedWeapon.fxml"));
        Parent main = (Parent) loader.load();
        
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();//centers the window
    }
    public void addGearScene() throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/gear/addGear.fxml"));
        Parent main = (Parent) loader.load();
        
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();//centers the window
    }
    public void addSpellScene() throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/spells/addSpell.fxml"));
        Parent main = (Parent) loader.load();
        
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();//centers the window
    }
    public void addAugmentationScene() throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/augmentations/addAugmentation.fxml"));
        Parent main = (Parent) loader.load();
        
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();//centers the window
    }
    public void addAdeptScene() throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/adeptPowers/addAdeptPower.fxml"));
        Parent main = (Parent) loader.load();
        
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();//centers the window
    }
    
    /*******************************************************
    ****************** Edit Scenes *************************
    ********************************************************/
    public void editContactScene(Contact contact) throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/contacts/editContact.fxml"));
        Parent main = (Parent) loader.load();
        
        this.addTextEditContacts(loader, contact);
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();//centers the window
    }
    public void editSkillScene(Skill skill) throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/skills/editSkill.fxml"));
        Parent main = (Parent) loader.load();
        
        this.addTextEditSkill(loader, skill);
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();//centers the window

    }
    public void editQualityScene(Quality quality) throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/qualities/editQuality.fxml"));
        Parent main = (Parent) loader.load();
        
        this.addTextEditQuality(loader, quality);
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();//centers the window
    }
    public void editArmorScene(Armor armor) throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/armor/editArmor.fxml"));
        Parent main = (Parent) loader.load();
        
        this.addTextEditArmor(loader, armor);
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();//centers the window
    }
    public void editMeleeWeaponScene(MeleeWeapon mw) throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/meleeWeapons/editMeleeWeapon.fxml"));
        Parent main = (Parent) loader.load();
        
        this.addTextEditMeleeWeapon(loader, mw);
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();//centers the window
    }
    public void editRangedWeaponScene(RangedWeapon rw) throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/rangedWeapons/editRangedWeapon.fxml"));
        Parent main = (Parent) loader.load();
        
        this.addTextEditRangedWeapon(loader, rw);
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();//centers the window
    }
    public void editGearScene(Gear gear) throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/gear/editGear.fxml"));
        Parent main = (Parent) loader.load();
        
        this.addTextEditGear(loader, gear);
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();//centers the window
    }
    public void editSpellScene(Spell spell) throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/spells/editSpell.fxml"));
        Parent main = (Parent) loader.load();
        
        this.addTextEditSpell(loader, spell);
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();//centers the window
    } 
    public void editAugmentationScene(Augmentation aug) throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/augmentations/editAugmentation.fxml"));
        Parent main = (Parent) loader.load();
        
        this.addTextEditAugmentation(loader, aug);
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();//centers the window
    } 
    public void editAdeptScene(AdeptPower other) throws Exception {
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("FXMLs/adeptPowers/editAdeptPower.fxml"));
        Parent main = (Parent) loader.load();
        
        this.addTextEditAdeptPower(loader, other);
        Scene scene = new Scene(main);
        primaryStage.setScene(scene);
        
        centerStage();//centers the window
    } 
        
        
    
    
    /*******************************************************
     ****************** Extra Functions ********************
     *******************************************************/
    
    public boolean loadCharacter() {
        character = new character.Character();
       boolean success = false;
       TextInputDialog dialog = new TextInputDialog();
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
       dialog.setTitle("Loading a Character");   
       dialog.setHeaderText(displayNames);
       dialog.setContentText("Please enter the Character's name:");
       String name;
       // Traditional way to get the response value.
       Optional<String> result = dialog.showAndWait();
       name = result.get();
        
        Alert alert = new Alert(AlertType.INFORMATION);
        alert.setHeaderText("Loading Character. . .");
        alert.setTitle("Loading...");
        alert.setContentText("Please wait while Loading. . .");
        alert.show();
        int status = character.loadFromDB(name);
        switch (status) {
            case 1:
                alert.close();
                success = true;
                break;
            case 2:
                alert.close();
                alert.setAlertType(AlertType.ERROR);
                alert.setTitle("Error while Loading");
                alert.setHeaderText("Error Loading Character");
                alert.setContentText("Error. Check internet connection and try again.");
                alert.show();
                break;
            default:
                alert.close();
                alert.setAlertType(AlertType.ERROR);
                alert.setTitle("Error while Loading");
                alert.setHeaderText("Could not find the given character");
                alert.setContentText("Check the spelling and try again.");
                alert.show();
                break;
        }
        
        character.sortLicenses();
        character.sortSkills();
        character.sortContacts();
        character.sortQualities();
        character.sortArmor();
        character.sortMeleeWeapons();
        character.sortRangedWeapons();
        return success;
    }
    
    public void setCharacter(character.Character me) {
        this.character = new character.Character(me);        
    }
    
    public character.Character getCharacter() {
        return character;
    }
        
    /*******************************************************
     ************* Centering of the Stage ******************
     *******************************************************/
    private void centerStage() {
        Rectangle2D primScreenBounds = Screen.getPrimary().getVisualBounds();
        primaryStage.setX((primScreenBounds.getWidth() - primaryStage.getWidth()) / 2);
        primaryStage.setY((primScreenBounds.getHeight() - primaryStage.getHeight()) / 2);
    }
    
     /*******************************************************
     ************* Adding Text to Edits *********************
     ********************************************************/
    public void addTextEditContacts(FXMLLoader root, Contact contact) {
        EditContactController control = root.getController();
        control.setEdit(contact.getName(), contact.getLoyalty(), contact.getConnection(), contact.getFavor());
    }
    public void addTextEditSkill(FXMLLoader root, Skill skill) {
        EditSkillController control = root.getController();
        control.setText(skill);
    }
    public void addTextEditQuality(FXMLLoader root, Quality quality) {
        EditQualityController control = root.getController();
        control.setText(quality);
    }
    public void addTextEditArmor(FXMLLoader root, Armor armor) {
        EditArmorController control = root.getController();
        control.setText(armor);
    }
    public void addTextEditMeleeWeapon(FXMLLoader root, MeleeWeapon mw) {
        EditMeleeWeaponController control = root.getController();
        control.setText(mw);
    }
    public void addTextEditRangedWeapon(FXMLLoader root, RangedWeapon rw) {
        EditRangedWeaponController control = root.getController();
        control.setText(rw);
    }
    public void addTextEditGear(FXMLLoader root, Gear gear) {
        EditGearController control = root.getController();
        control.setText(gear);
    }
    public void addTextEditAdeptPower(FXMLLoader root, AdeptPower ap) {
        EditAdeptPowerController control = root.getController();
        control.setText(ap);
    }
    public void addTextEditSpell(FXMLLoader root, Spell spell) {
        EditSpellController control = root.getController();
        control.setText(spell);
    }
    public void addTextEditAugmentation(FXMLLoader root, Augmentation aug) {
        EditAugmentationController control = root.getController();
        control.setText(aug);
    }
}
