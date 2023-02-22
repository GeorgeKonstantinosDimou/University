#include <stdio.h>
#include <stdlib.h>

#define StackLimit 10
#define NumberOfNodes 10   //όριο μεγέθους της συνδεδεμένης λίστας,

#define NilValue -1          // ειδική μεδενικη τιμη δείχνει το τέλος της Συνδ.λίστας

typedef int ListPointer; //τύπος δεδομένων για τα στοιχεία της συνδεδεμένης λίστας,

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
/* Δέχεται:    Μια συνδεδεμένη λίστα.
   Λειτουργία: Κάνει διάσχιση της συνδεδεμένης λίστας, αν δεν είναι κενή.
   Έξοδος:     Εξαρτάται από την επεξεργασία
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
/* Δέχεται:   Τον πίνακα Node και τον δείκτη FreePtr που δείχνει στον
                πρώτο διαθέσιμο κόμβο.
  Λειτουργία: Αρχικοποιεί τον πίνακα Node ως συνδεδεμένη λίστα συνδέοντας μεταξύ
                τους διαδοχικές εγγραφές του πίνακα,
                και αρχικοποιεί τον δείκτη FreePtr .
  Επιστρέφει: Τον τροποποιημένο πίνακα Node και τον
                δείκτη FreePtr του πρώτου διαθέσιμου κόμβου
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
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη λίστα.
   Επιστρέφει: Έναν (μηδενικό) δείκτη που δείχνει σε κενή λίστα
*/
{
  *List=NilValue;
}

boolean EmptyList(ListPointer List)
/* Δέχεται:    Έναν δείκτη List που δείχνει σε μια συνδεδεμένη λίστα.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη λίστα είναι κενή.
   Επιστρέφει: True αν η συνδεδεμένη λίστα είναι κενή και false διαφορετικά
*/
{
  return (List==NilValue);
}

boolean FullList(ListPointer FreePtr)
/* Δέχεται:    Μια συνδεδεμένη λίστα.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη λίστα είναι γεμάτη.
   Επιστρέφει: True αν η συνδεδεμένηλίστα είναι γεμάτη, false διαφορετικά
*/
{
  return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
/* Δέχεται:   Τον πίνακα Node και τον δείκτη FreePtr.
  Λειτουργία: Αποκτά έναν "ελεύθερο" κόμβο που τον δείχνει ο δείκτης P.
  Επιστρέφει: Τον δείκτη P και τον τροποποιημένο  δείκτη FreePtr
                που δεικτοδοτεί στο πρώτο διαθέσιμο κόμβο
*/
{
  *P = *FreePtr;
  if (!FullList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr)
/* Δέχεται:    Τον πίνακα Node, που αναπαριστά τη δεξαμενή των διαθέσιμων κόμβων,
                έναν δείκτη TempPtr και τον δείκτη FreePtr.
   Λειτουργία: Επιστρέφει στη δεξαμενή τον κόμβο στον οποίο δείχνει ο TempPtr.
   Επιστρέφει: Τον τροποποιημένο πίνακα Node και τον δείκτη FreePtr
*/
{
    Node[P].Next =*FreePtr;
    Node[P].Data.AM = -1;
    Node[P].Data.Grade = 0.1;
    *FreePtr =P;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, int Item,float Anitem)
/* Δέχεται:    Μια συνδεδεμένη λίστα, τον πίνακα Node, τον δείκτη PredPtr και
                ένα στοιχείο Item.
  Λειτουργία: Εισάγει στη συνδεδεμένη λίστα, αν δεν είναι γεμάτη, το στοιχείο
                Item μετά από τον κόμβο στον οποίο δείχνει ο δείκτης PredPtr.
  Επιστρέφει: Την τροποποιημένη συνδεδεμένη λίστα, τον τροποποιημένο πίνακα Node
                και τον δείκτη FreePtr.
  Εξοδος:     Μήνυμα γεμάτης λίστας, αν η συνδεδεμένη λίστα είναι γεμάτη
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
/* Δέχεται:   Μια συνδεδεμένη λίστα και τον δείκτη PredPtr που δείχνει
                στον προηγούμενο κόμβο από αυτόν που θα διαγραφεί.
  Λειτουργία: Διαγράφει από τη συνδεδεμένη λίστα, αν δεν είναι κενή,
                τον προηγούμενο κόμβο από αυτόν στον οποίο δείχνει ο PredPtr.
  Επιστρέφει: Την τροποποιημένη λίστα και το δείκτη FreePtr.
  Έξοδος:     Μήνυμα κενής λίστας, αν η συνδεδεμένη λίστα είναι κενή
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



//ΣΥΝΑΡΤΗΣΕΙΣ
// ΑΥΤΗ Η ΕΚΔΟΣΗ ΕΜΦΑΝΙΖΕΙ ΤΑ ΣTOIXEIA ΤΗΣ ΣΤΟΙΒΑΣ ΑΠΟ ΤΗ ΘΕΣΗ 0-TOP
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
/* Λειτουργία: Δημιουργεί μια κενή στοίβα.
   Επιστρέφει: Κενή Στοίβα.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι κενή.
   Επιστρέφει: True αν η Stack είναι κενή, False διαφορετικά
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι γεμάτη.
   Επιστρέφει: True αν η Stack είναι γεμάτη, False διαφορετικά
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* Δέχεται: Μια στοίβα Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει το στοιχείο Item στην στοίβα Stack αν η Stack δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη Stack.
   Έξοδος: Μήνυμα γεμάτης στοίβας, αν η στοίβα Stack είναι γεμάτη
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Διαγράφει το στοιχείο Item από την κορυφή της Στοίβας αν η Στοίβα δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη Stack.
   Έξοδος:  Μήνυμα κενής στοίβας αν η Stack είναι κενή
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

