/***************************************************
 * Discliamer: 
 *    This program was written in preparation for my
 *    job interview with richer education.
 *    
 *    Note that this script is intended for GOOD and not for EVIL.
 *    Please do not use in any negative context, at least not without
 *    prior consent from author of this script.
 * 
 * Author:
 *    Chibuike Okpaluba <co607@live.mdx.ac.uk>
 * 
 * Description:
 *    This program demonstrates basic understanding of:
 *    
 *    1. Generic programming with the Arduino,
 *    2. Interfacing with external devices and sensors etc.
 *    
 *    On execution the text "R.Education" will be printed on the
 *    attached matrix display. After this introductory animation,
 *    a square box whose position is relative to the orientation of 
 *    the device will be displayed on the matrix display.
 * 
 * Required Device:
 *    This program assumes that the following devices are connected:
 *    
 *    1. The orientation sensor : CMPS10/11, and
 *    2. The Adafruit monochrome display using the HT16K33 Backlight controller.
 * 
 * Questions and Answers:
 *    For more information please email the author of this module.
 *    
 * 
 * More Links:
 *    Website: https://www.chibuikepraise.com/projects
 *    Git page: https://github.com/chibike/alphabets_with_the_abb/blob/master/Program/testing_abb/Module1.mod
 *    Youtube Channel: https://www.youtube.com/channel/UCwisGpd_BvIv6qkBlG8Skeg
 *    
 * 
 * Thank you.
 * 
 ****************************************************/


#include <Wire.h>
#include <CMPS10.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

#include "header.h"

void setup()
{
  Serial.begin(230400);
  matrix.begin(0x70);

  play_intro();
}

void loop()
{
  bar.set_x( get_x_force() );
  bar.set_y( get_y_force() );
  
  bar.display();
  
  delay(100);
}

