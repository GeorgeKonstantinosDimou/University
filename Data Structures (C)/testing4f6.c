#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define HMax 9              /*     �� ������� ��� ������ HashTable
                                ���������� ��� �� 5 */
#define VMax 30             /*�� ������� ��� ������,
                                ���������� ��� �� 30 */
#define EndOfList -1        /* ������ ��� ����������� �� ����� ��� ������
                                ��� ��� ���� ��������� ��������� */

typedef struct{
 char onoma[10], eponymo[20];
 char tel[11];
 int code;
} ListElementType;  /*����� ��������� ��� �� �������� ��� ������
                               * ���������� ����� int */
typedef char KeyType[32];

typedef struct {
	KeyType RecKey;
	ListElementType Data;
	int Link;
} ListElm;

typedef struct  {
	int HashTable[HMax];   // ������� ������� ���� ��� ��������� ���������
    int Size;                // ������ �������� ��� ������ List
	int SubListPtr;          // D������� �� ��� �������� ���������
    int StackPtr;           // ������� ���� ��� ����� �������� ���� ��� ������ List
	ListElm List[VMax];
} HashListType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateHashList(HashListType *HList);
int HashKey(KeyType Key);
boolean FullHashList(HashListType HList);
void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void AddRec(HashListType *HList,ListElm InRec);
void DeleteRec(HashListType *HList,KeyType DelKey);
int findAverage(KeyType key);

int HashKey(KeyType Key)
/* �������:    ��� ���� Key ���� ��������.
   ����������: ������� ��� ���� ��������������� HValue ��� �� ������ Key.
   ����������: ��� ���� ��������������� HValue
*/
{
	/*�� ��������� ��� �� KeyType ��� ����� ��������
	�� ������ �� ������������ ��������� �� ������ �� ������*/
	int average;
	average=findAverage(Key);
	return average%9;
}

void CreateHashList(HashListType *HList)
/* ����������: ���������� ��� ���� HList.
   ����������: ��� ���� HList
*/
{
	int index;

	HList->Size=0;           //���������� ��� ���� �����
	HList->StackPtr=0;       //������� ��� ������ ��� ������� ��� ��������� ������

    /*����������� ��� ������ HashTable ��� ����� HList ���� ���� ��������� ���
        �� ���� �� ���� EndOfList (-1)*/
    index=0;
	while (index<HMax)
	{
		HList->HashTable[index]=EndOfList;
		index=index+1;
    }

     //���������� ��� ������� ��� ��������� ������ ��� ����� HList
    index=0;
	while(index < VMax-1)
	{
		HList->List[index].Link=index+1;
		index=index+1;
	}
	HList->List[index].Link=EndOfList;
}

boolean FullHashList(HashListType HList)
/* �������:    ��� ���� HList.
   ����������: ������� �� � ����� List ��� ����� HList ����� ������.
   ����������: TRUE �� � ����� List ����� ������, FALSE �����������.
*/
{
	return(HList.Size==VMax);
}

void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
/* �������:     ��� ���� HList ��� ��� ���� �������� KeyArg.
    ����������: ������� ��� ������� �� ������ KeyArg ���� �������� ���������.
    ����������: �� ���� Loc ��� �������� ��� �� ���� Pred ��� ������������
                �������� ���� ��������
*/
{
	int Next;
	Next=HList.SubListPtr;
	*Loc=-1;
	*Pred=-1;
	while(Next!=EndOfList)
	{
		if (strcmp(HList.List[Next].RecKey, KeyArg)==0)  //strcmp(HList.List[Next].RecKey,KeyArg)
		{
			*Loc=Next;
			Next=EndOfList;
		}
		else
		{
			*Pred=Next;
			Next=HList.List[Next].Link;
		}
	}
}
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
/* �������:     ��� ���� HList ��� ��� ���� �������� KeyArg.
    ����������: ������� ��� ������� �� ������ KeyArg ��� ���� HList.
    ����������: �� ���� Loc ��� �������� ��� �� ���� Pred ���
                ������������ �������� ��� ��������� ���� ����� ������.
                �� ��� ������� ������� �� ������ KeyArg ���� Loc=Pred=-1
*/
{
	int HVal;
	HVal=HashKey(KeyArg);
    if (HList.HashTable[HVal]==EndOfList)
	{
		*Pred=-1;
		*Loc=-1;
	}
	else
	{
		HList.SubListPtr=HList.HashTable[HVal];
		SearchSynonymList(HList,KeyArg,Loc,Pred);
	}
}

