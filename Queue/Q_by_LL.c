#include<stdio.h>
#include<stdlib.h>

struct node{
    int n;
    struct node *next;
};

typedef struct node* Node;
Node front, rear;

void enque(int x){
    Node newnode = (Node)malloc(sizeof(struct node));
    newnode->n = x;
    newnode->next = 0;

    if(front == 0 && rear == 0){
        front = rear = newnode;
    }

    else{
        rear->next = newnode;
        rear = newnode;
    }
}

int deque(){
    int a;
    Node temp = front;

    if(front == 0 || rear == 0){
        printf("\nThe queue is empty\n");
    }

    else{
        a = front->n;
        front = front->next;
        free(temp);
    }

    return a;
}

int peek(){
    return front->n;
}

void display(){
    Node temp;
    temp = front;

    printf("\nThe elements are: \n");

    while(temp != 0){
        printf("%d ",temp->n);
        temp = temp->next;
    }
}

void main(){
    int choice,m;

    while(1){
        printf("\n1.Enqueue\n2.Dqueue\n3.Peek\n4.Display\nEnter your Choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: printf("Enter a data: ");
            scanf("%d",&m);
            enque(m);
            break;

            case 2 : printf("The deleted element is %d",deque());
            break;

            case 3: printf("The front element is %d",peek());
            break;

            case 4: display();
            break;

            default:
            exit(0);
            break;
        }
    }
}