/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jFlix;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Gil
 */
public class DBControl {
    
     static final String DB_URL = "jdbc:mysql://localhost/jFlix";
       //root ""
       static final String DB_URL2 = "jdbc:mysql://" + System.getenv("OPENSHIFT_MYSQL_DB_HOST") + ":" +
               System.getenv("OPENSHIFT_MYSQL_DB_PORT")+ "/jFlix";
       //java "java-pass 
    
    public Connection connectDB() {
        Connection conn = null;
        Statement stmt = null;
        boolean message = false;
        
        String DB;
        String dbUser;
        String dbPswd;
        
        if (System.getenv("OPENSHIFT_MYSQL_DB_HOST") == null) {            
            DB = DB_URL;
            dbUser = "root";
            dbPswd = "";
        }
        else {
            DB = DB_URL2;
        dbUser = System.getenv("OPENSHIFT_MYSQL_DB_USERNAME");
        dbPswd = System.getenv("OPENSHIFT_MYSQL_DB_PASSWORD");
        }
        
//        PrintWriter out = response.getWriter();
        

        try {
            
            //creates the driver for connecting
            Class.forName("com.mysql.jdbc.Driver");
            
//            System.out.println(DB);
            
            conn = DriverManager.getConnection(DB, dbUser, dbPswd);

        }
        catch (Exception e) {
            System.out.println("ERROR");
        }
        
        return conn;
    }
    
    
    public boolean checkUser(String username) {
        
        Connection conn = new DBControl().connectDB();
        boolean found = false;
        
         try {
             Statement stmt = conn.createStatement();
             
              String query = "SELECT * FROM user";
              
              ResultSet rs = stmt.executeQuery(query);
              
              while(rs.next()) {
                  if (rs.getString("username").equals(username)) {
                      found = true;
                      break;
                  }
              }
         } catch (SQLException ex) {
             Logger.getLogger(DBControl.class.getName()).log(Level.SEVERE, null, ex);
         }
        
        return found;
    }
}
