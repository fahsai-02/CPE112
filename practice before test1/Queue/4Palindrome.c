// Deque = Double-ended Queue

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

int DQF(QUEUE *q){
    node *ptr;
    int value;
    if (q->front == NULL) return -999;
    value = q->front->data;
    ptr = q->front;
    q->front = (q->front)->next;
    free(ptr);
    return value;
}

int DQR(QUEUE *q){
    node *ptr, *prev;
    int value;
    if (q->front == NULL) return -999;
    value = q->rear->data;
    ptr = q->rear;
    if (q->front == q->rear) { // กรณีเหลือโหนดเดียว
        q->front = q->rear = NULL;
    } else {
        prev = q->front;
        while (prev->next != q->rear) { // หาโหนดก่อน rear
            prev = prev->next;
        }
        q->rear = prev;
        q->rear->next = NULL;
    }
    free(ptr);
    return value;
}

void isPalindrome(QUEUE* dq){
    while(dq->front != dq->rear && dq->front != NULL){
        if(DQF(dq) != DQR(dq)){
            printf("No");
            return;}}
    printf("Yes");
}

int main(){
    QUEUE dq;
    initialize(&dq);
    char str;
    while(1)
    {
        scanf("%c", &str);
        if(str == '\n') break;
        str = toupper(str);
        EnQueue(&dq, str);
    }
    isPalindrome(&dq);
}