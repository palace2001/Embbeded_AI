#!/bin/sh

cat /sys/bus/w1/devices/28-04168475a0ff/w1_slave > /home/pi/Desktop/project/OPTION/temp.txt
python OPTION/temperature.py