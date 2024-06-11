#include <stdio.h>
#include "ContactNode.h"
#include <stdlib.h>
#define NUM_CONTACTS 3

void TrimNewline(char string[]);


int main() {

    ContactNode* head_node = NULL;
    ContactNode* current_node = NULL;
    ContactNode* next_node = NULL;

    for (int i = 0; i < NUM_CONTACTS; i++) {
        ContactNode* node = CreateContactNode("none", "none");
        printf("Person %d\n", i + 1);
        printf("Enter a name:\n");
        scanf("%s", node->contactName);
        printf("Enter a phone number:\n");
        scanf("%s", node->contactPhoneNum);
        printf("\n");
        if (current_node == NULL) {
            head_node = current_node = node;
        } else {
            InsertContactNodeAfter(current_node, node);
            current_node = GetNextContactNode(current_node);
        }
    }   

    current_node = head_node;
    printf("CONTACT LIST\n");
    while(current_node != NULL) {
        next_node = GetNextContactNode(current_node);
        PrintContactNode(current_node);
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

