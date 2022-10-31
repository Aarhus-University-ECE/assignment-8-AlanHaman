#include "insertion_sort.h"

#include "linked_list.h"

void sort(linked_list* llPtr) {
    // Add your sort function here
 
    node_t* currentNode = llPtr->head->next;
    // At the start of each pass, Prev is the previous node, therefor it set to llPtr->head in the start
    node_t* prev = llPtr->head;
    node_t* temp;

    // while loop that runs through the list until currentnode is NULL
    while (currentNode != NULL) {
        
        if (currentNode->data < prev->data) {
           // if current is smaller then the previous, we have to sort it
           // we need to first check if the first to elements needs to exchange places
            if (prev == llPtr->head) {
                // here we are changing the place of the first and second element
                prev->next = currentNode->next;
                currentNode->next = prev;
                llPtr->head = currentNode;

            } else {
                temp = llPtr->head;
                if (currentNode->data < temp->data) {
                    prev->next = currentNode->next;
                    currentNode->next = temp;
                    llPtr->head = currentNode;
                } else {
                    while (temp->next->data <= currentNode->data) {
                        temp = temp->next;
                    }
                    // when the wile loop has run we know that temp->data < CurrentNode->data < temp-next-data
                    if (temp->next->next == currentNode) {
                        temp->next->next = currentNode->next;

                        // CurrentNode needs to point to prev 
                        currentNode->next = temp->next;

                        // and then temp needs to point to currentNode
                        temp->next = currentNode;

                        // If the if statement does not run that means that currentNode->next == NULL, then we run else
                    } else {
                     // prev needs to point to currentNode ->next, which is NULL
                        prev->next = currentNode->next;
                     // and currentNode needs to point to temp->next
                        currentNode->next = temp->next;
                        // temp needs to point to currentNode
                        temp->next = currentNode;
         }
               }
     }
        }
        prev = currentNode;
        currentNode = currentNode->next;
    }
    return;
}
