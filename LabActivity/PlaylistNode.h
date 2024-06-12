#define NODE_FIELD_SIZE 50

struct PlaylistNodeStruct {
    char uniqueID[NODE_FIELD_SIZE];
    char songName[NODE_FIELD_SIZE];
    char artistName[NODE_FIELD_SIZE];
    int songLength;
    struct PlaylistNodeStruct* nextPlaylistNode;
};
typedef struct PlaylistNodeStruct PlaylistNode;

PlaylistNode* CreatePlayListNode();
void InsertPlaylistNodeAfter(PlaylistNode* firstNode, PlaylistNode* secondNode);
void SetNextPlaylistNode(PlaylistNode* firstNode, PlaylistNode* secondNode);
PlaylistNode* GetNextPlaylistNode(PlaylistNode* node);
void PrintPlaylistNode(PlaylistNode* node);
void DestroyPlaylistNode(PlaylistNode* node);

