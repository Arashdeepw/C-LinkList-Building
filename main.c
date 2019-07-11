#include <stdio.h>
#include <stdlib.h>

struct node{ // node struct
    int data;
    struct node *next;
};

struct node * createNode(){ //method to make node
    return (struct node *) malloc(sizeof(struct node));
}

void addData(struct node **ps, int count){ //method to make nodes and create link list
    struct node *nn;
    int data;
    nn=createNode(); // makes node
    fflush(stdin);
    printf("Input data for node %d: ", count);
    scanf("%d",&data);
    nn->data = data;
    nn->next = *ps;
    *ps = nn;
}

void printList(struct node **ps){// method to print link list
    struct node *t;
    t=*ps;
    while(t){
        printf("%d\n",t->data);
        t=t->next;
    }
}

void addFirst(struct node **ps){ // method to add to first
    struct node *nn;
    int data;
    nn=createNode();
    fflush(stdin);
    printf("Input data for first node: ");
    scanf("%d",&data);
    nn->data = data;
    nn->next = *ps;
    *ps = nn;
}

void addLast(struct node **ps){ // add to end
    struct node *nn, *t;
    int data;
    nn=createNode();
    fflush(stdin);
    printf("Input data for last node: ");
    scanf("%d",&data);
    nn->data = data;
    nn->next = NULL;
    t=*ps;
    while(t->next != NULL){
        t=t->next;
    }
    t->next = nn;
}

void addLocation(struct node **ps){ // add at location
    struct node *nn, *t;
    int data;
    int loc;
    int count = 1;
    nn=createNode();
    fflush(stdin);
    printf("Input data for new node: ");
    scanf("%d",&data);
    fflush(stdin);
    printf("Input location for node: ");
    scanf("%d",&loc);
    nn->data = data;

    t=*ps;
    while(t->next && count < loc-1){
        t=t->next;
        count++;
    }
    nn->next = t->next;
    t->next=nn;
}

void deleteFirst(struct node **ps){ // delete first
    struct node *del;
    del=*ps;
    *ps = del->next;
    free(del);
}

void deleteLast(struct node **ps){ // delete last
    struct node *del, *t;
    t=*ps;
    while(t->next->next){
        t=t->next;
    }
    del = t->next;
    t->next = NULL;
    free(del);
}

void deleteLocation(struct node **ps){ // delete at location
    struct node *del, *t;
    t=*ps;
    int loc;
    int count = 1;
    fflush(stdin);
    printf("Input location for node: ");
    scanf("%d",&loc);

    while(t && count < loc-1){
        t=t->next;
        count++;
    }
    if(t->next){
        del=t->next;
        t->next=t->next->next;
    }
    free(del);
}

void search(struct node **ps){ // search
    struct node *t;
    int find;
    int count = 1;
    int check = 0;
    fflush(stdin);
    printf("Input data you want to find: ");
    scanf("%d",&find);
    t=*ps;
    while(t){

        if(t->data==find){ // prints data found
            printf("Data at node %d has data:%d\n",count, find);
            check++;
        }
        t=t->next;
        count++;
    }
    if(check==0){ // if nothing found prints
        printf("There is no node with that data\n");
    }
}

int main() {
    struct node *start; //start pointer
    start = NULL;

    char check = 'y';
    int count = 1;

    while(check=='y'){ // asks user to enter data into node and if they want to make another
        addData(&start, count);
        count++;
        printf("Enter more <y>es/<n>o? ");
        fflush(stdin);
        scanf("%s",&check);
    }

    int op;//menu
    do{
        printf("\n\t\t===============\n");
        printf("\t\t1> Display\n");
        printf("\t\t2> Insert First\n");
        printf("\t\t3> Insert Last\n");
        printf("\t\t4> Insert Anywhere\n");
        printf("\t\t5> Delete First\n");
        printf("\t\t6> Delete Last\n");
        printf("\t\t7> Delete Anywhere\n");
        printf("\t\t8> Search\n");
        printf("\t\t0. Exit\n");

        fflush(stdin);
        printf("\t\tEnter option: ");
        scanf("%d",&op);

        switch(op){
            case 0:
                printf("Closing"); // close
                break;
            case 1:
                printList(&start); // prints list of nodes
                break;
            case 2:
                addFirst(&start); // add to first
                break;
            case 3:
                addLast(&start); // add to last
                break;
            case 4:
                addLocation(&start); // add to location
                break;
            case 5:
                deleteFirst(&start); // delete first
                break;
            case 6:
                deleteLast(&start); //delete last
                break;
            case 7:
                deleteLocation(&start); // delate at location
                break;
            case 8:
                search(&start); // search for data
                break;
        }
    }while(op!=0);

}
