#!/bin/sh


while :
do
	sudo ./LED/green_off
	sudo ./LED/red_on
	sleep 0.13

	sudo ./LED/red_off
	sudo ./LED/yellow_on
	sleep 0.13

	sudo ./LED/yellow_off
	sudo ./LED/green_on
	sleep 0.13

done