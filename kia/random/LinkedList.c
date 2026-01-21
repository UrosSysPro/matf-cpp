#include "LinkedList.h"
#include "stdlib.h"
#include "stdio.h"

LinkedList* createLinkedList() {
    LinkedList* list = malloc(sizeof(LinkedList));
    list->root = NULL;
    return list;
}

LinkedListNode* linkedListAdd(LinkedListNode* node,int value) {
    if (node==NULL) {
        LinkedListNode* newNode = malloc(sizeof(LinkedListNode));
        newNode->value = value;
        newNode->next = NULL;
        return newNode;
    }
    node->next = linkedListAdd(node->next,value);
    return node;
}

void printLinkedListNode(LinkedListNode* node) {
    if (node!=NULL) {
        printf("%d ", node->value);
        printLinkedListNode(node->next);
    }
}

void printLinkedList(LinkedList* list) {
    printLinkedListNode(list->root);
}

void freeLinkedListNode(LinkedListNode* node) {
    if (node==NULL)return;
    freeLinkedListNode(node->next);
    free(node);
}

LinkedList* freeLinkedList(LinkedList* list) {
    freeLinkedListNode(list->root);
    free(list);
}
