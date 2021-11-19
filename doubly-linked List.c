#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct listitem{
    struct listitem *next;
    struct listitem *prev;
    int data;
    } LISTITEM;
    
int main(int argc, char **argv)
{
    LISTITEM *temp, head;
    
    head.next = (LISTITEM*) &head;
    head.prev = (LISTITEM*) &head;
    
    for (int i=0; i < 3; i++){
        temp = malloc(sizeof(LISTITEM));
        temp-> data = i;
        temp-> next =  head.next;
        head.next = temp;
        temp->prev = &head;
        temp->next->prev = temp;
        }
        
        
        // now let's see what we got going forward
        temp = head.next;
        while (temp != &head){
            printf("forward list item: current is %p; next is %p prev is %p^data is %d\n", temp, temp->next, temp->prev, temp->data);
            temp = temp->next;
            }
        
        //and going backwards
        temp = head.prev;
        while (temp != &head){
            printf("backward list item: current is %p; next is %p; prev is %p data is %d\n", temp, temp->next ,temp->prev, temp->data);
            temp = temp->prev;
            }
    return 0;
}
 