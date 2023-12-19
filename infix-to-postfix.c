#include <stdio.h>
#include <string.h>
#define N 10

struct stack
{
    char a[N];
    int top ;
};

void push(struct stack *s , char op){

    if(s->top == N-1){
        printf("stack overflow\n");
        return ;
    }

    (s->top)++;

    (s->a)[s->top] = op ;

    return ;
} 

char pop(struct stack *s){

    if(s->top == -1){
        printf("stack underflow\n");
        return '\0';
    }

    (s->top)--;

    return (s->a)[(s->top)+1]; 

}

int isEmpty(struct stack * s){

    if(s->top == -1){
        return 1 ;
    }
    else{
        return 0 ;
    }
}

int isOperator(char c){

    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' ||
      c == ')' ){
        return 1 ; 
      }
      else{
        return 0 ;
      }
}

int pred(char op){

    switch(op){

        case '/':
        return 4;
         case '*':
        return 3;
         case '+':
        return 2;
         case '-':
        return 1;
         case '(':
        return 0;

    };
}

void infixToPostfix(char infix[]){

    struct stack s ; 
    s.top = -1;

    int size = strlen(infix);

    for(int i = 0 ; i< size ; i++){

        if(!isOperator(infix[i])){
            printf("%c", infix[i]);
        }

        else{

            if(infix[i] == ')'){

                while(s.a[s.top] != '('){
                    printf("%c" , pop(&s) );
                }

                pop(&s);

            }

            if(isEmpty(&s) || pred(infix[i]) > pred(s.a[s.top])){
                push(&s , infix[i]);
            }
            else{

                while(!isEmpty(&s) && (pred(infix[i]) <=  pred(s.a[s.top])) ){
                    printf("%c" , pop(&s));
                }

                push(&s , infix[i]);
            }
        }
    }

    while(!isEmpty(&s)){
        printf("%c" , pop(&s));
    }

    return ;
}

int main(){

    char infix[] = "a/b+c*d-e" ; 

    infixToPostfix(infix);

}