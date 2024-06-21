#include <iostream>
using namespace std;
struct Node
{
    int value;
    Node *left;
    Node *right;

    Node(int val)
    {
        value = val;
        left = NULL;
        right = NULL;
    }
};
void inOrderTraversal(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    inOrderTraversal(node->left);

    cout << node->value << " ";

    inOrderTraversal(node->right);
}
void preorderTraversal(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    cout << node->value << " ";

    preorderTraversal(node->left);

    preorderTraversal(node->right);
}
void postOrderTraversal(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    postOrderTraversal(node->left);

    postOrderTraversal(node->right);

    cout << node->value << " ";
}
int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Pre-order traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postOrderTraversal(root);
    cout << endl;
    return 0;
}