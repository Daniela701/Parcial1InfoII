/*
Este programa pide al usario que ingrese diferentes opciones 
para visualizar un patron o secuencia de patrones

*/
unsigned int pines[3]= {11, 12, 13};//Arreglo para pines digitales
//Variables necesarias
int *n;
int Chs;
int opcion;
int patron;
int num;
int times=0;
int time=1000;//Tiempo entre un patron al siguiente

//Funcion para configurar los pines como salidas
void setup(){
 for (int i=0; i<=2; i++)
   pinMode (pines[i],OUTPUT);
 Serial.begin(9600);
}
//Funcion que recibe numeros hexagecimales y los envia a cada fila de leds
void leds(int F1, int F2, int F3, int F4, int F5, int F6, int F7, int F8, int time){
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
   delay(time);
}
//Funcion que verifica si todo esta en orden encendiendo todos los leds
void verificacion(){
  Serial.println("Acontinuacion debera ver todos los leds prendidos");
  leds(0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, time);
  delay(1000);
}
//Funcion que envia a la funcion leds los numeros hexagecimales de la letra o letras escogidas por el usario
void letters(int p, int time){
    if (p==1)
      leds(0x3C, 0x7E, 0x66, 0x66, 0x7E, 0x7E, 0x66, 0x66, time);
    else if (p==2)
      leds(0x7C, 0X7E, 0X66, 0X7C, 0X7C, 0X66, 0X7E, 0X7C, time);
    else if (p==3)
      leds(0x3C, 0x7E, 0X62, 0X60, 0X60, 0X62, 0X7E, 0X3C, time);
    else if (p==4)
      leds(0x78, 0x7C, 0X66, 0X66, 0X66, 0X66, 0X7C, 0X78, time);
    else if (p==5)
      leds(0x3C, 0x7E, 0X60, 0X7E, 0X7E, 0X60, 0X7E, 0X3C, time);
    else if (p==6)
      leds(0x7E, 0x7E, 0X60, 0X7E, 0X7E, 0X60, 0X60, 0X60, time);
    else if (p==7)
      leds(0x3C, 0x7E, 0X60, 0X6E, 0X6E, 0X66, 0X7E, 0X3C, time);
    else if (p==8)
      leds(0x66, 0x66, 0x66, 0x7E, 0x7E, 0x66, 0x66, 0x66, time);
    else if (p==9)
      leds(0x7E, 0x7E, 0X18, 0X18, 0X18, 0X18, 0X7E, 0X7E, time);
    else if (p==10)
      leds(0x7E, 0x7E, 0X18, 0X18, 0X18, 0X18, 0X78, 0X78, time);
    else if (p==11)
      leds(0x63, 0x66, 0x6C, 0x78, 0x78, 0x6C, 0x66, 0x63, time);
    else if (p==12)
      leds(0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x7E, 0x7E, time);
    else if (p==13)
      leds(0x42, 0x66, 0x7E, 0x66, 0x66, 0x66, 0x66, 0x66, time);
    else if (p==14)
      leds(0x00, 0x43, 0x63, 0x73, 0x6B, 0x67, 0x63, 0x00, time);
    else if (p==15)
      leds(0x3C, 0x7E, 0x66, 0x66, 0x66, 0x66, 0x7E, 0x3C, time);
    else if (p==16)
      leds(0x3C, 0x7E, 0x66, 0x7E, 0x78, 0x60, 0x60, 0x60, time);
    else if (p==17)
      leds(0x7E, 0xC3, 0xD3, 0xCB, 0XC7, 0X7E, 0X01, 0X00, time);
    else if (p==18)
      leds(0x3C, 0x7E, 0x62, 0x62, 0x7C, 0x70, 0x6C, 0x66, time);
    else if (p==19)
      leds(0x3C, 0x7E, 0x64, 0x7E, 0x3E, 0x46, 0x7E, 0x3C, time);
    else if (p==20)
      leds(0x7E, 0x7E, 0X18, 0X18, 0X18, 0X18, 0X18, 0X18, time);
    else if (p==21)
      leds(0x24, 0x66, 0x66, 0x66, 0x66, 0x66, 0x7E, 0x3C, time);
    else if (p==22)
      leds(0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x18, time);
    else if (p==23)
      leds(0x5A, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xFF, 0x66, time);
    else if (p==24)
      leds(0x00, 0x66, 0x66, 0x3C, 0x18, 0x3C, 0x66, 0x66, time);
    else if (p==25)
      leds(0x6C, 0x6C, 0x6C, 0x3C, 0x1C, 0x4C, 0x7C, 0x38, time);
    else if(p==26)
      leds(0x7E, 0x7E, 0x06, 0x0C, 0x18, 0x30, 0x7E, 0x7E, time);
 }
