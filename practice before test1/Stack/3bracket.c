#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char data;
    struct Node* next;   
}node;

void PUSH(node **top, char val){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

void POP(node **top){
    if(*top == NULL){
        printf("");
        return ;
    }
    node *ptr = *top;
    *top = (*top)->next;
    free(ptr);
}

int isValid(char str[]) {
    node *top = NULL;
    for (int i = 0; i < strlen(str); i++) {
        char ch = str[i];
        // ตรวจสอบเฉพาะวงเล็บเท่านั้น
        if (ch == '(' || ch == '[' || ch == '{') {
            PUSH(&top, ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (top == NULL) return 0;  // มีวงเล็บปิดโดยไม่มีวงเล็บเปิด
            if ((ch == ')' && top->data == '(') || 
                (ch == ']' && top->data == '[') || 
                (ch == '}' && top->data == '{')) {
                POP(&top);
            } else  return 0;
        }
    }
    if (top == NULL) return 1;
    return 0;
}
int main() {
    char str[100];
    scanf("%s", str);
    if (isValid(str)) printf("True\n");
    else printf("False\n");
}