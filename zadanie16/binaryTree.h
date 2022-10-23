typedef struct tree {
    int value;
    struct tree *left;
    struct tree *right;
} treeNode;

typedef treeNode* node;

void insert(node* root, int val);
int containSameValues(node* tree1, node* tree2);