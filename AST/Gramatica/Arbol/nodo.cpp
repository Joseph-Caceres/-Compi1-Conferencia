#include "nodo.h"
#include <iostream>


/*
 * Constructores
*/
nodo::nodo(QString nombre)
{

    this->nombre=nombre;
    this->id = rand() % 1000;
    this->cadenaDot=QString::number(this->id)+"[label=\""+nombre+"\"]\n";

}




int nodo::setValor(int valor){
    this->valor=valor;
}



/*
 * Insertando a la lista de hijos
*/
void nodo::insertarHijo(nodo* hijo){
    this->hijos.append(hijo);
    this->cadenaDot=this->cadenaDot+hijo->cadenaDot+ QString::number(this->id)+"->"+QString::number(hijo->id)+"\n";
}

/*
 * Operaciones aritmeticas
*/

void nodo::sumar(int valor1, int valor2){

    this->valor =valor1 +  valor2;
}
void nodo::restar(int valor1,int valor2){
    this->valor =valor1 -  valor2;

}
void nodo::multiplicar(int valor1, int valor2)
{
    this->valor =valor1 * valor2;
}

