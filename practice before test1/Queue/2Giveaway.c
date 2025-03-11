#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node;

typedef struct {
    node *front;
    node *rear;
}Circular;

void initialize(Circular *q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(Circular *q) {
    return (q->front == NULL);
}
// ฟังก์ชันเพิ่มข้อมูลเข้า Queue
void EnQueue(Circular *q, int value) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
        q->rear->next = q->front;  // ชี้กลับไปที่ front ทำให้เป็นวงกลม
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
        q->rear->next = q->front;  // ทำให้ rear->next ชี้กลับไปที่ front
    }
}

int dequeue(Circular *q) {
    if (isEmpty(q)) {
        return -1;
    }
    int value;
    if (q->front == q->rear) {  // มีโหนดเดียว
        value = q->front->data;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    } else {
        node *temp = q->front;
        value = temp->data;
        q->front = q->front->next;
        q->rear->next = q->front;  // ปรับ rear->next ให้ชี้กลับไปที่ front
        free(temp);
    }
    return value;
}

int Giveaway(Circular *student, Circular*give, int x){
    int k=x, j=0;  //นับจำนวนสมาชิกใน Q
    for(int i=x; j!=k; i--)
    {
        if(student->front->data == give->front->data){
            dequeue(student);
            dequeue(give);
            j=0;
            k--;
        }else{
            int value = dequeue(student);
            EnQueue(student, value);
            j++;
        }
    }
   return k; 
}
int main(){
    int x, s, g;
    Circular student;
    Circular give;
    initialize(&student);
    initialize(&give);
    scanf("%d", &x);
    int i=0;
    for(int i=0; i<x; i++){
        scanf("%d", &s);
        EnQueue(&student, s);
    }
    for(int i=0; i<x; i++){
        scanf("%d", &s);
        EnQueue(&give, s);
    }
    printf("%d",Giveaway(&student, &give, x));
    return 0;
}