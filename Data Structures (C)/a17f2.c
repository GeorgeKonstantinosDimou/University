#include <stdio.h>

#define StackLimit 20

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

StackType CopyStack(StackType *s1);

int main(){

    int i;
    StackElementType Item;
    StackType s1,s2;

    CreateStack(&s1);

    for(i=0;i<StackLimit;i++){
        Item = i;
        Push(&s1,Item);
    }
    printf("Stack s1");
    TraverseStack(s1);
    printf("After copying s1 to s2\n");
    s2 = CopyStack(&s1);

    printf("Stack s1");
    TraverseStack(s1);
    printf("Stack s2");
    TraverseStack(s2);
}

 void TraverseStack(StackType Stack){

    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}

void CreateStack(StackType *Stack) {

    Stack -> Top = -1;
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


StackType CopyStack(StackType *s1){


    StackElementType AnItem;
    StackType s2,temp;

    CreateStack(&s2);
    CreateStack(&temp);



    while(!EmptyStack(*s1)){      ///Προσωρινη αποθήκευση σε μια temp στοίβα
        Pop(s1,&AnItem);
        Push(&temp,AnItem);
    }

   while(!EmptyStack(temp)){    ///Εξαγωγή του στοιχείου απο την temp στοίβα στις στοίβες s1,s2
        Pop(&temp,&AnItem);
        Push(s1,AnItem);
        Push(&s2,AnItem);
    }

    return s2;
}

