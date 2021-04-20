/*
Este programa enciende leds en foma de S
*/
unsigned int pines[3]= {11, 12, 13};//Arreglo para pines digitales
unsigned int vl[9]={128, 64, 32, 16, 8, 4, 2, 1, 0}; //Arreglo para los valores que se ingresan en la funcion Leds
//Tiempo para encender de un led al siguiente
#define TIEMPO 0 

void leds(int F1, int F2, int F3, int F4, int F5, int F6, int F7, int F8){
   shiftOut(pines[0], pines[2], LSBFIRST, F1); 
   shiftOut(pines[0], pines[2], LSBFIRST, F2); 
   shiftOut(pines[0], pines[2], LSBFIRST, F3); 
   shiftOut(pines[0], pines[2], LSBFIRST, F4); 
   shiftOut(pines[0], pines[2], LSBFIRST, F5); 
   shiftOut(pines[0], pines[2], LSBFIRST, F6); 
   shiftOut(pines[0], pines[2], LSBFIRST, F7); 
   shiftOut(pines[0], pines[2], LSBFIRST, F8); 
   digitalWrite(pines[1], HIGH);
   digitalWrite(pines[1], LOW);
   delay(TIEMPO);
}

void setup(){
 for (int i=0; i<=2; i++)
   pinMode (pines[i],OUTPUT);
}

void loop(){
  for (int i=0; i<8; i++){
     if (i==0)
     leds(0, vl[i], vl[i], vl[i], 0, vl[i], vl[i], 0);
     else if (i==1)
     leds(vl[i], vl[i], vl[i], vl[i], 0, vl[i], vl[i], vl[i]);
     else if (i==2)
     leds(vl[i], vl[i], vl[i], vl[i], 0, 0, vl[i], vl[i]);
     else if (i==3 or i==4)
     leds(vl[i], vl[i], 0, vl[i], 0, 0, vl[i], vl[i]);
     else if (i==5 or i==6)
     leds(vl[i], vl[i], 0, vl[i], vl[i], vl[i], vl[i], vl[i]); 
     else if (i==7)
     leds(0, vl[i], 0, 0, vl[i], vl[i], vl[i], 0);
       }
}
