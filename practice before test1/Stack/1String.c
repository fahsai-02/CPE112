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
void Printword(char word[]){
    for(int i=strlen(word)-1; i>=0; i--){
        printf("%c", word[i]);
    }
}

int NewWord(node *top, char word[]){
    int i = 0;
    if(top == NULL){
        printf("//Empty word\n");
        word[i] = '\0';
        return 0;
    }

    node* ptr = top;
    while (ptr != NULL)
    {
        word[i] = ptr->data;
        ptr = ptr->next;
        i++;
    }
    word[i] = '\0';
    return 1;
}
int main(){
    node *top=NULL;
    int n=100;
    char *word = malloc(n*sizeof(char));
    int i=1;

    fgets(word, n, stdin);
    word[strcspn(word, "\n")] = '\0';

    PUSH(&top, word[0]);
    while (i != strlen(word))
    {
        if(top != NULL){
            if(top->data == word[i]-32 || top->data == word[i]+32){
                POP(&top);
                i++;
            }else{
                PUSH(&top, word[i]);
                i++;
            }
        }else{
            PUSH(&top, word[i]);
            i++;
        }
    }
    NewWord(top, word);
    Printword(word);

    free(word);

    return 0;
}