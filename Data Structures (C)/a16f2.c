#include <stdio.h>

#define StackLimit 80

typedef struct{
    int Tshirtprize;
    char Tshirtsize;
}StackElementType;

typedef struct{
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);

int main(){

    int i;

    int numboftShirts;
    char wantedshirt;
    boolean found;

    StackElementType tshirtfeatures,temp;
    StackType ClothesInThebox,ClothesOutofTheBox;

    printf("Give number of items ");       //������� 1
    scanf("%d",&numboftShirts);

    CreateStack(&ClothesInThebox);
    CreateStack(&ClothesOutofTheBox);

    printf("Give the items to store\n");    //������� 2
    for(i=0;i<numboftShirts;i++){
        printf("Give prize ");
        scanf("%d",&tshirtfeatures.Tshirtprize);
        getchar();
        printf("Give size ");
        scanf("%c",&tshirtfeatures.Tshirtsize);
        getchar();
        Push(&ClothesInThebox,tshirtfeatures);
    }
    printf("Items in the box");             //������� 3
    TraverseStack(ClothesInThebox);

    printf("What size do you want? " );     ///������� 4
    scanf("%c",&wantedshirt);

    found = FALSE;                        ///��� ������� �� ���������
    while(!(found || EmptyStack(ClothesInThebox)) ){
        Pop(&ClothesInThebox,&tshirtfeatures);      ///���� �� ������� ������� �� ��������� ��� ��� ��� ������ ��� �� ���������� ���� ����
        if(tshirtfeatures.Tshirtsize == wantedshirt){  ///��� ������ ��������� � ���������
            found = TRUE;
        }
        else{
            Push(&ClothesOutofTheBox,tshirtfeatures);
        }
    }

    if(found){
        printf("Found the size %c\n",wantedshirt);
    }
    else printf("Not Found the size %c",wantedshirt);

    printf("\n");
    printf("Items in the box");     ///������� 5
    TraverseStack(ClothesInThebox);

    printf("\n");

    printf("Items out of the box");
    TraverseStack(ClothesOutofTheBox);

    while(!(EmptyStack(ClothesOutofTheBox))){       ///������� 6
        Pop(&ClothesOutofTheBox,&tshirtfeatures);
        Push(&ClothesInThebox,tshirtfeatures);
    }

    printf("Items in the box");     ///������� 7
    TraverseStack(ClothesInThebox);

    printf("\n");

    printf("Items out of the box");
    TraverseStack(ClothesOutofTheBox);
 //   while(!(EmptyStack(ClothesOutofTheBox))){
 //       Pop(&ClothesOutofTheBox,&tshirtfeatures);
 //       Push(&ClothesInThebox,tshirtfeatures);
 //   }
 //   Push(&ClothesOutofTheBox,temp);             ///������� ��� temp ����������

}


void CreateStack(StackType *Stack){

    Stack -> Top = -1;
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

void TraverseStack(StackType Stack){

//������������� ��������� ��� �������� ��� ���
//�������� ��� ��� �����

    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%c, %d\n",Stack.Element[i].Tshirtsize,Stack.Element[i].Tshirtprize);
    }
    printf("\n");
}

boolean FullStack(StackType Stack){

    return (Stack.Top == (StackLimit - 1));
}

boolean EmptyStack(StackType Stack){

    return (Stack.Top == -1);
}

