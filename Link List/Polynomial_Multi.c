//To add the given two polynomial

#include<stdio.h>
#include<stdlib.h>

struct node{
    float coeff;
    int ex;
    struct node *next;
};

typedef struct node* Node;

Node insert(float coeff,int ex, Node head){
    Node newnode,temp;
    newnode = (Node)malloc(sizeof(struct node));
    newnode->coeff = coeff;
    newnode->ex = ex;
    newnode->next = NULL;

    temp = head;

    if(head==NULL || ex>head->ex){
        newnode->next = head;
        head = newnode;
    }

    else{
        temp = head;
        while(temp->next!=NULL && temp->next->ex > ex){
            temp = temp->next;
        }
        
        newnode->next = temp->next;
        temp->next = newnode;
    }

    return head;
} 

Node create(Node head){
    int ex;
    float coeff;
    int n;

    printf("Enter a number of terms in a Polynomial: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter a co_efficient of term %d: ",(i+1));
        scanf("%f",&coeff);

        printf("Enter a exponent of term %d: ",(i+1));
        scanf("%d",&ex);

        head = insert(coeff,ex,head);
    }

    return head;
}

Node polyMulti(Node head1,Node head2,Node head3){
    Node ptr1 = head1;
    Node ptr2 = head2;
    head3 = NULL;

    int res1,res2;

    if(head1 == NULL || head2 == NULL){
        printf("The Polynomial is empty\n");
        return 0;
    }

    while(ptr1!=NULL){
        ptr2 = head2;

        while(ptr2 != NULL){
            res1 = ptr1->coeff * ptr2->coeff;
            res2 = ptr1->ex + ptr2->ex;
            head3 = insert(res1,res2,head3);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }

    return head3;
}


//Copied in Geeks for Geeks
void removeDuplicates(Node head){
    Node ptr1,ptr2,dup;
    ptr1 = head;

    while(ptr1!=0 && ptr1->next!=0){
        ptr2 = ptr1;

        while(ptr2->next!=0){
            if(ptr1->ex == ptr2->next->ex ){
                ptr1->coeff = ptr1->coeff + ptr2->next->coeff;
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            }

            else ptr2 = ptr2->next;
        }

        ptr1 = ptr1->next;
    }
}

void display(Node head){
    removeDuplicates(head);

    Node temp;
    temp = head;

    while(temp!=NULL){
        printf(" (%.1f x^%d) ",temp->coeff,temp->ex);

        temp = temp->next;
        if(temp!=NULL){
            printf("+");
        }
    }
}

void main(){
    Node head1 = NULL;
    Node head2 = NULL;
    Node head3 = NULL;

    printf("Enter a first polynomial: \n");
    head1 = create(head1);

    printf("Enter a second polynomial: \n");
    head2 = create(head2);

    printf("\nThe first Polynomial is :\n");
    display(head1);

    printf("\nThe second Polynomial is :\n");
    display(head2);

    head3 = polyMulti(head1,head2,head3);

    printf("\nThe resultant Polynomial is :\n");
    display(head3);
}