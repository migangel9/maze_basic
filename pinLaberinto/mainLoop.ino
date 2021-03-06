void loop(){    
    estabilizar();
    for(;;){
      long uFront = getDistancia(pinTrigFront, pinEchoFront);      
      //long uBack = getDistancia(pinTrigBack, pinEchoBack);
      long uIzq = getDistancia(pinTrigIzq, pinEchoIzq);        
      long uDer = getDistancia(pinTrigDer, pinEchoDer);          
      //uIzq = uIzq - 20;
      uDer = uDer - 20;
      setCentrar(uIzq, uDer);       
      if(vaPorIzquierda){
        porIzquierda(uDer, uIzq, uFront, 0);        
      }      
      else if (vaPorDerecha){
        porDerecha(uDer, uIzq, uFront, 0);
      }

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
}

void inicializar(){
  leeSwitch();
  velocidadGlobal = velocidad2;
  asignaErrores();  
  long uIzq;
  long uDer;
  
    uIzq = getDistancia(pinTrigIzq, pinEchoIzq);  
    uDer = getDistancia(pinTrigDer, pinEchoDer);
    
  //Rango = getRango(uIzq,uDer);      
  Rango = 50;  
}