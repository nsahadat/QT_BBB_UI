/*
 * PWC_Drive.cpp
 *
 *  Created on: Apr 21, 2016
 *      Author: sahil
 */



/*
//Filename: PWC_Drive.cpp
//Version : 0.1
//
//Project : TDS GTBionics Lab
//Author  : Md Nazmus Sahadat
//Contact : m.n.sahadat@gatech.edu
//Date    : 25th September 2014
//
//Description - This program demonstrates how to send configure AD5724 from BBB.
// This was verified with an oscilloscope.
//
//Revision History: BBB_standalone_TDS_DAC_1.0
*/

/*
Copyright (C) 2014 Md Nazmus Sahadat
*/
#include "PWC_Drive.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <poll.h>


unsigned int nLDACGPIO = 48; // for setting the output voltage
unsigned int nSYNC = 5;		// DAC chip select
unsigned int nCLRGPIO = 60;	// for clearing the output
/*
#define CS 	14 //115			// 14 changed according to new cape
#define DC 49
#define RST 15 //117			//15 changed according to new cape design
*/




/************************voltage equation********************
 * IN = (volt * 4096)/(4.32 *1.8)
 * IN = number you have to write in 12 starts from D15~D4
 * Gain = 4.32 for 10.8V output range we are using
 * REFIN (PIN 17) = 1.8V from BBB
 *
 ************************************************************/

/***************************************************************************************
***************initialization of DAC AD5724*********************************************
*****************************************************************************************/
void init_DAC(void)
{
int fd1;
unsigned char buf1[3] = {0X0C, 0X00, 0X02}; // output range select for DAC +10.8V
unsigned char buf2[3] = {0X19, 0X00, 0X00}; // control register
unsigned char buf3[3] = {0X10, 0X00, 0X0F}; //power control registers
fd1 = open("/dev/spidev1.0", O_RDWR);
gpio_set_value(nSYNC, LOW);	// sahadat debug
write(fd1, &buf1, 3);
usleep(100);		// debug
gpio_set_value(nSYNC, HIGH);	// sahadat debug
gpio_set_value(nSYNC, LOW);	// sahadat debug
write(fd1, &buf2, 3);
usleep(100);		// debug
gpio_set_value(nSYNC, HIGH);	// sahadat debug
gpio_set_value(nSYNC, LOW);	// sahadat debug
write(fd1, &buf3, 3);
usleep(100);		// debug
close(fd1);
gpio_set_value(nSYNC, HIGH);	// sahadat debug



// sahadat debug for new WC
/*int fd2;
unsigned char volt1[3] = {0X04, 0X8F, 0XF0}; // all four register to be set to +6V ref and ref voltage = 2.5V
fd2 = open("/dev/spidev1.0", O_RDWR);
gpio_set_value(nSYNC, LOW);	// sahadat debug
write(fd2, &volt1, 3);
usleep(100);
gpio_set_value(nSYNC, HIGH);	// sahadat debug
close(fd2);
*/
gpio_set_value(nLDACGPIO, LOW);
usleep(10);
gpio_set_value(nLDACGPIO, HIGH);

}


/***************************************************************************************
***************moving the PWC forward*********************************************
*****************************************************************************************/

void pwc_forward(int speed)
{

int fd2;
//unsigned int nLDACGPIO = 48; // for setting the output voltage
//unsigned int nCLRGPIO  = 60;	// for clearing the output
unsigned char volt[3];// = {0X03, 0XDF, 0XD0};  // 6.8V for the forward DAC D

switch(speed)
{
case 1:
	volt[0] = 0X03;
	volt[1] = 0X9A;
	volt[2] = 0X10;	//6.5V output
	break;
case 2:
	volt[0] = 0X03;
	volt[1] = 0XA5;
	volt[2] = 0XE0;	//7 V output
	break;
case 3:
	volt[0] = 0X03;
	volt[1] = 0XB1;
	volt[2] = 0XC0;	//7.5V output
	break;
case 4:
	volt[0] = 0X03;
	volt[1] = 0XBD;
	volt[2] = 0XA0;	//8 V output
	break;
case 5:
	volt[0] = 0X03;
	volt[1] = 0XC9;
	volt[2] = 0X70; //8.5V output
	break;
case 6:
	volt[0] = 0X03;
	volt[1] = 0XD5;
	volt[2] = 0X50;	//9V output
	break;
case 7:
	volt[0] = 0X03;
	volt[1] = 0XE1;
	volt[2] = 0X20;	//9.5V output
	break;
/*case 8:
	volt[0] = 0X03;
	volt[1] = 0XED;
	volt[2] = 0X00;	//10V output
	break;
case 9:
	volt[0] = 0X03;
	volt[1] = 0XFF;
	volt[2] = 0XF0;	//10V output
	break;
*/
default:
	volt[0] = 0X03;
	volt[1] = 0XD5;
	volt[2] = 0X50;	//9V output
	break;

}

fd2 = open("/dev/spidev1.0", O_RDWR);
gpio_set_value(nSYNC, LOW);	// sahadat debug
write(fd2, &volt, 3);
gpio_set_value(nSYNC, HIGH);	// sahadat debug
close(fd2);

gpio_set_value(nLDACGPIO, LOW);
usleep(10);
gpio_set_value(nLDACGPIO, HIGH);


}


