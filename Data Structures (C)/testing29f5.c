///dai18069 2021
///FINISHED PRODUCT!!!
/*������ ��������� ��� �� ������� ��� ���� ����� ��� ���� (��������), ��� ��� (��������), ��� ������ (��������). ��
��������� �� �������� ��� ���� ������   �� 2 ����������  ������� �� ��� ������ ���, ������ �� ������ ��������� � ���
��� 60 ���� ��� ������ �� ������ ���������� ��� 60.
���� ��������� �� ������ �� ��������� ��  ��� �� ������ ���  ����. �� ��������� �� ������������ ��� ����
�����������
-  �������� ��� ��������� ��� ���� ������ ��� ���������� ��� ������� �� ��� ������ ��� (��� ��� ����� �� �������
<=60 ��� ��� ��� ����� �� ������� > 60). ��� ��� 2 ��� �� ������ �� ����� � ����.
-  �������� ��� 2 ���������
-  ��������� ������ �� ���� ��� ���� ��� ��� ������.   ������� ��� ����������� ��������� ���� �������� ��� �� ������� �� �������� ��� ��������� ��� � �������� ���
���� ���������. � ��������� �� ����� ��� 3  �����: �) ��� ����� ��� ������ �� �������� ����� �����������  �� ��� ��
���  2 ���������  (����, ������), �)  ��� ����� ��� ������  �� ���� ��� ���� ����������� ���� ���������� ��������
���� � ������ ��� ��� ���������� �� �� ������� ��� �)  ���  �����  ��� ������ �� ����  ��� ����  ����������� �� ������
��������. �� �������� ��� ���� ���������� ��������� ��� ����������� ���������.
  (��� ��� ���������� ��� ��������� ��������� ������� ����� ����� ��� ����, ���, ������) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int amka, afm, age;
}BinTreeElementType;        /*� ����� ��� ��������� ��� ���
                                        ���������� ����� int */
typedef struct BinTreeNode *BinTreePointer;
typedef struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} BinTreeNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void InorderTraversal(BinTreePointer Root);

int main(){

    BinTreePointer ARoot,BRoot,LocPtr;
    BinTreeElementType AnItem;

    char answer;
    int i;
    boolean found=TRUE;

    CreateBST(&ARoot);
    CreateBST(&BRoot);

    do{
        printf("Give AMKA?");
        scanf("%d",&AnItem.amka);
        printf("Give AFM?");
        scanf("%d",&AnItem.afm);
        printf("Give Age?");
        scanf("%d",&AnItem.age);
        if(AnItem.age<=60){
            BSTInsert(&ARoot,AnItem);
        }
        else
            BSTInsert(&BRoot,AnItem);
        printf("\n");
        printf("Continue Y/N:");
        do{
            scanf("%c",&answer);
        }while(answer!='N' && answer!='n' && answer!='Y' && answer!='y');
    }while(answer!='N' && answer!='n');

    printf("people with age less-equal 60\n");
    InorderTraversal(ARoot);
    printf("\n");
    printf("people with age greater 60\n");
    InorderTraversal(BRoot);
    printf("\n");

    for(i=0;i<3;i++){
        printf("Give AMKA:");
        scanf("%d",&AnItem.amka);
        printf("Give Age:");
        scanf("%d",&AnItem.age);
        if(AnItem.age<=60){
            BSTSearch(ARoot,AnItem,&found,&LocPtr);
        }
        else{
            BSTSearch(BRoot,AnItem,&found,&LocPtr);
        }
        if(found==TRUE){
            if(AnItem.age==LocPtr->Data.age)printf("The person with AMKA %d,AFM %d and age %d is in the catalogue\n", AnItem.amka, AnItem.afm, AnItem.age);
            else if(AnItem.age!=LocPtr->Data.age)printf("The person with AMKA %d has age %d different from the person you are looking for\n", AnItem.amka, LocPtr->Data.age);
        }
        else printf("The person with AMKA %d and age %d is Unknown\n", AnItem.amka, AnItem.age);
    }
}

void CreateBST(BinTreePointer *Root)
/* ����������: ���������� ��� ���� ���.
   ����������:  ��� �������� ������(NULL) Root
*/
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
/* �������:   ��� ��� �� �� Root �� ������� ��� ���� ���.
  ����������: ������� �� �� ��� ����� ����.
  ����������: TRUE �� �� ��� ����� ���� ��� FALSE �����������
*/
{   return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* �������:     ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� �������� Item.
   ����������:  ������� �� �������� Item ��� ���.
   ����������: �� ������������� ��� �� ��� ������ Root �� ������� ��� ���� ���
*/
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (Item.amka < LocPtr->Data.amka)
            LocPtr = LocPtr ->LChild;
        else if (Item.amka > LocPtr ->Data.amka)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("To %d EINAI HDH STO DDA\n", Item);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        LocPtr ->Data = Item;
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (Item.amka < Parent ->Data.amka)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
                BinTreePointer *LocPtr)
/* �������:    ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
   ����������: ������� ��� ��� ���� ����� �� ���� KeyValue ��� ����� ������ ���.
   ����������: � Found ���� ���� TRUE ��� � ������� LocPtr ������� ���� ����� ���
                �������� ��� ���� KeyValue, �� � ��������� ����� ��������.
                ����������� � Found ���� ���� FALSE
*/
{

    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
        if (KeyValue.amka < (*LocPtr)->Data.amka)
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (KeyValue.amka > (*LocPtr)->Data.amka)
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
    }
}



void InorderTraversal(BinTreePointer Root)
/* �������:    ��� ������� ������ �� �� ������ Root �� ������� ���� ���� ���.
   ����������: ������� ���������������� �������� ��� �������� ������� ���
                ������������� ���� ����� ������� ��� ����.
   ���������: �� ����������� ��� ������, ��� ��������� ��� �� ����� ��� ������������
*/
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("(%d, %d, %d)",Root->Data.amka,Root->Data.afm,Root->Data.age);
        InorderTraversal(Root->RChild);
    }
}
