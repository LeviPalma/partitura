const int pot=A0;
int valor=0;
#define tempo (60/90)*1000

void TEMPO(int valor){
 if(valor>0 && valor<73){//semibreve
     tone(5, 293);
     delay(tempo*4);
     noTone(5);
     delay(200);
    }
    if(valor>72 && valor<145){//minima
     tone(5, 293);
     delay(tempo*2);
     noTone(5);
     delay(200);
    }

    if(valor>144 && valor<217){//seminima
     tone(5, 293);
     delay(tempo);
     noTone(5);
     delay(200);
    }

    if(valor>216 && valor<289){//colcheia
     tone(5, 293);
     delay(tempo/2);
     noTone(5);
     delay(200);
    }

 if(valor>288 && valor<361){//semicolcheia
     tone(5, 293);
     delay(tempo/4);
     noTone(5);
     delay(200);
}

     if(valor>360 && valor<433){//fusa
     tone(5, 293);
     delay(tempo/8);
     noTone(5);
     delay(200);
 }

     if(valor>432 && valor<505){//semifusa
     tone(5, 293);
     delay(tempo/16);
     noTone(5);
     delay(200);
     }


    //PAUSAS


    if(valor>504 && valor<577){//pausa da semibreve
     delay(tempo*4);
     delay(200);
     }

     if(valor>576 && valor<649){//pausa da minima
     delay(tempo*2);
     delay(200);
     } 
 
     if(valor>648 && valor<721){//pausa da seminima
     delay(tempo);
     delay(200);
     }

     if(valor>720 && valor<793){//pausa da colcheia
     delay(tempo/2);
     delay(200);
     }

     if(valor>792 && valor<865){//pausa da semicolcheia
     delay(tempo/4);
     delay(200);
     }

     if(valor>576 && valor<649){//pausa da fusa
     delay(tempo/8);
     delay(200);
     }
     
     if(valor>576 && valor<649){//pausa da semifusa
     delay(tempo/16);
     delay(200);
    }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 
}

void loop() {
  // put your main code here, to run repeatedly:
    int valor;
    int valor=analogRead(pot);
TEMPO(valor);
//   
}





//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*
Funcao getValues :
    Por padrao utiliza a porta Analogica A0 e as portas Digitais 2-5 (2 ate 5), podendo ser alteradas 
com a passagem de parametros.
Por nao suportar a declarao incial de vetores em parametros, foi utilizado o esquema a seguir:
    
    getValues(analog_values, analog_port, 2, 3, 4, 5);
    
    analog_values -> vetor passado por referencia para ser editado dentro da funcao. Ele recebera os valores de cada posicao 
        do demux.
    
    analog_port -> porta analogica que ira se usada para a leitura.
    Depois da passagem desses parametros, a seguir vem a passagem das portas digitais separadas por virgula.
      ... 2, 3, 4, 5 ...
      respectivamente as entradas do demux S0, S1, S1, S3.
*/

void getValues(int analog_values[],int analog_port = A0, int digital_one = 2, int digital_two = 3, int digital_three = 4, int digital_four = 5 ){
  //int analog_values[16] = {0};

  int digital_ports[4] = {digital_one, digital_two, digital_three, digital_four};

  int values[16][4]  = {{0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},{0,1,0,0},{0,1,0,1},{0,1,1,0},{0,1,1,1},{1,0,0,0},{1,0,0,1},{1,0,1,0},{1,0,1,1},{1,1,0,0},{1,1,0,1},{1,1,1,0},{1,1,1,1}};
  
  for( int position_values = 0; position_values<16; position_values++ ){

    for( int position_digital = 0; position_digital < 4; position_digital++ ){

      digitalWrite(digital_ports[position_digital], values[position_values][position_digital]);
    }

    analog_values[position_values] = analogRead(analog_port);
  }

}

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int values[16] = {0};
  getValues(values);
for(int i =0; i<16; i++){
  Serial.print("Na posicao ");Serial.print(i);Serial.print(" tem o valor : ");Serial.println(values[i]);

  delay(50);
}
}
