#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int plate;
    struct Node *next;
} node;

void PUSH(node **top, int val) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->plate = val;
    newNode->next = *top;
    *top = newNode;
}

int POP(node **top) {
    if (*top == NULL) return -1;
    node *temp = *top;
    int val = temp->plate;
    *top = (*top)->next;
    free(temp);
    return val;
}
void MoveDisk(char from, char to, node **fromStack, node **toStack, int *count) {
    int disk = POP(fromStack);
    PUSH(toStack, disk);
    printf("Move disk %d from %c to %c\n", disk, from, to);
    (*count)++;
}
void Hanoi(int n, char A, char B, char C, node **topA, node **topB, node **topC, int *count) {
    if (n == 1) {
        MoveDisk(A, C, topA, topC, count);
        return;}
    Hanoi(n - 1, A, C, B, topA, topC, topB, count); // สลับที่เสาร์ BกับC เพื่อย้ายจาก A ไป B
    MoveDisk(A, C, topA, topC, count);
    Hanoi(n - 1, B, A, C, topB, topA, topC, count); // ย้ายจาก B ไป C
}
int main() {
    int num, count = 0;
    scanf("%d", &num);
    node *topFromStack = NULL, *topAuxStack = NULL, *topToStack = NULL;
    for (int i = num; i > 0; i--) {
        PUSH(&topFromStack, i);
    }
    Hanoi(num, 'A', 'B', 'C', &topFromStack, &topAuxStack, &topToStack, &count);
    printf("Total moves: %d\n", count);
    return 0;
}
