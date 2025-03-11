#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char data;
    struct Node *next;
}node;

typedef struct
{
    node *front;
    node *rear;
}QUEUE;

void initialize(QUEUE *q) {
    q->front = NULL;
    q->rear = NULL;
}

void EnQueue(QUEUE *q, char num){
    node *newNode = (node*)malloc(sizeof(node));
    if(q->front == NULL){
        newNode->data = num;
        newNode->next = NULL;
        q->front = newNode;
        q->rear = newNode;
    }else{
        newNode->data = num;
        newNode->next = NULL;
        (q->rear)->next = newNode;
        q->rear = newNode;
    }
}

int DeQueue(QUEUE *q){
    node *ptr;
    int value;
    if (q->front == NULL) return -999;
    value = q->front->data;
    ptr = q->front;
    q->front = (q->front)->next;
    free(ptr);
    return value;
}

char Front(QUEUE *q){
    if (q->front == NULL) return -1;
    return q->front->data;
}

int SetPriority(char p){
    if(p=='a'||p=='e'||p=='i'||p=='o'||p=='u'||
    p=='A'||p=='E'||p=='I'||p=='O'||p=='U'){
            return 3;
        }
    else if((p>='b' && p<='z')||(p>='B'&&p<='Z')){
        return 1;
    }else{return 2;}
}

void PrintQueue(QUEUE *q){
    if(q->front == NULL){
        printf("none");
    }
    while (q->front != NULL){
        printf("%c", q->front->data);
        DeQueue(q);
    }
}

void Secretcode(QUEUE *q, QUEUE *q3){
    QUEUE q1, q2;
    initialize(&q1);
    initialize(&q2);
    while (q->front != NULL){
        int p = SetPriority(q->front->data);
        switch (p){
        case 1: EnQueue(&q1, q->front->data);   break;
        case 2: EnQueue(&q2, q->front->data);   break;
        case 3: EnQueue(q3, q->front->data);    break;
        }
        DeQueue(q);
    }
    if(q1.front==NULL && q2.front==NULL && q3->front==NULL){
        PrintQueue(q3); return;
    }
    if(q1.front!=NULL && q2.front!=NULL){
        q2.rear->next = q1.front;
    }else if(q1.front!=NULL && q2.front==NULL){
        q2.front = q1.front;
    }
    if(q3->front!=NULL){
        q3->rear->next = q2.front;
    }else{
        q3->front = q2.front;
    }
    PrintQueue(q3);
}

int main(){
    QUEUE q, qFinal;
    initialize(&q);
    initialize(&qFinal);

    char a;
    while (1)
    {
        scanf("%c", &a);
        if(a=='\n') break;
        EnQueue(&q, a);
    }
    Secretcode(&q, &qFinal);
}