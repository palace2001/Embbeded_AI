#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <wiringPi.h>

int main(void)
{
	int cnt = 0;
	wiringPiSetup();
	pinMode(0, OUTPUT);
	pinMode(2, INPUT);
	system("sudo ./LED/red_on");

	while(1)
	{	
		if(digitalRead(2)){
			system("sudo ./LED/red_off");
			system("sudo ./stop_record & ./record.sh & ./LED/y_breathing");	
			break;
		}
	
	}

	return 0;

}