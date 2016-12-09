#!/usr/bin/env python

import wolframalpha
import os
import sys
import random

app_id='QW8J45-V6Y3X7HTHX'

client = wolframalpha.Client(app_id)

query = ' '.join(sys.argv[1:])

if "temperature" in query:
        os.system("./OPTION/temperature.sh")
        wf = open('/home/pi/Desktop/project/OPTION/temp.txt','r')
        res = wf.readline()
        print res
elif "memo" in query:
         os.system("./OPTION/memo.sh")
         print "I sent a memo"
elif "music" in query:
        if "on" in query :
                randomfile = random.choice(os.listdir("/home/pi/Desktop/project/OPTION/music"))
                m = ' /home/pi/Desktop/project/OPTION/music/' + randomfile
                os.system('mplayer' + m + ' < /dev/null &')
                print "Music On"
        elif "off" in query :
                os.system('killall -9 mplayer')
                print "Music Off"
elif "music" in query && "off" in query :
        print "Music Off"
else:
        res = client.query(query)
        if res['@success'] == "true":
                        print next(res.results).text.encode('utf-8')
        else:
                        print "Sorry, I am not sure."
