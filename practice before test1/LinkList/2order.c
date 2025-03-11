#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

void InsE(node **start, int val){
    node *newNode, *ptr;
    newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;

    if (*start == NULL) {
        *start = newNode;
        return;
    }
    ptr = *start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

void DelH(node **start){
    if (*start == NULL) return;
    node *temp = *start;
    *start = temp->next;
    free(temp);
}

void printList(node *start){
    if (start == NULL)
    {
        printf("none");
        return;
    }
    node *ptr = start;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void Mash(node **start1, node **start2){
    node *ptr1 = *start1, *ptr2 = *start2;
    node *next1, *next2;

    while (ptr1 != NULL && ptr2 != NULL) {
        next1 = ptr1->next;
        next2 = ptr2->next;

        ptr1->next = ptr2;
        if (next1 == NULL) {
            break;
        }

        ptr2->next = next1;

        ptr1 = next1;
        ptr2 = next2;
    }

    *start2 = ptr2;
}

int main(){
    node *start1 = NULL;
    node *start2 = NULL;

    int num1, num2;
    scanf("%d", &num1);

    for (int i = 0; i < num1; i++) {
        int a;
        scanf("%d", &a);
        InsE(&start1, a);
    }

    scanf("%d", &num2);

    for (int j = 0; j < num2; j++) {
        int a;
        scanf("%d", &a);
        InsE(&start2, a);
    }

    Mash(&start1, &start2);

    printList(start1);

    return 0;
}
