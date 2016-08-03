#!/bin/bash

# Lab LinuxInfo
# Brother Jones, CS 345, Operating Systems
# Jacob Bowser

##################################################################
# Summary:
# This program will find the information of the computer system
# and display it on the screen, responding to each of the 
# questions.
##################################################################

##################################################################
# The CPU type and model is in the /proc/cpuinfo, so i grep the 
# model name and use -m 1 to get just one line, then I make the
# colon the delimiter with -d and grab the second field with -f
##################################################################
echo "What is the CPU type and model?"
echo -e '   ' `cat /proc/cpuinfo | grep -m 1 'model name' | cut -d':' -f2`'\n'

##################################################################
# The Processors can be found with the lscpu command along with 
# the cores and the threads. I used greps and cuts to get the 
# desired numbers. The if statement checks if there is more than
# one thread, if so it outputs hyperthreaded, otherwise, it 
# outputs not hyperthreaded. fi finishes the statment
##################################################################
PROC=`lscpu | grep 'Socket' | cut -c 24`
CORES=`lscpu | grep 'socket' | cut -c 24`
THREAD=`lscpu | grep 'Thread(s)' | cut -c 24`
echo "How many processors on this system?"
if [ $THREAD == 1 ]
then
    echo -e '   ' $PROC "processor with" $CORES "cores each (not hyperthreaded)\n"
else
    echo -e '   ' $PROC "processor with" $CORES "cores each (hyperthreaded)\n"
fi

##################################################################
# The Linux version can be found with the uname command, I use a
# cut and a delimieter to get the version I want.
##################################################################
echo "What version of the Linux kernel is being used?"
echo -e '    Linux version' `uname -a | cut -d' ' -f3-10`'\n'  

##################################################################
# The time since the last boot is in the uptime command, I used
# one command to get the correct fields, but had to use characters
# for the last number to cut off the comma.
##################################################################
echo "How long has it been since the system was last booted?"
echo -e '   ' `uptime | cut -d' ' -f3-5`'  '`uptime | cut -c 22-26`'\n'

##################################################################
# These numbers were found in the /proc/stat. The first number on
# the cpu is the user, the second is nice, the third, the system, 
# and the fourth is idle. I added the user and nice times, then
# using the scale command I gave decimal points, then divided by 
# 100 because it was 100 times too big.
##################################################################
USER=`cat /proc/stat | grep -m 1 'cpu ' | cut -d' ' -f3`
NICE=`cat /proc/stat | grep -m 1 'cpu ' | cut -d' ' -f4`
SYSTEM=`cat /proc/stat | grep -m 1 'cpu ' | cut -d' ' -f5`
IDLE=`cat /proc/stat | grep -m 1 'cpu ' | cut -d' ' -f6`
((USER+=NICE))
USER1=`echo "scale=2; $USER / 100" | bc` 
SYSTEM1=`echo "scale=2; $SYSTEM / 100" | bc`
IDLE1=`echo "scale=2; $IDLE / 100" | bc`
echo "How much CPU execution time has been spent in user, system and idle modes?"
echo -e '   ' "USER: $USER1 seconds"
echo -e '   ' "SYSTEM: $SYSTEM1 seconds"
echo -e '   ' "IDLE: $IDLE1 seconds\n"

##################################################################
# The memory is found in /proc/meminfo on the memTotal line, so
# I used the grep and cut method to get the correct numbers
##################################################################
echo "How much memory is on the machine?"
echo -e '   ' `grep MemTotal /proc/meminfo | cut -d' ' -f1` '      ' `grep MemTotal /proc/meminfo | cut -d' ' -f9,10`'\n'

##################################################################
# The free memory is found in /proc/meminfo as well. So I used the
# same method to get the numbers that I needed.
##################################################################
echo "How much memory is currently available?"
echo -e '   ' `grep MemFree /proc/meminfo | cut -d' ' -f1` '        ' `grep MemFree /proc/meminfo | cut -d' ' -f11,12`'\n'

##################################################################
# The read and write kBytes are found in the iostat but they need
# to be divided by 2 in order to work.
##################################################################
READ=`iostat | grep sda | cut -d' ' -f36`
WRITE=`iostat | grep sda | cut -d' ' -f39`
((READ/=2))
((WRITE/=2))
echo "How many kBytes have been read and written to the disk since the last reboot?"
echo -e '    Read:' $READ "kB"
echo -e '    Written:' $WRITE "kB\n"

##################################################################
# The processes are found in the /proc/stat. I used grep, cut
# method to get the right numbers.
##################################################################
echo "How many processes have been created since the last reboot?"
echo -e '    Processes created:' `grep processes /proc/stat | cut -d' ' -f2`'\n'

##################################################################
# The context switches are found in the /proc/stat under ctxt. I
# used the grep and cut method.
##################################################################
echo "How many context switches have been performed since the last reboot?"
echo -e '    Context switches:' `grep ctxt /proc/stat | cut -d' ' -f2`'\n'

##################################################################
# The Load average time is in uptime. I used the cut method to
# get the right numbers.
##################################################################
echo "What is the current load average for the last 1, 5 and 15 minutes?"
echo -e '    Load average:' `uptime | cut -d' ' -f13-16`