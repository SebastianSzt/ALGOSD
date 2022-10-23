typedef struct onpTreeNode
{
    // Proszę uzupełnić odnowiednią strukturą danych
    struct onpTreeNode *left;
    struct onpTreeNode *right;
} onpTree;

typedef onpTree* node;

void buildTree(node* root, char* expression);
node* calculate(node *root);