#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import sys



f = open('/home/pi/Desktop/project/OPTION/temp.txt','r')

f.readline()
line = f.readline().split(" ")
v =line[9].split("=")
t = int(v[1])/1000
data = "The temperature in this room : " + str(t) + "°C"
wf = open('/home/pi/Desktop/project/OPTION/temp.txt','w') 
wf.write(data)
