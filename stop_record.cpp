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

	while(1)
	{	
		if(digitalRead(2)){
			system("killall y_breathing record.sh -9 arecord");
			system("sudo ./LED/yellow_off");
			break;
		}
	
	}

	return 0;

}