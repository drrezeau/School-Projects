void copy( const Time & souce)
{
   this->seconds = souce.seconds;
   this->minutes = souce.minutes;
   this->hours = south.hours;
}

Time & operator = (const Time <T> rhs)
{
   this->seconds = rhs.seconds;
   this->minutes = rhs.minutes;
   this->hours = rhs.hours;
   return *this;
};

Time (const Time & rhs)
{
   *this = rhs;
};

void time :: addMinutes(int minutes)
{
   this->minutes += minutes;

   addHours(this->minutes/60);
   this->minutes %= 60;
}
