///dai18069 2021
///FINISHED PRODUCT!!!
/*Γράψτε πρόγραμμα που θα δέχεται για κάθε άτομο τον ΑΜΚΑ (ακέραιος), τον ΑΦΜ (ακέραιος), την ηλικία (ακέραιος). Θα
καταχωρεί τα στοιχεία του κάθε ατόμου   σε 2 καταλόγους  ανάλογα με την ηλικία του, αυτούς με ηλικία μικρότερη ή ίση
των 60 ετών και αυτούς με ηλικία μεγαλύτερη των 60.
Κάθε κατάλογος θα πρέπει να οργανωθεί ως  ΔΔΑ με κλειδί τον  ΑΜΚΑ. Το πρόγραμμα θα περιλαμβάνει τις εξής
λειτουργίες
-  Εισαγωγή των στοιχείων του κάθε ατόμου στο αντίστοιχο ΔΔΑ ανάλογα με την ηλικία του (ΔΔΑ για άτομα με ηλικίες
<=60 και ΔΔΑ για άτομα με ηλικίες > 60). Και στα 2 ΔΔΑ το κλειδί θα είναι ο ΑΜΚΑ.
-  Εμφάνιση των 2 καταλόγων
-  Αναζήτηση ατόμου με βάση τον ΑΜΚΑ και την ηλικία.   Δίνεται ένα στιγμιότυπο εκτέλεσης όπου φαίνεται πως θα γίνεται το διάβασμα των δεδομένων και η εμφάνιση του
κάθε καταλόγου. Η αναζήτηση θα γίνει για 3  άτομα: α) ένα άτομο του οποίου τα στοιχεία έχουν καταχωρηθεί  σε ένα εκ
των  2 καταλόγων  (ΑΜΚΑ, ηλικία), β)  ένα άτομο του οποίου  το ΑΜΚΑ του έχει καταχωρηθεί στον αντίστοιχο κατάλογο
αλλά η ηλικία του δεν ταυτίζεται με τη δοθείσα και γ)  ένα  άτομο  του οποίου το ΑΜΚΑ  δεν έχει  καταχωρηθεί σε κανένα
κατάλογο. Τα μηνύματα της κάθε περίπτωσης φαίνονται στο στιγμιότυπο εκτέλεσης.
  (για την απλοποίηση της εισαγωγής δεδομένων δόθηκαν ίδιες τιμές για ΑΜΚΑ, ΑΦΜ, ηλικία) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int amka, afm, age;
}BinTreeElementType;        /*ο τύπος των στοιχείων του ΔΔΑ
                                        ενδεικτικά τύπου int */
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
/* Λειτουργία: Δημιουργεί ένα κενό ΔΔΑ.
   Επιστρέφει:  Τον μηδενικό δείκτη(NULL) Root
*/
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
/* Δέχεται:   Ενα ΔΔα με το Root να δείχνει στη ρίζα του.
  Λειτουργία: Ελέγχει αν το ΔΔΑ είναι κενό.
  Επιστρέφει: TRUE αν το ΔΔΑ είναι κενό και FALSE διαφορετικά
*/
{   return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* Δέχεται:     Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και ένα στοιχείο Item.
   Λειτουργία:  Εισάγει το στοιχείο Item στο ΔΔΑ.
   Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του
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
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του.
   Επιστρέφει: Η Found έχει τιμή TRUE και ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE
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
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί ενδοδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("(%d, %d, %d)",Root->Data.amka,Root->Data.afm,Root->Data.age);
        InorderTraversal(Root->RChild);
    }
}
