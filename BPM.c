const int pot=A0;
int valor=0;
#define tempo (60/15)*1000
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 
}

void loop() {
  // put your main code here, to run repeatedly:
valor=analogRead(pot);
Serial.println(valor);
if(valor>0 && valor<73){//semibreve
 tone(5, 293);
 delay(tempo);
 noTone(5);
 delay(200);
}
if(valor>72 && valor<145){//minima
 tone(5, 293);
 delay(tempo/2);
 noTone(5);
 delay(200);
}

if(valor>144 && valor<217){//seminima
 tone(5, 293);
 delay(tempo/4);
 noTone(5);
 delay(200);
}

if(valor>216 && valor<289){//colcheia
 tone(5, 293);
 delay(tempo/8);
 noTone(5);
 delay(200);
}

 if(valor>288 && valor<361){//semicolcheia
 tone(5, 293);
 delay(tempo/16);
 noTone(5);
 delay(200);
}

 if(valor>360 && valor<433){//fusa
 tone(5, 293);
 delay(tempo/32);
 noTone(5);
 delay(200);
 }

 if(valor>432 && valor<502){//semifusa
 tone(5, 293);
 delay(tempo/64);
 noTone(5);
 delay(200);
 }


 }
