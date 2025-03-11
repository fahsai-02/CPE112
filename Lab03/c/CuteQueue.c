// 67070501064 Nakagamon Saengdara

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;
// ใส่ค่าเข้าด้านขวา
void EnQ(node **front, node **rear, int num){
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
// นำค่าออกด้านซ้าย
void DeQ(node **front, node **rear){
    node *ptr;
    if (*front == NULL) return;
    ptr = *front;
    *front = (*front)->next;
    free(ptr);    
}
// แสดงค่าด้านซ้ายสุด
void Front(node **front){
    if(*front == NULL){
        printf("none\n");
        return;
    }
    printf("%d\n", (*front)->data);
}

void printList(node *front){
    node *ptr = front;
    if(front == NULL){
        printf("none\n");
        return;
    }
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    int x;
    char option[5];
    node *front, *rear;

    front = NULL;
    rear = NULL;

    do
    {
        scanf("%s",option);
        if(strcmp(option, "ENQ") == 0){
            scanf("%d", &x);
            EnQ(&front, &rear, x);
        }
        else if(strcmp(option, "DEQ") == 0){
            DeQ(&front, &rear);
        }
        else if(strcmp(option, "FRONT") == 0){
            Front(&front);
        }
    } while (strcmp(option, "END") != 0);

    printList(front);
    return 0;
}