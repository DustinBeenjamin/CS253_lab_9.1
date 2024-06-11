#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ContactNode.h"

ContactNode* CreateContactNode(char nameInit[], char phoneNumInit[]);
void InsertContactNodeAfter(ContactNode* thisNode, ContactNode* newNode);
ContactNode* GetNextContactNode(ContactNode* thisNode);
void PrintContactNode(ContactNode* thisNode);
void DestroyContactNode(ContactNode* thisNode);
void DestroyContactNodes(ContactNode* thisNode);

ContactNode* CreateContactNode(char nameInit[], char phoneNumInit[]) {
    ContactNode* node = (ContactNode*)malloc(sizeof(ContactNode));
    if (node != NULL) {
        //node will be NULL only if there is not enough room on the HEAP
        strcpy(node->contactName, nameInit);
        strcpy(node->contactPhoneNum, phoneNumInit);
        node->nextNodePtr = NULL;
    }
    node->nextNodePtr = NULL;
    return node;
}

void InsertContactNodeAfter(ContactNode* thisNode, ContactNode* newNode) {
    thisNode->nextNodePtr = newNode;
}

ContactNode* GetNextContactNode(ContactNode* thisNode) {
    return thisNode->nextNodePtr;
}

void PrintContactNode(ContactNode* thisNode) {
    printf("Name: %s\nPhone number: %s\n\n", thisNode->contactName, thisNode->contactPhoneNum);
}

void DestroyContactNode(ContactNode* thisNode) {
    free(thisNode);
}

void DestroyContactNodes(ContactNode* thisNode) {
    ContactNode* currentNode = thisNode;
    ContactNode* nextNode = GetNextContactNode(currentNode);
    while (nextNode != NULL) {
        //FREE THE MEMORY OF THE PROVIDED NODE, AND ALL NODES THAT FOLLOW
        free(currentNode);
        currentNode = nextNode;
        nextNode = GetNextContactNode(currentNode);
    }
    free(currentNode);
}

