/*
Este programa pide al usario que ingrese diferentes opciones 
para visualizar un patron o secuencia de patrones

Manual de uso: 
1.El usuario se encontrara con un menu de entrada, debera digitar el numero de la opcion que eligio
2.Al entrar en la primera opcion(Verificacion del funcionamiento de leds) no tendra que digitar
ningun tipo de dato, solo debe asegurarse que todos los leds se enciendan
3.Al entrar a la segunda opcion tiene dos alternativas: Crear su propio patron o elegir uno 
que ya esta establecido en el programa
3.1 Al elegir la opcion 1(crear patron) debera digitar unos y ceros por cada led 
de cada fila. Va a digitar 1 solo si desea que ese led este prendido y va a digitar
0 si desea que este apagado. Ejemplo: Yo quiero que el led 7 de la fila 1 este prendido,
entonces digitare 1 cuando me corresponda darle valor a este led
3.2 Al entrar a la opcion 2(ver patron) tendra una lista de letras, lo unico que debera
hacer es digitar el numero de lista de la letra que quiere ver como patron de leds
4.Al entrar a secuencia de patrones le pediran el numero de letras que quiere ver,
el tiempo para pasar de una letra a otra y por ultimo los numeros de la lista correspondiente 
a las letras que desea ver
LISTO! 
*/
unsigned int pines[3]= {11, 12, 13};//Arreglo para pines digitales
//Variables necesarias
int patron[8];//Arreglo de 8 elementos no designados (luego este arreglo se llena de datos)
int *n;//Apuntador
int Chs;
int opcion;
int num;
int times=0;
float time=1000;//Tiempo entre un patron al siguiente

