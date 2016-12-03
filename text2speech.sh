#!/usr/bin/env bash

sudo ./LED/green_on

INPUT=$*
STRINGNUM=0
ary=($INPUT)
for key in "${!ary[@]}"
do
  SHORTTMP[$STRINGNUM]="${SHORTTMP[$STRINGNUM]} ${ary[$key]}"
  LENGTH=$(echo ${#SHORTTMP[$STRINGNUM]})

  if [[ "$LENGTH" -lt "100" ]]; then

    SHORT[$STRINGNUM]=${SHORTTMP[$STRINGNUM]}
  else
    STRINGNUM=$(($STRINGNUM+1))
    SHORTTMP[$STRINGNUM]="${ary[$key]}"
    SHORT[$STRINGNUM]="${ary[$key]}"
  fi
done
for key in "${!SHORT[@]}"
do
  say() { local IFS=+;/usr/bin/mplayer -ao alsa -really-quiet -noconsolecontrols "http://translate.google.com/translate_tts?ie=UTF-8&client=tw-ob&q=$*&tl=En-us"; }
  say $*
done


sudo ./LED/green_off



