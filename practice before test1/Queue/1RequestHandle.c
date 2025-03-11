#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define MIN 1

typedef struct Node
{
    int data;
    struct Node *next;
}node;

void EnQueue(node **front, node **rear, int num){
    node *newNode = (node*)malloc(sizeof(node));
    if(*front == NULL){
        newNode->data = num;
        newNode->next = NULL;
        *front = newNode;
        *rear = newNode;
    }else{
        newNode->data = num;
        newNode->next = NULL;
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

void DeQueue(node **front, node **rear){
    node *ptr;
    if (*front == NULL) return;
    ptr = *front;
    *front = (*front)->next;
    free(ptr);
}

int CountQ(node **front){
    node* ptr = *front;
    int i=0;
    if(*front == NULL) return 0;
    while (ptr != NULL)
    {   i += ptr->data;
        ptr = ptr->next;
    }
    return i;
}

void RequestHandle(node**front,node**rear,int x,int t[]){
    int j=0, k=0;
    for(int i=0; t[j] != -1; i++){
        if(i == t[j]){
            EnQueue(front, rear, 1);
            printf("%dhuk", t[j]);
            printf("%d\n", CountQ(front));
            j++;
        }
        if(((i+1)%x)==0 && *front!=NULL){
            DeQueue(front, rear);
        }}
}
int main(){
    int x;
    int t[MAX];
    node *front=NULL, *rear=NULL;
    scanf("%d", &x);
    int i=0;
    do{
        scanf("%d", &t[i]);
        i++;
    }while(t[i-1] != -1);
    RequestHandle(&front, &rear, x, t);
}