#include<stdio.h>

#define n 10

struct stack{
    int top;
    int a[n];
};

void push(int m, struct stack *st){
    st->top++;
    st->a[st->top] = m;
}

int pop(struct stack *st){
    return st->a[st->top--];
}

void enque(struct stack *st){
    int m;

    if(st->top == (n-1)){
        printf("\nThe queue is full\n");
        return;
    }

    else{
        printf("Enter a number to be added to a Queue: ");
        scanf("%d",&m);

        st->top++;
        st->a[st->top] = m;
    }
}

void deque(struct stack *st1, struct stack *st2){
    if(st1->top == -1){
        printf("\nQueue is empty\n");
        return;
    }

    while(st1->top != -1){
        push(pop(st1),st2);
    }

    pop(st2);

    while(st2->top != -1){
        push(pop(st2),st1);
    }
}

void display(struct stack st){
    int i;

    if(st.top == -1){
        printf("\nThe stack is empty\n");
        return;
    }

    printf("\nThe elements are\n");

    for(i=0;i<=st.top;i++){
        printf("%d ",st.a[i]);
    }
}

void main(){
    struct stack st1, st2;
    int choice;

    st1.top = -1;
    st2.top = -1;

    while(1){
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: enque(&st1);
            break;

            case 2: deque(&st1, &st2);
            break;

            case 3: display(st1);
            break;
        }
    }
}