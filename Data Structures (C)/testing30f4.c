#include <stdio.h>
#include <stdlib.h>

#define StackLimit 10
#define NumberOfNodes 10   //���� �������� ��� ������������ ������,

#define NilValue -1          // ������ �������� ���� ������� �� ����� ��� ����.������

typedef int ListPointer; //����� ��������� ��� �� �������� ��� ������������ ������,

typedef struct{
    int AM;
    float Grade;
} ListElementType;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;

typedef enum {
    FALSE, TRUE
} boolean;

typedef int StackElementType;

typedef struct  {
    int Top;
   StackElementType Element[StackLimit];
} StackType;

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
boolean FullList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void ReleaseNode(NodeType Node[NumberOfNodes], ListPointer P, ListPointer *FreePtr);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, int Item,float Anitem);
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr);
void TraverseLinked(ListPointer List, NodeType Node[]);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);
double FindMins(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack);
void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void veryUsefulMethod(char *a);
void TraverseStack(StackType Stack);

int main()
{
    ListPointer List;
    NodeType Node[NumberOfNodes];
    ListPointer FreePtr,PredPtr;
    int am;
    float Grade;

    StackType Stack;
    StackElementType mathites;
    InitializeStoragePool(Node, &FreePtr);

    CreateList(&List);

    veryUsefulMethod("Question C");
    veryUsefulMethod("Storage Pool");
    printAll(List, FreePtr, Node);

    veryUsefulMethod("Question D");
    veryUsefulMethod("Linked List");
    TraverseLinked( List, Node);

    veryUsefulMethod("Question E");
    int i;
    PredPtr = NilValue;
    for(i=0; i<5; i++){
        printf("DWSE AM GIA EISAGWGH STH LISTA: ");
        scanf("%d", &am);
        printf("DWSE VATHMO GIA EISAGWGH STH LISTA: ");
        scanf("%f", &Grade);
        Insert(&List, Node,&FreePtr, PredPtr, am, Grade);
    }

    veryUsefulMethod("Question F");
    veryUsefulMethod("Storage Pool");
    printAll(List, FreePtr, Node);

    veryUsefulMethod("Question G");
    veryUsefulMethod("Linked list");
    TraverseLinked( List, Node);

    veryUsefulMethod("Question H");
    if(EmptyList(List))
        printf("Empty List\n");
    else
        printf("Not an Empty List\n");

    veryUsefulMethod("Question I");
    if(FullList(FreePtr))
        printf("Full List\n");
    else
        printf("Not a Full List\n");

    veryUsefulMethod("Question J");
    float minGrade;
    minGrade=FindMins(List, Node, &Stack);
    printf("Min value=%f\n",minGrade);
    printf("AM with min grade are: ");
    while(!EmptyStack(Stack)){
        Pop(&Stack, &mathites);
        printf("%d",&mathites);
    }
    printf("\n");

    veryUsefulMethod("Question K");
    TraverseStack(Stack);

    veryUsefulMethod("Question L");
    veryUsefulMethod("Storage Pool");
    printAll(List, FreePtr, Node);

    veryUsefulMethod("Question M");
    veryUsefulMethod("Linked list");
    TraverseLinked( List, Node);

	return 0;
}

void veryUsefulMethod(char *a){
    printf("---------------%s--------------------\n",a);
}


double FindMins(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack){
     ListPointer CurrPtr;
     float minGrade;
     CreateStack(Stack);
     StackElementType mathites,am;
     if(!EmptyList(List)){
            CurrPtr=List;
            minGrade=Node[CurrPtr].Data.Grade;
            while (CurrPtr != NilValue){
                 if(Node[CurrPtr].Data.Grade<=minGrade){
                       if(Node[CurrPtr].Data.Grade<minGrade){
                             while(!EmptyStack(*Stack))
                                  Pop(Stack, &mathites);
                             minGrade= Node[CurrPtr].Data.Grade;
                       }
                        am=Node[CurrPtr].Data.AM;
                        Push(Stack,am);
                }

                CurrPtr=Node[CurrPtr].Next;
           }
    }
    else
            printf("Empty List...");

    return minGrade;
}

void TraverseLinked(ListPointer List, NodeType Node[])
/* �������:    ��� ����������� �����.
   ����������: ����� �������� ��� ������������ ������, �� ��� ����� ����.
   ������:     ��������� ��� ��� �����������
*/
{
    ListPointer CurrPtr;

    if (!EmptyList(List))
    {
        CurrPtr =List;
    while (CurrPtr != NilValue)
    {
        printf("(%d:<%d,%.1f>->%d) ",CurrPtr,Node[CurrPtr].Data.AM,Node[CurrPtr].Data.Grade, Node[CurrPtr].Next);
        CurrPtr=Node[CurrPtr].Next;
    }
        printf("\n");
    }
    else printf("Empty List ...\n");
}

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d:<%d,%.1f>->%d) ",i,Node[i].Data.AM, Node[i].Data.Grade,Node[i].Next);
    printf("\n");
}

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
/* �������:   ��� ������ Node ��� ��� ������ FreePtr ��� ������� ����
                ����� ��������� �����.
  ����������: ����������� ��� ������ Node �� ����������� ����� ���������� ������
                ���� ���������� �������� ��� ������,
                ��� ����������� ��� ������ FreePtr .
  ����������: ��� ������������� ������ Node ��� ���
                ������ FreePtr ��� ������ ���������� ������
*/
{
   int i;

    for (i=0; i<NumberOfNodes;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data.AM = -1;
        Node[i].Data.Grade = -1;
    }
    Node[NumberOfNodes-1].Next=NilValue;
    *FreePtr=0;
}

