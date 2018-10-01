
// protecting against multiple includes
#pragma once


// defining matrix dimensions
#define LED_MAXTRIX_WIDTH 8
#define LED_MAXTRIX_HEIGHT 16


// defining Bar object
class Bar
{
  public:
    Bar(int, int);

    void display() const;
    void set_x(int x_pos);
    void set_y(int y_pos);

  private:
    int x;
    int y;

    int width;
    int height;
};


// initializing required objects
Bar bar = Bar(2, 2);
CMPS10 compass;
Adafruit_8x16matrix matrix = Adafruit_8x16matrix();


float get_x_force()
{
  /*********************************************************
   * This function returns the scaled pitch measurement of the device
   *********************************************************/
   
  return map(compass.pitch(), -90, 90, 0, LED_MAXTRIX_WIDTH);
}

float get_y_force()
{
  /*********************************************************
   * This function returns the scaled roll measurement of the device
   *********************************************************/
   
  return map(compass.roll(), -90, 90, 0, LED_MAXTRIX_HEIGHT);
}

void play_intro()
{
  /*********************************************************
   * This function animates the text "R.Education"
   *********************************************************/
   
  matrix.setTextSize(0.5);
  matrix.setTextWrap(false);
  matrix.setTextColor(LED_ON);

  // change display orientation to landscape
  matrix.setRotation(1);

  // scroll text right to left
  for (int8_t x=13; x>=-73; x--)
  {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print("R.Education");
    matrix.writeDisplay();
    delay(150);
  }

  // scroll text left to right
  for (int8_t x=-75; x<=13; x++)
  {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print("R.Education");
    matrix.writeDisplay();
    delay(150);
  }

  // change display orientation to potrait
  matrix.setRotation(0);
}
