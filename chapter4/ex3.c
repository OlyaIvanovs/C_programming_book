#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100 /* max size of operand or operator */
#define MAXVAL 100 /* maximum depth of val stack */
#define NUMBER '0' /* signal that a number was found */
#define MATH '1' /* signal that a nmath function(sin, exp, pow) was found */
#define VARIABLE '2' /* signal that a variable was found */
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void ungets(char []);
double gettopelement(void);
void duplicatetop(void);
void swaptopelements(void);
double math(char s[], double n);

int sp = 0; /* next free stack position */ 
double val[MAXVAL];
double variables[26];
char buf[BUFSIZE];
int bufp = 0;

/* reverse Polisch calculator */
int main()
{
    int type;
    double op2;
    double op3;
    char s[MAXOP];
    int v;
    

    while ((type = getop(s)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof(s));
                break;
            case VARIABLE:  // 10 A = 20 B = A B +
                v = tolower(s[0]) - 'a';
                push(variables[v]);
                break;
            case MATH:
                push(math(s, pop()));
                break;
            case '=':
                variables[v] = pop();
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else 
                    printf("error: zero division\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0) {
                    op3 = pop();
                    push(op3 - op2 * (int)(op3 / op2));
                }
                else 
                    printf("error: zero division\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknow command %s\n", s);
                break;
        }
    }
    
    gettopelement();
    duplicatetop();
    swaptopelements();

    /* print all elements of the stack */
    printf("All elements of the stack\n");
    for (int i = 0; i <= sp; i++) {
        printf("%g\t", val[i]);
    }

    return 0;
}

/* Print the top element of the stack */
double gettopelement(void)
{
    if (sp == 0) {
        printf(".There is no top element. Stack is empty\n");
        return 0.0;
    } else {
        printf("The top element %.8g\t", val[sp - 1]);
        return val[0];
    }
}

/* duplicate the top element of stack */
void duplicatetop()
{
    double op1 = pop();
    push(op1);
    push(op1);
}


/* swap the top two elements */
void swaptopelements()
{
    double op1, op2;
    if (sp > 1) {
        op1 = pop();
        op2 = pop();
        push(op1);
        push(op2);
    } else {
        printf("Operation 'swap' two elements is impossible.");
    }
}


/* clear the stack */
void clearstack()
{
    sp = 0;
}


/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL) {
        val[sp++] = f;
    }
    else
        printf("error: stack full; cant push %g\n", f);
}



/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}


/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t' )
        ;
    s[1] = '\0';

    if (!isalnum(c) && c != '.')
        return c; /* not a number */
    i = 0;

    if (isdigit(c)) { 
        
        while (isdigit(s[++i] = c = getch())); /* collect integer part */

        if (c == '.')   /* collect fraction part */
            while (isdigit(s[++i] = c = getch()));

        s[i] = '\0';

        if (c != EOF)
        ungetch(c);

        return NUMBER;
    }
    
    if (isalpha(c)) /* collect the name of math function */
        while (isalpha(s[++i] = c = getch()));

    if (strlen(s) == 2 && ((s[0] >= 'A' && s[0] <= 'Z') || (s[0] >= 'a' && s[0] <= 'z'))) {
        return VARIABLE;
    }

    s[i] = '\0';

    if (c != EOF)
    ungetch(c);

    return MATH;
}

int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar(); 
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE) 
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}


double math(char s[], double n)
{
    if (!n) {
        printf("Stack is empty\n");
        return 0.0;
    }
    
    if (strcmp(s, "sin") == 0)
        return sin(n);
        
    if (strcmp(s, "cos") == 0) 
        return cos(n);
    if (strcmp(s, "exp") == 0) 
        return exp(n);

    printf("A function %s does not exist.", s);
    return 0.0;
}

void ungets(char s[]) 
{
    int i = strlen(s);
    while (i > 0) {
        ungetch(s[--i]);
    }
}
