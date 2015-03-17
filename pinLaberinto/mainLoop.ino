void loop(){  
  //getDistancia(pinTrigFront, pinEchoFront);
  
    long uFront = getDistancia(pinTrigFront, pinEchoFront);
    //long uBack = getDistancia(pinTrigBack, pinEchoBack);
    long uIzq = getDistancia(pinTrigIzq, pinEchoIzq);  
    long uDer = getDistancia(pinTrigDer, pinEchoDer);    

    setCentrar(uIzq, uDer); 
    //porIzquierda(uDer, uIzq, uFront, 0);
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

void inicializar(){
  velocidadGlobal = velocidad2;
  asignaErrores();  
  long uIzq;
  long uDer;
  
    uIzq = getDistancia(pinTrigIzq, pinEchoIzq);  
    uDer = getDistancia(pinTrigDer, pinEchoDer);
  
  //Rango = getRango(uIzq,uDer);      
  Rango = 70;
}