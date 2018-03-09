#include <LiquidCrystal.h>

//EDIT

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);  


#define Glosnik 3
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

int lcd_key     =0;
int adc_key_in  =0;
int sekundy;
int minuty;

int read_LCD_buttons(){               // read the buttons
    adc_key_in = analogRead(0);       // read the value from the sensor 

    // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
    // we add approx 50 to those values and check to see if we are close
    // We make this the 1st option for speed reasons since it will be the most likely result

    if (adc_key_in > 1000) return btnNONE; 

    // For V1.1 us this threshold
    if (adc_key_in < 50)   return btnRIGHT;  
    if (adc_key_in < 250)  return btnUP; 
    if (adc_key_in < 450)  return btnDOWN; 
    if (adc_key_in < 650)  return btnLEFT;
    if (adc_key_in < 850)  return btnSELECT;  

   // For V1.0 comment the other threshold and use the one below:

    return btnNONE;                // when all others fail, return this.
}



int beep(){tone(Glosnik,4000,200);}                          

int start(){
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("NACISNIJ SELECT");
  lcd.setCursor(0,2);
  lcd.print("ABY ROZPOCZAC");
  delay(100);
  if(read_LCD_buttons()==btnSELECT)
  {
    beep(); praca();
    }  
  }

int praca(){
  beep();
  lcd.begin(16,2);
  
  for(int i=1500;i>0;i--){
  lcd.setCursor(0,2);
  lcd.print("WORK              ");  
  sekundy=i%60;
  minuty=i/60;
  
  if(minuty<10){
  lcd.setCursor(0,0);
  lcd.print("0");
  lcd.setCursor(1,0);
  lcd.print(minuty);}else
  {lcd.setCursor(0,0);
  lcd.print(minuty);}
  lcd.setCursor(2,0);
  lcd.print(":");
  
  if(sekundy<10){
  lcd.setCursor(3,0);
  lcd.print("0");
    
  lcd.setCursor(4,0);
  lcd.print(sekundy);}else
  {lcd.setCursor(3,0);
  lcd.print(sekundy);}
  
  delay(1000);
  
  if(read_LCD_buttons()==btnSELECT)
  {beep();
    do{lcd.setCursor(0,2);
  lcd.print("PAUSE HOLD RIGHT");delay(1000);}while(read_LCD_buttons()!=btnRIGHT);
  }
  }przerwa();}

int przerwa(){
  beep();
  lcd.begin(16,2);
  
  for(int i=300;i>0;i--){
  lcd.setCursor(0,2);
  lcd.print("REST              ");  
  sekundy=i%60;
  minuty=i/60;
  if(minuty<10){
  lcd.setCursor(0,0);
  lcd.print("0");
  lcd.setCursor(1,0);
  lcd.print(minuty);}else
  {lcd.setCursor(0,0);
  lcd.print(minuty);}
  lcd.setCursor(2,0);
  lcd.print(":");
  
  if(sekundy<10){
  lcd.setCursor(3,0);
  lcd.print("0");
    
  lcd.setCursor(4,0);
  lcd.print(sekundy);}else
  {lcd.setCursor(3,0);
  lcd.print(sekundy);}
  
  delay(1000);
  
  if(read_LCD_buttons()==btnSELECT)
  {beep();
    do{lcd.setCursor(0,2);
  lcd.print("PAUSE HOLD RIGHT");delay(1000);}while(read_LCD_buttons()!=btnRIGHT);
  }
  }praca();}

void setup() {

}

void loop() {
  start();

  

}
