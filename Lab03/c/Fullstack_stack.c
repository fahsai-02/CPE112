// Nakagamon Saengdara 67070501064
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node;
// ใส่ค่า
void Push(int val, node **top){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}
// นำค่าออก
void Pop(node **top){
    if (*top == NULL){
        printf("");
        return;
    }
    node *ptr = *top;
    *top = (*top)->next;
    free(ptr);
}
// ดูค่าบนสุดของ stack
void Peek(node **top){
    if (*top == NULL){
        printf("none\n");
        return;
    }
    printf("%d\n", (*top)->data);
}

void PrintLinkList(node *top){
    if (top == NULL){
        printf("none\n");
        return;
    }
    node *ptr = top;
    while (ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}    

int main(){
    node *top = NULL;
    int num;
    char option[5];

    do {
        scanf("%s", option);
        
        if (strcmp(option, "PUSH") == 0){
            scanf("%d", &num);
            Push(num, &top);
        }
        else if (strcmp(option, "PEEK") == 0){
            Peek(&top);
        }
        else if (strcmp(option, "POP") == 0){
            Pop(&top);
        }
    } while (strcmp(option, "END") != 0);
    
    PrintLinkList(top);
    return 0;
}
