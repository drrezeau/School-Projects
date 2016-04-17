/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package character;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;
import javafx.scene.control.Alert;

/**
 *
 * @author David
 */
public class Character {
    //necessary information about the character
    //handled with a new character. 
    private String player;
    private String name;
    private String alias;
    private String metatype;
    private Integer age;
    private Integer heightFeet;
    private Integer heightInch;
    private Integer weight;
    private String sex;
    private Integer karma;
    private boolean hasMagic;
    
    //Everything else should have some value assigned at character creation
    private String lifestyle;
    private Integer nuyen;//money
    private ArrayList<License> licenses;
    
    //the character attributes
    private Integer body;
    private Integer agility;
    private Integer reaction;
    private Integer strength;
    private Integer willpower;
    private Integer logic;
    private Integer intuition;
    private Integer charisma;
    private Integer edge;
    
    
    private Integer essence;
    private Integer magic;
    
    private CyberDeck cyberdeck;
    private Vehicle vehicle;
    
    //The different things to remember for a character
    final private ArrayList<Skill> skills;
    final private ArrayList<Quality> qualities;
    final private ArrayList<Contact> contacts;
    final private ArrayList<MeleeWeapon> meleeWeapons;
    final private ArrayList<RangedWeapon> rangedWeapons;
    final private ArrayList<Armor> armor;
    final private ArrayList<Augmentation> augmentations;
    final private ArrayList<Spell> spells;
    final private ArrayList<Gear> gear;
    final private ArrayList<AdeptPower> adeptPowers;

    private boolean characterLoaded = false;
    
    public Character() {
        licenses = new ArrayList();
        skills = new ArrayList();
        qualities = new ArrayList();
        contacts = new ArrayList();
        meleeWeapons = new ArrayList();
        rangedWeapons = new ArrayList();
        armor = new ArrayList();
        gear = new ArrayList();
        this.adeptPowers = new ArrayList();
        this.augmentations = new ArrayList();
        this.spells = new ArrayList();
        
        body = 1;
        agility = 1;
        reaction = 1;
        strength = 1;
        willpower = 1;
        logic = 1;
        intuition = 1;
        charisma = 1;
        edge = 1;
        magic = 0;
        essence = 0;
        lifestyle = "";
        nuyen = 0;
        
        this.vehicle = new Vehicle();
        this.cyberdeck = new CyberDeck();
    }
    
    public Character(String player, String characterName, String alias, int age, int weight,
            int feet, int inch, String sex, boolean hasMagic, String metatype) {
        this.player = player;
        this.name = characterName;
        this.alias = alias;
        this.heightFeet = feet;
        this.heightInch = inch;
        this.weight = weight;
        this.metatype = metatype;
        this.age = age;
        this.sex = sex;
        this.hasMagic = hasMagic;
        
        this.lifestyle = "street";
        this.nuyen = 0;
        licenses = new ArrayList();
        karma = 0;
        
        skills = new ArrayList();
        qualities = new ArrayList();
        contacts = new ArrayList();
        meleeWeapons = new ArrayList();
        rangedWeapons = new ArrayList();
        armor = new ArrayList();
        gear = new ArrayList();
        this.spells = new ArrayList();
        
        body = 1;
        agility = 1;
        reaction = 1;
        strength = 1;
        willpower = 1;
        logic = 1;
        intuition = 1;
        charisma = 1;
        edge = 1;
        magic = 0;
        
        cyberdeck = new CyberDeck();
        this.vehicle = new Vehicle();
        this.adeptPowers = new ArrayList();
        this.augmentations = new ArrayList();
    }
    
