#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

void InsE(node **head, int val) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    node *ptr = *head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

void findCriticalPoints(node *head, int *minDist, int *maxDist) {
    node *prev = NULL, *curr = head, *next = NULL;
    int first = -1, last = -1, prevIdx = -1, idx = 0;
    *minDist = -1;
    *maxDist = -1;

    while (curr != NULL && curr->next != NULL) {
        next = curr->next;
        if (prev != NULL && next != NULL) {
            if ((curr->data > prev->data && curr->data > next->data) || 
                (curr->data < prev->data && curr->data < next->data)) {
                
                if (first == -1) {
                    first = idx;
                } else {
                    if (*minDist == -1 || (idx - prevIdx) < *minDist) {
                        *minDist = idx - prevIdx;
                    }
                    *maxDist = idx - first;}
                prevIdx = idx;
            }
        }
        prev = curr;
        curr = next;
        idx++;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    node *head = NULL;
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        InsE(&head, value);
    }
    int minDist, maxDist;
    findCriticalPoints(head, &minDist, &maxDist);
    printf("%d %d\n", minDist, maxDist);
}
