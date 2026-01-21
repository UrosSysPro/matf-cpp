#ifndef MATF_CPP_LINKEDLIST_H
#define MATF_CPP_LINKEDLIST_H

typedef struct LINKED_LIST_NODE {
   int value;
   struct LINKED_LIST_NODE* next;
} LinkedListNode;

typedef struct LINKED_LIST{
   LinkedListNode* root;
} LinkedList;

LinkedList* createLinkedList();
LinkedListNode* linkedListAdd(LinkedListNode* node,int value);
void printLinkedList(LinkedList* list);
LinkedList* freeLinkedList(LinkedList* list);


#endif //MATF_CPP_LINKEDLIST_H