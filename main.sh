#!/usr/bin/env bash

./LED/off_LED.sh

while :
do
  echo "Recording... Press Button to Stop."

  sudo ./waiting
  ./speech2text.sh
  python parsing.py
  rm stt.txt

  QUESTION=$(cat result.txt)
  echo "Me: " $QUESTION
  rm result.txt

  ANSWER=$(python query.py $QUESTION)

  killall loading_LED.sh
  ./LED/off_LED.sh

  echo "Robot: " $ANSWER

  ./text2speech.sh $ANSWER
done