/***************************************************************************************
***************moving the PWC backward*********************************************
*****************************************************************************************/

void pwc_backward(int speed)
{

int fd2;
//unsigned int nLDACGPIO = 48; // for setting the output voltage
//unsigned int nCLRGPIO  = 60;	// for clearing the output
unsigned char volt[3]; // = {0X03, 0XA4, 0X90}; //5V output  DACD

switch(speed)
{
case 0:
	volt[0] = 0X03;		// why 04
	volt[1] = 0X8E;
	volt[2] = 0X30;
	break;

case 1:
	volt[0] = 0X03;
	volt[1] = 0X82;
	volt[2] = 0X50;	//5.5V output
	break;
case 2:
	volt[0] = 0X03;
	volt[1] = 0X76;
	volt[2] = 0X80; //5V output
	break;
case 3:
	volt[0] = 0X03;
	volt[1] = 0X6A;
	volt[2] = 0XA0; //4.5V output
	break;
case 4:
	volt[0] = 0X03;
	volt[1] = 0X5E;
	volt[2] = 0XD0; //4V output
	break;
case 5:
	volt[0] = 0X03;
	volt[1] = 0X52;
	volt[2] = 0XF0;	//3.5V output
	break;
case 6:
	volt[0] = 0X03;
	volt[1] = 0X47;
	volt[2] = 0X10;	//3 V output
	break;
case 7:
	volt[0] = 0X03;
	volt[1] = 0X3B;
	volt[2] = 0X40;	//2.5V output
	break;
/*case 8:
	volt[0] = 0X03;
	volt[1] = 0X2F;
	volt[2] = 0X60;	//2V output
	break;
*/
default:
		volt[0] = 0X03;
		volt[1] = 0X47;
		volt[2] = 0X10;	//3 V output
	break;

}
fd2 = open("/dev/spidev1.0", O_RDWR);
gpio_set_value(nSYNC, LOW);	// sahadat debug
write(fd2, &volt, 3);
gpio_set_value(nSYNC, HIGH);	// sahadat debug
close(fd2);

gpio_set_value(nLDACGPIO, LOW);
usleep(10);
gpio_set_value(nLDACGPIO, HIGH);


}



/***************************************************************************************
***************moving the PWC right*********************************************
*****************************************************************************************/

void pwc_right(int speed)
{

int fd2;
//unsigned int nLDACGPIO = 48; // for setting the output voltage
//unsigned int nCLRGPIO  = 60;	// for clearing the output
//unsigned char volt[3];
unsigned char volt[3]; //4.8V output DACC
switch (speed)
{
	case 1:
		volt[0] = 0X02;
		volt[1] = 0X82;
		volt[2] = 0X50; //5.5V output
		break;
	case 2:
		volt[0] = 0X02;
		volt[1] = 0X76;
		volt[2] = 0X80; //5V output
		break;
	case 3:
		volt[0] = 0X02;
		volt[1] = 0X6A;
		volt[2] = 0XA0; //4.5V output
		break;
	case 4:
		volt[0] = 0X02;
		volt[1] = 0X5E;
		volt[2] = 0XD0; //4V output
		break;
	case 5:
		volt[0] = 0X02;
		volt[1] = 0X52;
		volt[2] = 0XF0; //3.5V output
		break;
	case 6:
		volt[0] = 0X02;
		volt[1] = 0X47;
		volt[2] = 0X10; //3V output
		break;
	case 7:
		volt[0] = 0X02;
		volt[1] = 0X3B;
		volt[2] = 0X40; //2.5V output
		break;
/*	case 8:
		volt[0] = 0X02;
		volt[1] = 0X2F;
		volt[2] = 0X60; //2V output
		break;
*/
	default:
		volt[0] = 0X02;
		volt[1] = 0X47;
		volt[2] = 0X10; //3V output
		break;
}

fd2 = open("/dev/spidev1.0", O_RDWR);
gpio_set_value(nSYNC, LOW);	// sahadat debug
write(fd2, &volt, 3);
gpio_set_value(nSYNC, HIGH);	// sahadat debug
close(fd2);

gpio_set_value(nLDACGPIO, LOW);
usleep(10);
gpio_set_value(nLDACGPIO, HIGH);




}



/***************************************************************************************
***************moving the PWC left*********************************************
*****************************************************************************************/

