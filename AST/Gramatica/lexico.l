    /*
    +---------------------
    | 1.Definiciones
    +---------------------
    */
%{
    #include <iostream> 
    #include <string>
    #include "parser.h" 
    int nLine = 1; 
 

%}

%option noyywrap
    //Expresiones regulares
entero [0-9]+

    /*
    +----------------
    | 2. Reglas
    +----------------
    */
%%

 //Signos

"+"          {std::cout<<yytext<<std::endl; strcpy(yylval.TEXT, yytext); return sMas; }
"-"          {strcpy(yylval.TEXT, yytext); return sMenos;}
"*"          {strcpy(yylval.TEXT, yytext); return sPor;}

";"          {strcpy(yylval.TEXT, yytext); return sPuntoComa;}
"("          {strcpy(yylval.TEXT, yytext); return sAbreParent;}
")"          {strcpy(yylval.TEXT, yytext); return sCierraParent;}


"imprimir"   {strcpy(yylval.TEXT, yytext); return tImprimir; }
 
{entero}     {strcpy(yylval.TEXT, yytext); return valNumero;}


"\n"        { nLine++;}

[[:blank:]] { /*Se ignoran*/ }

.           {
    
               std::cout<<"Error léxico, no se esperaba token:"<<yytext<<" en la linea:"<<nLine<<std::endl;
            }

%%
/*CODIGO DE USUARIO*/