void AddRec(HashListType *HList,ListElm InRec)
/* �������:    ��� ���� HList ��� ��� ������� InRec.
   ����������: ������� ��� ������� InRec ��� ����� List, �� ��� ����� ������,
                ��� ���������� �� ���� HList.
   ����������: ��� ������������� ���� HList.
   ������:     ������ ������� ������, �� � List ����� ������, �����������,
                �� ������� ��� ������� �� �� ���� ������,
                �������� ����������� ���������
*/
{
	int Loc, Pred, New, HVal;

   // New=0;
	if(!(FullHashList(*HList)))
	{
		Loc=-1;
		Pred=-1;
		SearchHashList(*HList,InRec.RecKey,&Loc,&Pred);
		if(Loc==-1)
		{
			HList->Size=HList->Size +1;
			New=HList->StackPtr;
			HList->StackPtr=HList->List[New].Link;
			HList->List[New]=InRec;
			if (Pred==-1)
			{
			    HVal=HashKey(InRec.RecKey);
                HList->HashTable[HVal]=New;
				HList->List[New].Link=EndOfList;
			}
			else
			{
                HList->List[New].Link=HList->List[Pred].Link;
				HList->List[Pred].Link=New;
			}
		}

		else
		{
			printf("YPARXEI HDH EGGRAFH ME TO IDIO KLEIDI \n");
		}
	}
	else
	{
		printf("Full list...");
	}
}
void DeleteRec(HashListType *HList,KeyType DelKey)
/* DEXETAI:    TH DOMH (HList) KAI To KLEIDI (DelKey) THS EGGRAFHS
               POY PROKEITAI NA DIAGRAFEI
   LEITOYRGIA: DIAGRAFEI, THN EGGRAFH ME KLEIDI (DelKey) APO TH
               LISTA (List), AN YPARXEI ENHMERWNEI THN DOMH HList
   EPISTREFEI: THN TROPOPOIHMENH DOMH (HList)
   EJODOS:     "DEN YPARXEI EGGRAFH ME KLEIDI" MHNYMA
*/
{
	int Loc, Pred, HVal;

	SearchHashList(*HList,DelKey,&Loc,&Pred);
	if(Loc!=-1)
	{
		if(Pred!=-1)
		{
			HList->List[Pred].Link=HList->List[Loc].Link;
		}
		else
		{
			HVal=HashKey(DelKey);
		    HList->HashTable[HVal]=HList->List[Loc].Link;
		}
		HList->List[Loc].Link=HList->StackPtr;
		HList->StackPtr=Loc;
		HList->Size=HList->Size -1;
	}
	else
	{
		printf("DEN YPARXEI  EGGRAFH ME KLEIDI %s \n",DelKey);
	}
}

void PrintPinakes(HashListType HList);
void BuildHashList(HashListType *HList);
void Search_HashList_By_Subject(HashListType HList, int code);

