// ง่าย เน้นถ่าย วิธีสร้าง คิว

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
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

void EnQueue(QUEUE *q, int num){
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
// ลบค่า front ซ้าย
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
// ดูค่า front
int Front(QUEUE *q){
    if (q->front == NULL) return -1;
    return q->front->data;
}

void Management(QUEUE *q, int r, int t, int n){
    int num = Front(q), count = 0;
    int j=1;
    for(int i=0; ; i++){
        if(j>n/t||q->front==NULL||
            q->front->data>r){ break;
        }else if(num <= r){
            DeQueue(q);
            num += Front(q);
            count++;
        }else{
            j++;    
            num = 0;
            num += Front(q);
            i--;}
    }printf("%d", count);
}

int main(){
    int r, t, n;
    QUEUE q;
    initialize(&q);
    scanf("%d %d %d", &r, &t ,&n);
    int a=0;
    while(1){
        scanf("%d", &a);
        if (a==-1) break;
        EnQueue(&q, a);
    }
    Management(&q, r, t, n);
}