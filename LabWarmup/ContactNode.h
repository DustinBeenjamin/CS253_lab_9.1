#define CONTACT_FIELD_SIZE 50

struct ContactNode_struct {
   char contactName[CONTACT_FIELD_SIZE];
   char contactPhoneNum[CONTACT_FIELD_SIZE];
   struct ContactNode_struct* nextNodePtr;
};
typedef struct ContactNode_struct ContactNode;


ContactNode* CreateContactNode(char nameInit[], char phoneNumInit[]);
void InsertContactNodeAfter(ContactNode* thisNode, ContactNode* newNode);
ContactNode* GetNextContactNode(ContactNode* thisNode);
void PrintContactNode(ContactNode* thisNode);
void DestroyContactNode(ContactNode* thisNode);