int main(){
 HashListType hlist;
 ListElm item;
 char ans;
 int loc, pred, code;

 printf("1. Create hash list\n");
 CreateHashList(&hlist);
 BuildHashList(&hlist);
 PrintPinakes(hlist);

 printf("2. Insert new teacher\n");
 do{
    printf("Enter teacher's name: ");
    scanf("%s",item.Data.onoma);
    getchar();
    printf("Enter teacher's surname: ");
    scanf("%s",item.Data.eponymo);
    getchar();
    printf("Enter teacher's phone: ");
    scanf("%s",item.Data.tel);
    getchar();
    printf("Enter teacher's code: ");
    scanf("%d",&item.Data.code);
    getchar();

    strcpy(item.RecKey,item.Data.onoma);
    strcat(item.RecKey," ");
    strcat(item.RecKey, item.Data.eponymo);
    AddRec(&hlist,item);
    printf("Continue? Y/N: ");
    do{
            scanf("%c",&ans);
     }while(toupper(ans)!='Y' && toupper(ans)!='N');
   }while(toupper(ans)=='Y');
   PrintPinakes(hlist);

   printf("3. Delete a teacher\n");
   printf("Enter teacher's name: ");
   scanf("%s",item.Data.onoma);
   getchar();
   printf("Enter teacher's surname: ");
   scanf("%s",item.Data.eponymo);
   getchar();
   strcpy(item.RecKey,item.Data.onoma);
   strcat(item.RecKey," ");
   strcat(item.RecKey, item.Data.eponymo);
   DeleteRec(&hlist,item.RecKey);
   PrintPinakes(hlist);

   printf("Search for a teacher\n");
   printf("Enter teacher's name: ");
   scanf("%s",item.Data.onoma);
   getchar();
   printf("Enter teacher's surname: ");
   scanf("%s",item.Data.eponymo);
   getchar();
   strcpy(item.RecKey,item.Data.onoma);
   strcat(item.RecKey," ");
   strcat(item.RecKey, item.Data.eponymo);
   SearchHashList(hlist,item.RecKey,&loc,&pred);
    if(loc==-1){
        printf("DEN YPARXEI EGGRAFH ME KLEIDI %s\n",item.RecKey);
    }
    else{

        printf("[%s,%s,%d]\n",hlist.List[loc].RecKey, hlist.List[loc].Data.tel , hlist.List[loc].Data.code);
    }

    printf("5. Search by subject\n");
    printf("Enter code: ");
    scanf("%d",&code);
    Search_HashList_By_Subject(hlist,code);
 return 0;
}

void PrintPinakes(HashListType HList)
{
    int i;
	printf("Hash table\n");
	for (i=0; i<HMax;i++)
              printf("%d, ",HList.HashTable[i]);

	printf("\nHash List\n");
    for (i=0;i<HList.Size;i++)
	   printf("%d) %s, %d\n",i,HList.List[i].RecKey,HList.List[i].Link);
	printf("\n");
}

int findAverage(KeyType key){
 char first, last;
 int average;

 //printf("%d", (int) strlen(key));
 first=toupper(key[0]);
 last=toupper(key[strlen(key)-1]);

 first-=64;
 last-=64;

 average=(first+last)/2;
 return average;
}

void BuildHashList(HashListType *HList){
 FILE *f;
 int nscan;
 char termch;
 //char space[1]={' '};
 ListElm item;

 f=fopen("i4f6.txt","r");
 if(f==NULL){
    return;
 }
 while(1){
    nscan=fscanf(f,"%10[^,],%20[^,],%10[^,],%d%c", item.Data.onoma, item.Data.eponymo, item.Data.tel, &item.Data.code, &termch);

   if(nscan==EOF){
    break;
  }
   if(nscan!=5){
    printf("invalid file format\n");
    break;
   }

  strcpy(item.RecKey,item.Data.onoma);
  strcat(item.RecKey," ");
  strcat(item.RecKey, item.Data.eponymo);
  AddRec(HList,item);
}

}

void Search_HashList_By_Subject(HashListType HList, int code){
  int sublist;
  for(int i=0;i<HMax;i++){
    sublist=HList.HashTable[i];
    while(sublist!=EndOfList){
        if(HList.List[sublist].Data.code == code){
            printf("%d: [%s %s,%s,%d]\n",sublist, HList.List[sublist].Data.onoma, HList.List[sublist].Data.eponymo, HList.List[sublist].Data.tel, HList.List[sublist].Data.code);
        }
        sublist=HList.List[sublist].Link;
    }
  }
}
