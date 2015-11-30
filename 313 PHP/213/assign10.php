<?php
header("Content-type:text/xml \n\n");
?>


<?xml-stylesheet type = "text/xsl" href = "student.xsl" ?>  
<studentList> 
  <student>
    <name>
      <first> David </first>
      <middle> Rezeau </middle>
      <last> Lambertson </last>
    </name>
    <location>
      <city> Concord </city>
      <state> California </state>
    </location>
    <college name='College of Science'>
      <department name ='Department of Computer Science and EE'>
        <major id='237'> Computer Science</major>
      </department>
    </college>
  </student>
     
  <student>
    <name>
      <first> Shane </first>
      <middle> Walamoo </middle>
      <last> Nelson </last>
    </name>
    <location>
      <city> Rexburg </city>
      <state> Idaho </state>
    </location>
    <college name='College of Science'>
      <department name ='Department of Computer Science and EE'>
        <major id='237'>Software Engineer</major>
      </department>
    </college>
  </student>

  <student>
    <name>
      <first> Cecil</first>
      <last> Friavan</last>
    </name>
    <location>
      <city> Avondale Keep </city>
      <state> Avondale </state>
    </location>
    <college name='College of Fitness'>
      <department name ='Department of Knightship and Lordship'>
        <major id='237'>Lordmanship</major>
      </department>
    </college>
  </student>
  <student>
    <name>
      <first> Seth </first>
      <last> Draxen </last>
    </name>
    <location>
      <city> Avondale Keep </city>
      <state> Avondale </state>
    </location>
    <college name='College of Fitness'>
      <department name ='Department of Knightship and Lordship'>
        <major id='237'>Knightmanship</major>
      </department>
    </college>
  </student>
  <student>
    <name>
      <first> Trent </first>
      <middle> Michael </middle>
      <last> Wright </last>
    </name>
    <location>
      <city> Pheonix </city>
      <state> Arizone </state>
    </location>
    <college name='College of Business'>
      <department name ='Department of Accounting and Business'>
        <major id='237'>Accounting</major>
      </department>
    </college>
  </student>
</studentList>
