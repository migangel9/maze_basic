/* Función para medir la longitud del pulso. Regresa cm */
long getDistancia(byte pinTrig, byte pinEcho){
  long distancia;
	long tiempo;
	digitalWrite(pinTrig,LOW); /* Para cuestión de estabilización del sensor*/
	delayMicroseconds(5);
	digitalWrite(pinTrig, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  tiempo = pulseIn(pinEcho, HIGH);  
  distancia = int(0.017 * tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/
  // distancia = (tiempo /2.9) / 2; // Cálculos en milímetros
  // distancia = (tiempo /29) / 2; // Cálculos en centímetros
  // distancia = ((float(tiempo/1000.0))*34.32)/2;  	
  // distance= tiempo * 0.0001657;
  return distancia; 
}

/* Funcion para ir en el centro del sendero */
void setCentrar(long uIzq, long uDer){  
  if (uIzq < rangoAceptable){
    giraDerecha();
  }
  if (uDer < rangoAceptable){
    giraIzquierda(); 
  }
}

/* Funcion para girar por tempo la direccion q se indique TRUE=derecha ; FALSE=izq;*/
void girar(short time, boolean direccion, byte velocidad){///
  unsigned long actual;
  actual = millis();
  if(direccion == true){  // girar a la derecha
    giraMotor(true, velocidad);
    giraMotor(false, velocidad);
  }
  else{  // girar a la izquierda
    giraMotor(true, velocidad);
    giraMotor(false, velocidad);
  }
  for(;;){
    if((millis() - actual) > time){
      break;
    }
  }
}

/*Funcion para girar motor*/
void giraMotor(byte pinMotor1, pinMotor2, boolean direccion, byte velocidad) {
  if(direccion == true){   //gira a la derecha
    analogWrite(pinMotor1, 0);
    analogWrite(pinMotor2, velocidad);
  }
  else{  //gira a la izqquierdar
    analogWrite(pinMotor1, velocidad);
    analogWrite(pinMotor2, 0);
  }
}

/*Funcion para parar Motor*/
void paraMotor(byte pinMotor1,byte pinMotor2) {
  analogWrite(pinMotor1, 0);
  analogWrite(pinMotor2, 0);
}

/*Funcion Basica Busca por Izquierda: Siempre decidira ir por el lado izquierdo*/
void porIzquierda(long uDer, long uIzq, long uFront, long uBack){
  // vuelta 90° a la izq (No hay salida mas que a la izq)
  if (uFront <= rangoAceptable && uIzq > rangoAceptable){
    girar(giro90, FALSE, velocidadGlobal);
  }
  // vuelta 90° a la der (No hay salida mas que a la der)
  if (uFront <= rangoAceptable && uDer > rangoAceptable){
    girar(giro90, TRUE, velocidadGlobal);
  }
  // Encontro dos caminos libres izq y der, gira por izq
  if (uIzq && uDer > rangoAceptable && uFront < rangoAceptable){
    girar(giro90, FALSE, velocidadGlobal);
  }
  // Encontro tres caminos libres izq y der, gira por izq
  if (uIzq && uDer && uFront > rangoAceptable){
    girar(giro90, FALSE, velocidadGlobal);
  }
  // Camino cerrado
  if (uIzq && uDer && uFront > rangoAceptable){
    girar(giro180, FALSE, velocidadGlobal);
  }
}

/*Funcion Basica Busca por derecha: Siempre decidira ir por el lado izquierdo*/
void porDerecha(long uDer, long uIzq, long uFront, long uBack){
  // vuelta 90° a la izq (No hay salida mas que a la izq)
  if (uFront <= rangoAceptable && uIzq > rangoAceptable){
    girar(giro90, FALSE, velocidadGlobal);
  }
  // vuelta 90° a la der (No hay salida mas que a la der)
  if (uFront <= rangoAceptable && uDer > rangoAceptable){
    girar(giro90, TRUE, velocidadGlobal);
  }
  // Encontro dos caminos libres izq y der, gira por der
  if (uIzq && uDer > rangoAceptable && uFront < rangoAceptable){
    girar(giro90, TRUE, velocidadGlobal);
  }
  // Encontro tres caminos libres izq y der, gira por der
  if (uIzq && uDer && uFront > rangoAceptable){
    girar(giro90, TRUE, velocidadGlobal);
  }
  // Camino cerrado
  if (uIzq && uDer && uFront > rangoAceptable){
    girar(giro180, TRUE, velocidadGlobal);
  }
}