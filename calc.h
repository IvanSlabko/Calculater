#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <complex.h>
#define MAX_CHAR 255
 
int* getToken(char*);
void pars(char*);
int fSum(double*);
int fMulti(double*);
int fExp(double*);
int fUnary(double*); 
int fBrack(double*); 
int fAtom(double*); 

char *expr;
char token[80]; 

enum {
    Empty, 
    Operator, 
    Variable, 
    Number
} type;

enum {
    No, 
    Syntax, 
    Zero
} error;
 
void pars(char *line) {
    int *pointer;
    double result;
    expr = line;
    error = No;
    pointer = getToken(line);
    fSum(&result);
    *pointer = 0;
 
    switch(error)
    {
     case No:
        sprintf(line, "%0.3f", result);
        break;
     case Syntax:
        sprintf(line, "Syntacsis error");
        break;
     case Zero:
        sprintf(line, "Divide by thero");
        break;
    }
}
 
int* getToken(char *expr)
{
    static int i = 0;
    type = Empty;
 
    if (expr[i] == '\0') {
        i=0;
        return 0;
    }
 
    if((expr[i] == '+') || (expr[i] == '-') || (expr[i] == '*') || (expr[i] == '/') || (expr[i] == '%')  || (expr[i] == '^') || (expr[i] == '(') || (expr[i] == ')')) {
        *token = expr[i];
        *(token+1) = '\0';
        type = Operator;
    } else if(isalpha(expr[i])) {
        *token = expr[i];
        *(token+1) = '\0';
        type = Variable;
    } else if(isdigit(expr[i])) {
        int j=0;

        token[j]=expr[i];
        
        while(isdigit(expr[i+1]) || expr[i+1]=='.') {
            token[++j]=expr[++i];
        }

        token[j+1]='\0';
        type = Number;
    }
    i++;
    return &i;
}
 
int fSum(double *anw) {
    char op;
    double temp;

    if(fMulti(anw)){ 
        return 1;
    }
    
    while((op = *token) == '+' || op == '-') {
        getToken(expr);
        fMulti(&temp);
        
        switch(op) {
            case '+':
                *anw += temp;
                break;
            case '-':
                *anw -= temp;
                break;
        }
    }
 
    return 0;
}
 
int fMulti(double *anw) {
    char op;
    double temp;

    if(fExp(anw)){ 
        return 1; 
    }
 
    while((op = *token) == '*' || op == '/' || op == '%') {
        getToken(expr);
        if(fExp(&temp)) {
            return 1;
        }

        switch(op) {
         case '*':
            *anw *= temp;
            break;
         case '/':
            if(temp == 0.0) {
                error=Zero;
                return 1;
            }
            *anw /= temp;
            break;
         case '%':
            *anw = (int)*anw % (int)temp;
            break;
        }
    }
 
    return 0;
}
 
int fExp(double *anw) {
    double temp;
    if(fUnary(anw)) {
        return 1;
    }
 
    while(*token  == '^') {
        getToken(expr);

        if(fUnary(&temp)) { 
            return 1; 
        }
        *anw = pow(*anw, temp);
    }
 
    return 0;
}
 
int fUnary(double *anw) {
    char op=0;

    if(*token == '+' || *token == '-') {
        op = *token;
        getToken(expr);
    }

    if(fBrack(anw)){ 
        return 1;
    }

    if(op == '-') { 
        *anw = -(*anw);
    }
    return 0;
}
 
int fBrack(double *anw) {
    if(*token == '(') {
        getToken(expr);
        fSum(anw);
 
        if(*token != ')') {
            error=Syntax;
            return 1;
        }
        getToken(expr);
    } else if(fAtom(anw)) {
        return 1; 
    }
 
    return 0;
}
 
int fAtom(double *anw) {
    if(type == Number) {
        *anw = atof(token);
        getToken(expr);
    } else {
        error=Syntax;
        return 1;
    }
 
    return 0;
}
 
void calcPars(char *str) {

    pars(str);
}
