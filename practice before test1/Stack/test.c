// // #include <stdio.h>

// // int main(){
// //     char word [20];
// //     scanf("%s",word);

// //     char a, b, c;
// //     a = word[2];
// //     b = word[3];

// //     printf("%c %c %c", a, b, c);
// // }

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct Node
// {
//     char data;
//     struct Node* next;   
// }node;

// void* PUSH(node **top, char val){
//     node* newNode = (node*)malloc(sizeof(node));
//     newNode->data = val;
//     newNode->next = *top;
//     *top = newNode;
//     // return(newNode);
// }

// void PrintList(node *top){
//     if(top == NULL){
//         printf("none\n");
//         return;
//     }
//     node* ptr = top;
//     while (ptr != NULL)
//     {
//         printf("%d ", ptr->data);
//         ptr = ptr->next;
//     }
//     printf("\n");
// }

// int main(){
//     node *top=NULL;
//     // node *addrass =NULL;
//     char string[100];
//     char data1, data2;
//     int chack;

//     scanf("%s", string);
//     do
//     {
//         if(data1 == data2+32 || data1 == data2-32) {
//             if(addrass != NULL){
//                 data1 = addrass->data;
//             }
//         }else if(data1 != data2+32 && data1 != data2-32) {
//             addrass = PUSH(&top, data1);
//             data1 = data2;
//         }
//     } while (data2 != '\0');

//     PrintList(top);
//     return 0;
// }