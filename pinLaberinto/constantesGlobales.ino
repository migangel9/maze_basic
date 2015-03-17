// Constantes de velocidad
#define velocidad1 140
#define velocidad2 50

//Constantes de control
//#define KP 0.20
//#define KD 1.5
//#define KI 0.000001 
#define KP 0.20
#define KD 1.5
#define KI 0

//Constante de rango en cm
#define rangoMenos 30
#define rangoLimite 35
#define rangoMas 80
#define rangoSuperior 100

#define rango1 5
#define rango2 10
#define rango3 15
#define rango4 20
#define rango5 25
#define rango6 30
#define rango7 35
#define rango8 40
#define rango9 45
#define rango10 50


//Constantes de giro
#define giro180 342
#define giro90  160

//Constantes de ERROR
#define PORCENTAJE_ERR1  1
#define PORCENTAJE_ERR2  0.9
#define PORCENTAJE_ERR3  0.8
#define PORCENTAJE_ERR4  0.7
#define PORCENTAJE_ERR5  0.6
#define PORCENTAJE_ERR6  0.5
#define PORCENTAJE_ERR7  0.4
#define PORCENTAJE_ERR8  0.3
#define PORCENTAJE_ERR9  0.2
#define PORCENTAJE_ERR10 0.1
#define PORCENTAJE_ERR0  0
#define PORCENTAJE_ERR11 -0.1
#define PORCENTAJE_ERR12 -0.2
#define PORCENTAJE_ERR13 -0.3
#define PORCENTAJE_ERR14 -0.4
#define PORCENTAJE_ERR15 -0.5
#define PORCENTAJE_ERR16 -0.6
#define PORCENTAJE_ERR17 -0.7
#define PORCENTAJE_ERR18 -0.8
#define PORCENTAJE_ERR19 -0.9
#define PORCENTAJE_ERR20 -1



/* Variables Globales */

//variables de control
float Err = 0;
float PreErr = 0;
float Integral = 0;
float Derivativo = 0;
float pid = 0;
byte velocidadGlobal;

float Err1; 
float Err2;
float Err3;
float Err4;
float Err5;
float Err6;
float Err7;
float Err8; 
float Err9;
float Err10;
float Err11;
float Err12;
float Err13;
float Err14;
float Err15; 
float Err16;
float Err17;
float Err18;
float Err19;
float Err20;
float Err0;


int Rango = 0;
