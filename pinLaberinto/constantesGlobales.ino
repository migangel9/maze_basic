// Constantes de velocidad
#define velocidad1 140
#define velocidad2 70

//Constantes de control
#define KP 1
#define KI 0 
#define KD 0

//Constante de rango en cm
#define rangoMenos 30
#define rangoLimite 25
#define rangoMas 80
#define rangoSuperior 100

#define rango6 5
#define rango5 10
#define rango4 15
#define rango3 20



//Constantes de giro
#define giro180 342
#define giro90  160

//Constantes de ERROR
#define PORCENTAJE_ERR1  0.5
#define PORCENTAJE_ERR2  0.3
#define PORCENTAJE_ERR3  0.1
#define PORCENTAJE_ERR0  0
#define PORCENTAJE_ERR5  -0.1
#define PORCENTAJE_ERR6  -0.3
#define PORCENTAJE_ERR7  -0.5

/* Variables Globales */

//variables de control
float Err=0;
float PreErr=0;
float Integral=0;
float Derivativo=0;
float pid = 0;
byte velocidadGlobal;

float Err1; 
float Err2;
float Err3;
float Err0;
float Err5;
float Err6;
float Err7;
