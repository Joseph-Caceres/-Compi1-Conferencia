#include "principal.h"
#include "ui_principal.h"


#include <QFileDialog>
#include <string>
#include <QString>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <QTextStream>
#include <QMessageBox>
#include "Gramatica/parser.h"
#include "Gramatica/scanner.h"



principal::principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::principal)
{
    ui->setupUi(this);
}

principal::~principal()
{
    delete ui;
}

void principal::on_btnAnalizar_clicked()
{

    extern int nLine;
    nLine=1;


    QFile file("temp.txt"); //SE CREA UN ARCHIVO TEMPORAL PARA COMPILARLO
    if ( file.open( file.WriteOnly ) ) { //BUFFER PARA EL TEXTO QUE SE DESEA COMPILAR
        QTextStream stream1( &file );
        stream1 << ui->txtEntrada->toPlainText();
    }


    //setSalida(ui->txtConsola);//SE ASIGNA EL PUNTERO DE LA SALIDA PARA SER USADA POR BISON

    const char* x = "temp.txt";
    FILE* input = fopen(x, "r");
    yyrestart(input);
    yyparse();

    QMessageBox msgBox;
    msgBox.setText("FIN DEL ANALISIS");
    msgBox.exec();

}