void CreateList(ListPointer *List)
/* ����������: ���������� ��� ���� ����������� �����.
   ����������: ���� (��������) ������ ��� ������� �� ���� �����
*/
{
  *List=NilValue;
}

boolean EmptyList(ListPointer List)
/* �������:    ���� ������ List ��� ������� �� ��� ����������� �����.
   ����������: ������� �� � ����������� ����� ����� ����.
   ����������: True �� � ����������� ����� ����� ���� ��� false �����������
*/
{
  return (List==NilValue);
}

boolean FullList(ListPointer FreePtr)
/* �������:    ��� ����������� �����.
   ����������: ������� �� � ����������� ����� ����� ������.
   ����������: True �� � ���������������� ����� ������, false �����������
*/
{
  return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
/* �������:   ��� ������ Node ��� ��� ������ FreePtr.
  ����������: ������ ���� "��������" ����� ��� ��� ������� � ������� P.
  ����������: ��� ������ P ��� ��� �������������  ������ FreePtr
                ��� ����������� ��� ����� ��������� �����
*/
{
  *P = *FreePtr;
  if (!FullList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr)
/* �������:    ��� ������ Node, ��� ���������� �� �������� ��� ���������� ������,
                ���� ������ TempPtr ��� ��� ������ FreePtr.
   ����������: ���������� ��� �������� ��� ����� ���� ����� ������� � TempPtr.
   ����������: ��� ������������� ������ Node ��� ��� ������ FreePtr
*/
{
    Node[P].Next =*FreePtr;
    Node[P].Data.AM = -1;
    Node[P].Data.Grade = 0.1;
    *FreePtr =P;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, int Item,float Anitem)
/* �������:    ��� ����������� �����, ��� ������ Node, ��� ������ PredPtr ���
                ��� �������� Item.
  ����������: ������� ��� ����������� �����, �� ��� ����� ������, �� ��������
                Item ���� ��� ��� ����� ���� ����� ������� � ������� PredPtr.
  ����������: ��� ������������� ����������� �����, ��� ������������� ������ Node
                ��� ��� ������ FreePtr.
  ������:     ������ ������� ������, �� � ����������� ����� ����� ������
*/
{
  ListPointer TempPtr;
  GetNode(&TempPtr,FreePtr,Node);
  if (!FullList(TempPtr)) {
    if (PredPtr==NilValue)
    {
        Node[TempPtr].Data.AM =Item;
        Node[TempPtr].Data.Grade =Anitem;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data.AM =Item;
        Node[TempPtr].Data.Grade =Anitem;
        Node[TempPtr].Next =Node[PredPtr].Next;
        Node[PredPtr].Next =TempPtr;
      }
}
  else
    printf("Full List ...\n");
}

void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr)
/* �������:   ��� ����������� ����� ��� ��� ������ PredPtr ��� �������
                ���� ����������� ����� ��� ����� ��� �� ���������.
  ����������: ��������� ��� �� ����������� �����, �� ��� ����� ����,
                ��� ����������� ����� ��� ����� ���� ����� ������� � PredPtr.
  ����������: ��� ������������� ����� ��� �� ������ FreePtr.
  ������:     ������ ����� ������, �� � ����������� ����� ����� ����
*/
{
  ListPointer TempPtr ;

  if (!EmptyList(*List))
    if (PredPtr == NilValue)
    {
        TempPtr =*List;
        *List =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,FreePtr);
    }
    else
      {
        TempPtr =Node[PredPtr].Next;
        Node[PredPtr].Next =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,FreePtr);
      }
  else
    printf("Empty List ...\n");
}



//�����������
// ���� � ������ ��������� �� �TOIXEIA ��� ������� ��� �� ���� 0-TOP
void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}

void CreateStack(StackType *Stack)
/* ����������: ���������� ��� ���� ������.
   ����������: ���� ������.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* �������: ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ����.
   ����������: True �� � Stack ����� ����, False �����������
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* �������: ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ������.
   ����������: True �� � Stack ����� ������, False �����������
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* �������: ��� ������ Stack ��� ��� �������� Item.
   ����������: ������� �� �������� Item ���� ������ Stack �� � Stack ��� ����� ������.
   ����������: ��� ������������� Stack.
   ������: ������ ������� �������, �� � ������ Stack ����� ������
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* �������: ��� ������ Stack.
   ����������: ��������� �� �������� Item ��� ��� ������ ��� ������� �� � ������ ��� ����� ����.
   ����������: �� �������� Item ��� ��� ������������� Stack.
   ������:  ������ ����� ������� �� � Stack ����� ����
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

