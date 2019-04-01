#ifndef NODO_H
#define NODO_H

#include <qstring.h>
#include <QList>
class nodo
{
public:

    //Constructores
    nodo(QString nombre);
    nodo(QString nombre, int valor);

    //Operanciones
    void sumar(int valor1,int valor2);
    void restar(int valor1,int valor2);
    void multiplicar(int valor1,int valor2);


    //set
    int setValor(int valor);
    void insertarHijo(nodo* hijo);

    int id;
    QString nombre;
    QList<nodo*> hijos;

    //Sintetizando valor
    int valor;

    //Sitentizando la cadena
    QString cadenaDot;

};

#endif // NODO_H
