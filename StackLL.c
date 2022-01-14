#include<stdio.h>
#include<stdlib.h>

struct node{
    int n;
    struct node *next;
};

struct node *top = NULL;

void push(){
    struct node *new;
    new = (struct node*)malloc(sizeof(struct node));

    if(new == NULL)
        printf("\nStack is Overflow\n");

    else{
        printf("Enter a data: ");
        scanf("%d",&new->n);
        
        new->next = top;
        top = new;
    }
}

void pop(){
    if(top==NULL)
        printf("The stack is Empty: ");

    else{
        struct node *t;
        t = top;
        top = top->next;
        free(t);
    }
}

void print(){
   if(top == NULL)
       printf("\nThe stack is empty\n");
    
    else{
        struct node *p = top;

        printf("\nThe elements are :\n");

        while(p != NULL){
            printf("%d ",p->n);
            p = p->next;
        }
    }
}

void peek(){
    int pos;

    if(top == NULL)
       printf("\nThe stack is empty\n");

    else{
        struct node *p = top;

        printf("Enter the position : ");
        scanf("%d",&pos);

        for(int i=1;i<pos && p!=NULL;i++){
            p = p->next;
        }

        if(p==NULL)
           printf("\nInvalid position\n");

        else{
            printf("\nThe element is %d\n",p->n);
        }
    }   
}

void main(){
    int choice;

    while(1){
        printf("\nEnter your choice\n1.Push\n2.Pop\n3.Peek\n4.Print\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:push();break;
            case 2:pop();break;
            case 3:peek();break;
            case 4:print();break;
            default:exit(0);break;
        }
    }
}