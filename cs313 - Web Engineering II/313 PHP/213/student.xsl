<?xml version="1.0" encoding="utf-8"?> 

<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

  <xsl:template match="studentList">
    <html>
      <head>
        <link rel="stylesheet" type="text/css" href="assignments/Business Layout.css" />
  	<style>
          table
          {
            border: 2px solid black;
            border-collapse:collapse;
            margin:auto;
            text-align:center;
          }

          th, td
          {
            padding:10px;
          }
          .center
          {
            text-aligned:center;
          }
        </style>
      </head>
      <body>
        <header>
          <h1> Student Database </h1>
          
        </header>
        <br />
        <table border="solid" style="font-size:125%; background-color:lightblue">
          <tr>
            <th>Full Name</th>
            <th>Address</th>
            <th>College</th>
            <th>Department</th>
            <th>Major</th>
          </tr>
          <xsl:for-each select="student">
            <xsl:sort select="college/department/@name" />
          <tr>
            <td><xsl:value-of select="name" /></td>
            <td><xsl:value-of select="location/city" />,  <xsl:value-of select="location/state" /></td>
            <td><xsl:value-of select="college/@name" /></td>
            <td><xsl:value-of select="college/department/@name" /></td>
            <td><xsl:value-of select="college" /></td>
          </tr>
        </xsl:for-each>
        </table>
      </body>
    </html>
  </xsl:template>
</xsl:stylesheet>
