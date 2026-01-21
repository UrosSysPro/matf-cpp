/*delovi memorije
 *static/global promenljive
 *code
 *stack
 *heap
*/

/* collections
 * list - bilo koja struktura podataka koja cuva podatke sekvencijalno i podrzava addFirst, addLast...
 *      - Array List - implementira listu koirsteci niz
 *      - Linked List - implementira listu koristeci cvorove
 * tree - bilo koja struktura podataka koja organizuje podatke u stablo
 *      - eksplicitno stablo koristi cvorove za implementaciju
 *      - implicitno stablo koristi niz za implementaciju
 *      - samobalansirajuce stablo
 *
 * map - bilo koja struktura koja cuva key-value parove
 *      - HashMap
 *      - TreeMap
 * stack - bilo koja struktura koja implementira push i pop operacije u O(1) kompleksnosti
 * heap - bilo koja struktura koja implementira add i getTop operacije u O(log2(n)) kompleksnosti
 * queue - bilo koja struktura koja implementira addFirst i removeLast operacije u O(1) kompleksnosti
 */
#include "LinkedList.h"

int main(int argc, char** argv) {
    LinkedList* list = createLinkedList();

    list->root = linkedListAdd(list->root,1);
    list->root = linkedListAdd(list->root,2);
    list->root = linkedListAdd(list->root,3);

    printLinkedList(list);

    freeLinkedList(list);

    return 0;
}