// 67070501064 Nakagamon Saengdara
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;    
}node;

typedef struct input
{
    char type[4];
    int num1;
    int num2;
}STRUCT;

/* ++++++++++++ Insert ++++++++++++ */
// insert begining
void InsH(node **start, int val){
    node *newNode;
    newNode = (node*)malloc(sizeof(node));
    newNode->data = val;        //(*newNode).data;
    newNode->next = *start;
    *start = newNode;
}

// insert end
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

// insert left
void InsL(node **start, int num, int val){
    node *newNode, *ptr, *prePtr;
    ptr = *start;
    prePtr = ptr;
    /*กรณีไม่มี List และ ใน สist มีแค่ตัวเดียว*/
    if (ptr == NULL) return;
    else if (ptr->data == num){
        InsH(start, val);
    }
    else{
        newNode = (node*)malloc(sizeof(node));
        newNode->data = val;
        newNode->next = NULL;

        while (ptr->data != num) {
            prePtr = ptr;
            ptr = ptr->next;   
            if(ptr == NULL) return;
        }
        prePtr->next = newNode;
        newNode->next = ptr;
    }
}

/* ++++++++++++ Delete ++++++++++++ */
// Delete begining
void DelH(node **start){
    if (*start == NULL) return;
    node *temp = *start;
    *start = temp->next;
    if (temp->next == NULL) *start = NULL;
    free(temp);
}

// Delete end
void DelE(node **start){
    node *temp, *preTemp;
    temp = *start;
    preTemp = temp;
    
    if (*start == NULL) return;
    else if (temp->next == NULL){
        *start = NULL;
        free(temp);
        return;
    }
    while (temp->next != NULL)
    {
        preTemp = temp;
        temp = temp->next;
    }
    preTemp->next = NULL;
    free(temp);
}

// Delete a
void DelA(node **start, int num){
    node *temp, *preTemp;
    temp = *start;
    preTemp = temp;

    if (temp == NULL) return;
    else if(temp->data == num){
        *start = temp->next;
        free(preTemp);
    }
    else{
        while (temp->data != num) {
            preTemp = temp;
            temp = temp->next;
            if (temp == NULL) return; 
        }
        preTemp->next = temp->next;
        free(temp);
    }
}

//print Linklist
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
}

int main(){
    STRUCT input;
    node *start = NULL;

    do
    {
        scanf("%s", input.type);
        if(strcmp(input.type,"INSH") == 0){
            scanf("%d", &input.num1);
            InsH(&start, input.num1);            
        }
        else if(strcmp(input.type, "INSE") == 0){
            scanf("%d", &input.num1);
            InsE(&start, input.num1);
        }
        else if (strcmp(input.type, "INSL") == 0)
        {
            scanf("%d %d", &input.num1, &input.num2);
            InsL(&start, input.num1, input.num2);
        }     
        else if (strcmp(input.type, "DELH") == 0)
        {
            DelH(&start);
        }     
        else if (strcmp(input.type, "DELE") == 0)
        {
            DelE(&start);
        }     
        else if (strcmp(input.type, "DEL") == 0)
        {
            scanf("%d", &input.num1);
            DelA(&start, input.num1);
        }     
    } while (strcmp(input.type, "END") != 0);

    printList(start);

    return 0;
}