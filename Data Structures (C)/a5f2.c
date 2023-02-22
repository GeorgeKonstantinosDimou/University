#include <stdio.h>

#define StackLimit 15

typedef int StackElementType;

typedef struct{
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;


//Δωσμένες συναρτήσεις
void CreateStack(StackType *Stack);
void Push(StackType *Stack, StackElementType Item);
void TraverseStack(StackType Stack);
void Pop(StackType *Stack, StackElementType *Item);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);

int main(){

    int i,n;
    char letter,letter1;
    StackElementType stack_item,stack_item_assi,x,temp,tempe,tempf;
    StackType Stack1,Stackassistant;

    CreateStack(&Stack1);       //Δημιουργία stack και ανάθεση τιμών 10πλάσιες του όρου i
    for(i=0;i<StackLimit;i++){
        stack_item_assi = i * 10;
        Push(&Stack1,stack_item_assi);
    }

    TraverseStack(Stack1); // Eκτύπωση stack

    printf("Give nth element (n<=6)");
    scanf("%d",&n);
    printf("\n");

    for(i=0;i<2;i++){
        x = Stack1.Element[Stack1.Top];       //Ανάθεση τιμής στην χ
        Pop(&Stack1,&Stack1.Element[Stack1.Top]);//"Διαγραφή" των 2 τελευταίων στοιχείων
    }

    printf("Question a: x=%d",x);
    TraverseStack(Stack1);
    printf("\n");


    temp = Stack1.Element[Stack1.Top];          //Ερώτημα β
    Pop(&Stack1,&Stack1.Element[Stack1.Top]);  // Ανάθεση σε temp της top τιμής με σκοπό
    x = Stack1.Element[Stack1.Top];            //να ξαναγίνει push μετά
    Push(&Stack1,temp);

    printf("Question b: x=%d",x);
    TraverseStack(Stack1);
    printf("\n");


    for(i=0;i<n;i++){
        x = Stack1.Element[Stack1.Top];           //Ερώτημα γ Ανάθεση τιμής στην χ
        Pop(&Stack1,&Stack1.Element[Stack1.Top]);//"Διαγραφή" των n τελευταίων στοιχείων
    }

    printf("Question c: x=%d",x);
    TraverseStack(Stack1);
    printf("\n");


    //Δημιουργία βοηθητικής στοίβας για ερώτημα δ

    CreateStack(&Stackassistant);
    for(i=0;i<Stack1.Top-1;i++){
        Push(&Stackassistant,Stack1.Element[i]);
        if(Stackassistant.Top == 0) tempe = Stackassistant.Element[Stackassistant.Top]; //cheat βοηθητική tempe για το ερωtημα e
        if(Stackassistant.Top == 2) tempf = Stackassistant.Element[Stackassistant.Top]; //cheat βοηθητική tempe για το ερωtημα f
    }
    x = Stackassistant.Element[Stackassistant.Top];

    printf("Question d: x=%d",x);
    TraverseStack(Stack1);
    printf("\n");

    x = tempe;                          //Eρώτημα e
    printf("Question e: x=%d",x);
    TraverseStack(Stack1);
    printf("\n");

    x = tempf;                         //Ερώτημα f
    printf("Question f: x=%d",x);
    TraverseStack(Stack1);
    printf("\n");


    while(!EmptyStack(Stack1)){
        Pop(&Stack1,&Stack1.Element[Stack1.Top]);
    }
    x = tempe;
    printf("Question g: x=%d",x);
    TraverseStack(Stack1);
}

void CreateStack(StackType *Stack){

    Stack -> Top = -1;
}

void Push(StackType *Stack, StackElementType Item) {

    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

 void TraverseStack(StackType Stack){

    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}

void Pop(StackType *Stack, StackElementType *Item) {

    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

boolean EmptyStack(StackType Stack) {

    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack) {

    return (Stack.Top == (StackLimit - 1));
}



