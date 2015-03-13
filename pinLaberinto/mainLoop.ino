void loop(){
//  getDistancia(pinTrigFront, pinEchoFront);
  long uFront = getDistancia(pinTrigFront, pinEchoFront);
  long uBack = getDistancia(pinTrigBack, pinEchoBack);
  long uIzq = getDistancia(pinTrigIzq, pinEchoIzq);
  long uDer = getDistancia(pinTrigDer, pinEchoDer);
 
 /* Serial.print("F: ");
  Serial.print(Ufront);
  Serial.print(" cm\t");
  Serial.print("B: ");
  Serial.print(Uback);
  Serial.print(" cm\t"); 
  Serial.print("I: ");
  Serial.print(Uizq);
  Serial.print(" cm\t");
  Serial.print("D: ");
  Serial.print(Uder);
  Serial.println(" cm");
  */

  delay(50);
}
