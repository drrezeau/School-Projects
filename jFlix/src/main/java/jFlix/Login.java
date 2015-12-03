/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jFlix;

import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import java.sql.*;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Bryce
 */
@WebServlet(name = "Login", urlPatterns = {"/Login"})
public class Login extends HttpServlet {

    
    /**
     * 
     * @param input
     * @return 
     */
    public static String md5(String input) {
        String md5 = null;
        if(null == input) return null;
        try {
            //Create MessageDigest object for MD5
            MessageDigest digest = MessageDigest.getInstance("MD5");
            //Update input string in message digest
            digest.update(input.getBytes(), 0, input.length());
            //Converts message digest value in base 16 (hex) 
            md5 = new BigInteger(1, digest.digest()).toString(16);
        } catch (NoSuchAlgorithmException e) {
        }
        return md5;
    }
    
    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        
           try {
               /*
               Bryce and Paul, if you do not have MySQL working with a database for this project,
               You can use the default username Beast and password qwerty to log in and test the
               Collection page.
               */
               //Gets the username and password that is typed in for logging in.
               
               
               String user = request.getParameter("username");
               String password = request.getParameter("password");
               
               user = user.toLowerCase();
               
               String hashPass = md5(password);
               
               Connection conn;
               Statement stmt;
               boolean message = false;
               PrintWriter out = response.getWriter();
               
               
               conn = new DBControl().connectDB();
               
               //query from the database all information from the user table
               String query = "SELECT * FROM user";
               stmt = conn.createStatement();
               
               //executes the query and saves it into a ResultSet
               ResultSet rs = stmt.executeQuery(query);
               
               //loops through all the users and checks them
               while (rs.next()) {
//                   out.println(rs.getString("username")); //displays each user
                   
                   
                   if (rs.getString("username").equals(user)) { //only enters if it finds the username
//                       out.println("I FOUND A USER");
                       
                       if (rs.getString("password").equals(hashPass)) { //enters if pswd equal
                           //sets the session for the user and then redirects to their collections
                           request.getSession().setAttribute("username", user);
                           request.getSession().setAttribute("displayname", rs.getString("displayname"));
                           request.getRequestDispatcher("collection.jsp").forward(request, response);
                           rs.close();
                           message = false;
                           break;
//                        System.out.println("Password is correct");
                       }
                       else {
                           request.setAttribute("message", "Password Incorrect");
                           message = true;
                       }
                   }
                   else {
                       request.setAttribute("message", "User does not Exist");
                       message = true;
                   }
               }
               rs.close();
               stmt.close();
               conn.close();
               
               if (message){
                   request.getRequestDispatcher("index.jsp").forward(request, response);
               }  } catch (SQLException ex) {
               Logger.getLogger(Login.class.getName()).log(Level.SEVERE, null, ex);
           }

    }

    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}
