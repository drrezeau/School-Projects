#!/bin/bash

# Lab LinuxInfo
# Brother Jones, CS 345, Operating Systems
# Benjamin Walker

############################################################################
#
# Summary:
#    This program is used to illustrate the usefullness of BASH commands
#  in an executable script file. Here we are displaying different system
#  properties and statistical data for the user.
############################################################################

#1
echo -en "What is the CPU type and model?\n\t"
grep -nri "Intel(R) Core(TM) i5-2400 CPU @ 3.10GHz" /proc/c* | cut -d':' -f4 | uniq

#2
echo -en "\n"
echo -en "How many processors on this system?\n\t"
NUM=$(grep -nri "physical id" /proc/cpuinfo | cut -d':' -f3 | uniq | grep -c " 0")

echo -en "${NUM} processor with "
grep -ncri "physical id" /proc/cpuinfo | tr -d '\n'
echo -en " cores each"
if [ $NUM == 1 ]
    then
    echo -en " (not hyperthreaded)"
fi

#3
echo -en "\n\n"
echo -en "What version of the Linux kernel is being used?\n\t"
grep -nri "Linux version" /proc/version | cut -d' ' -f1-3,14- | cut -d':' -f2- | cut -d' ' -f-10

#4
echo -en "\n"
echo -en "How long has it been since the system was last booted?\n\t"
uptime | cut -d' ' -f3-6 | cut -d',' -f1-2

#5
echo -en "\n"
echo -en "How much CPU execution time has been spent in user, system and idle modes?\n\t"
USER=$(grep "cpu " /proc/stat | cut -d' ' -f3)
NICE=$(grep "cpu " /proc/stat | cut -d' ' -f4)
SYSTEM=$(grep "cpu " /proc/stat | cut -d' ' -f5)
IDLE=$(grep "cpu " /proc/stat | cut -d' ' -f6)

USERNUM=$(echo "(($USER+$NICE)/100)" | bc -l)
SYSNUM=$(echo "(($SYSTEM)/100)" | bc -l)
IDLENUM=$(echo "(($IDLE)/100)" | bc -l)

printf "USER: %.2f\n" "$USERNUM"
printf "\tSYSTEM: %.2f\n" "$SYSNUM"
printf "\tIDLE: %.2f\n" "$IDLENUM"

#6
echo -en "\n"
echo -en "How much memory is on the machine?\n\t"
grep -nri "MemTotal:" /proc/m* | cut -d':' -f3-

#7
echo -en "\n"
echo -en "How much memory is currently available?\n\t"
grep -nri "MemFree:" /proc/m* | cut -d':' -f3-

#8
echo -en "\n"
echo -en "How many kBytes have been read and written to the disk since the last reboot?\n\t"
echo -en "Read: "
iostat -k | grep "sda" | sed -n 's/ \+/ /gp' | cut -d' ' -f5 | tr -d '\n'
echo -en " kB\n"
echo -en "\tWritten: " 
iostat -k | grep "sda" | sed -n 's/ \+/ /gp'| cut -d' ' -f6 | tr -d '\n'
echo -en " kB\n"

#9
echo -en "\n"
echo -en "How many processes have been created since the last reboot?\n\t"
echo -en "Processes created: "
grep -nri "processes " /proc/stat | cut -d' ' -f2

#10
echo -en "\n"
echo -en "How many context switches have been performed since the last reboot?\n\t"
echo -en "Context switches: "
grep -nri "ctxt" /proc/stat | cut -d' ' -f2

#11
echo -en "\n"
echo -en "What is the current load average for the last 1, 5 and 15 minutes?\n\t"
echo -en "Load average: " && cat /proc/loadavg | cut -d' ' -f-3
