typedef struct threeNodesTreeNode
{
    float data;
    struct threeNodesTreeNode *left;
    struct threeNodesTreeNode *middle;
    struct threeNodesTreeNode *right;
} threeNodesTree;

typedef threeNodesTree* node;

void append(node* root, float value);
node find(node* root, float value);