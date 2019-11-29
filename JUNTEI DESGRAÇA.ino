const int pot=A0;
int soma=0;
int valor=0;
#define tempo (60/90)*1000


int TEMPO(int valor){
 if(valor>0 && valor<73){//semibreve
    return tempo*4;
    }
    if(valor>72 && valor<145){//minima
     return tempo*2;
    }

    if(valor>144 && valor<217){//seminima
     return tempo;
    }

    if(valor>216 && valor<289){//colcheia
     return tempo/2;
    }

    if(valor>288 && valor<361){//semicolcheia
     return tempo/4;
}

    if(valor>360 && valor<433){//fusa
     return tempo/8;
 }

     if(valor>432 && valor<505){//semifusa
      return tempo/16;
     }


    //PAUSAS


    if(valor>504 && valor<577){//pausa da semibreve
     return tempo*4;
     }

     if(valor>576 && valor<649){//pausa da minima
     return tempo*2;
     } 
 
     if(valor>648 && valor<721){//pausa da seminima
     return tempo;
     }

     if(valor>720 && valor<793){//pausa da colcheia
     return tempo/2 ;
     }

     if(valor>792 && valor<865){//pausa da semicolcheia
     return tempo/4;
     }

     if(valor>576 && valor<649){//pausa da fusa
     return tempo/8;
     }
     
     if(valor>576 && valor<649){//pausa da semifusa
     return tempo/16;
    }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);

  Serial.begin(9600);
 
}

void lerLinha(int vetor[2][3], int pot){
    int portas[3] = {A0, A1, A2};
    for (int i = 0; i < 3; ++i)
    {
        vetor[pot][i] = analogRead(portas[i]);
    }
}

int lerPartitura(int matriz[2][3]){
    for(int c=0;c<2;c++){
      digitalWrite(2,0);
      digitalWrite(3,0);
      digitalWrite(c+2,1);
      //]soma+=TEMPO(analogRead(A));
      lerLinha(matriz, c);
    }
    /*if(soma>tempo*4){
        Serial.println("ta errado mermao");
        return 0;
    } 
    return 1;*/
}

void loop() {
    int partitura[2][3];
    lerPartitura(partitura);
    
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
           Serial.print("Coluna: ");Serial.print(i);
           Serial.print('\n');
           Serial.print("Linha: " ); Serial.println(j);
           Serial.println(partitura[i][j]);
           Serial.print('\n');
           Serial.print('\n');
           delay(1500);
        }
    }
  
  }
 
