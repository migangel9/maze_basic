void setup()
{
	Serial.begin(115200); //inicia a porta serial 
	//Declara pines de sensores trig salida, echo entrada
	pinMode(pinTrigFront, OUTPUT);
	pinMode(pinEchoFront, INPUT);
	pinMode(pinTrigBack, OUTPUT);
	pinMode(pinEchoBack, INPUT);
	pinMode(pinTrigIzq, OUTPUT);
	pinMode(pinEchoIzq, INPUT);
	pinMode(pinTrigDer, OUTPUT);
	pinMode(pinEchoDer, INPUT);

	//Declara pines de motores
	pinMode(pinMotorIzq1, OUTPUT); 
	pinMode(pinMotorIzq2, OUTPUT); 
	pinMode(pinMotorDer1, OUTPUT); 
	pinMode(pinMotorDer2, OUTPUT); 
   
	//Declara pines del switch
	pinMode(pinSwitch1,INPUT);
	pinMode(pinSwitch2,INPUT);

	//Declara pines del LED
	pinMode(pinLed1,OUTPUT);
	pinMode(pinLed2,OUTPUT);
}
