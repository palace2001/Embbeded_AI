#!/bin/sh

killall loading_LED.sh
./LED/off_LED.sh

sudo ./stop_record & ./record.sh & ./LED/y_breathing
./speech2text.sh
python parsing.py
rm stt.txt
MEMOCONTENTS=$(cat result.txt)
rm result.txt
echo $MEMOCONTENTS | sudo mutt -s "Title" palace2001@naver.com

killall loading_LED.sh
./LED/off_LED.sh






