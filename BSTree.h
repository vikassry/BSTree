typedef struct node Node;
typedef Node* nodePtr;

struct node{
	int data;
	Node *left;
	Node *right;
};

typedef struct tree{
	Node *root;
	int count;
} BSTree;

BSTree createBSTree(void);
int insert(BSTree *, int);
Node * find(BSTree, int);
Node *findParent(BSTree, int);
Node* Delete(BSTree *, int);
void traverse(BSTree, void (*)(int));