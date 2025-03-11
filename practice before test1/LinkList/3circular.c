#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

void insert(node **head, int val) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; // วนกลับไปที่ตัวเอง (วงกลม)
        return;
    }
    node *ptr = *head;
    while (ptr->next != *head) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = *head; // เชื่อมกลับไปที่หัว
}
int josephus(node *head, int k) {
    node *ptr = head, *prev = NULL;
    // หยุดเมื่อเหลือโหนดเดียว
    while (ptr->next != ptr) {
        // นับ K-1 ครั้ง เพื่อให้ ptr ไปถึงโหนดที่จะถูกลบ
        for (int i = 1; i < k; i++) {
            prev = ptr;
            ptr = ptr->next;
        }
        // ลบโหนดที่ ptr ชี้อยู่
        prev->next = ptr->next;
        free(ptr);
        ptr = prev->next;
    }
    int survivor = ptr->data;
    free(ptr);
    return survivor;
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    node *head = NULL;
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        insert(&head, value);
    }
    int survivor = josephus(head, k);
    printf("%d\n", survivor);
    return 0;
}