//To create, print , insert and delete a link list 

#include<stdio.h>
#include<stdlib.h>

struct node{
    int n;
    struct node *next;
};

struct node *head,*temp,*newnode;
int count=0,*ptr = &count;

void create(){
    int choice;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter a new data: ");
    scanf("%d",&(newnode->n));
    newnode->next = 0;

    if(head == 0){
        head = temp = newnode;
    }

    else{
        temp->next = newnode;
        temp = newnode;
    }

    printf("\n->1 to continue\n->0 to terminate\n\n");
    scanf("%d",&choice);

    while(choice){
        create();
        return;
    }
}

void print(){
    if(head==0){
        printf("There is no link list...\nPlease create link list...\n");
    }
    temp = head;
    printf("\n\n...The data through link list... \n");
    while(temp!=0){
        printf("%d  ",temp->n);
        temp = temp->next;
    }
}

void insertF(){
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter a new data:\n");
    scanf("%d",&newnode->n);
    newnode->next = head;
    head = newnode;
}

void insertE(){
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter a new data:\n");
    scanf("%d",&(newnode->n));
    newnode->next = 0;
    while(temp->next!=0){
        temp = temp->next;
    }
    temp->next = newnode;
}

void insertP(){
    temp = head;
    struct node *prevnode;
    int i,pos;
    printf("\nEnter a position to be inserted :\n");
    scanf("%d",&pos);

    (*ptr) = 0;

    while(temp!=0){
        (*ptr)++;
        temp = temp->next;
    }

    temp = head;

    if(pos>(*ptr)){
        printf("\n...The length of link list is %d...",(*ptr));
        printf("\n...Invalid position....\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter a new data:\n");
    scanf("%d",&(newnode->n));

    prevnode = temp; 

    for(i=1;i<pos;i++){
        prevnode = temp;
        temp = temp->next;
    }

    newnode->next = prevnode->next;
    prevnode->next = newnode;

}

void deleteF(){
    struct node *prevnode;
    if(head==0){
        printf("There is no link list...\nPlease create link list...\n");
    }
    temp = head;
    prevnode = temp;
    temp = temp->next;
    head = temp;
    free(prevnode);
}

void deleteE(){
    struct node *prevnode;
    if(head==0){
        printf("There is no link list...\nPlease create link list...\n");
    }
    temp = head;
    while(temp->next != 0){
        prevnode = temp;
        temp = temp->next;
    }
    prevnode->next = 0;
    free(temp);
}

void deleteP(){
    struct node *prevnode,*nextnode;
    int pos,i;
    if(head==0){
        printf("\nThere is no link list...\nPlease create link list...\n");
    }
    printf("\nEnter a position of element to be deleted\n");
    scanf("%d",&pos);

    temp = head;

    (*ptr) = 0;

    while(temp!=0){
        (*ptr)++;
        temp = temp->next;
    }

    temp = head;

    if(pos>(*ptr)){
        printf("\n...The length of link list is %d...",(*ptr));
        printf("\n...Invalid position....\n");
        return;
    }

    temp = head;

    for(i=1;i<pos;i++){
        prevnode = temp;
        temp = temp->next;
    }

    prevnode->next = temp->next;
    free(temp);
}

void reverse(){
    struct node *prevnode,*nextnode;
    prevnode = 0;
    temp = nextnode = head;
    
    while(nextnode!=0){
        nextnode = nextnode->next;
        temp->next = prevnode;
        prevnode = temp;
        temp = nextnode;
    }
    
    head = prevnode;
}

void sort(){
    struct node *nextnode;
    int n;
    temp = head;

    while(temp!=0){
        nextnode = temp->next;
        while(nextnode!=0){
            if((temp->n)>(nextnode->n)){
                n = nextnode->n;
                nextnode->n = temp->n;
                temp->n = n;
            }
            nextnode = nextnode->next;
        }
        temp = temp->next;
    }
}

void search(){
    int a=0,ele,flag=0;
    printf("\nEnter a Element to be searched : ");
    scanf("%d",&ele);

    temp = head;

    while(temp!=0)
    {
        a++;
        if(ele == temp->n)
        {
            flag = 1;
            goto next;
        }
        temp = temp->next;
    }

    next:

    if(flag==1)
       printf("it is found in %dth position",a);

    else
      printf("Search unsuccessfull");   
}

void main(){
    int choice;
    head = 0;

     for(;;){
          printf("\n\nThe program performs following operations on link list\n\n1.Create\n2.Print\n3.Insert at first\n4.Insert at last\n5.Insert at given position\n6.Delete 1st element\n7.Delete last element\n8.Delete at given position\n9.Reverse\n10.Sort\n11.Search\n\n");
          scanf("%d",&choice);

         switch(choice){
             case 1:
             create();
             break;

             case 2:
             print();
             break;

             case 3:
             insertF();
             break;

             case 4:
             insertE();
             break;

             case 5:
             insertP();
             break;

             case 6:
             deleteF();
             break;

             case 7 :
             deleteE();
             break;

             case 8:
             deleteP();
             break;

             case 9:
             reverse();
             break;
             
             case 10:
             sort();
             break;

             case 11:
             search();
             break;

             default :
             exit(0);
        
         }
     }
}
