#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* top = NULL;

void print(){
    struct node* temp;
    temp = top;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void addNode(int data){
    struct node* newNode = NULL;
    newNode = malloc(sizeof newNode);
    newNode->data = data;
    newNode->link = NULL;

    if(top == NULL){
        top = newNode;
        return;
    }

    newNode->link = top;
    top = newNode;
}

int pop(){
    struct Node* temp;
    temp = (struct Node *) top;

    if(top == NULL){
        printf("Stach Overflow");
        exit(1);
    }

    int val = top->data;
    top =  top->link;
    free(temp);
    temp = NULL;
    return val;
}

int peek(){
    if(top == NULL) exit(1);
    int data = top->data;

    return data;
}

int main(){

    addNode(10);
    addNode(21);
    addNode(76);
    addNode(23);
    addNode(76);
    addNode(23);
    addNode(98);

    int val = pop();
    printf("%d\n", val);

    printf("the peek is %d\n", peek());
    print();
}
