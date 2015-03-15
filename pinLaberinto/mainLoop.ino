void loop(){
  velocidadGlobal = velocidad2;
  asignaErrores();
//  getDistancia(pinTrigFront, pinEchoFront);
  long uFront = getDistancia(pinTrigFront, pinEchoFront);
  //long uBack = getDistancia(pinTrigBack, pinEchoBack);
  long uIzq = getDistancia(pinTrigIzq, pinEchoIzq);  
  long uDer = getDistancia(pinTrigDer, pinEchoDer);
  int Rango = getRango(uIzq,uDer);    
  setCentrar(uIzq, uDer, Rango); 
  porIzquierda(uDer, uIzq, uFront, 0, Rango);
  Serial.print("\t R: ");
  Serial.print(Rango);
  Serial.print(" \t");  
  Serial.print("F: ");
  Serial.print(uFront);
  Serial.print(" mm\t");
  //Serial.print("B: ");
  //Serial.print(uBack);
  //Serial.print(" mm\t"); 
  Serial.print("I: ");
  Serial.print(uIzq);
  Serial.print(" mm\t");
  Serial.print("D: ");
  Serial.print(uDer);
  Serial.println(" mm");
}
