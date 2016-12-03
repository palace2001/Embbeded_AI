#!/bin/bash

./LED/loading_LED.sh &

ffmpeg -y -i temp.wav -ac 1 -ar 44100 -acodec flac out.flac > /dev/null 2>&1

#echo “Processing…”

#echo -n “You Said: ”

wget -U "Mozilla/5.0" --post-file out.flac --header "Content-Type: audio/x-flac; rate=44100" -O - "http://www.google.com/speech-api/v2/recognize?lang=en_US&client=chromium&key=AIzaSyCS0fw-RF2Qr-3ENkGx37PLy6lhiVfljO4" > stt.txt

sudo rm temp.wav
rm out.flac > /dev/null 2>&1



