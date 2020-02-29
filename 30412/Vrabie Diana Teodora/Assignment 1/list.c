//
// Created by diana on 26/02/2020.
//

#include "list.h"

void initializeList() {
    first = NULL;
    last = NULL;
}

void addElementToFront(int data) {
    if (first == NULL) {
        first = (ListElement*) malloc(sizeof(ListElement));
        first->data = data;
        first->next = last;
        last = first;
    } else {
        ListElement *newElement = (ListElement *) malloc(sizeof(ListElement));
        newElement->next = first;
        newElement->data = data;
        first = newElement;
    }
}

void printAll(FILE *file) {
    if (first == NULL) {
        fprintf(file, "List is empty!\n");
    } else {
        ListElement *currentElement = first;
        while (currentElement != NULL) {
            fprintf(file, "%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        fprintf(file, "\n");
    }
}

/*void addElementToEnd(int data) {
    if (first == NULL) {
        first->data = data;
        first->next = last;
        last = first;
    } else {
        ListElement *newElement = (ListElement*) malloc(sizeof(ListElement));

    }

}
*/



