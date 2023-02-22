#include <stdio.h>

#define StackLimit 80

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

    int i=0;
    StackElementType ch,AnItem;
    boolean flag=TRUE;

    StackType stack1;

    CreateStack(&stack1);

    printf("Enter string:");

    do{
    scanf("%c", &ch); getchar();

    while(ch != '\r' && ch != 'C'){         ///Γέμιστα της 1ης στοίβας μέχρι τον χαρακτήρα C η enter
        if(ch != '#'){
        Push(&stack1,ch);
        scanf("%c", &ch); getchar();
        }
        else return 0;
    }

    while(flag){                            ///Ταυτόχρονη εισαγωγή και έλεγχος μεταξύ
        scanf("%c", &ch); getchar();
        if(ch != '#'){
        if(ch == stack1.Element[stack1.Top]){
            Pop(&stack1,&AnItem);
        }
        else {
            flag = FALSE;
        }
        }
        else break;
    }
    break;
    }while(ch != '#');

    //printf("%d",flag);
    printf(flag ? "True" : "False");
}

void CreateStack(StackType *Stack){

    Stack -> Top = -1;
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
