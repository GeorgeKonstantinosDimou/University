#include <stdio.h>
#include <stdlib.h>

#define StackLimit 15

typedef int StackElementType;

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
void TraverseStack(StackType Stack);


int main(){

    int i,n;
    StackType Stack1,tmpStack;
    StackElementType Item1;

    CreateStack(&Stack1);
    CreateStack(&tmpStack);
    for(i=0;i<=StackLimit;i++){
        Push(&Stack1,i*10);
    }
    TraverseStack(Stack1);
    printf("Give nth element (n<=6)");
    scanf("%d",&n);
    printf("\n");

    for(i=0;i<=1;i++) Pop(&Stack1,&Item1);
    printf("Question a: x=%d",Item1);
    TraverseStack(Stack1);
    printf("\n");

    for(i=0;i<=1;i++){
        Pop(&Stack1,&Item1);
        Push(&tmpStack,Item1);
    }
    printf("Question b: x=%d",Item1);
    for(i=0;i<=1;i++){
        Pop(&tmpStack,&Item1);
        Push(&Stack1,Item1);
    }
    TraverseStack(Stack1);
    printf("\n");

    for(i=0;i<n;i++) Pop(&Stack1,&Item1);
    printf("Question c: x=%d",Item1);
    TraverseStack(Stack1);
    printf("\n");

    for(i=0;i<n;i++){
        Pop(&Stack1,&Item1);
        Push(&tmpStack,Item1);
    }
    printf("Question d: x=%d",Item1);
    for(i=0;i<n;i++){
        Pop(&tmpStack,&Item1);
        Push(&Stack1,Item1);
    }
    TraverseStack(Stack1);
    printf("\n");

    while(!EmptyStack(Stack1)){
        Pop(&Stack1,&Item1);
        Push(&tmpStack,Item1);
    }
    printf("Question e: x=%d",Item1);
    while(!EmptyStack(tmpStack)){
        Pop(&tmpStack,&Item1);
        Push(&Stack1,Item1);
    }
    TraverseStack(Stack1);
    printf("\n");

    while(Stack1.Top>=2){
        Pop(&Stack1,&Item1);
        Push(&tmpStack,Item1);
    }
    printf("Question f: x=%d",Item1);
    while(tmpStack.Top>=0){
        Pop(&tmpStack,&Item1);
        Push(&Stack1,Item1);
    }
    TraverseStack(Stack1);
    printf("\n");

    while(!EmptyStack(Stack1)){
        Pop(&Stack1,&Item1);
    }
    printf("Question g: x=%d",Item1);
}

void CreateStack(StackType *Stack){
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack) {
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack) {
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item) {
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item) {
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

 void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}

