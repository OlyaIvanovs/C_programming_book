#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMBER '0'
#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0; /* next free stack position */
double val[MAXVAL];

void push(double);
double pop(void);

int main(int argc, char *argv[]) {
    double op2;
    int type;
    
    while (--argc > 0) {
        if (isdigit(**++argv)) {
            type = NUMBER;
        } 
        else {
            type = **argv;
        }
        
        switch (type)
        {
            case NUMBER:
                push(atof(*argv));
                break;
            case '*':
                push(pop() * pop());
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0)
                    push(pop() / op2);
                else 
                    printf("error: zero division\n");
                break;
            default:
                printf("error: unknown command %d\n", type);
        }
    }
    printf("result \t%.8g\n", pop());
    return 0;
}

/* push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else 
        printf("error: stack full, cant push\n");
}

/* pop and return top value from stack */
double pop(void){
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}