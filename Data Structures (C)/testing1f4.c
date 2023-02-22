///dai18069
///FINISHED!!
//Copyrights reserved 2021
/*�� ���������� � ��������� Search �� �� �������� ���������: boolean Search(ListPointer FreePtr, ListPointer List, NodeType Node[NumberOfNodes], ListElementType Item, ListPointer *PredPtr);
� ����� �� ������� ��� ����������� �����  (��) ����������� �� ������ (���������� FreePtr, List, Node) ��� ��� ��������
Item ��� �� ���������� boolean ���� � ����� ������� �� ������� � ��� �� ������������ �������� Item ��� �� ��� �� ����
(PredPtr) ��� ��������� ��� ����� ����������� ��� Item, ���� � �� ��� �� �������� ���� ��� �������� � �� ��������
��� ��������� Item  �� ����� ������������  (����� ��� Search  ���� ���  �������� � �� �������� ��������� ��� ��). �
�������� ��������� ���� �.�. ������� ������������ ��� ��������� ��� �� ������ �Continue Y/N:�  (��� �����������
���������).  ��� �� ������������� ��������. H ��������� Search �� ������ 2 ����� ��� ��� �������� ��� ������� ��� ��
��� ��� ��� �������� ��� ��� ������� ��� ��. �� �� �������� ������ �� ��������� �� ������ �The number is in the list and its predecessor is in position� ��� ��� ���� ��� PredPtr, ����������� �� ��������� �� ������ �The number is not in the list�. ��
��������� �� ������ �� ������� ���� ����� ��� �������� ����������� ��� �� ������� ��� ����������� �� �������� ��� ��
main().
A. ������������ storage pool
B. ���������� ��� (������� ������� 10)
C. �������� ��� storage pool
D. �������� ��� ��������� ��� ��
E. �������� ��������� ���� ��. ���� ��� ���� �������� ��������� ��� �� ���� �� ������ �� ��������� ������������
�� ������� ������� (����� ��� Search ���� ��� �������� ��������� ��� ��)
F. �������� ��� storage pool
G. �������� ��� ��������� ��� ��
H. ������� ��� � �� ����� �����. �� � �� ����� ����� ��������� ������ �Empty List� ����������� �Not an Empty List�
I. ������� ��� � �� ����� ������. �� � �� ����� ������ ��������� ������ �Full List� ����������� �Not a Full List�
J. ��������� ���� ��������� ��� �� (��� �������� ��� ������� ��� �� ��� ��� �������� ��� ��� �������).*/

#include <stdio.h>
#include <stdlib.h>

#define NumberOfNodes 10

#define NilValue -1         // ������ �������� ���� ������� �� ����� ��� ����.������


typedef int ListElementType; /*����� ��������� ��� �� �������� ��� ������������ ������,
                                ���������� ���������� � ����� int */
typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;

typedef enum {
    FALSE, TRUE
} boolean;


boolean Search(ListPointer FreePtr, ListPointer List, NodeType Node[NumberOfNodes], ListElementType Item, ListPointer *PredPtr);
void printALL(ListPointer List,ListPointer FreePtr,NodeType Node[]);
void printer(char questionletter);

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
boolean FullList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void ReleaseNode(NodeType Node[NumberOfNodes], ListPointer P, ListPointer *FreePtr);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr);
void TraverseLinked(ListPointer List, NodeType Node[]);

int main(){

    NodeType Node1[NumberOfNodes];
    ListPointer Alist;
    ListPointer FreePtr,PredPtr;
    ListElementType AnItem;

    int i;
    char letter,answer;

    InitializeStoragePool(Node1,&FreePtr);     ///Question A
    CreateList(&Alist);                    ///Question B

    letter='C';

    printer(letter);
    printALL(Alist,FreePtr,Node1);          ///Question C

    letter='D';                            ///Question D
    printer(letter);
    TraverseLinked(Alist,Node1);

    letter='E';
    printer(letter);
    do{
        printf("Give a number: ");
        scanf("%d",&AnItem);
        Search(FreePtr,Alist,Node1,AnItem,&PredPtr);
        Insert(&Alist,Node1,&FreePtr,PredPtr,AnItem);
        printf("\n");
        printf("Continue Y/N: ");
        scanf("%c",&answer);
        while (answer!='N' && answer!='Y' && answer!='n' && answer!='y'){
            scanf("%c",&answer);
        }
    }while(answer!='n' && answer!='N');

    letter='F';
    printer(letter);
    printALL(Alist,FreePtr,Node1);          ///Question E

    letter='G';
    printer(letter);
    TraverseLinked(Alist,Node1);          ///Question G

    letter='H';
    printer(letter);
    if(EmptyList(Alist))printf("Empty List\n");
    else printf("Not an Empty List\n");       ///Question H


    letter='I';
    printer(letter);
    if(FullList(FreePtr))printf("Full List\n");              ///Question I
    else printf("Not a full List\n");

    letter='J';
    printer(letter);
    for(i=0;i<2;i++){
    printf("Give me a number ");
    scanf("%d",&AnItem);
    printf("\n");
    if(Search(FreePtr,Alist,Node1,AnItem,&PredPtr))printf("The number is in the list and its predecessor is in potition %d\n",PredPtr);
    else printf("The number is not in the list");
    }
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

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data=-1;    /* ��� ����� �������� � ������� ������� ����� ��� ����� ��� ���������, ������� ���� �������� */
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data=-1;
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
  Node[P].Data = -1; /* ��� �������� ������, ��������� ��� �� ��������� ����
                        �������� �� ������������ ������ */
  *FreePtr =P;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
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
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data =Item;
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
          printf("(%d: %d->%d) ",CurrPtr,Node[CurrPtr].Data, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}

void printALL(ListPointer List,ListPointer FreePtr,NodeType Node[]){

    int i;

    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n",List,FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for(i=0;i<NumberOfNodes;i++){
        printf("(%d: %d->%d) ",i,Node[i].Data,Node[i].Next);
    }
    printf("\n");
}

void printer(char questionletter){

    printf("---------------Question %c--------------------\n",questionletter);
    if(questionletter=='C' || questionletter=='F') printf("--------------Storage pool------------------\n");
    else if(questionletter=='D' || questionletter=='G') printf("--------------Linked List------------------\n");
    else if(questionletter=='J') printf("---------------Search for a number---------------\n");
    else printf("\n");
}

boolean Search(ListPointer FreePtr, ListPointer List, NodeType Node[NumberOfNodes], ListElementType Item, ListPointer *PredPtr){

    ListPointer CurrPtr;

    boolean stop=FALSE;
    boolean found=FALSE;

    *PredPtr = NilValue;

    if(!EmptyList(List)){
        CurrPtr=List;
        while(CurrPtr!=NilValue && (!stop)){
            if(Node[CurrPtr].Data>=Item){
                stop=TRUE;
                found=Node[CurrPtr].Data==Item;
            }
            else{
                *PredPtr=CurrPtr;
                CurrPtr=Node[CurrPtr].Next;
            }
        }
    }
    else found=FALSE;
    return found;
}
