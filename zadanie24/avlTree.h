typedef struct avlTreeNode
{
    int data;
    int coeff;
    struct avlTreeNode *left;
    struct avlTreeNode *right;
} avlTree;

typedef avlNode* node;

void insert(node* root, int data);
void remove(node* root, int data);
node find(node* root, int data);