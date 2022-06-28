//node struct with a right and left pointer
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

//function to create a new node
node *create_node(int data){
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}