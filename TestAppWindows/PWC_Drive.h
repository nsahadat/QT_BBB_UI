/*
 * PWC_Drive.h
 *
 *  Created on: Apr 21, 2016
 *      Author: sahil
 */

#ifndef PWC_DRIVE_H_
#define PWC_DRIVE_H_



/*
//Filename: PWC_Drive.h
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

/****************************************************************
* define speed constants
****************************************************************/
/*
# define FWD_SPD1 {0X03, 0XDF, 0XD0}
# define FWD_SPD2 {0X03, 0XDF, 0XD0}
# define FWD_SPD3 {0X03, 0XDF, 0XD0}
# define FWD_SPD4 {0X03, 0XDF, 0XD0}
# define FWD_SPD5 {0X03, 0XDF, 0XD0}
# define FWD_SPD6 {0X03, 0XDF, 0XD0}
# define FWD_SPD7 {0X03, 0XDF, 0XD0}
# define FWD_SPD8 {0X03, 0XDF, 0XD0}

# define BCK_SPD1 {0X03, 0XA4, 0X90}
# define BCK_SPD2 {0X03, 0XA4, 0X90}
# define BCK_SPD3 {0X03, 0XA4, 0X90}
# define BCK_SPD4 {0X03, 0XA4, 0X90}
# define BCK_SPD5 {0X03, 0XA4, 0X90}
# define BCK_SPD6 {0X03, 0XA4, 0X90}
# define BCK_SPD7 {0X03, 0XA4, 0X90}
# define BCK_SPD8 {0X03, 0XA4, 0X90}

# define LFT_SPD1 {0X02, 0XF6, 0XE0}
# define LFT_SPD2 {0X02, 0XF6, 0XE0}
# define LFT_SPD3 {0X02, 0XF6, 0XE0}
# define LFT_SPD4 {0X02, 0XF6, 0XE0}
# define LFT_SPD5 {0X02, 0XF6, 0XE0}
# define LFT_SPD6 {0X02, 0XF6, 0XE0}
# define LFT_SPD7 {0X02, 0XF6, 0XE0}
# define LFT_SPD8 {0X02, 0XF6, 0XE0}

# define RGT_SPD1[3] {0X02, 0X94, 0X20}
# define RGT_SPD2[3] {0X02, 0X94, 0X20}
# define RGT_SPD3[3] {0X02, 0X94, 0X20}
# define RGT_SPD4[3] {0X02, 0X94, 0X20}
# define RGT_SPD5[3] {0X02, 0X94, 0X20}
# define RGT_SPD6[3] {0X02, 0X94, 0X20}
# define RGT_SPD7[3] {0X02, 0X94, 0X20}
# define RGT_SPD8[3] {0X02, 0X94, 0X20}

*/
#include "SimpleGPIO.h"
#include <iostream>


#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************
* Constants
****************************************************************/
#define SYSFS_GPIO_DIR "/sys/class/gpio"
#define POLL_TIMEOUT (3 * 1000) /* 3 seconds */
#define MAX_BUF 64




/*
enum PIN_DIRECTION{
INPUT_PIN=0,
OUTPUT_PIN=1
};
enum PIN_VALUE{
LOW=0,
HIGH=1
};
*/
/****************************************************************
* gpio_export
****************************************************************/
/*
int gpio_export(unsigned int gpio);
int gpio_unexport(unsigned int gpio);
int gpio_set_dir(unsigned int gpio, PIN_DIRECTION out_flag);
int gpio_set_value(unsigned int gpio, PIN_VALUE value);
int gpio_get_value(unsigned int gpio, unsigned int *value);
int gpio_set_edge(unsigned int gpio, char *edge);
int gpio_fd_open(unsigned int gpio);
int gpio_fd_close(int fd);
*/
void init_DAC(void);
void pwc_forward(int speed);
void pwc_backward(int speed);
void pwc_right(int speed);
void pwc_left(int speed);
void pwc_backward_left(int speed);
void pwc_backward_right(int speed);
void pwc_forward_left(int speed);
void pwc_forward_right(int speed);
void init_GPIO(void);
void init_pwc(void);
void init_pwc_latched(void);
void init_FB_pwc(void);
void delay_ms(int msec);

#ifdef __cplusplus
}
#endif



#endif /* PWCDRIVE_H_ */



