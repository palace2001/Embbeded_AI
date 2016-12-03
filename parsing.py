import sys
import json


data = []
with open('stt.txt') as f:
    for line in f:
        data.append(json.loads(line))
        
#print(data[1]['result'][0]['alternative'][0]['transcript'])

w = open('result.txt','w')
w.write(data[1]['result'][0]['alternative'][0]['transcript'])
