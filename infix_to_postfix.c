#include<stdio.h>
#include<stdlib.h>

char stack[20];
int top = -1;

int pop(){
    return stack[top--];
}

void push(char x){
    stack[++top] = x;
}

int prty(char x){
    if(x =='(')
       return 0;
    else if(x=='+' || x=='-')
       return 1;
    else if(x=='*' || x=='/')
       return 2;   
}

int isOperand(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/' || x=='(' || x==')')
        return 0;

    else 
        return 1;    
}

int main(){
    char eqn[20];
    char *exp,x;

    printf("Enter a expression: ");
    scanf("%s",eqn);

    exp = eqn;

    while(*exp != '\0'){
        if(isOperand(*exp))
           printf("%c",*exp);

        else if(*exp == '(')
           push(*exp);

        else if(*exp == ')'){
            while((x = pop()) != '(')
               printf("%c",x);
        }

        else{
            while(prty(stack[top]) >= prty(*exp))
               printf("%c",pop());

            push(*exp);   
        }
        exp++;
    }

    while(top != -1){
        printf("%c",pop());
    }
}