    public Character(Character copy) {
        this.player = copy.player;
        this.name = copy.name;
        this.alias = copy.alias;
        this.metatype = copy.metatype;
        this.age = copy.age;
        this.sex = copy.sex;
        this.weight = copy.weight;
        this.heightFeet = copy.heightFeet;
        this.heightInch = copy.heightInch;
        this.hasMagic = copy.hasMagic;
        
        this.lifestyle = copy.lifestyle;
        this.nuyen = copy.nuyen;
        this.licenses = copy.getLicenses();
        this.karma = copy.karma;
        
        skills = copy.getSkills();
        qualities = copy.getQualities();
        contacts = copy.getContacts();
        meleeWeapons = copy.getMeleeWeapons();
        rangedWeapons = copy.getRangedWeapons();
        armor = copy.getArmor();
        gear = copy.getGear();
        
        body = copy.getBody();
        agility = copy.getAgility();
        reaction = copy.getReaction();
        strength = copy.getStrength();
        willpower = copy.getWillpower();
        logic = copy.getLogic();
        intuition = copy.getIntuition();
        charisma = copy.getCharisma();
        edge = copy.getEdge();
        magic = copy.getMagic();
        
        cyberdeck = new CyberDeck(copy.getCyberdeck());
        this.vehicle = new Vehicle(copy.getVehicle());
        this.adeptPowers = copy.getAdeptPowers();
        this.augmentations = copy.getAugmentations();
        this.spells = copy.getSpells();
    }
    
    
    public void editAttributes(int myBody, int myAgility, int myReaction, int myStrength, int myWillpower, int myLogic, int myIntuition, int myCharisma, int myEdge) {
        body = myBody;
        agility = myAgility;
        reaction = myReaction;
        strength = myStrength;
        willpower = myWillpower;
        logic = myLogic;
        intuition = myIntuition;
        charisma = myCharisma;
        edge = myEdge;
    }
    /*******************************************************
     *********** Functions for Adding new Traits ***********
     *******************************************************/
    //Used in the JavaFX project
    public void addLicense(String name, Integer rating) {
        License id = new License(name,rating);
        licenses.add(id);
    }
    public void addLifestyleMoney(String myLifestyle, Integer myNuyen) {
        lifestyle = myLifestyle;
        nuyen = myNuyen;
    }
    public void addSkill(String skillName, int rating) {
        Skill skill = new Skill(skillName, rating);
        skills.add(skill);
    }
    public void addQuality(String qualityName, String notes, String positive) {
        Quality quality = new Quality(qualityName, notes, positive);
        qualities.add(quality);
    }
    public void addContact(String name, int loyalty, int connection, String favor) {
        Contact contact = new Contact(name, loyalty, connection, favor);
        contacts.add(contact);
    }
    public void addArmor(String name, int rating, String notes) {
        Armor armor = new Armor(name, rating, notes);
        this.armor.add(armor);
    }
    public void addMeleeWeapon(String name, int reach, int damage, int accuracy, int armorPierce) {
        MeleeWeapon mw = new MeleeWeapon(name, reach, damage, accuracy, armorPierce);
        this.meleeWeapons.add(mw);
    }
    public void addRangedWeapon(String name, String mode, int damage, int accuracy, int armorPierce, int recoil, String notes) {
        RangedWeapon rw = new RangedWeapon(name, mode, damage, accuracy, armorPierce, recoil, notes);
        this.rangedWeapons.add(rw);
    }
    public void addGear(String name, int rating, String notes) {
        Gear gear1 = new Gear(name, rating, notes);
        gear.add(gear1);
    }
    public void addAdeptPower(String name, int rating, String notes) {
        AdeptPower AP = new AdeptPower(name, notes, rating);
        adeptPowers.add(AP);
    }
    public void addAugmentation(String name, int rating, String notes, float essence) {
        Augmentation aug = new Augmentation(name, notes, rating, essence);
        augmentations.add(aug);
    }
    public void addSpell(String name, String type, String range, String duration, int drain) {
        Spell spell = new Spell(name,type,range,duration,drain);
        spells.add(spell);
    }
    /*******************************************************
     *********** Functions for Deleting Traits *************
     *******************************************************/ 
    public void deleteLicense(String name) {
        name = name.toLowerCase();
        for (int i = 0; i < licenses.size(); i++) {
            if(name.equals(licenses.get(i).getName().toLowerCase())) {
                licenses.remove(i);
                break;
            }
        }
    }
    public void deleteSkill(String name) {       
       String skillName = name.toLowerCase();
              
       for (int i = 0; i < skills.size(); i++) {
           if (skillName.equals(skills.get(i).getSkill().toLowerCase())) {
               skills.remove(i);
               break;
           }
       }
    }
    public void deleteQuality(String name) {        
        String qualityName = name;
 
        for (int i = 0; i < qualities.size(); i++) {
            if(qualityName.toLowerCase().equals(qualities.get(i).getName().toLowerCase())) {
                qualities.remove(i);
                break;
            }
        }
     }
    public void deleteContact(String name) {
        String contactName = name;

        for (int i = 0; i < contacts.size(); i++) {
            if (contactName.toLowerCase().equals(contacts.get(i).getName().toLowerCase())) {
                contacts.remove(i);
                break;
            }
        }
    }
    public void deleteArmor(String name) {
        String contactName = name;

        for (int i = 0; i < armor.size(); i++) {
            if (contactName.toLowerCase().equals(armor.get(i).getName().toLowerCase())) {
                armor.remove(i);
                break;
            }
        }
    }
    public void deleteMeleeWeapon(String name) {        
        String meleeWeapon = name;

        for (int i = 0; i < meleeWeapons.size(); i++) {
            if (meleeWeapon.equals(meleeWeapons.get(i).getName())) {
                meleeWeapons.remove(i);
                break;
            }
        }
    }
    public void deleteRangedWeapon(String name) {        
        String rangedWeapon = name.toLowerCase();

        for (int i = 0; i < rangedWeapons.size(); i++) {
            if (rangedWeapon.equals(rangedWeapons.get(i).getName().toLowerCase())) {
                rangedWeapons.remove(i);
                break;
            }
        }
    }   
    public void deleteGear(String name) {        
        String tmp = name.toLowerCase();

        for (int i = 0; i < gear.size(); i++) {
            if (tmp.equals(gear.get(i).getName().toLowerCase())) {
                gear.remove(i);
                break;
            }
        }
    }
    public void deleteAdeptPower(String name) {        
        String tmp = name.toLowerCase();

        for (int i = 0; i < adeptPowers.size(); i++) {
            if (tmp.equals(adeptPowers.get(i).getName().toLowerCase())) {
                adeptPowers.remove(i);
                break;
            }
        }
    }
    public void deleteAugmentation(String name) {        
        String tmp = name.toLowerCase();

        for (int i = 0; i < augmentations.size(); i++) {
            if (tmp.equals(augmentations.get(i).getName().toLowerCase())) {
                augmentations.remove(i);
                break;
            }
        }
    }
    public void deleteSpell(String name) {        
        String tmp = name.toLowerCase();

        for (int i = 0; i < spells.size(); i++) {
            if (tmp.equals(spells.get(i).getName().toLowerCase())) {
                spells.remove(i);
                break;
            }
        }
    }
    
