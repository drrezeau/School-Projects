<?xml version="1.0" encoding="utf-8"?> 

<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

  <xsl:template match="/">
    <html>
      <head>
  	<style>
          table
          {
            border: 2px solid black;
            border-collapse:collapse;
            margin:auto;
            text-align:center;
          }
          .center
          {
            text-aligned:center;
          }
        </style>
      </head>
      <body style="background-color:darkgoldenrod"> 
  	<xsl:for-each select="bsa/council"> 
  	  <h2 style="text-align:center"><xsl:value-of select="@name" /></h2>
  	  <xsl:for-each select="troop">
  	    <h3 style="text-align:center"><xsl:value-of select="@name" />
  	      <span style="margin:20px">#<xsl:value-of select="@number" /></span></h3>

  	    <table border="1" class="center">
  	      <tr bgcolor="darkkhaki">
  		<th>First Name</th>
  		<th>Last Name</th>
  		<th>Phone</th>
  		<th>Address</th>
  		<th>Ranks</th>
  		<th>Merit badges</th>
  	      </tr>
  	      <xsl:for-each select="scout">
                <xsl:sort select="lastname" />
    		<tr bgcolor="darkkhaki">
      		  <td><xsl:value-of select="firstname" /></td>
      		  <td><xsl:value-of select="lastname" /></td> 
     		  <td><xsl:value-of select="phone" /></td>
      		  <td><xsl:value-of select="address" /></td>  
      		  <td>
      		    <select style="background-color:darkseagreen; width:100%">
    	  	      <xsl:for-each select="rank">
	      		<option>
      			  <xsl:value-of select="." />
	      		</option>
	      	      </xsl:for-each>
      		    </select>
      		  </td>
      		  <td>
      		    <select style="background-color:darkseagreen; width:100%">
    	  	      <xsl:for-each select="meritbadges">
	      		<option>
      			  <xsl:value-of select="." />
	      		</option>
	      	      </xsl:for-each>
      		    </select>
      		  </td>  
    		</tr>
    	      </xsl:for-each>
  	    </table>
  	  </xsl:for-each>
  	</xsl:for-each>
      </body>
    </html>
  </xsl:template>

</xsl:stylesheet>