//Funcion que le permite al usario elegir o crear un patron
void imagen(int op, int patron){
  Serial.println("Digite el numero 1 si quiere crear su propio patron");
  Serial.println("Digite el numero 2 si desea utilizar la opcion predeterminada");
  Serial.println("Esta opcion permite visualizar letras y numeros");
  delay(10000);
  while (Serial.available()>0){
      op= Serial.parseInt();
      if (op==1){
           n=new int [8];
           Serial.println("Acontinuacion podra crear su propio patron");
           Serial.println("Si aun no sabe como hacerlo por favor leer el manual de uso");
           Serial.println("Ahora empiece a digitar los numeros correspondientes por fila");
           delay(1000);
           for (int i=0; i<8; i++){
             Serial.print("Fila");
             Serial.println(i+1);
             delay(10000);
             while (Serial.available()>0)
               n[i]=Serial.parseInt();
           }
           Serial.println("Ahora debera ver el patron que ha creado");
           leds(n[0], n[1], n[2], n[3], n[4], n[5], n[6], n[7], time);   
           delete[] n;
      }
      else if (op==2){
           Serial.println("Digite 1 si quiere mostrar el patron de una letra");
           Serial.println("Digite 2 si quiere mostrar el patron de un numero");
           delay(10000);
       	   while (Serial.available()>0){
             patron= Serial.parseInt();
             if (patron==1){
               Serial.println("Acontinuacion se le mostrara la lista enumerada de las letras disponibles:");
  			   Serial.println("1. A    2. B    3. C    4. D    5. E    6. F    7. G    8. H");
               Serial.println("9. I    10.J    11.K    12.L    13.M    14.N    15.O    16.P");
               Serial.println("17.Q    18.R    19.S    20.T    21.U    22.V    23.W    24.X");
               Serial.println("25.Y    26.Z");
               Serial.println("Digita el numero de la letra correspondiente");
               delay(10000);
               while (Serial.available()>0){
                 patron= Serial.parseInt();
                 Serial.println("Ahora debera ver el patron");
                 letters(patron, time);
               }
              }
             }
            }
           }
}
void publik(int op, int num, int t){
  Serial.println("Digite 1 si desea ver una secuencia de numeros");
  Serial.println("Digite 2 si desea ver una secuencia con letras");
  delay(10000);
  while (Serial.available()>0){
    op= Serial.parseInt();
    if (op==1){
      Serial.println("Por favor digite el numero de elementos que quiere en su secuencia");
      delay(10000);
      while (Serial.available()>0){
        num= Serial.parseInt();
        Serial.println("Ahora digite el tiempo en el que quiere que se muestre cada patron");
        Serial.println("Aclaracion: El tiempo debe ser en segundos");
        delay(10000);
        while (Serial.available()>0){
          t= Serial.parseInt();
          Serial.print("Por favor digite los numeros que quiere mostrar en cada uno de los patrones");
        }
      }
    }
    else if (op==2){
      Serial.println("Por favor digite el numero de elementos que quiere en su secuencia");
      delay(10000);
      while (Serial.available()>0){
        num= Serial.parseInt();
        Serial.print("Ahora digite el tiempo en el que quiere que se muestre cada patron");
        Serial.println("Aclaracion: El tiempo debe ser en segundos");
        delay(10000);
        while (Serial.available()>0){
          t= Serial.parseInt();
          t*=1000;
          Serial.println("Ahora se le mostrara la lista de letras disponibles:");
          Serial.println("1. A    2. B    3. C    4. D    5. E    6. F    7. G    8. H");
          Serial.println("9. I    10.J    11.K    12.L    13.M    14.N    15.O    16.P");
          Serial.println("17.Q    18.R    19.S    20.T    21.U    22.V    23.W    24.X");
          Serial.println("25.Y    26.Z");
          Serial.println("Por favor digite los numeros correspondientes");
          Serial.println(" a las letras que quiere mostrar en cada uno de los patrones");
          n=new int [num];
          delay(1000);
          for (int i=0; i<num; i++){
             Serial.print("Patron numero ");
             Serial.println(i+1);
             delay(10000);
             while (Serial.available()>0)
               n[i]=Serial.parseInt();
           }
          Serial.println("Ahora debera ver la animacion");
          while(times<5){
            for(int i=0; i<num; i++){
              letters(n[i], t);
            }
            times++;
          }
          delete[] n;
        }
      }
    }
  }    
  
}
//Funcion que muestra el menu de opciones
void loop(){
        Chs=0;
        Serial.println("Elija una de las siguientes opciones:");
        Serial.println();
        Serial.println("Digite 1 para verificar que todos los leds funcionan correctamente");
        Serial.println("Digite 2 para mostrar un solo patron");
        Serial.println("Digite 3 para mostrar una serie de patrones");
        delay(10000);
  		while (Serial.available()>0){
          Chs= Serial.parseInt();
          if (Chs==1)
            verificacion();
          else if (Chs==2)
            imagen(opcion, patron);
          else if (Chs==3)
            publik(opcion, num, time);
        }
  }