    /*******************************************************
     *********** Functions for Stingifying Traits ***********
     *******************************************************/  
    public String creataLicenseString() {
        String rtn = "";
        int length = this.licenses.size();
        for (int i = 0; i < length; i++) {
            rtn += (i+1) + ": " + licenses.get(i).getName() + " | Rating: " + licenses.get(i).getRating() + '\n';
        }
        
        return rtn;
    }
    public String createSkillString() {
        String rtn = "";
        int length = skills.size();
        for (int i = 0; i < length; i++) {
           rtn += (i+1) + ": " + skills.get(i).getSkill() + " | Rating: " + skills.get(i).getRating() + '\n';
        }
        
        return rtn;
    }
    public String createQualityString() {
        String rtn = "";
        int length = qualities.size();
        for (int i = 0; i < length; i++) {
           rtn += (i+1) + ": " + qualities.get(i).getName() + " | Notes: " + qualities.get(i).getNote() + " | " + qualities.get(i).isPositive() + '\n';
        }
        
        return rtn;
    }    
    public String createContactString() {
        String rtn = "";
        int length = contacts.size();
        for (int i = 0; i < length; i++) {
           rtn += (i+1) + ": " + contacts.get(i).getName() + " | Loyalty: " + contacts.get(i).getLoyalty() + " | Connection: " + contacts.get(i).getConnection() 
                   + " | Favor: " + contacts.get(i).getFavor() + '\n';
        }
        
        return rtn;
    }
    public String createArmorString() {
        String rtn = "";
        int length = armor.size();
        for (int i = 0; i < length; i++) {
           rtn += (i+1) + ": " + armor.get(i).getName() + " | Rating: " + armor.get(i).getRating() + " | Notes: " 
                   + armor.get(i).getNotes() + '\n';
        }
        
        return rtn;
    }
    public String createMeleeWeaponsString() {
        String rtn = "";
        int length = meleeWeapons.size();
        for (int i = 0; i < length; i++) {
           rtn += (i+1) + ": " + meleeWeapons.get(i).getName() + " | Reach: " + meleeWeapons.get(i).getReach() + " | Damage: " 
                   + meleeWeapons.get(i).getDamage() + " | Accuracy: " + meleeWeapons.get(i).getAccuracy() 
                   + " | Armor Piercing: " + meleeWeapons.get(i).getArmorPierce() + '\n';
        }
        
        return rtn;
    }
    public String createRangedWeaponsString() {
        String rtn = "";
        int length = rangedWeapons.size();
        for (int i = 0; i < length; i++) {
           rtn += (i+1) + ": " + rangedWeapons.get(i).getName() + " | Damage: " + rangedWeapons.get(i).getDamage() 
                   + " | Accuracy: " + rangedWeapons.get(i).getAccuracy() + " | Armor Piercing: " 
                   + rangedWeapons.get(i).getArmorPierce() + " | Mode: " + rangedWeapons.get(i).getMode() + " | Recoil: " 
                   + rangedWeapons.get(i).getRecoil() + " | Notes: " + rangedWeapons.get(i).getNotes() + '\n';
        }
        
        return rtn;
    }
    public String createGearString() {
        String rtn = "";
        int length = gear.size();
        for (int i = 0; i < length; i++) {
           rtn += (i+1) + ": " + gear.get(i).getName() + " | Rating: " + gear.get(i).getRating() 
                   + " | Notes: " + gear.get(i).getNotes() + '\n';
        }
        
        return rtn;
    }
    public String createAdeptPowersString() {
        String rtn = "";
        int length = adeptPowers.size();
        for (int i = 0; i < length; i++) {
           rtn += (i+1) + ": " + adeptPowers.get(i).getName() + " | Rating: " + adeptPowers.get(i).getRating() 
                   + " | Notes: " + adeptPowers.get(i).getNotes() + '\n';
        }
        
        return rtn;
    }
    public String createAugmentationsString() {
        String rtn = "";
        int length = augmentations.size();
        for (int i = 0; i < length; i++) {
           rtn += (i+1) + ": " + augmentations.get(i).getName() + " | Rating: " + augmentations.get(i).getRating() 
                   + " | Notes: " + augmentations.get(i).getNotes() + " | Essence Cost: " 
                   + augmentations.get(i).getEssenceCost() + '\n';
        }
        
        return rtn;
    }
    public String createSpellsString() {
        String rtn = "";
        int length = spells.size();
        for (int i = 0; i < length; i++) {
            rtn += (i+1) + ": " + spells.get(i).getName() + " | Type: " + spells.get(i).getType() 
                    + " | Range: " + spells.get(i).getRange() + " | Duration: " + spells.get(i).getDuration()
                    + " | Drain: F " + ((spells.get(i).getDrain() > 0) ? "- " : "+ ") + spells.get(i).getDrain() + '\n';
        }
        
        
        return rtn;
    }
    
