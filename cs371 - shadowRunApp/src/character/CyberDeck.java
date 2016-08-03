/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package character;

import java.util.ArrayList;

/**
 *
 * @author david_000
 */
public class CyberDeck {
    String name;
    int deviceRating;
    int attack, sleaze, dataProcessing, firewall;
    int matrixConditionMonitor;
    
    ArrayList<String> programs;

    public CyberDeck() {
        name ="no deck";
        deviceRating = 0;
        attack = sleaze = dataProcessing = firewall = 0;
        matrixConditionMonitor = 0;
        
        programs = new ArrayList();
    }

    
    public CyberDeck(String name, int deviceRating, int attack, int sleaze, int dataProcessing, 
            int firewall, int matrixConditionMonitor) {
        this.name = name;
        this.deviceRating = deviceRating;
        this.attack = attack;
        this.sleaze = sleaze;
        this.dataProcessing = dataProcessing;
        this.firewall = firewall;
        this.matrixConditionMonitor = matrixConditionMonitor;
        
        programs = new ArrayList();
    }
    
    public CyberDeck(CyberDeck copy) {
        this.name = copy.name;
        this.deviceRating = copy.deviceRating;
        this.attack = copy.attack;
        this.sleaze = copy.sleaze;
        this.dataProcessing = copy.dataProcessing;
        this.firewall = copy.firewall;
        this.matrixConditionMonitor = copy.matrixConditionMonitor;
        
        programs = copy.getPrograms();
    }
    
    public void setCyberDeck(String name, int deviceRating, int attack, int sleaze, int dataProcessing, 
            int firewall, int matrixConditionMonitor) {
        this.name = name;
        this.deviceRating = deviceRating;
        this.attack = attack;
        this.sleaze = sleaze;
        this.dataProcessing = dataProcessing;
        this.firewall = firewall;
        this.matrixConditionMonitor = matrixConditionMonitor;        
    }
    
    public String displayString() {
        String rtn = name + " | Rating:" + deviceRating + " | Attack:" + attack + " | Sleaze:" 
                + sleaze +  " | Data Processing:" + dataProcessing +  " | Firewall:" 
                + firewall +  " | Matrix Condition:" + matrixConditionMonitor + '\n';
        
        rtn += "\n--- PROGRAMS ---\n";
        for (int i = 0; i < programs.size(); i++) {
            rtn += programs.get(i) + '\n';
        }
        
        return rtn;
    }
    
    public String prepareForDB() {
        String rtn = name + ":" + deviceRating + ":" + attack + ":" + sleaze + ":" 
                + dataProcessing + ":" + firewall + ":" + matrixConditionMonitor;
        
        for (int i = 0; i < programs.size(); i++) {
            rtn += ":" + programs.get(i);
        }
        return rtn;
    }
    
    public boolean addProgram(String program) {
        if(programs.add(program)) {
            return true;
        } 
        return false;
    }

    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public int getDeviceRating() {
        return deviceRating;
    }
    public void setDeviceRating(int deviceRating) {
        this.deviceRating = deviceRating;
    }
    public int getAttack() {
        return attack;
    }
    public void setAttack(int attack) {
        this.attack = attack;
    }
    public int getSleaze() {
        return sleaze;
    }
    public void setSleaze(int sleaze) {
        this.sleaze = sleaze;
    }
    public int getDataProcessing() {
        return dataProcessing;
    }
    public void setDataProcessing(int dataProcessing) {
        this.dataProcessing = dataProcessing;
    }
    public int getFirewall() {
        return firewall;
    }
    public void setFirewall(int firewall) {
        this.firewall = firewall;
    }
    public int getMatrixConditionMonitor() {
        return matrixConditionMonitor;
    }
    public void setMatrixConditionMonitor(int matrixConditionMonitor) {
        this.matrixConditionMonitor = matrixConditionMonitor;
    }
    public ArrayList getPrograms() {
        return programs;
    }
    
}
