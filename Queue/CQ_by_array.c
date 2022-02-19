#include<stdio.h>
#include<stdlib.h>
#define n 5

int q[n];
int front = -1;
int rear = -1;

void enque(){
    int x;

    if(rear == -1 && front == -1){
        printf("Enter a data: ");
        scanf("%d",&x);
        front = rear = 0;
        q[rear] = x;
    }

    else if(((rear+1) % n) == front){
        printf("\nThe queue is full\n");
        return;
    }

    else{
        printf("Enter a data: ");
        scanf("%d",&x);
        rear = (rear+1) % n;
        q[rear] = x;
    }
}

void deque(){
    int a;

    if(rear == -1 && front == -1){
        printf("\nThe Queue is underflow\n");
    }

    else if(rear == front){
        rear = front = -1;
    }

    else{
        front = (front+1) % n;
    }
}

int peek(){
    return q[front];
}

void display(){
    int i = front;  

    if(rear == -1 && front == -1)
    {
        printf("The Queue is empty\n");
        return;
    }

    else{
        printf("The elemnt in the queue is:\n");

        while(i != rear){
            printf("%d ",q[i]);
            i = (i+1)%n;
        }

        printf("%d ",q[rear]);
    }

    
}

void main(){
    int choice,m;

    while(1){
        printf("\n1.Enqueue\n2.Dqueue\n3.Peek\n4.Display\nEnter your Choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: enque();
            break;

            case 2 : deque();
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