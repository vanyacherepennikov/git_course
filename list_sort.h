

typedef struct Node {
    int x;
    int y; 
    struct Node* next;
} Node;

Node* zapoln(Node* head, int x, int y);
void print(Node* head);
int kv(Node* node);
Node* sort(Node* head);