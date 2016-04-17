#!/bin/bash

# Lab LinuxInfo
# Brother Jones, CS 345, Operating Systems
# David Lambertson

############################################################################
# Summary:
#    Going through this lab was really fun, but tedius. The spacing of 
#everything threw me off. there is more detail below for comments.
#
############################################################################

#Was practicing with variables in shell scripts
firstQuestion="What is the CPU type and model?"
secondQuestion="How many processors on this system?"

##########################################################
#Fairly straight forward. Grep grabs the lines only with what I am searching
#for. The -m 1 only gives me the first one. Cut -d':' splits that line 
#according to the : and creates an array. The -f2 grab the second item from the array.
##########################################################
echo $firstQuestion
echo -e '   '`cat /proc/cpuinfo | grep -m 1 "model name"| cut -d':' -f2`
printf '\n'

#########################################################
#I use variables to grab the data I need to make it easier to display later.
##########################################################

numOfProc=`lscpu | grep "Socket" | cut -c 24`
numOfCores=`lscpu | grep "socket" | cut -c 24`
thread=`lscpu | grep "Thread" | cut -c 24`

echo -e $secondQuestion
#If statement to check if we are hyperthreaded or not.
if [ $thread ]
then
    echo -e '    '$numOfProc 'processor with' $numOfCores 'cores each (not hyperthreaded)\n'
else
    echo -e '    '$numOfProc 'processor with' $numOfCores 'cores each (hyperthreaded)\n'
fi
#fi is needed else the code breaks!!

############################################################
echo -e "What version of the Linux kernel is being used?"
echo -e '    '`uname` 'version' `uname -r` `cat /proc/sys/kernel/version | cut -c -30`'\n'

############################################################
echo "How long has it been since the system was last booted?"
echo -e '    '`uptime |cut -c 11-20`'  '`uptime | cut -c 22-26`'\n'

##################################
echo "How much CPU execution time has been spent in user, system and idle modes?"

CPUInfo=`cat /proc/stat |grep -m 1 "cpu"`

#Splits my string of data into an array
arr2=(${CPUInfo// / })

#Grabs the necessary information I need from my array
user1=${arr2[2]}
user2=${arr2[1]}
sys=${arr2[3]}
idle=${arr2[4]}

#The way I found to do math in shell
((user1 += user2))
#this is easier to use for floating point math
user=`echo "scale=2; $user1 / 100" |bc`
sys=`echo "scale=2; $sys / 100" |bc`
idle=`echo "scale=2; $idle / 100" |bc`

#display my answer
echo -e "    USER: $user seconds" 
echo -e "    SYSTEM: "$sys "seconds"
echo -e "    IDLE: "$idle "seconds\n"


################################################
#I do the command twice to get the needed info while keeping the spacing.
################################################
echo "How much memory is on the machine?"
echo -e '    '`cat /proc/meminfo | grep MemTotal | cut -d':' -f1`':       '`cat /proc/meminfo | grep MemTotal | cut -d':' -f2`'\n'

###################################################
echo "How much memory is currently available?"
echo -e '    '`cat /proc/meminfo | grep MemFree| cut -d':' -f1`':        '`cat /proc/meminfo | grep MemFree| cut -d':' -f2`'\n'

################################################33
echo "How many kBytes have been read and written to the disk since the last reboot?"
bytes=`iostat |grep -m 1 sda`

#Needed to divide by two, But I dont know why
arr=(${bytes// / })
read=`echo "${arr[4]} / 2" |bc`
write=`echo "${arr[5]} / 2" |bc`


echo -e '    Read:' $read "kB"
echo -e '    Written:' $write "kB\n"

#####################################################
echo "How many processes have been created since the last reboot?"
info=`grep "processes" /proc/stat`
processes=(${info// / })
echo -e '    Processes created:' ${processes[1]}'\n'

######################################################
echo "How many context switches have been performed since the last reboot?"
echo -e "    Context switches:" `grep ctxt /proc/stat | cut -d' ' -f2`'\n'
##########################################################
echo "What is the current load average for the last 1, 5 and 15 minutes?"
echo -e '    '"Load average: "`uptime | cut -c 54-70`