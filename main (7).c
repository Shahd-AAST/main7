#include <stdio.h>
#include <stdlib.h>
//////////////////////////////// Representation
typedef struct Node Node;
struct Node{
    int data;
    Node* next;
};
Node* top = NULL;
int capacity = 5;
int count = 0;
//////////////////////////////// makeNode
Node* makeNode(int x){
    Node* p = (Node*) malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    return p;
}
//////////////////////////////// (Add to Stack)
void push(int x){
    if(count == capacity){
        printf("Stack Overflow\n");
        return;
    }
    Node* p = makeNode(x);
    p->next = top;
    top = p;
    count++;
}
//////////////////////////////// (Remove from Stack)
int pop(){
    if(top == NULL){
        printf("Stack Underflow\n");
        return -1;
    }
    Node* del = top;
    //save value on top in a variable to return
    int value = top->data;
    top = top->next;
    free(del);
    count--;
    return value;
}
////////////////////////////////
int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    return 0;
}