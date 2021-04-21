/*
Este programa enciende los leds formando las letras del abecedario

Letras del abecedario con sus respectivos 
numeros hexagecimales que permiten prender los leds
de forma correcta
*/
unsigned A[8]= {0x3C, 0x7E, 0x66, 0x66, 0x7E, 0x7E, 0x66, 0x66};
unsigned B[8]= {0x7C, 0X7E, 0X66, 0X7C, 0X7C, 0X66, 0X7E, 0X7C};
unsigned C[8]= {0x3C, 0x7E, 0X62, 0X60, 0X60, 0X62, 0X7E, 0X3C};
unsigned D[8]= {0x78, 0x7C, 0X66, 0X66, 0X66, 0X66, 0X7C, 0X78};
unsigned E[8]= {0x3C, 0x7E, 0X60, 0X7E, 0X7E, 0X60, 0X7E, 0X3C};
unsigned F[8]= {0x7E, 0x7E, 0X60, 0X7E, 0X7E, 0X60, 0X60, 0X60};
unsigned G[8]= {0x3C, 0x7E, 0X60, 0X6E, 0X6E, 0X66, 0X7E, 0X3C};
unsigned I[8]= {0x7E, 0x7E, 0X18, 0X18, 0X18, 0X18, 0X7E, 0X7E};
unsigned H[8]= {0x66, 0x66, 0x66, 0x7E, 0x7E, 0x66, 0x66, 0x66};
unsigned J[8]= {0x7E, 0x7E, 0X18, 0X18, 0X18, 0X18, 0X78, 0X78};
unsigned K[8]= {0x63, 0x66, 0x6C, 0x78, 0x78, 0x6C, 0x66, 0x63};
unsigned L[8]= {0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x7E, 0x7E};
unsigned M[8]= {0x42, 0x66, 0x7E, 0x66, 0x66, 0x66, 0x66, 0x66};
unsigned N[8]= {0x00, 0x43, 0x63, 0x73, 0x6B, 0x67, 0x63, 0x00};
unsigned O[8]= {0x3C, 0x7E, 0x66, 0x66, 0x66, 0x66, 0x7E, 0x3C};
unsigned P[8]= {0x3C, 0x7E, 0x66, 0x7E, 0x78, 0x60, 0x60, 0x60};
unsigned Q[8]= {0x7E, 0xC3, 0xD3, 0xCB, 0XC7, 0X7E, 0X01, 0X00};
unsigned R[8]= {0x3C, 0x7E, 0x62, 0x62, 0x7C, 0x70, 0x6C, 0x66};
unsigned S[8]= {0x3C, 0x7E, 0x64, 0x7E, 0x3E, 0x46, 0x7E, 0x3C};
unsigned T[8]= {0x7E, 0x7E, 0X18, 0X18, 0X18, 0X18, 0X18, 0X18};
unsigned U[8]= {0x24, 0x66, 0x66, 0x66, 0x66, 0x66, 0x7E, 0x3C};
unsigned V[8]= {0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x18};
unsigned W[8]= {0x5A, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xFF, 0x66};
unsigned X[8]= {0x00, 0x66, 0x66, 0x3C, 0x18, 0x3C, 0x66, 0x66};
unsigned Y[8]= {0x6C, 0x6C, 0x6C, 0x3C, 0x1C, 0x4C, 0x7C, 0x38};
unsigned Z[8]= {0x7E, 0x7E, 0x06, 0x0C, 0x18, 0x30, 0x7E, 0x7E};
unsigned int pines[3]= {11, 12, 13};//Arreglo para pines digitales
//Tiempo para encender de un led al siguiente
#define TIEMPO 1000

void leds(int F1, int F2, int F3, int F4, int F5, int F6, int F7, int F8){
//Funcion que recibe numeros hexagecimales y los envia a cada fila de leds
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
 Serial.begin(9600);
}

void loop(){
//Funcion para encender los leds en forma de letras
  leds(A[0], A[1], A[2], A[3], A[4], A[5], A[6], A[7]);
  leds(B[0], B[1], B[2], B[3], B[4], B[5], B[6], B[7]);
  leds(C[0], C[1], C[2], C[3], C[4], C[5], C[6], C[7]);
  leds(D[0], D[1], D[2], D[3], D[4], D[5], D[6], D[7]);
  leds(E[0], E[1], E[2], E[3], E[4], E[5], E[6], E[7]);
  leds(F[0], F[1], F[2], F[3], F[4], F[5], F[6], F[7]);
  leds(G[0], G[1], G[2], G[3], G[4], G[5], G[6], G[7]);
  leds(H[0], H[1], H[2], H[3], H[4], H[5], H[6], H[7]);
  leds(I[0], I[1], I[2], I[3], I[4], I[5], I[6], I[7]);
  leds(J[0], J[1], J[2], J[3], J[4], J[5], J[6], J[7]);
  leds(K[0], K[1], K[2], K[3], K[4], K[5], K[6], K[7]);
  leds(L[0], L[1], L[2], L[3], L[4], L[5], L[6], L[7]);
  leds(M[0], M[1], M[2], M[3], M[4], M[5], M[6], M[7]);
  leds(N[0], N[1], N[2], N[3], N[4], N[5], N[6], N[7]);
  leds(O[0], O[1], O[2], O[3], O[4], O[5], O[6], O[7]);
  leds(P[0], P[1], P[2], P[3], P[4], P[5], P[6], P[7]);
  leds(Q[0], Q[1], Q[2], Q[3], Q[4], Q[5], Q[6], Q[7]);
  leds(R[0], R[1], R[2], R[3], R[4], R[5], R[6], R[7]);
  leds(S[0], S[1], S[2], S[3], S[4], S[5], S[6], S[7]);
  leds(T[0], T[1], T[2], T[3], T[4], T[5], T[6], T[7]);
  leds(U[0], U[1], U[2], U[3], U[4], U[5], U[6], U[7]);
  leds(V[0], V[1], V[2], V[3], V[4], V[5], V[6], V[7]);
  leds(W[0], W[1], W[2], W[3], W[4], W[5], W[6], W[7]);
  leds(X[0], X[1], X[2], X[3], X[4], X[5], X[6], X[7]);
  leds(Y[0], Y[1], Y[2], Y[3], Y[4], Y[5], Y[6], Y[7]);
  leds(Z[0], Z[1], Z[2], Z[3], Z[4], Z[5], Z[6], Z[7]);
  
}