    /*****************************************************
     ************* Sorting ArrayLists ********************
     *****************************************************/
    public void sortLicenses() {
        Collections.sort(licenses, new Comparator() {
            @Override
            public int compare(Object one, Object two) {
                //use instanceof to verify the references are indeed of the type in question
                return ((License)one).getName()
                        .compareTo(((License)two).getName());
            }
        }); 
    }
    public void sortSkills() {
        Collections.sort(skills, new Comparator() {
            @Override
            public int compare(Object one, Object two) {
                //use instanceof to verify the references are indeed of the type in question
                return ((Skill)one).getSkill()
                        .compareTo(((Skill)two).getSkill());
            }
        }); 
    }
    public void sortQualities() {
        Collections.sort(qualities, new Comparator() {
            @Override
            public int compare(Object one, Object two) {
                //use instanceof to verify the references are indeed of the type in question
                return ((Quality)one).getName()
                        .compareTo(((Quality)two).getName());
            }
        }); 
    }
    public void sortContacts() {
        Collections.sort(contacts, new Comparator() {
            @Override
            public int compare(Object one, Object two) {
                //use instanceof to verify the references are indeed of the type in question
                return ((Contact)one).getName()
                        .compareTo(((Contact)two).getName());
            }
        }); 
    }
    public void sortArmor() {
        Collections.sort(armor, new Comparator() {
            @Override
            public int compare(Object one, Object two) {
                //use instanceof to verify the references are indeed of the type in question
                return ((Armor)one).getName()
                        .compareTo(((Armor)two).getName());
            }
        }); 
    }
    public void sortMeleeWeapons() {
        Collections.sort(meleeWeapons, new Comparator() {
            @Override
            public int compare(Object one, Object two) {
                //use instanceof to verify the references are indeed of the type in question
                return ((MeleeWeapon)one).getName()
                        .compareTo(((MeleeWeapon)two).getName());
            }
        }); 
    }
    public void sortRangedWeapons() {
        Collections.sort(rangedWeapons, new Comparator() {
            @Override
            public int compare(Object one, Object two) {
                //use instanceof to verify the references are indeed of the type in question
                return ((RangedWeapon)one).getName()
                        .compareTo(((RangedWeapon)two).getName());
            }
        }); 
    }
    public void sortGear() {
        Collections.sort(gear, new Comparator() {
            @Override
            public int compare(Object one, Object two) {
                //use instanceof to verify the references are indeed of the type in question
                return ((Gear)one).getName()
                        .compareTo(((Gear)two).getName());
            }
        }); 
    }
    public void sortAdeptPowers() {
        Collections.sort(adeptPowers, new Comparator() {
            @Override
            public int compare(Object one, Object two) {
                //use instanceof to verify the references are indeed of the type in question
                return ((AdeptPower)one).getName()
                        .compareTo(((AdeptPower)two).getName());
            }
        }); 
    }
    public void sortAugmentations() {
        Collections.sort(augmentations, new Comparator() {
            @Override
            public int compare(Object one, Object two) {
                //use instanceof to verify the references are indeed of the type in question
                return ((Augmentation)one).getName()
                        .compareTo(((Augmentation)two).getName());
            }
        }); 
    }
    
    /*****************************************************
     ************* Functions For Database ****************
     *****************************************************/
    // JDBC driver name and database URL
    static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";

    static final String DB_URL = "jdbc:mysql://us-cdbr-iron-east-03.cleardb.net/heroku_77540a9be8a2f22"; //**HEROKU
//    static final String DB_URL = "jdbc:mysql://localhost/EM"; //**Local

    //  Database credentials
   static final String USER = "b120a816248bc1"; //** Heroku
//    static final String USER = "root"; //**Local
   static final String PASS = "4821acef"; //** Heroku
//    static final String PASS = "root"; //**Local
    
