#include <stdio.h>
#include "PlaylistNode.h"

int main(){
    PlaylistNode* head = CreatePlayListNode();
    PlaylistNode* node_one = CreatePlayListNode();
    PlaylistNode* node_two = CreatePlayListNode();
    PlaylistNode* node_three = CreatePlayListNode();

    SetNextPlaylistNode(head, node_one);
    SetNextPlaylistNode(node_one, node_two);
    InsertPlaylistNodeAfter(head, node_three);

    PlaylistNode* current = head;
    PlaylistNode* next;
    while (current != NULL) {
        next = GetNextPlaylistNode(current);
        PrintPlaylistNode(current);
        DestroyPlaylistNode(current);
        current = next;
    }
}