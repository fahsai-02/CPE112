#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node {
    char data;
    struct Node* next;   
} node;

void PUSH(node **top, char val) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

char POP(node **top) {
    if (*top == NULL) return '\0';
    node *temp = *top;
    char val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

char PEEK(node *top) {
    if (top == NULL) return '\0';
    return top->data;
}

int Priority(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}
void infixToPostfix(char infix[], char postfix[]) {
    node *mathSymbols = NULL;
    int j = 0;
    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix[j++] = c;   //posfix[j]=c; j++;
        } else if (c == '(') {
            PUSH(&mathSymbols, c);
        } else if (c == ')') {
            while (PEEK(mathSymbols) != '(') {
                postfix[j++] = POP(&mathSymbols);
            }
            POP(&mathSymbols);  // ลบ '('
        } else {  // operator
            while (mathSymbols != NULL && Priority(PEEK(mathSymbols)) >= Priority(c)) {
                postfix[j++] = POP(&mathSymbols);
            }PUSH(&mathSymbols, c); }
    }
    while (mathSymbols != NULL) { postfix[j++] = POP(&mathSymbols); }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("%s\n", postfix);
    return 0;
}
