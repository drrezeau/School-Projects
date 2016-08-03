#!/bin/bash

# Lab LinuxInfo
# Brother Jones, CS 345, Operating Systems
# Shane Jensen

############################################################################
#
# Summary:
#    Prints out a bunch of CPU and system info from /proc by
#    using bash text manipulation tools.
#
############################################################################

# Example Format:
#Intel(R) Core(TM) i5-2400 CPU @ 3.10GHz
echo "What is the CPU type and model?"
echo "  "$(grep -m 1 "model name" /proc/cpuinfo | cut -c14-)

# Example Format:
#1 processor with 4 cores each (not hyperthreaded)
echo -e "\nHow many processors on this system?"
echo "  "$(awk '/physical\ id/{pi[$0]++};/cpu\ cores/{nc=$4};/siblings/{s=$3};END{for(x in pi){np++};ht="hyperthreaded";if(s==nc){ht="not "ht};printf np" processor with "nc" cores each ("ht")"}' /proc/cpuinfo)

# Example Format:
#Linux version 2.6.32-573.12.1.el6.x86_64 #1 SMP Mon Nov 23 12:55:32 EST
echo -e "\nWhat version of the Linux kernel is being used?"
echo "  "$(uname -s -r -v | sed -e 's/x 2/x version 2/' -e 's/ 2015//')

# Example Format:
#up 2 days,  12:01
echo -e "\nHow long has it been since the system was last booted?"
echo "  "$(uptime | cut -d" " -f3-7 | sed s/..$//)

# Example Format:
#USER: 47.37 seconds
#SYSTEM: 44.80 seconds
#IDLE: 132199.48 seconds
echo -e "\nHow much CPU execution time has been spent in user, system and idle modes?"
awk /^cpu\ /'{ printf "  USER: %.2f seconds\n  SYSTEM: %.2f seconds\n  IDLE: %.2f seconds\n", (($2+$3)/100), ($4/100), ($5/100) }' /proc/stat 

# Example Format:
#MemTotal:        3942852 kB
echo -e "\nHow much memory is on the machine?"
echo "  ""$(grep MemTotal /proc/meminfo)"

# Example Format:
#MemFree:         3236500 kB
echo -e "\nHow much memory is currently available?"
echo "  "$(grep MemFree /proc/meminfo)

# Example Format:
#Read: 426376 kB
#Written: 67293 kB
echo -e "\nHow many kBytes have been read and written to the disk since the last reboot?"
iostat -k -d | awk /^sda/'{ printf "  Read: " $5 " kB\n  Written: " $6 " kB\n" }'

# Example Format:
#Processes created: 7440
echo -e "\nHow many processes have been created since the last reboot?"
echo "  Processes created: "$(grep processes /proc/stat | cut -d" " -f2)

# Example Format:
#Context switches: 4821897
echo -e "\nHow many context switches have been performed since the last reboot?"
echo "  Context switches: "$(grep ctxt /proc/stat | cut -d" " -f2)

# Example Format:
#Load average: 0.00, 0.00, 0.00
echo -e "\nWhat is the current load average for the last 1, 5 and 15 minutes?"
echo "  "$(uptime | cut -d" " -f11- | sed s/l/L/)
