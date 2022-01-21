#include<stdio.h>
#include<stdlib.h>

struct stack{
   int size,top;
   int *s;
};

void create(struct stack *st){
    printf("Enter a number of Elements: ");
    scanf("%d",&st->size);
    st->top = -1;

    st->s = (int *)malloc(st->size*sizeof(int));
}

void push(struct stack *st){
    if(st->top == st->size-1){
        printf("\nStack Overflow\n");
        return;
    }

    printf("Enter a element: ");
    st->top++;
    scanf("%d",&st->s[st->top]);
}

void pop(struct stack *st){
    if(st->top == -1){
        printf("\nStack Underflow\n");
        return;
    }

    st->top--;
}

void peek(struct stack st){
    int index=0;
    printf("Enter a index : ");
    scanf("%d",&index);

    if(st.size-index+1<0){
        printf("\nInvalid Index\n");
        return;
    }

    printf("The element is %d",(st.s[st.top-index+1]));
}

void top(struct stack st){
    printf("The top most element is %d",st.s[st.top]);
}

void isempty(struct stack st){
    if(st.top == -1){
       printf("\nYes...The stack is empty\n");
    }

    else
       printf("\nThe stack is non-empty\n");
}

void isfull(struct stack st){
   if(st.top == st.size-1){
       printf("\nYes...The stack is Full\n");
    }

    else
       printf("\nNo...The stack is not full\n");
}

void display(struct stack st){
    int i;

    if(st.top == -1){
        printf("\nThe stack is empty\n");
    }

    printf("The elements are\n");

    for(i=st.top;i>=0;i--){
        printf("%d ",st.s[i]);
    }
}

int main(){
    int choice;
    struct stack st;

    while(1){
        printf("\nEnter your choice: ");
        printf("\n1.Create\n2.Push\n3.Pop\n4.Peek\n5.Top\n6.Display\n7.Check for empty\n8.Check for overflow\n");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:create(&st);break;
            case 2:push(&st);break;
            case 3:pop(&st);break;
            case 4:peek(st);break;
            case 5:top(st);break;
            case 6:display(st);break;
            case 7:isempty(st);break;
            case 8:isfull(st);break;
            default:exit(0);break;
        }
    }
}
