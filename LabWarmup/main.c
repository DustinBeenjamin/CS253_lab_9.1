#include <stdio.h>
#include "ContactNode.h"
#include <stdlib.h>
#define NUM_CONTACTS 4

void TrimNewline(char string[]);


int main() {

    ContactNode* head_node;
    ContactNode* current_node;
    ContactNode* next_node;

    head_node = CreateContactNode("1", "1");
    current_node = head_node;

    ContactNode* node_one = CreateContactNode("2", "2");
    ContactNode* node_two = CreateContactNode("3", "3");
    ContactNode* node_three = CreateContactNode("4", "4");

    InsertContactNodeAfter(head_node, node_one);
    InsertContactNodeAfter(node_one, node_two);    
    InsertContactNodeAfter(node_two, node_three);    

    for (int i = 0; i < NUM_CONTACTS; i++) {
        PrintContactNode(current_node);
        current_node = GetNextContactNode(current_node);
    }

    current_node = head_node;
    while (current_node != NULL) {
        next_node = GetNextContactNode(current_node);
        DestroyContactNode(current_node);
        current_node = next_node;
    }









}

void TrimNewline(char string[]) {
    int i = 0;
    for (int i = 0; i < 100; i++) {
        if (string[i] == '\n') {
            break;
        } else {
            i++;
        }
    }
    string[0] == '\0';
}

