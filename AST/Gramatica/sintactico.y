%{
    #include "scanner.h"
    #include <iostream>
    #include <string>

    #include "Arbol/nodo.h"

    extern int yylineno; //linea actual donde se encuentra el parser (analisis lexico) lo maneja BISON 
    extern char *yytext; //lexema actual donde esta el parser (analisis lexico) lo maneja BISON
    extern int nLine;

    //Consola
    #include <QPlainTextEdit>


    int yyerror(const char* mens){ 
        return 0;
    } 

    struct Nod{
     nodo *Padre;
    };


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
            
            std::cout<<$1->Padre->cadenaDot.toStdString()<<std::endl;
            std::cout<<"Resultado:"<<$1->Padre->valor<<std::endl;

        
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
 
