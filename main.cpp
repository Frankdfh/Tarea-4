#include "NodoArbolBinario.h"
#include "Evaluador.h"
#include <iostream>       // std::cin, std::cout
#include <list>          // std::list
using namespace std;

//Devuelve la suma de todos los numeros del arbol con la raiz dada.
//Explicacion: Si la raiz es igual a NULL retorne 0, se crea una variable sumador para guardar
//el valor de la raiz, luego se hace 1 llamada recursiva tanto con el hijo izquierdo como con el hijo derecho
//se realiza la suma tanto del valor de la raiz como el valor de la suma de los hijos izquierdo y derecho.
int suma(NodoArbolBinario* raiz)
{
    if(raiz==NULL)
    {
       return 0;
    }
    int sumador=raiz->num;
    int sumaizquierda= suma(raiz->hijo_izq);
    int sumaderecha=suma(raiz->hijo_der);
    sumador=sumador+sumaizquierda+sumaderecha;
    return sumador;
}

//Devuelve la cantidad de nodos que tiene el arbol con la raiz dada.
//Explicacion:Si la raiz es igual a NULL retorne 0, se hace llamada recursiva para contar la cantidad de nodos
//en el lado izquierdo y derecho, luego unicamente se le suma 1 a ambos tomando en cuenta la raiz
int cantidadNodos(NodoArbolBinario* raiz)
{
    if (raiz==NULL)
    {
        return 0;
    }
    int contar_izq = cantidadNodos(raiz->hijo_izq);
    int contar_der = cantidadNodos(raiz->hijo_der);
    return 1+contar_izq+contar_der;
}

//Devuelve el promedio de los numeros que tiene el arbol con la raiz dada.
//Explicacion: Como tenemos solucionados las 2 funciones anteriores(de sumar y contar) unicamente las llamamos
//para hacer uso de ellas asignando ese valor a un int, luego creamos otro int con el promedio dividiendo
//la suma entre la cantidad.
int promedio(NodoArbolBinario* raiz)
{
    int sum = suma(raiz);
    int cant = cantidadNodos(raiz);
    int promedio = sum / cant;
    return promedio;
}

//Devuelve la cantidad de pasos que tiene que dar el algoritmo para llegar a un numero dado.
//Ejemplo: http://www.comp.nus.edu.sg/~stevenha/visualization/bst.html
//Para llegar al nodo 7 se ocupan 3 pasos (15,6,7)
//Para llegar al nodo 5 se ocupan 4 pasos (15,6,4,5)
//Para llegar al nodo 15 se ocupa 1 paso (15)
//Explicacion: Se verifica si la raiz es nula o si el valor de inicio y destino es el mismo entonses devolvemos 1
//Luego verificamos si el destino es mayor que la raiz entonses se busca por los hijos derechos y se cuentan los pasos
//caso que sea menor recorremos los hijos izquierdos e igual contamos los pasos, luego retonamos el contador.
int cuantosPasos(NodoArbolBinario* raiz,int num)
{
    if(raiz==NULL)
    {
      return 1;
    }
    if(raiz->num == num)
    {
      return 1;
    }
    int cont = 1;
    if(num>raiz->num)
    {
        cont += cuantosPasos(raiz->hijo_der,num);
    }

    if(num<raiz->num)
    {
        cont += cuantosPasos(raiz->hijo_izq,num);
    }
    return cont;

}

//Devuelve la cantidad de hojas que tiene el arbol con la raiz dada
//EXPLICACION: Verificamos que la raiz no sea nula, si lo es retornara 0, si los hijos de la raiz es nulo, entonses regresara 1
//debido a que la raiz seria la unica hoja, caso contrario se contaran las hojas de los hijos izquierdos mas las
//hojas de los hijos derechos y se retorna ese valor.
int sumaHojas(NodoArbolBinario* raiz)
{
    if(raiz==NULL)
    return 0;
    //cuerpo
    if(raiz->hijo_izq==NULL && raiz->hijo_der==NULL) //se verifica que el lado izquierdo y derecho del arbol sean nulos
    {
       return 1;
    }
    else
    {
       return sumaHojas(raiz->hijo_izq)+sumaHojas(raiz->hijo_der);
    }

}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 1;
}
