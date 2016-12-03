// LED Switch On/Off Test

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


const char *PATH_GPIO_EXPORT = "/sys/class/gpio/export";
const char *PATH_GPIO_UNEXPORT = "/sys/class/gpio/unexport";
const char *PATH_GPIO_24_DIRECTION = "/sys/class/gpio/gpio24/direction";
const char *PATH_GPIO_24_VALUE = "/sys/class/gpio/gpio24/value";


#define GPIO_NUM 24
#define MAX_TIME 4000


typedef enum {
    OFF = 0,
    ON
} gpio_state ;


void gpio_init();
void gpio_exit();
void set_gpio_state(gpio_state state);
void delay(clock_t n);

FILE *GPIO_EXPORT;
FILE *GPIO_24_DIRECTION;
FILE *GPIO_24_VALUE;



int main()
{

	

    int time = 0;
	int led_dir = 0;

    gpio_state state = OFF;

    gpio_init();


    
	while(1){
		if(!led_dir){
			set_gpio_state(ON);
			usleep(time);
			set_gpio_state(OFF);
			usleep(MAX_TIME - time);
			time += 10;
			if(time >= MAX_TIME)
				led_dir = 1;
		}
		else{
			set_gpio_state(ON);
			usleep(time);
			set_gpio_state(OFF);
			usleep(MAX_TIME - time);
			time -= 10;
			if(time <= 0.0f)
				led_dir = 0;
		}
		

	} 

    gpio_exit();
}




void gpio_init()
{

    if ((GPIO_EXPORT = fopen(PATH_GPIO_EXPORT, "w")) == NULL) {
        printf("%s open failed\n", PATH_GPIO_EXPORT);
        exit(0);
    }


    fprintf(GPIO_EXPORT, "%d", GPIO_NUM);
    fclose(GPIO_EXPORT);


    if ((GPIO_24_DIRECTION = fopen(PATH_GPIO_24_DIRECTION, "w")) == NULL) {
        printf("%s open failed\n", PATH_GPIO_24_DIRECTION);
        exit(0);
    }


    fprintf(GPIO_24_DIRECTION, "out");
    fclose(GPIO_24_DIRECTION);


    if ((GPIO_24_VALUE = fopen(PATH_GPIO_24_VALUE, "w")) == NULL) {
        printf("%s open failed\n", PATH_GPIO_24_VALUE);\
        exit(0);
    }

}

void gpio_exit()
{
    FILE *GPIO_UNEXPORT;    

    fclose(GPIO_24_VALUE);
            
    if ((GPIO_UNEXPORT = fopen(PATH_GPIO_UNEXPORT, "w")) == NULL) {
        printf("%s open failed\n", PATH_GPIO_UNEXPORT);
        exit(0);
    }

    fprintf(GPIO_UNEXPORT, "%d", GPIO_NUM);
    fclose(GPIO_UNEXPORT);
}


void set_gpio_state(gpio_state state) 
{
    fprintf(GPIO_24_VALUE, "%d", state);
    fflush(GPIO_24_VALUE);
}

void delay(clock_t n)
{
	clock_t start = clock();
	while(clock() - start < n);
}