//Funcion para configurar los pines como salidas
void setup(){
 for (int i=0; i<=2; i++)
   pinMode (pines[i],OUTPUT);
 Serial.begin(9600);
}
//Funcion que recibe 8 valores que convierte a bianrios y los envia a cada dila de leds
void leds(int F1, int F2, int F3, int F4, int F5, int F6, int F7, int F8, float time){
   shiftOut(pines[0], pines[2], LSBFIRST, F1); //El pin 0 corresponde al pin que envia 1s o 0s
   shiftOut(pines[0], pines[2], LSBFIRST, F2); //El pin 2 corresponde al reloj de registro de desplazamiento
   shiftOut(pines[0], pines[2], LSBFIRST, F3); 
   shiftOut(pines[0], pines[2], LSBFIRST, F4); 
   shiftOut(pines[0], pines[2], LSBFIRST, F5); 
   shiftOut(pines[0], pines[2], LSBFIRST, F6); 
   shiftOut(pines[0], pines[2], LSBFIRST, F7); 
   shiftOut(pines[0], pines[2], LSBFIRST, F8); 
   digitalWrite(pines[1], HIGH);//Este pin corresponde al Reloj de registro de salida
   digitalWrite(pines[1], LOW);
   delay(time);
}
//Funcion que verifica si todo esta en orden encendiendo los leds fila por fila
void verificacion(){
  Serial.println("Debera ver como se enciende cada fila de leds");
  leds(0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, time);
  leds(0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, time);
  leds(0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, time);
  leds(0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, time);
  leds(0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, time);
  leds(0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, time);
  leds(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, time);
  leds(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, time);
  leds(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, time);
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
void imagen(int op){
  Serial.println("Digite el numero 1 si quiere crear su propio patron");
  Serial.println("Digite el numero 2 si desea utilizar la opcion predeterminada");
  Serial.println("(Esta opcion permite visualizar letras)");
  delay(10000);
  while (Serial.available()>0){
      op= Serial.parseInt();
      if (op==1){
           n= patron;//La varible n apunta al arreglo patron de 8 elementos 
           Serial.println("Por cada fila(8filas) tenemos 8 leds");
           Serial.println("Si desea que un led se prenda digite 1, por el contrario digite 0");
           Serial.println("Digite los numeros correspondientes al numero de fila y led");
           delay(10000);
           for (int i=0; i<8; i++){
             Serial.print("Fila");
             Serial.println(i+1);
             delay(1000);
             for (int j=0; j<8; j++){
               Serial.print("Led");
               Serial.println(j+1);
               delay(1950);
               while (Serial.available()>0){
                 op=Serial.parseInt();
                 if (op==1){//Los unos y ceros que ingresa el usuario se convierten en numeros decimales
                   if(i==0)
                     num+=1;
                   else if (j==1)
                     num+=2;
                   else if (j==2)
                     num+=4;
                   else if (j==3)
                     num+=8;
                   else if (j==4)
                     num+=16;
                   else if (j==5)
                     num+=32;
                   else if (j==6)
                     num+=64;
                   else if (j==7)
                     num+=128;
                 } 
               }
             }
             n[i]=num;//Se va sumando a cada posicion del apuntador el valor decimal que le corresponde a cada fila
             num=0;
           }
           Serial.println("Ahora debera ver el patron que ha creado");
           leds(n[0], n[1], n[2], n[3], n[4], n[5], n[6], n[7], time);   
           
      }
      else if (op==2){
           Serial.println("En esta seccion podra ver el patron de una letra");
           Serial.println("Acontinuacion se le mostrara la lista enumerada de las letras disponibles:");
  		   Serial.println("1. A    2. B    3. C    4. D    5. E    6. F    7. G    8. H");
           Serial.println("9. I    10.J    11.K    12.L    13.M    14.N    15.O    16.P");
           Serial.println("17.Q    18.R    19.S    20.T    21.U    22.V    23.W    24.X");
           Serial.println("25.Y    26.Z");
           Serial.println("Digita el numero de la letra correspondiente");
           delay(10000);
           while (Serial.available()>0){
                 op= Serial.parseInt();
                 Serial.println("Ahora debera ver el patron");
                 letters(op, time);//Se envia a la funcion Letters el numero que le corresponde a la letra que escogio el usuario, ademas de la variable time
               }
              }
   }
 }
//Funcion que le permite al usario escoger varios patrones y ver una animacion
void publik(int op, int num, float t){
  Serial.println("");
  Serial.println("En esta opcion podra ver animaciones de letras");
  Serial.println("Usted debera digitar las letras para cada patron");
  delay(10000);
  Serial.println("Por favor digite el numero de elementos que quiere en su secuencia");
  Serial.println("Aclaracion: cada letra corresponde a un elemento");
  delay(10000);
  while (Serial.available()>0){
        num= Serial.parseInt();
        Serial.println("Ahora digite el tiempo en el que quiere que se muestre cada patron");
        Serial.println("Aclaracion: El tiempo debe ser en segundos");
        delay(10000);
        while (Serial.available()>0){
          t= Serial.parseFloat();
          t*=1000;//Conversion de segundos a milisegundos 
          Serial.println("Ahora se le mostrara la lista de letras disponibles:");
          Serial.println("1. A    2. B    3. C    4. D    5. E    6. F    7. G    8. H");
          Serial.println("9. I    10.J    11.K    12.L    13.M    14.N    15.O    16.P");
          Serial.println("17.Q    18.R    19.S    20.T    21.U    22.V    23.W    24.X");
          Serial.println("25.Y    26.Z");
          Serial.println("Por favor digite los numeros correspondientes");
          Serial.println("a las letras que quiere mostrar en cada uno de los patrones");
          n=new int [num];//Apuntador con memoria dinamica
          delay(10000);
          for (int i=0; i<num; i++){
             Serial.print("Patron numero ");
             Serial.println(i+1);
             delay(10000);
             while (Serial.available()>0)
                n[i]=Serial.parseInt();//Se suma cada numero a una posicion de la variable
           }
          Serial.println("Ahora debera ver la animacion");
          while(times<5){
            for(int i=0; i<num; i++){
              letters(n[i], t);//Se envia a la funcion Letters cada posicion de n para crear la animacion de letras
            }
            times++;//Variable que suma 1, sirve para que la animacion se repita cinco veces
          }
          delete[] n;//Se libera el espacio de esta variable
        }
      }  
  
}
//Funcion que muestra el menu de opciones
void loop(){
        Chs=0;//Se utiliza para guardar el numero que digito el usuario para el menu principal
        Serial.println("Bienvenido");
        Serial.println("Digite 1 para verificar que todos los leds funcionan correctamente");
        Serial.println("Digite 2 para mostrar un solo patron");
        Serial.println("Digite 3 para mostrar una serie de patrones");
        delay(10000);
  		while (Serial.available()>0){
          Chs= Serial.parseInt();
          if (Chs==1)
            verificacion();
          else if (Chs==2)
            imagen(opcion);
          else if (Chs==3)
            publik(opcion, num, time);
        }
  }