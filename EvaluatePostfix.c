#include<stdio.h>
#include<math.h>

int stack[20];
int top = -1;

int pop(){
    return stack[top--];
}

void push(char x){
    stack[++top] = x;
}

int isDigit(char x){
    if(x=='+' || x=='-' || x=='*' ||x=='/' || x=='^' )
       return 0;

    else 
       return 1;
}

int main(){
    char exp[20],*e;
    int n1,n2,n3,num;

    printf("Enter a equation: ");
    scanf("%s",exp);
    e = exp;

    while(*e != '\0'){
        if(isDigit(*e)){
            num = *e - '0';
            push(num);
        }

        else{
            n1 = pop();
            n2 = pop();

            switch(*e){
                case '+':
                n3 = n2 + n1;break;

                case '-':
                n3 = n2 - n1;break;

                case '*':
                n3 = n2* n1;break;

                case '/':
                n3 = (n2 / n1);break;

                case '^':
                n3 = pow(n2,n1);break;
            }

            push(n3);
        }

        e++;
    }

    printf("The result of expression %s  =   %d",exp,pop());
}