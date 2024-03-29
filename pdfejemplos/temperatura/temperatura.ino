#include <Adafruit_GFX_AS.h>
#include <Adafruit_ILI9341_AS.h>
#include <MySignals.h>
#define graphic_low_extrem 230
#define graphic_high_extrem 30
#define graphic_left_extrem 0
#define graphic_right_extrem 320

Adafruit_ILI9341_AS tft = Adafruit_ILI9341_AS(TFT_CS, TFT_DC);
//! It stores the current value of x position in the LCD.
uint16_t graphic_x;
//! It stores the current value of the MySignals.
uint16_t valRead;
//! It stores the previous value of the MySignals.
uint16_t graphic_prevRead;


void setup(void){
    Serial.begin(115200);
    MySignals.begin();
    tft.init();
    tft.setRotation(3);
    tft.fillScreen(ILI9341_WHITE);
    tft.fillRect(0,0,320,30,ILI9341_RED);
    tft.setTextColor(ILI9341_WHITE);
    tft.drawString("Temperatura",5,5,4);
    }

void loop()
{
  float temperature = MySignals.getTemperature ();
  Serial.print (F( "Temperatura (* C):"));
  Serial.println (temperature, 2 );
  delay ( 5000 ) ;
  valRead = (float)MySignals.getTemperature()*10.0;
  Serial.println(valRead);
  valRead = map(valRead, 300, 400, 230, 30);
  printGraphic(valRead, 0);
}

void printGraphic(uint16_t value, uint8_t delay_time)
{
    if (value < graphic_high_extrem)
      {
        value = graphic_high_extrem;
      }
    
    if (value > graphic_low_extrem)
      {
        value = graphic_low_extrem;
      }
      
    //Pinta la linea solo a partir de que ya exista al menos 1 valor
    if (graphic_x > graphic_left_extrem + 1)
      {
      tft.drawLine(graphic_x - 1, graphic_prevRead, graphic_x, value, ILI9341_RED);
      }
      
    //(barre pantalla pintando una linea)
    tft.drawLine(graphic_x + 1, graphic_high_extrem, graphic_x + 1, graphic_low_extrem, ILI9341_WHITE);
    graphic_prevRead = value;
    graphic_x++;
    delay(delay_time);
    
    if (graphic_x == graphic_right_extrem)
      {
        graphic_x = graphic_left_extrem;
      }
    SPI.end();
}


