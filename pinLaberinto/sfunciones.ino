/* Función para medir la longitud del pulso. Regresa cm */
long getDistancia(byte pinTrig, byte pinEcho){
  long distancia;
	long tiempo;
	digitalWrite(pinTrig,LOW); /* Para cuestión de estabilización del sensor*/
	delayMicroseconds(5);
	digitalWrite(pinTrig, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  tiempo = pulseIn(pinEcho, HIGH);  
  /*fórmula para calcular la distancia obteniendo un valor entero*/
  distancia = (tiempo / 2.9) / 2; // Cálculos en milímetros
  // distancia = (tiempo /29) / 2; // Cálculos en centímetros
  // distancia = ((float(tiempo/1000.0))*34.32)/2;  	
  // distance= tiempo * 0.0001657;
  // distancia = int(0.017 * tiempo); 
  return distancia; 
}

/* Funcion para calcular el rango  sesorIzq + sensorDer / 2 */
int getRango(int uIzq, int uDer){  
  return ((uIzq + uDer) / 2); 
}

/* Funcion para ir en el centro del sendero */
void setCentrar(long uIzq, long uDer, int Rango){  
  if (uIzq < rangoLimite){    
    digitalWrite(pinLed1,HIGH);
    girarPID(uIzq, uDer, Rango);
  }
  else if (uDer < rangoLimite){    
    digitalWrite(pinLed2,HIGH);    
    girarPID(uIzq, uDer, Rango);
  }
  else{
    //girarPID();  
    digitalWrite(pinLed1,LOW);
    digitalWrite(pinLed2,LOW);
    girarPID(uIzq, uDer, Rango);
  }
}

/* Funcion para ir en el centro del sendero */
void girarPID(long uIzq, long uDer, int Rango){ 
  float velocidadDer = 0;   
  float velocidadIzq = 0;

  if (uIzq <= (Rango - rango6) && uIzq >= (Rango - rango5)){
    Err = Err3;
  }
  else if (uIzq <= (Rango - rango5) && uIzq >= (Rango - rango4)){
    Err = Err2;
  }
  else if (uIzq <= (Rango - rango4) && uIzq >= (Rango - rango3)){
    Err = Err1;
  }
  else if (uDer <= (Rango - rango6) && uDer >= (Rango - rango5)){
    Err = Err5;
  }
  else if (uDer <= (Rango - rango5) && uDer >= (Rango - rango4)){
    Err = Err6;
  }
  else if (uDer <= (Rango - rango4) && (Rango - uDer >= rango3)){
    Err = Err7;
  }
  else{
    Err = Err0;
  }

  Integral = Integral + Err;
  Derivativo = Err - PreErr;
  pid = (KP*Err) + (KI*Integral) + (KD*Derivativo);
  PreErr = Err;
  //  delay(2);
  velocidadDer = velocidadGlobal - pid;
  velocidadIzq = velocidadGlobal + pid;

  Serial.print("velocidadDer: ");
  Serial.print(velocidadDer);
  Serial.print("\t velocidadIzq: ");
  Serial.print(velocidadIzq);
  Serial.print("\t PID: ");
  Serial.print(pid);


  if(velocidadIzq < 0){
    analogWrite(pinMotorIzq2, (velocidadIzq * -1));
    analogWrite(pinMotorIzq1, 0);
  }
  else{
    analogWrite(pinMotorIzq2, 0);
    analogWrite(pinMotorIzq1, velocidadIzq);
  }  
  if(velocidadDer < 0){
    analogWrite(pinMotorDer2, (velocidadDer * -1));
    analogWrite(pinMotorDer1, 0);
  }
  else{
    analogWrite(pinMotorDer2, 0);
    analogWrite(pinMotorDer1, velocidadDer);
  }
}


/* Funcion para girar por tempo la direccion q se indique true=derecha ; false=izq;*/
void girar(short limiteTiempo, boolean direccion, byte velocidad){///
  unsigned long actual;
  actual = millis();
  if(direccion == true){  // girar a la derecha
    giraMotor(pinMotorIzq1, pinMotorIzq2, true, velocidad);
    giraMotor(pinMotorDer1, pinMotorDer2, false, velocidad);
  }
  else{  // girar a la izquierda
    giraMotor(pinMotorIzq1, pinMotorIzq2, false, velocidad);
    giraMotor(pinMotorDer1, pinMotorDer2, true, velocidad);
  }
  for(;;){
    if((millis() - actual) > limiteTiempo){
       paraMotores();
       break;
    }
  }
}

void paraMotores() {
  analogWrite(pinMotorIzq1, 0);
  analogWrite(pinMotorIzq2, 0);
  analogWrite(pinMotorDer1, 0);  
  analogWrite(pinMotorDer2, 0);
}


/*Funcion para girar motor*/
void giraMotor(byte pinMotor1, byte pinMotor2, boolean direccion, byte velocidad) {
  if(direccion == true){   //gira a la derecha
    analogWrite(pinMotor1, velocidad);
    analogWrite(pinMotor2, 0);
  }
  else{  //gira a la izqquierdar
    analogWrite(pinMotor1, 0);
    analogWrite(pinMotor2, velocidad);
  }
}

/*Funcion para parar Motor*/
void paraMotor(byte pinMotor1,byte pinMotor2) {
  analogWrite(pinMotor1, 0);
  analogWrite(pinMotor2, 0);
}

/*Funcion Basica Busca por Izquierda: Siempre decidira ir por el lado izquierdo*/
void porIzquierda(long uDer, long uIzq, long uFront, long uBack, int Rango){
  // vuelta 90° a la izq (No hay salida mas que a la izq)
 /* if (uFront <= rangoLimite && uIzq >= rangoSuperior){
    delay(2000);
    girar(giro90, false, velocidad1);
    delay(2000);
  }
  // vuelta 90° a la der (No hay salida mas que a la der)
  if (uFront <= rangoLimite && uDer >= rangoSuperior){
    delay(2000);
    girar(giro90, true, velocidad1);
    delay(2000);
  }
  // Encontro dos caminos libres izq y der, gira por izq
  if (uIzq && uDer >= rangoSuperior && uFront <= rangoLimite){
    delay(2000);
    girar(giro90, false, velocidad1);
    delay(2000);
  }
  // Encontro tres caminos libres izq y der, gira por izq
  if (uIzq && uDer && uFront >= rangoSuperior){
    delay(2000);
    girar(giro90, false, velocidad1);
    delay(2000);
  }*/
  // Camino cerrado
  //if (((uIzq && uDer <= Rango) && (uIzq && uDer <= Rango-rango5)) && uFront <= rangoLimite)
  if (uFront <= rangoLimite){
    paraMotores();
    delay(2000);
    girar(giro180, false, velocidad1);
    
    delay(2000);
  }
}

/*Funcion Basica Busca por derecha: Siempre decidira ir por el lado izquierdo*/
void porDerecha(long uDer, long uIzq, long uFront, long uBack){
  // vuelta 90° a la izq (No hay salida mas que a la izq)
  if (uFront <= rangoLimite && uIzq > rangoLimite){
    delay(2000);
    girar(giro90, false, velocidadGlobal);
    delay(2000);
  }
  // vuelta 90° a la der (No hay salida mas que a la der)
  if (uFront <= rangoLimite && uDer > rangoLimite){
    delay(2000);
    girar(giro90, true, velocidadGlobal);
    delay(2000);
  }
  // Encontro dos caminos libres izq y der, gira por der
  if (uIzq && uDer > rangoLimite && uFront < rangoLimite){
    delay(2000);
    girar(giro90, true, velocidadGlobal);
    delay(2000);
  }
  // Encontro tres caminos libres izq y der, gira por der
  if (uIzq && uDer && uFront > rangoLimite){
    delay(2000);
    girar(giro90, true, velocidadGlobal);
    delay(2000);
  }
  // Camino cerrado
  if (uIzq && uDer && uFront > rangoLimite){
    delay(2000);
    girar(giro180, true, velocidadGlobal);
    delay(2000);
  }
}

/*Funcion para calcular los errores de acuerdo a la velocidad Global*/
void asignaErrores(){
  Err1 = (velocidadGlobal * PORCENTAJE_ERR1);
  Err2 = (velocidadGlobal * PORCENTAJE_ERR2);
  Err3 = (velocidadGlobal * PORCENTAJE_ERR3);
  Err0 = (velocidadGlobal * PORCENTAJE_ERR0);
  Err5 = (velocidadGlobal * PORCENTAJE_ERR5);
  Err6 = (velocidadGlobal * PORCENTAJE_ERR6);
  Err7 = (velocidadGlobal * PORCENTAJE_ERR7);  
}