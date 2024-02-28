/*Variante de examen parcial 1, Caso practico
*/

//librerias usadas en c++ para diferentes funciones dentro del programa
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <iomanip>
//esto nos permite poder usar datos como cout cin sin el nombre largo
using namespace std;

#define NUMERO_ALUMNOS 5
#define NUMERO_MATERIAS 5
#define NUMERO_NOTAS 4
#define MAX_CALIFICACION 100
#define MIN_CALIFICACION 0
#define MAXIMA_LONGITUD_CADENA 100
//declaraion de funciones:
void llamaCiclo();//llamara al ciclo

int busquedaAleatorios(int minimo, int maximo);//funcion de retorno entero de busqueda de numeros aleatorios
void llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1]);//funcion sin retorno para llenar matriz
void imprimirMatrizLinea();//funcion sin retorno para imprimir lineas
//funcion para imprimir MaTriz
float imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1], char alumnos[NUMERO_ALUMNOS][MAXIMA_LONGITUD_CADENA], string nombreFacultad);

//funcion para iniciar el programa y retornarlo
int main()
{
    srand(getpid());//funcion para generar datos randoms y que nos ayude con la funcion de busquedaAleatorios
    llamaCiclo();//llama a la funcion ciclo
    return 0;
}//fin del ciclo main

