#include<stdio.h>
#include<stdlib.h>

struct node{
    int n;
    struct node *prev,*next;
}; 

struct node *tail,*temp,*newnode;

void create(){
    tail=0;
    int i=1;
    while(i){
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = 0;
    printf("Enter the data: ");
    scanf("%d",&newnode->n);

    if(tail==0){
       tail=newnode;
       tail->next = tail;
    }

    else{
        newnode->next = tail->next;
        tail->next = newnode;
    }

    tail = tail->next;

    printf("\n1->To continue\n0->To Terminate\n");
    scanf("%d",&i);
    }
}

void insertFront(){
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = 0;
    printf("Enter the data: ");
    scanf("%d",&newnode->n);

    if(tail==0){
       tail=newnode;
       tail->next = tail;
    }

    else{
        newnode->next = tail->next;
        tail->next = newnode;
    }
}

void deleteFront(){
    temp = tail->next;

    if(tail==0){
        printf("\nEmpty List...\n");
    }

    else if(tail->next == tail){
        tail=0;
        free(temp);
    }

    else{
        tail->next = temp->next;
        free(temp);
    }
}

void insertEnd(){
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = 0;
    printf("Enter the data: ");
    scanf("%d",&newnode->n);

    if(tail==0){
       tail=newnode;
       tail->next = tail;
    }

    else{
        newnode->next = tail->next;
        tail->next = newnode;
        tail = tail->next;
    }
}

void deleteEnd(){
    temp = tail->next;
    struct node *prevnode;

    if(tail==0){
        printf("\nEmpty List...\n");
    }

    else if(tail->next == tail){
        tail=0;
        free(temp);
    }

    else{
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = 0;
        printf("Enter the data: ");
        scanf("%d",&newnode->n);

        while(temp->next!=tail->next){
            prevnode = temp;
            temp = temp->next;
        }

        tail = prevnode;
        tail->next = temp->next;
        free(temp);
    }
}

void insertPos(){
    int pos,i=1,l=getlength();

    printf("Enter the position: ");
    scanf("%d",&pos);

    temp = tail->next;

    if(pos<=0 || pos>(l+1)){
        printf("\nInvalid position\n");
    }

    else if(pos==(l+1)){
        insertEnd();
    }

    else if(pos==1){
       insertFront();
    }

    else{
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = 0;
        printf("Enter the data: ");
        scanf("%d",&newnode->n);

        while(i<pos-1){
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;    
    }
}

void deletePos(){
    int pos,i=1,l=getlength();
    struct node *prevnode;

    printf("Enter the position: ");
    scanf("%d",&pos);

    temp = tail->next;

    if(pos<=0 || pos>l){
        printf("\nInvalid position\n");
    }

    else if(pos==(l)){
        deleteEnd();
    }

    else if(pos==1){
       deleteFront();
    }
    
    else{
        while(i<pos){
            prevnode = temp;
            temp = temp->next;
            i++;
        }

        prevnode->next = temp->next;
        free(temp);
    }
}

void reverse(){
    struct node *prevnode,*nextnode;
    temp = tail->next;
    nextnode = temp->next;

    while(temp != tail){
        prevnode = temp;
        temp = nextnode;
        nextnode = temp->next;
        temp->next = prevnode;
    }

    nextnode->next = tail;
    tail = nextnode;
}

void sort(){
    int n;
    struct node *nextnode;
    temp = tail->next;

    do{
        nextnode = temp->next;
        while(nextnode != tail->next){
           if((temp->n)>(nextnode->n)){
              n = nextnode->n;
              nextnode->n = temp->n;
              temp->n = n;
           }
           nextnode = nextnode->next;
        }
        temp = temp->next;   
    }while(temp != tail->next);
}

int getlength(){
    int l=1;
    temp = tail->next;
    do{
        l++;
        temp = temp->next;
    }while(temp->next != tail->next);

    return l;
}

void display(){
    temp = tail->next;
    do{
        printf("%d ",temp->n);
        temp = temp->next;
    }while(temp != tail->next);
}

int main(){
    int choice;
    while(1){
        printf("\n\nEnter your choice:");
        printf("\n1.Create\n2.Insert at front\n3.Delete at front\n4.Insert at end\n5.Delete at end\n6.Inssert at position\n7.Delete at position\n8.Reverse\n9.Sort\n10.Display\n\n");

        scanf("%d",&choice);

        switch(choice){
            case 1: create();break;
            case 2: insertFront();break;
            case 3: deleteFront();break;
            case 4: insertEnd();break;
            case 5: deleteEnd();break;
            case 6: insertPos();break;
            case 7: deletePos();break;
            case 8: reverse();break;
            case 9: sort();break;
            case 10: display();break;
        }
    }
}