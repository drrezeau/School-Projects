/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jFlix;

import com.fasterxml.jackson.databind.ObjectMapper;
import com.google.gson.Gson;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.URL;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import static javax.ws.rs.client.Entity.json;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;

/**
 *
 * @author Bryce
 */
@WebServlet(name = "Search", urlPatterns = {"/Search"})
public class Search extends HttpServlet {

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

        String search = request.getParameter("search");
        search = search.trim();
        search = search.replace(" ", "+");
        
//      GET MOVIE LIST
        URL url = new URL("http://www.omdbapi.com/?s=" + search + "&r=json");
//        
        ObjectMapper mapper = new ObjectMapper();
//        
        Map<String, Object> map = mapper.readValue(url, Map.class);
//
        List list = (List)map.get("Search");
        
//      GET MOVIE ID's
        List<Object> imdbIDs = new ArrayList<>();
        for (Object item : list)
        {
              Map<String, Object> innerMap = (Map<String, Object>)item;
              for (String key : innerMap.keySet())
              {
                  if (key.equals("imdbID")){
                      imdbIDs.add(innerMap.get(key));
                  }
              }
        }
        
//      GET MOVIE POSTER LINKS
        List<Object> results = new ArrayList<>();
        for (Object item2: imdbIDs){
            URL url2 = new URL("http://www.omdbapi.com/?i=" + item2 + "&r=json");
            ObjectMapper mapper2 = new ObjectMapper();
            Map<String, Object> map2 = mapper2.readValue(url2, Map.class);
            results.add(map2);
        }     
        
        request.setAttribute("search", results);
        request.getRequestDispatcher("add_movie.jsp").forward(request, response);
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
