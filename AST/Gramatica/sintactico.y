%{
    #include "scanner.h"
    #include <iostream>
    #include <string>
    #include <QTextEdit>

    #include "Arbol/nodo.h"

    extern int yylineno; //linea actual donde se encuentra el parser (analisis lexico) lo maneja BISON 
    extern char *yytext; //lexema actual donde esta el parser (analisis lexico) lo maneja BISON
    extern int nLine;


    //salida
    QTextEdit *salida;
    QTextEdit *dot;
    void setSalida(QTextEdit* sal, QTextEdit* grafo) {
        //metodo que asigna el valor al QTextEdit de salida
        salida=sal;
        dot=grafo;
    }

    int yyerror(const char* mens){
        std::cout<<mens<<std::endl; 
        return 0;
    } 

    struct Nod{
     nodo *Padre;
    };



    //Grafo
    QString cadGrafo="digraph G {\nnodesep=0.3;\nranksep=0.2;\nmargin=0.1;\nnode [shape=circle];\nedge [arrowsize=0.8];\n";

%}

//error-verbose si se especifica la opcion los errores sintacticos son especificados por BISON
%error-verbose

%union{ 
    char TEXT[256];//Caracter!
    struct Nod *NODO;
}

%token<TEXT>  sMas
%token<TEXT>  sMenos
%token<TEXT>  sPor
%token<TEXT>  sPuntoComa
%token<TEXT>  sAbreParent
%token<TEXT>  sCierraParent
%token<TEXT>  tImprimir
%token<TEXT>  valNumero




//TIPOS DE NO TERMINALES
%type<NODO> S
%type<NODO> E 

%left sMas sMenos
%left sPor


/*SIMBOLO CON EL QUE INICIA*/
%start S
 
%%



S:      
        E
        {
            
            
            dot->setText(cadGrafo+$1->Padre ->cadenaDot+"}");


            QString result = QString::number($1->Padre->valor);
            salida->append( "Resultado = "+result);

        
        }
        ;
 
 E:              
          E  sPor E  
        {
            $$=new Nod(); 

            nodo *nuevo=new nodo("*");
            nuevo->insertarHijo($1->Padre);
            nuevo->insertarHijo($3->Padre);

            nuevo->multiplicar($1->Padre->valor,$3->Padre->valor);

            $$->Padre=nuevo;
        }
        | E sMas E
        {
            $$=new Nod(); 

            nodo *nuevo=new nodo("+");
            nuevo->insertarHijo($1->Padre);
            nuevo->insertarHijo($3->Padre);

            nuevo->sumar($1->Padre->valor,$3->Padre->valor);

            $$->Padre=nuevo;
        }
        | valNumero
        {
            $$=new Nod(); 

            nodo *nuevo=new nodo(QString::fromStdString($1));
            nuevo->setValor(std::atoi($1));

            $$->Padre=nuevo;
        }
        ;
 
