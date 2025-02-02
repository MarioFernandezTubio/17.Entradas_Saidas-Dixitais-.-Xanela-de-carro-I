/* 

Cando prememos unha vez, o pulsador activa un motor 
que move o vidro cara arriba; ao premer unha segunda vez, 
o pulsador activa outro motor que move o vidro cara abaixo.
Cada un dos motores para ao estar aceso 7 segundos.

*/

#define UP 7
#define DOWN 6
#define BOTON 13

bool pulsa = 0;
int contador = -1;

bool estado = 0;                 /* Por defecto,
								    a xanela está abaixo*/

void setup()
    
{
  pinMode(BOTON, INPUT);         // Pulsador 1 no pin 13

  pinMode(UP, OUTPUT);           // Subir vidro
  pinMode(DOWN, OUTPUT);         // Baixar vidro
  Serial.begin(9600);			 // Pra ver o Monitor Serie
}

void loop(){
  
/*************** Comprobamos o PULSADOR. ****************/
  
  pulsa = digitalRead(BOTON);    // Miro se o botón está pulsado.
 
  if ( pulsa == true ){          // Se o botón se pulsa...
 
    estado = !estado;            // Alternamos estado do pulsador
    
   while(digitalRead(BOTON)){ 
      delay(20);                 /* Aseguro unha única lectura.
      							    Por eso lle poño unha espera de 20ms 
							        entre lecturas de pulsación.*/
    }
          
    digitalWrite(UP, estado);    // Sube o vidro.
    digitalWrite(DOWN,!estado);  // Ordenamos que o vidro non baixe.
    contador = 700;              // Tempo que dura subindo ou baixando o vidro.
    
  }
  
  
/************** Cancelamos a Marcha dos Motores. ***************/
  
  if ( contador > 0 ){           // Se o contador é maior a "0".
    
    contador -= 1;			     // Desconta 1 segundo.                           
  
  } else{
    digitalWrite(UP, LOW);       // Para de subir.
    digitalWrite(DOWN, LOW);     // Para de baixar.
    }
  
  
/********************  Monitor Serie  ********************/
  Serial.print(estado); Serial.print("  "); Serial.println(contador);
}
