/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jFlix;

import com.fasterxml.jackson.databind.ObjectMapper;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author Bryce
 */
@WebServlet(name = "SingleMovie", urlPatterns = {"/SingleMovie"})
public class SingleMovie extends HttpServlet {

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
        
        String imdbID = request.getParameter("imdbID");
        
        URL url = new URL("http://www.omdbapi.com/?i=" + imdbID + "&plot=full");
        
        ObjectMapper mapper = new ObjectMapper();
        
        Map<String, Object> map = mapper.readValue(url, Map.class);
        
//      GET Movie Info for Youtube
        String title = "";
        String year = "";
              Map<String, Object> innerMap = (Map<String, Object>)map;
              for (String key : innerMap.keySet())
              {
                  if (key.equals("Title")){
                      title = innerMap.get(key).toString();
                  }
                  if (key.equals("Year")){
                      year = innerMap.get(key).toString();
                  }
              }
        
        title = title.trim();
        title = title.replace(" ", "-");
        
        // GET MOVIE Youtube ID
        URL url2 = new URL("http://gdata.youtube.com/feeds/api/videos?q=" + title + "-official-trailer-" + year + "&start-index=1&max-results=1&v=2&alt=json&hd");
  
        ObjectMapper mapper2 = new ObjectMapper();
        
        Map<String, Object> map2 = mapper2.readValue(url2, Map.class);
        
        // GET MOVIE ID
        String trailerId = "";
        
        Map<String, Object> map3 = (Map)map2.get("feed");
        ArrayList movieEntry = (ArrayList)map3.get("entry");
        
        for (Object item : movieEntry)
        {
              Map<String, Object> innerMap2 = (Map<String, Object>)item;
              for (String key : innerMap2.keySet())
              {
                  if (key.equals("media$group")){
                        trailerId = innerMap2.get(key).toString();
                        System.out.println(trailerId);
                        // HELP ME!!!!!!!!!!!!!!!!!!!!!!!!! PLEASE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                        //____________________________________________________________________________________
                        // 
                        //I NEED HELP HERE... I NEED TO GET THE VALUE OF "yt$videoid" and save it to trailerId.
                        //its the last part of the string.  for example... 
                        // yt$videoid={$t=naQr0uTrH_s}}
                        // i would need this value ...
                        // naQr0uTrH_s
                        // THANKS!
                    }
              }
          }
              
        request.setAttribute("trailerId", trailerId);
        request.setAttribute("movie", map);
        request.getRequestDispatcher("single_movie.jsp").forward(request, response);
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
