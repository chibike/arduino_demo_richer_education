
#include "header.h"

Bar::Bar(int w, int h)
{
  width = w;
  height = h;

  x = (LED_MAXTRIX_WIDTH - width) / 2;
  y = (LED_MAXTRIX_HEIGHT - height) / 2;
}

void Bar::set_x(int x_pos)
{
  /*********************************************************
   * This function updates the x position; ensuring that it
   * does not exceed the display's boundaries
   *********************************************************/
   
  this->x = constrain(x_pos, 0, LED_MAXTRIX_WIDTH - this->width);
}

void Bar::set_y(int y_pos)
{
  /*********************************************************
   * This function updates the y position; ensuring that it
   * does not exceed the display's boundaries
   *********************************************************/
   
  this->y = constrain(y_pos, 0, LED_MAXTRIX_HEIGHT - this->height);
}

void Bar::display() const
{
  /*********************************************************
   * This function draws the bar on the display
   *********************************************************/
   
  matrix.clear();
  matrix.fillRect(this->x, this->y, this->width, this->height, LED_ON);
  matrix.writeDisplay();
}