void pwc_left(int speed)
{

int fd2;
//unsigned int nLDACGPIO = 48; // for setting the output voltage
//unsigned int nCLRGPIO  = 60;	// for clearing the output
unsigned char volt[3]; // = {0X02, 0XF6, 0XE0}; //7.2V output DACC

switch(speed)
{
case 1:
	volt[0] = 0X02;
	volt[1] = 0X9A;
	volt[2] = 0X10;	//6.5V output
	break;
case 2:
	volt[0] = 0X02;
	volt[1] = 0XA5;
	volt[2] = 0XE0;	//7 V output
	break;
case 3:
	volt[0] = 0X02;
	volt[1] = 0XB1;
	volt[2] = 0XC0;	//7.5V output
	break;
case 4:
	volt[0] = 0X02;
	volt[1] = 0XBD;
	volt[2] = 0XA0;	//8 V output
	break;
case 5:
	volt[0] = 0X02;
	volt[1] = 0XC9;
	volt[2] = 0X70; //8.5V output
	break;
case 6:
	volt[0] = 0X02;
	volt[1] = 0XD5;
	volt[2] = 0X50;	//9V output
	break;
case 7:
	volt[0] = 0X02;
	volt[1] = 0XE1;
	volt[2] = 0X20;	//9.5V output
	break;
/*case 8:
	volt[0] = 0X02;
	volt[1] = 0XED;
	volt[2] = 0X00;	//10V output
	break;
*/
default:
	volt[0] = 0X02;
		volt[1] = 0XD5;
		volt[2] = 0X50;	//9V output

	break;
}
fd2 = open("/dev/spidev1.0", O_RDWR);
gpio_set_value(nSYNC, LOW);	// sahadat debug
write(fd2, &volt, 3);
gpio_set_value(nSYNC, HIGH);	// sahadat debug
close(fd2);

gpio_set_value(nLDACGPIO, LOW);
usleep(10);
gpio_set_value(nLDACGPIO, HIGH);

}


/***************************************************************************************
***************initialization of GPIO BBB*********************************************
*****************************************************************************************/

void init_GPIO(void){

unsigned int CS = 26;//14; //115			// 14 changed according to new cape
unsigned int DC = 49;
unsigned int RST = 23;//15; //117			//15 changed according to new cape design

gpio_export(nLDACGPIO); // The loading DAC
gpio_export(nCLRGPIO); // The clearing DAC
gpio_export(nSYNC); // chip select of DAC
gpio_export(CS);
gpio_export(DC);
gpio_export(RST);

gpio_set_dir(nLDACGPIO, OUTPUT_PIN);
gpio_set_dir(nCLRGPIO, OUTPUT_PIN);
gpio_set_dir(nSYNC, OUTPUT_PIN);
// display //

gpio_set_dir(CS,OUTPUT_PIN);
gpio_set_dir(DC,OUTPUT_PIN);
gpio_set_dir(RST,OUTPUT_PIN);

gpio_set_value(nCLRGPIO, LOW);
usleep(1000);
gpio_set_value(nCLRGPIO, HIGH);
usleep(1000);


}




/***************************************************************************************
***************putting the PWC to centre*********************************************
*****************************************************************************************/

void init_pwc(void)
{

int fd3;
unsigned char volt[3] = {0X04, 0X8F, 0XF0}; // debug: all four register to be set to +6V ref and ref voltage = 2.5V 
fd3 = open("/dev/spidev1.0", O_RDWR);
gpio_set_value(nSYNC, LOW);	// sahadat debug
write(fd3, &volt, 3);
gpio_set_value(nSYNC, HIGH);	// sahadat debug
close(fd3);

gpio_set_value(nLDACGPIO, LOW);
usleep(10);
gpio_set_value(nLDACGPIO, HIGH);

}



/***************************************************************************************
***************putting the PWC to centre during latched mode*********************************************
*****************************************************************************************/

void init_pwc_latched(void)
{

int fd3;
//unsigned int nLDACGPIO = 48; // for setting the output voltage
//unsigned int nCLRGPIO  = 60;	// for clearing the output
unsigned char volt[3] = {0X02, 0X8F, 0XF0}; // all four register to be set to +6V ref and ref voltage = 2.5V
fd3 = open("/dev/spidev1.0", O_RDWR);
gpio_set_value(nSYNC, LOW);	// sahadat debug
write(fd3, &volt, 3);
gpio_set_value(nSYNC, HIGH);	// sahadat debug
close(fd3);

gpio_set_value(nLDACGPIO, LOW);
usleep(10);
gpio_set_value(nLDACGPIO, HIGH);


}


/**************** end of latched initialization*********************************/

//--------------setting FW/BW to zero-----------------------//
void init_FB_pwc(void)
{
	int fd3;
	unsigned char volt[3] = {0X03, 0X8F, 0XF0}; // all four register to be set to +6V ref and ref voltage = 2.5V
	fd3 = open("/dev/spidev1.0", O_RDWR);
	gpio_set_value(nSYNC, LOW);	// sahadat debug
	write(fd3, &volt, 3);
	gpio_set_value(nSYNC, HIGH);	// sahadat debug
	close(fd3);

	gpio_set_value(nLDACGPIO, LOW);
	usleep(10);
	gpio_set_value(nLDACGPIO, HIGH);

}