    public boolean saveToDB() {       
        String licensesToSave = "";
        String skillsToSave = "";
        String qualitiesToSave = "";
        String contactsToSave = "";
        String meleeWeaponsToSave = "";
        String armorToSave = "";
        String rangedWeaponsToSave = "";
        String gearToSave = "";
        String deckToSave = "";
        String vehicleToSave = "";
        String spellsToSave = "";
        String augmentationsToSave = "";
        String adeptPowersToSave = "";
        int hasMagicInt = 0;
        
        if (this.hasMagic) {
            hasMagicInt = 1;
        }
        
        //Create the string to save for skills
        for (int i = 0; i < licenses.size(); i++) {
            licensesToSave += licenses.get(i).prepareForDB() + ";";
        }
        for (int i = 0; i < skills.size(); i++) {
            skillsToSave += skills.get(i).prepareForDB() + ";";
        }
        //Create the string to save for qualities
        for (int i = 0; i < qualities.size(); i++) {
            qualitiesToSave += qualities.get(i).prepareForDB() + ";";
        }
        //Create the string to save for contacts
        for (int i = 0; i < contacts.size(); i++) {
            contactsToSave += contacts.get(i).prepareForDB() + ";";
        }
        //Create the string to save for armor
        for (int i = 0; i < armor.size(); i++) {
            armorToSave += armor.get(i).prepareForDB() + ";";
        }
        //Create the string to save for melee weapons
        for (int i = 0; i < meleeWeapons.size(); i++) {
            meleeWeaponsToSave += meleeWeapons.get(i).prepareForDB() + ";";
        }
        //Create the string to save for ranged weapons
        for (int i = 0; i < rangedWeapons.size(); i++) {
            rangedWeaponsToSave += rangedWeapons.get(i).prepareForDB() + ";";
        }
        //Create the string to save for gear
        for (int i = 0; i < gear.size(); i++) {
            gearToSave += gear.get(i).prepareForDB() + ";";
        }
        //Create the string to save for adept powers
        for (int i = 0; i < adeptPowers.size(); i++) {
            adeptPowersToSave += adeptPowers.get(i).prepareForDB() + ";";
        }
        //Create the string to save for adept powers
        for (int i = 0; i < augmentations.size(); i++) {
            augmentationsToSave += augmentations.get(i).prepareForDB() + ";";
        }
        //Create the string to save for spells
        for (int i = 0; i < spells.size(); i++) {
            spellsToSave += spells.get(i).prepareForDB() + ";";
        }

        
        deckToSave = cyberdeck.prepareForDB();
        vehicleToSave = vehicle.prepareForDB();

        String sql = new String();
        Connection conn = makeConn();
        
        int height = (heightFeet*12) + heightInch;
        //The SQL String needed to update the database
        if (this.characterLoaded) { //updating a character already in the DB
            sql = "UPDATE characters SET player='" + this.player + "', characterName='" + this.name + "', alias='" + this.alias 
                    + "', age=" +this.age + ", height=" + height + ", weight=" + this.weight + ", metatype='" + this.metatype 
                    + "', sex='" + this.sex + "',karma=" + this.karma + ", body=" + this.body + ", agility=" + this.agility 
                    + ", reaction=" + this.reaction + ", strength=" + this.strength + ", willpower=" + this.willpower 
                    + ", logic=" + this.logic + ", intuition=" + this.intuition + ", charisma=" + this.charisma 
                    + ", edge=" + this.edge + ", magic=" + this.magic + ", hasMagic='" + hasMagicInt + "', lifestyle='" + this.lifestyle
                    + "', nuyen=" + this.nuyen + ", licenses='" + licensesToSave + "', skills='" + skillsToSave 
                    + "', qualities='" + qualitiesToSave + "', contacts='" + contactsToSave + "', meleeWeapons='" + meleeWeaponsToSave 
                    + "', armor='" + armorToSave + "', rangedWeapons='" + rangedWeaponsToSave + "', gear='" + gearToSave 
                    + "', cyberdeck='" + deckToSave + "', vehicle='" + vehicleToSave + "', otherPowers='" + adeptPowersToSave 
                    + "', augmentations='" + augmentationsToSave + "', spells='" + spellsToSave //add new Items here
                    + "' WHERE characterName='" + this.name + "';";

        } else { //saving a new character into the database
            sql = "INSERT INTO characters (player, characterName, alias, metatype, age, height, weight, sex, karma, body,"
                    + "agility, reaction, strength, willpower, logic, intuition, charisma, edge, magic, hasMagic, lifestyle,"
                    + "nuyen, licenses, skills, qualities, contacts, otherPowers, augmentations, spells, "
                    + "meleeWeapons, armor, rangedWeapons, gear, cyberdeck, vehicle) VALUES ('"
                    + this.player + "', '" + this.name + "', '" + this.alias + "', '" +this.metatype + "', " + this.age + ", "
                    + height + ", '" + this.weight + "', '" + this.sex + "', " + this.karma + ", " + this.body + ", " 
                    + this.agility + ", " + this.reaction + ", " + this.strength + ", " + this.willpower + ", " 
                    + this.logic + ", " + this.intuition + ", " + this.charisma + ", " + this.edge + ", " 
                    + this.magic + ", " + hasMagicInt + ", '" + this.lifestyle + "', " + this.nuyen + ", '" 
                    + licensesToSave + "', '" + skillsToSave + "', '" 
                    + qualitiesToSave + "', '" + contactsToSave + "', '" + adeptPowersToSave + "', '" 
                    + augmentationsToSave + "', '" + spellsToSave + "', '"
                    + meleeWeaponsToSave + "', '" + armorToSave + "', '" + rangedWeaponsToSave + "', '" + gearToSave + "', '" 
                    + deckToSave + "', '" + vehicleToSave +  "');";
            
            this.characterLoaded = true;
        }
        
        try {
            Statement stmt = conn.createStatement();
            stmt.executeUpdate(sql);
            
            stmt.close();
            conn.close();
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
        return true;
    }
    public int loadFromDB(String name) {
        //Creating the variables to put strings that need to be parsed
        this.characterLoaded = true;
        String licensesFromDB = new String();
        String licensesTemp[];
        String skillsFromDB = new String();
        String skillsTemp[];
        String qualitiesFromDB = new String();
        String qualitiesTemp[];
        String contactsFromDB = new String();
        String contactsTemp[];
        String armorFromDB = new String();
        String armorTemp[];
        String meleeWeaponsFromDB = new String();
        String meleeWeaponsTemp[];
        String rangedWeaponsFromDB = new String();
        String rangedWeaponsTemp[];
        String gearFromDB = new String();
        String gearTemp[];
        String deckFromDB = new String();
        String deckTemp[];
        String vehicleFromDB = new String();
        String vehicleTemp[];
        String adeptPowersFromDB = new String();
        String adeptPowersTemp[];
        String augmentationsFromDB = new String();
        String augmentationsTemp[];
        String spellsFromDB = new String();
        String spellsTemp[];

        //Lets the user pick which character to load from the database
        String characterName = name;
        int height;
        Connection conn = makeConn();

        try {
            Statement stmt = conn.createStatement();
            String sql;
            sql = "SELECT * FROM characters WHERE characterName='"+characterName+"'";
            ResultSet rs = stmt.executeQuery(sql);
            
            //If the character requested is not found in the DB
            if (!rs.isBeforeFirst()) {
                return 0;
            } 
            
            rs.next();
            
            //Gather all the variables and save them into their spots
            this.player = rs.getString("player");
            this.name = rs.getString("characterName");
            this.alias = rs.getString("alias");
            this.metatype = rs.getString("metatype");
            this.age = rs.getInt("age");
            height = rs.getInt("height");
            this.weight = rs.getInt("weight");
            this.sex = rs.getString("sex");
            this.karma = rs.getInt("karma");
            this.body = rs.getInt("body");
            this.agility = rs.getInt("agility");
            this.reaction = rs.getInt("reaction");
            this.strength = rs.getInt("strength");
            this.willpower = rs.getInt("willpower");
            this.logic = rs.getInt("logic");
            this.intuition = rs.getInt("intuition");
            this.charisma = rs.getInt("charisma");
            this.edge = rs.getInt("edge");
            this.magic = rs.getInt("magic");
            this.hasMagic = rs.getBoolean("hasMagic");
            this.lifestyle = rs.getString("lifestyle");
            this.nuyen = rs.getInt("nuyen");
            
            licensesFromDB = rs.getString("licenses");
            skillsFromDB = rs.getString("skills");
            qualitiesFromDB = rs.getString("qualities");
            contactsFromDB = rs.getString("contacts");
            armorFromDB = rs.getString("armor");
            meleeWeaponsFromDB = rs.getString("meleeWeapons");
            rangedWeaponsFromDB = rs.getString("rangedWeapons");
            deckFromDB = rs.getString("cyberdeck");
            vehicleFromDB = rs.getString("vehicle");
            adeptPowersFromDB = rs.getString("otherPowers");
            augmentationsFromDB = rs.getString("augmentations");
            spellsFromDB = rs.getString("spells");
            
            rs.close();
            stmt.close();
            conn.close();
        } catch (Exception e) {
            e.printStackTrace();//did not succeed in doing the query
            return 2;
        }
        
        heightFeet = height/12;
        heightInch = height%12;
        
        //Parsing through the Strings to save into the vectors
        if (!(licensesFromDB.isEmpty())) {
            licensesTemp = licensesFromDB.split(";");
            
            for (int i = 0; i < licensesTemp.length; i++) {
                String temp[] = licensesTemp[i].split(":");
                License l = new License(temp[0],Integer.parseInt(temp[1]));
                this.licenses.add(l);
            }
        }
            //Skills
        if (!(skillsFromDB.isEmpty())) {
            skillsTemp = skillsFromDB.split(";");
            
            for (int i = 0; i < skillsTemp.length; i++) {
                String temp[] = skillsTemp[i].split(":");
                Skill skilltemp = new Skill(temp[0], Integer.parseInt(temp[1]));
                this.skills.add(skilltemp);
            }
        }
            //Qualities
        if (!(qualitiesFromDB.isEmpty())) {
            qualitiesTemp = qualitiesFromDB.split(";");
            
            for (int i = 0; i < qualitiesTemp.length; i++) {
               String temp[] = qualitiesTemp[i].split(":");
                Quality qualitytemp = new Quality(temp[0], temp[1], temp[2]);
                this.qualities.add(qualitytemp);
            }
        }
            //Contacts
        if (!(contactsFromDB.isEmpty())) {
            contactsTemp = contactsFromDB.split(";");
            
            for (int i = 0; i < contactsTemp.length; i++) {
                String temp[] = contactsTemp[i].split(":");
                Contact contactTemp;
                if (temp.length < 4) {
                    contactTemp = new Contact(temp[0], Integer.parseInt(temp[1]), Integer.parseInt(temp[2]), "");
                } else {
                    contactTemp = new Contact(temp[0], Integer.parseInt(temp[1]), Integer.parseInt(temp[2]), temp[3]);
                }
                this.contacts.add(contactTemp);
            }
        }
        if (!(armorFromDB.isEmpty())) {
            armorTemp = armorFromDB.split(";");
            
            for (int i = 0; i < armorTemp.length; i++) {
                String temp[] = armorTemp[i].split(":");
                Armor armor;
                if (temp.length < 3) {
                    armor = new Armor(temp[0], Integer.parseInt(temp[1]), "");
                } else {
                    armor = new Armor(temp[0], Integer.parseInt(temp[1]), temp[3]);
                }
                this.armor.add(armor);
            }
        }
        
        if (!(meleeWeaponsFromDB.isEmpty())) {
            meleeWeaponsTemp = meleeWeaponsFromDB.split(";");
            
            for (int i = 0; i < meleeWeaponsTemp.length; i++) {
                String temp[] = meleeWeaponsTemp[i].split(":");
                
                MeleeWeapon mw = new MeleeWeapon(temp[0],Integer.parseInt(temp[1]),Integer.parseInt(temp[2]),
                        Integer.parseInt(temp[3]),Integer.parseInt(temp[4]));
                this.meleeWeapons.add(mw);
            }
        }
        if (!(rangedWeaponsFromDB.isEmpty())) {
            rangedWeaponsTemp = rangedWeaponsFromDB.split(";");
            
            for (int i = 0; i < rangedWeaponsTemp.length; i++) {
                String temp[] = rangedWeaponsTemp[i].split(":");
                RangedWeapon rw;
                if (temp.length == 6) {
                    rw = new RangedWeapon(temp[0],temp[4],Integer.parseInt(temp[1]),
                        Integer.parseInt(temp[2]),Integer.parseInt(temp[3]), Integer.parseInt(temp[5]), "");
                } else {
                    rw = new RangedWeapon(temp[0],temp[4],Integer.parseInt(temp[1]),
                        Integer.parseInt(temp[2]),Integer.parseInt(temp[3]), Integer.parseInt(temp[5]), temp[6]);
                }
                this.rangedWeapons.add(rw);
            }
        }
        if (!(gearFromDB.isEmpty())) {
            gearTemp = gearFromDB.split(";");
            
            for (int i = 0; i < gearTemp.length; i++) {
                String temp[] = gearTemp[i].split(":");
                Gear gear;
                if (temp.length == 2) {
                    gear = new Gear(temp[0],Integer.parseInt(temp[1]), "");
                } else {
                    gear = new Gear(temp[0],Integer.parseInt(temp[1]), temp[2]);
                }
                this.gear.add(gear);
            }
        }
        if (!(adeptPowersFromDB.isEmpty())) {
            adeptPowersTemp = adeptPowersFromDB.split(";");
            
            for (int i = 0; i < adeptPowersTemp.length; i++) {
                String temp[] = adeptPowersTemp[i].split(":");
                AdeptPower ap;
                if (temp.length == 2) {
                    ap = new AdeptPower(temp[0], "", Integer.parseInt(temp[1]));
                } else {
                    ap = new AdeptPower(temp[0], temp[2], Integer.parseInt(temp[1]));
                }
                this.adeptPowers.add(ap);
            }
        }
        if (!(spellsFromDB.isEmpty())) {
            spellsTemp = spellsFromDB.split(";");
            
            for (int i = 0; i < spellsTemp.length; i++) {
                String temp[] = spellsTemp[i].split(":");
                Spell spell;
                
                spell = new Spell(temp[0], temp[1], temp[2],temp[3], Integer.parseInt(temp[4]));
                this.spells.add(spell);
            }
        }
        if (!(augmentationsFromDB.isEmpty())) {
            augmentationsTemp = augmentationsFromDB.split(";");
            
            for (int i = 0; i < augmentationsTemp.length; i++) {
                String temp[] = augmentationsTemp[i].split(":");
                Augmentation aug;

                if (temp.length == 3) {
                    aug = new Augmentation(temp[0], "", Integer.parseInt(temp[1]), Float.parseFloat(temp[2]));
                } else {
                    aug = new Augmentation(temp[0], temp[2], Integer.parseInt(temp[1]), Float.parseFloat(temp[3]));
                }
                this.augmentations.add(aug);
            }
        }
        if (!deckFromDB.isEmpty()) {
            deckTemp = deckFromDB.split(":");
            cyberdeck.setCyberDeck(deckTemp[0], Integer.parseInt(deckTemp[1]), Integer.parseInt(deckTemp[2]),
                    Integer.parseInt(deckTemp[3]), Integer.parseInt(deckTemp[4]), Integer.parseInt(deckTemp[5]), 
                    Integer.parseInt(deckTemp[6]));
            for (int i = 7; i < deckTemp.length; i++) {
                cyberdeck.addProgram(deckTemp[i]);
            }
        }
        
        if (!vehicleFromDB.isEmpty()) {
            vehicleTemp = vehicleFromDB.split(":");
            if (vehicleTemp.length > 8) {
                vehicle.setVehicle(vehicleTemp[0], Integer.parseInt(vehicleTemp[1]), Integer.parseInt(vehicleTemp[2]),
                        Integer.parseInt(vehicleTemp[3]), Integer.parseInt(vehicleTemp[4]), Integer.parseInt(vehicleTemp[5]), 
                        Integer.parseInt(vehicleTemp[6]), Integer.parseInt(vehicleTemp[7]), vehicleTemp[8]);
            } else {
                vehicle.setVehicle(vehicleTemp[0], Integer.parseInt(vehicleTemp[1]), Integer.parseInt(vehicleTemp[2]),
                        Integer.parseInt(vehicleTemp[3]), Integer.parseInt(vehicleTemp[4]), Integer.parseInt(vehicleTemp[5]), 
                        Integer.parseInt(vehicleTemp[6]), Integer.parseInt(vehicleTemp[7]), "");
            }
        }
            
        return 1;
        
    }
    
    public boolean deleteFromDB(String name) {
        Connection conn = makeConn();
        String characterName = name.toLowerCase();
        boolean success = false;
         try {
            Statement stmt = conn.createStatement();
            String sql;
            sql = "delete FROM characters WHERE characterName='"+characterName+"'";
            int i = stmt.executeUpdate(sql);
            success = (i != 0);
         } catch (Exception e) {
             
         }
        
         if (!success) {
             return false;
         }
        return true;
    }
    public ArrayList<String> getAllCharacterNames() {
        Connection conn = makeConn();
        ArrayList<String> myList = new ArrayList();
        try {
            Statement stmt = conn.createStatement();
            String sql;
            sql = "select characterName FROM characters";
            ResultSet rs = stmt.executeQuery(sql);
            
            while(rs.next()) {
                myList.add(rs.getString("characterName"));
            }
         } catch (Exception e) {
             
         }
        
        return myList;
    }
   
    //Creates a connectiong with the DB and returns it
    public static Connection makeConn() {
        Connection conn = null;
        try{
        //STEP 2: Register JDBC driver
        Class.forName("com.mysql.jdbc.Driver");

        //STEP 3: Open a connection
        conn = DriverManager.getConnection(DB_URL,USER,PASS);
        }catch(Exception se){
            //Handle errors for JDBC
            se.printStackTrace();
        }
        return conn;
     }

     /*******************************************************
     **************** Getters and Setters *******************
     *******************************************************/
   
    public String getPlayer() {
        return player;
    }
    public String getAlias() {
        return alias;
    }
    public String getMetatype() {
        return metatype;
    }
    public Integer getAge() {
        return age;
    }
    public Integer getHeightFeet() {
        return heightFeet;
    }
    public Integer getHeightInch() {
        return heightInch;
    }
    public Integer getWeight() {
        return weight;
    }
    public String getSex() {
        return sex;
    }

    public Integer getKarma() {
        return karma;
    }
    public void setKarma(int karma) {
        this.karma = karma;
    }
    public Integer getEssence() {
        return essence;
    }
    public boolean isHasMagic() {
        return hasMagic;
    }
    
    public ArrayList<Skill> getSkills() {
        return skills;
    }
    public ArrayList<Quality> getQualities() {
        return qualities;
    }
    public ArrayList<Contact> getContacts() {
        return contacts;
    }
    public ArrayList<MeleeWeapon> getMeleeWeapons() {
        return meleeWeapons;
    }
    public ArrayList<RangedWeapon> getRangedWeapons() {
        return rangedWeapons;
    }
    public ArrayList<Armor> getArmor() {
        return armor;
    }
    public ArrayList<License> getLicenses() {
        return licenses;
    }
    public CyberDeck getCyberdeck() {
        return cyberdeck;
    }
    public Vehicle getVehicle() {
        return vehicle;
    }
    public ArrayList<Gear> getGear() {
        return gear;
    }
    public ArrayList<AdeptPower> getAdeptPowers() {
        return adeptPowers;
    }
    public ArrayList<Augmentation> getAugmentations() {
        return augmentations;
    }
    public ArrayList<Spell> getSpells() {
        return spells;
    }
    
    
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }

