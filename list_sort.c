#include <stdio.h>
#include <stdlib.h>

#include "list_sort.h"

Node* zapoln(Node* head, int x, int y) {
    Node* newelement = malloc(sizeof(Node));
    newelement -> x = x;
    newelement -> y = y;
    newelement -> next = head;
    return newelement;
}

void print(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("(%d, %d), ", current->x, current->y);
        current = current->next;
    }
    printf("NULL\n");
}

int kv(Node* node) {
    return node->x * node->x + node->y * node->y;
}

Node* sort(Node* head) {
    Node* sorted = NULL; 
    Node* now = head;

    while (now != NULL) {
        Node* next = now->next; 

        if (sorted == NULL || kv(now) < kv(sorted)) {
            now->next = sorted;
            sorted = now;
        } else {
            Node* temp = sorted;
            while (temp->next != NULL && kv(temp->next) < kv(now)) {
                temp = temp->next;
            }
            now->next = temp->next;
            temp->next = now;
        }

        now = next;
    }

    return sorted;
}

int main(){
    Node* list = NULL;

    /*(0, 0), (3, 4), (1, -1), (-2, 2), (5, 5), (-3, 0), (10, -10), (6, -2), (9, 1), (7, -7)*/
    list = zapoln(list, 0, 0);
    list = zapoln(list, 3, 4);
    list = zapoln(list, 1, -1);
    list = zapoln(list, -2, 2);
    list = zapoln(list, 5, 5);
    list = zapoln(list, -3, 0);
    list = zapoln(list, 10, -10);
    list = zapoln(list, 6, -2);
    list = zapoln(list, 9, 1);
    list = zapoln(list, 7, -7);

    list = sort(list);

    print(list);

    return 0;
}