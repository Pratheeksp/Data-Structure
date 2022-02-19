#include<stdio.h>
#include<stdlib.h>
#define n 5

int q[n];
int front = -1;
int rear = -1;

void enque(int x){
    if(rear == n-1){
        printf("\nThe queue is full\n");
        return;
    }

    else if(rear == -1 && front == -1){
        front = rear = 0;
        q[rear] = x;
    }

    else{
        rear++;
        q[rear] = x;
    }
}

int deque(){
    int a;

    if(rear == -1 && front == -1){
        printf("\nThe Queue is underflow\n");
    }

    else if(rear == front){
        rear = front = -1;
    }

    else{
        a = q[front];
        front++;
    }

    return a;
}

int peek(){
    return q[front];
}

void display(){
    if(rear == -1 && front == -1)
    {
        printf("The Queue is empty\n");
        return;
    }

    printf("The elemnt in the queue is:\n");

    for(int i=front; i<=rear; i++){
        printf("%d ",q[i]);
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