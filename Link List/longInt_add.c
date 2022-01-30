#include<stdio.h>
#include<stdlib.h>

struct node{
    int n;
    struct node *next;
};
struct node* push(int a, struct node *head){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->n = a;
    newnode->next = 0;

    newnode->next = head;
    head = newnode;

    return head;
}

struct node *read(int num, struct node *x){
    int a;

    while(num!=0){
        a = num%10;
        num = num/10;

        x = push(a,x);
    }

    return x;
}

struct node *reverse(struct node *head){
    struct node *current,*prev =0,*nextnode;
    current = head;

    while(nextnode!=0){
        nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }

    head = prev;

    return head;
}

struct node *add(struct node *x, struct node *y){
    int sum = 0, carry = 0,a ,b;
    struct node *result = 0;
    struct node *first = x, *second = y;

    while(first || second){
        if(first)
           a = first->n;

        else a = 0;

        if(second)
           b = second->n; 

        else b = 0;    

        sum = a + b + carry;

        carry = (sum>=10) ? 1:0;
        sum = sum%10;

        result = push(sum,result);

        if(first){
            first = first->next;
        }

        if(second){
            second = second->next;
        }
    }

    if(carry){
        result = push(carry,result);
    }

    return result;
}

void print(struct node* head){
    struct node *temp = head;

    if(head == NULL){
        printf("NULL list");
    }

    while(temp!=0){
        printf("%d",temp->n);
        temp = temp->next;
    }
}

int main(){
    int num1 , num2;
    struct node *x = NULL,*y = NULL,*z;
    
    printf("Enter a first number: ");
    scanf("%d",&num1);
    printf("Enter a second number : ");
    scanf("%d",&num2);

    x = read(num1,x);
    y = read(num2,y);

    printf("The First Number is: ");
    print(x);
    printf("\n");

    printf("The second number is: ");
    print(y);
    printf("\n");

    //printf("The reverse of First number is: ");
    x = reverse(x);
    //print(x);
    printf("\n");

    //printf("The reverse of second number is: ");
    y = reverse(y);
    //print(y);
    //printf("\n");

    z = add(x,y);

    printf("The result is : ");
    print(z);

}