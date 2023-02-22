#include <stdio.h>
#include <stdlib.h>

#define StackLimit 50

typedef char StackElementType;

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);


int main(){

    StackType Stack1;
    char letter,Item1;
    boolean valid=TRUE,flag=TRUE;

    CreateStack(&Stack1);

    printf("Enter string:\n");
    scanf("%c",&letter);
    getchar();

    if(letter=='#')return 0;

    while(letter!='#' && valid==TRUE){
        if(!flag){
            if(letter=='C'){
                flag=TRUE;
                scanf("%c",&letter);
            }
            else{
                    Push(&Stack1,letter);
                    scanf("%c",&letter);
            }
        }
        else {
            if(!EmptyStack(Stack1)){
                Pop(&Stack1,&Item1);
                if(Item1!=letter) valid=FALSE;
                else scanf("%c",&letter);
            }
            else valid=FALSE;

        }
    }
    if(valid==TRUE && EmptyStack(Stack1))return TRUE;
    else return FALSE;
}

void CreateStack(StackType *Stack){
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack){
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack){
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item){
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item){
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