//la funcionCiclo no retorna datos pero si va a tener procesos de datos
void llamaCiclo()
{

    //delaracion de las tres matrices de INCISO 1
    float matriz_facultad_1[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    float matriz_facultad_2[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    float matriz_facultad_3[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    //declaracion de variabla caracter opcion
    char opcion;
    //declaracion de variable booleana, inicida en veradero
    bool repetir = true;
    //declaracion de variables decimales para el promedio de las 3 facultades
    float promedio_facultad_1;
    float promedio_facultad_2;
    float promedio_facultad_3;
    //declaracion e inicializacion de matriz alumnos
    /*En esta seccion me parecio interesante como se crea una variable de tipo char
    ya que inicamos que vamos a tener NUMERO_ALUMNOS=5 filas con 5 alumnos
    y la MAXIMA_LONGITUD_CADENA nos indicara cuantos caracteres tendra nuestros nombres, en este caso 100
    */
    char alumnos[NUMERO_ALUMNOS][MAXIMA_LONGITUD_CADENA] = {"Rocio","Kevin","Mar","Lucas","Pablito"};

    //ciclo do para pedir el proceso cuantas veces desee
    do
    {
        //esta funcion en mi entedimiento es de limpiar pantalla
        system("cls");
        //inicializacion de promedios en 0 para que funcionen las variables
        promedio_facultad_1=0;
        promedio_facultad_2=0;
        promedio_facultad_3=0;
        //un mini titulo con dos saltos de linea
        cout << "*** Comparativo de Facultades ***" << endl << endl;
        //llamado a la funcion de llenarMatriz junto a su argumento de primera facultad
        llenarMatriz(matriz_facultad_1);
        //esta hara el promedio de la primera facultad, pidiendo por argumentos la matriz, los alumnos que tambien son matriz y un string con su nombre respectivo
        promedio_facultad_1 = imprimirMatriz(matriz_facultad_1, alumnos, "Facultad de Ingenieria");

        //llamado a la funcion de llenarMatriz junto a su argumento de segunda facultad
        llenarMatriz(matriz_facultad_2);
        //esta hara el promedio de la segunda facultad, pidiendo por argumentos la matriz, los alumnos que tambien son matriz y un string con su nombre respectivo
        promedio_facultad_2 = imprimirMatriz(matriz_facultad_2, alumnos, "Facultad de Arquitectura");

        //llamado a la funcion de llenarMatriz junto a su argumento de tercera facultad
        llenarMatriz(matriz_facultad_3);
        //esta hara el promedio de la tercera facultad, pidiendo por argumentos la matriz, los alumnos que tambien son matriz y un string con su nombre respectivo
        promedio_facultad_3 = imprimirMatriz(matriz_facultad_3, alumnos, "Facultad de Derecho");


        //este es un estructura de control con la cual podremos saber quien tiene el mejor o peor promedio
        if (promedio_facultad_1 > promedio_facultad_2 && promedio_facultad_1 > promedio_facultad_3)
        {
            cout << " La facultad con el mejor promedio es : " << "Facultad de Ingenieria" << " Promedio: " << promedio_facultad_1 << endl;
        } else
        if (promedio_facultad_2 > promedio_facultad_1 && promedio_facultad_2 > promedio_facultad_3)
        {
            cout << " La facultad con el mejor promedio es : " << "Facultad de Arquitectura" << " Promedio: " << promedio_facultad_2 << endl;
        } else
        if (promedio_facultad_3 > promedio_facultad_2 && promedio_facultad_3 > promedio_facultad_1)
        {
            cout << " La facultad con el mejor promedio es : " << "Facultad de Administracion" << " Promedio: " << promedio_facultad_3 << endl;
        } else
        {
            cout << " Algunas facultades tienen el mismo promedio " << endl << endl;

        }

        //aqui tenemos la variable o vigilante que cambia segun se ingrese en pantall
        cout << "Desea otro calculo (s/n)? ";
        //ingreso de pantalla
        cin >> opcion;

        //if para ver que opcion pide dar falso a repetir si es de n su respuesta
        if (opcion == 'n')
        {
            repetir=false;
        }
    } while (repetir);//fin del ciclo while
}

//funcion de retorno entero para busqueda de numero alearios, junto a dos argumentos
int busquedaAleatorios(int minimo, int maximo)
{
    //funcion para numero random entre 0 y los que se ingresen a los parametros
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}


//funcion para llenar la Matriz con notas de los alumnos
void llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1])
{
 //declaracion de variables para uso del for
    int y, x;
    for (y = 0; y < NUMERO_ALUMNOS; y++)
    {
        //variable inicializada para la suma que luego se usara en el promedio
        float suma = 0;
        int calificacion = 0;//calificacion total

        //un ciclo for para llenar las notas en numeros aleatorios en base a lo que se ingrese
        for (x = 0; x < NUMERO_NOTAS; x++)
        {
            //para el primer y las actividades
            if (x == 0 || x == 3)  //primer parcial
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 20);//busqueda de aleatorios
            } else if (x == 1)  //segundo parcial
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 25);//busqueda de aleatorios
            } else if (x == 2)  //examen final
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 35);//busqueda de aleatorios
            }
            //variable contador para suma de las calificaciones por aluumnos
            suma += (float)calificacion;
            //llenado de matriz segun sus notas de parcial aleatorios
            matriz[y][x] = calificacion;
            //inicio de nuevo en 0 para nuevas calificaciones del siguiente patojo
            calificacion=0;
        }

        //llenado de matriz para la columna de notas
        matriz[y][NUMERO_NOTAS] = suma;
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//esta imprime la matriz de lineas
void imprimirMatrizLinea()
{
    int x;

    cout << "+--------";
    for (x = 0; x < NUMERO_NOTAS + 1; x++)
    {
        cout << "+---------";
    }
    cout << "+\n";//salto para cada nueva linea
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//funcion para imprimir la matiz en pantalla, usando las notas matriz, alumnos matriz y el nombre de facultad
float imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1], char alumnos[NUMERO_ALUMNOS][MAXIMA_LONGITUD_CADENA], string nombreFacultad)
{
    //Funciòn que imprime la matriz en pantalla y realizando los calculos necesarios del promedio
    int y, x;
    //declaracion de variables con inicializacion en matrices
    float promedioMayor = matriz[0][NUMERO_NOTAS];
    float promedioMenor = matriz[0][NUMERO_NOTAS];
    //variables declaradas en 0
    float totalGeneral = 0;
    float promedioGeneral = 0;
    //variables de char, vectores
    char alumnoPromedioMayor[MAXIMA_LONGITUD_CADENA];
    char alumnoPromedioMenor[MAXIMA_LONGITUD_CADENA];

    //esta funcion me permite traer de memoria los datos ingresados anteriormene
    memcpy(alumnoPromedioMayor, alumnos[0], MAXIMA_LONGITUD_CADENA);
    memcpy(alumnoPromedioMenor, alumnos[0], MAXIMA_LONGITUD_CADENA);
    cout << nombreFacultad << endl;
    cout << "Parcial:   Primero    Segundo    Final     Actividades" << endl;
    imprimirMatrizLinea();

    //imprime los alunmos
    cout << setw(9) << "Alumno";
    for (x = 0; x < NUMERO_NOTAS; x++)
    {
        cout << setw(9) << "Parcial" << x + 1;
    }
    cout << setw(8) << "Total" << endl;
    imprimirMatrizLinea();

    //imprime notas
    for (y = 0; y < NUMERO_ALUMNOS; y++)
    {
        cout << "!" << setw(8) << alumnos[y] << "!";
        float suma = 0;
        for (x = 0; x < NUMERO_NOTAS; x++)
        {
            int calificacion = matriz[y][x];
            cout << setw(9) << calificacion << "|";
        }

        //aqui ya calcula el promedio
        float promedio = matriz[y][NUMERO_NOTAS];
        totalGeneral += matriz[y][NUMERO_NOTAS];
        if (promedio > promedioMayor)
        {
            promedioMayor = promedio;
            memcpy(alumnoPromedioMayor, alumnos[y], MAXIMA_LONGITUD_CADENA);
        }
        if (promedio < promedioMenor)
        {
            promedioMenor = promedio;
            memcpy(alumnoPromedioMenor, alumnos[y], MAXIMA_LONGITUD_CADENA);
        }
        //se uso setw para la colocacion precisa en columnas
        cout << setw(9) << fixed << setprecision(2) << promedio << "!" << endl;
        imprimirMatrizLinea();
    }

    //escribe el promedio en pantalla
    promedioGeneral = totalGeneral / NUMERO_ALUMNOS;
    cout << "FELICIDADES OBTUVISTE LA Nota mayor: " << setw(10) << alumnoPromedioMayor <<  setw(10) << promedioMayor << endl;
    cout << "DEBE MEJORAR Nota menor: " << setw(10) << alumnoPromedioMenor <<  setw(10) << promedioMenor << endl;
    cout << "Nota prom : " << setw(10) <<  promedioGeneral << endl << endl;
    return promedioGeneral;
}