    public Integer getBody() {
        return body;
    }
    public void setBody(Integer body) {
        this.body = body;
    }

    public Integer getAgility() {
        return agility;
    }
    public void setAgility(Integer agility) {
        this.agility = agility;
    }

    public Integer getReaction() {
        return reaction;
    }
    public void setReaction(Integer reaction) {
        this.reaction = reaction;
    }

    public Integer getStrength() {
        return strength;
    }
    public void setStrength(Integer strength) {
        this.strength = strength;
    }

    public Integer getWillpower() {
        return willpower;
    }
    public void setWillpower(Integer willpower) {
        this.willpower = willpower;
    }

    public Integer getLogic() {
        return logic;
    }
    public void setLogic(Integer logic) {
        this.logic = logic;
    }

    public Integer getIntuition() {
        return intuition;
    }
    public void setIntuition(Integer intuition) {
        this.intuition = intuition;
    }

    public Integer getCharisma() {
        return charisma;
    }
    public void setCharisma(Integer charisma) {
        this.charisma = charisma;
    }

    public Integer getEdge() {
        return edge;
    }
    public void setEdge(Integer edge) {
        this.edge = edge;
    }
    public Integer getMagic() {
        return magic;
    }

    public String getLifestyle() {
        return lifestyle;
    }
    public Integer getNuyen() {
        return nuyen;
    }
}
