// Constantes de velocidad
#define velocidad1 80
#define velocidad2 100

//Constantes de control
#define KP 1
#define KI 0 
#define KD 0

//Constante de rango en cm
#define rangoMenos 2
#define rangoAceptable 5
#define rangoMas 8

//Constantes de giro
#define giro180 342
#define giro90  160


/* Variables Globales */

//variables de control
float Err=0;
float PreErr=0;
float Integral=0;
float Derivativo=0;

byte velocidadGlobal;
