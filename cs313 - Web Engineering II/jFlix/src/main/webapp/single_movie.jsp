<%-- 
    Document   : single_movie
    Created on : Mar 16, 2015, 11:38:25 PM
    Author     : Bryce
--%>
<%
if(null == session.getAttribute("username")){  
  response.sendRedirect("index.jsp");
}
%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %> 
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>${movie.Title}</title>
        <link href="css/bootstrap.min.css" type="text/css" rel="stylesheet"/>
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.2/jquery.min.js"></script>
    </head>
    <body>
        <header>
            <%@include file="/modules/nav.html"%>
        </header>
        <a href="javascript:history.back()">
            <div class="backButton">
                <div class="container">
                    <span class="glyphicon glyphicon-menu-left" aria-hidden="true"></span>
                    <p>Back To Search Results</p>
                </div>
            </div>
        </a>
        <div class="container">
            <!-- This line of code is here for testing purposes.-->
            <p>${trailerId}</p>
            <!-- ... -->
            <div class="row">
                <div class="col-md-3" style="padding-top: 20px;">
                    <img class="img-responsive" src="${movie.Poster}" alt="${movie.Title}"/><br>
                    <div class="row">
                        <div class="col-md-12">
                            <button class="btn btn-danger" style="width: 100%;">Watch Trailer</button>
                        </div>
                        <div class="col-md-12" style="padding-top: 20px">
                            <button class="btn btn-primary" style="width: 100%; height: 60px">Add To My Collection</button>
                        </div>
                    </div>
                </div>
                <div class="col-md-9">
                    <div class="row">
                        <div class="col-md-12">
                            <h2>${movie.Title}</h2>
                        </div>
                    </div>
                    <div class="row" style="background-color: #d2d2d2; padding: 20px 0px;">
                        <div class="col-md-3">
                            <b>IMDB User Rating:</b> ${movie.imdbRating}
                        </div>
                        <div class="col-md-4">
                            <b>Genre:</b> ${movie.Genre}
                        </div>
                        <div class="col-md-2">
                            <b>Year:</b> ${movie.Year}
                        </div>
                        <div class="col-md-3">
                            <b>Maturity Rating:</b> ${movie.Rated}
                        </div>
                    </div>
                    <div class="row" style="padding-bottom: 20px;">
                        <div class="col-md-12">
                            <h3>Plot:</h3>
                            <p>${movie.Plot}</p>
                        </div>
                        <div class="col-md-12">
                            <h3>Actors:</h3>
                            <p>${movie.Actors}</p>
                        </div>
                    </div>
                    <div class="row" style="background-color: #d2d2d2; padding: 20px 0px;">
                        <div class="col-md-3">
                            <h3>Director:</h3>
                            <p>${movie.Director}</p>
                        </div>
                        <div class="col-md-5">
                            <h3>Writer:</h3>
                            <p>${movie.Writer}</p>
                        </div>
                        <div class="col-md-4">
                            <h3>Awards:</h3>
                            <p>${movie.Awards}</p>
                        </div>
                    </div>
                </div>
            </div>
        </div>
        <footer>
            <%@include file="/modules/footer.html"%>
        </footer>
    </body>
</html>
