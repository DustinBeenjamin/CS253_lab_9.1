#include "PlaylistNode.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

PlaylistNode* CreatePlayListNode();
void InsertPlaylistNodeAfter(PlaylistNode* firstNode, PlaylistNode* secondNode);
void SetNextPlaylistNode(PlaylistNode* firstNode, PlaylistNode* secondNode);
PlaylistNode* GetNextPlaylistNode(PlaylistNode* node);
void PrintPlaylistNode(PlaylistNode* node);
void DestroyPlaylistNode(PlaylistNode* node);
void TrimNewline(char string[]);

PlaylistNode* CreatePlayListNode() {
    PlaylistNode* node = (PlaylistNode*)malloc(sizeof(PlaylistNode));
    printf("Enter the song name:\n");
    fgets(node->songName, NODE_FIELD_SIZE, stdin);
    TrimNewline(node->songName);
    printf("Enter the artist name:\n");
    fgets(node->artistName, NODE_FIELD_SIZE, stdin);
    TrimNewline(node->artistName);
    printf("Enter the song length:\n");
    scanf("%d", &(node->songLength));
    node->nextPlaylistNode = NULL;
    /////CHANGE THIS TO GENERATE A RANDOM NUMBER
    strcpy(node->uniqueID, "THIS IS A RANDOM IDENTIFIER");
    getchar();
    printf("\n");
    return node;
}
 
void InsertPlaylistNodeAfter(PlaylistNode* firstNode, PlaylistNode* secondNode){
    if (firstNode->nextPlaylistNode == NULL) {
        SetNextPlaylistNode(firstNode, secondNode);
    } else {
        secondNode->nextPlaylistNode = GetNextPlaylistNode(firstNode);
        firstNode->nextPlaylistNode = secondNode;
    }
}

void SetNextPlaylistNode(PlaylistNode* firstNode, PlaylistNode* secondNode){
    //DO NOT USE THIS FUNCTION IF THE NODE ALREADY POINTS TO ANOTHER NODE
    //DOING SO WILL CAUSE HEAP MEMORY LOSS
    //USE "InsertPlaylistNodeAfter() Instead"
    firstNode->nextPlaylistNode = secondNode;
}

PlaylistNode* GetNextPlaylistNode(PlaylistNode* node){
    return node->nextPlaylistNode;
}

void PrintPlaylistNode(PlaylistNode* node){
    printf("Unique ID: %s\n", node->uniqueID);
    printf("Song Name: %s\n", node->songName);
    printf("Artist Name: %s\n", node->artistName);
    printf("Song Length (in seconds): %d\n\n", node->songLength);
}

void DestroyPlaylistNode(PlaylistNode* node){
    if (node->nextPlaylistNode == NULL) {
        free(node);
    } else {
        //THIS IS NOT AVAILABLE YES (DONT DELETE A NODE IF IT POINTS TO ANOTHER)
    }
}

void TrimNewline(char string[]) {
    int i = 0;
    char c = string[i];
    while (c != '\n') {
        i++;
        c = string[i];
    }
    string[i] = '\0';
}