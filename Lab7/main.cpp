#include <iostream>
using namespace std;

struct node {
    int key;
    struct node *left, *right;
};
// Inorder traversal
void traverseInOrder(struct node *root) {
    if(root!=NULL){
        traverseInOrder(root->left);
        cout<<root->key<<" ";
        traverseInOrder(root->right);
    }
}
// Insert a node
struct node *insertNode(struct node *root, int key) {
    if(root==NULL){
        //creating a new node
        node *newNode=new node();
        newNode->left=NULL;
        newNode->key=key;
        newNode->right=NULL;
        root=newNode;
    }else if(root->key >=key){
        root->left=insertNode(root->left,key);
    }else if(root->key <key){
        root->right=insertNode(root->right,key);
    }
    return root;
}
//Find a minimun node of the given tree
struct node *Minimum(node *tree){
    if(tree->left!=NULL){
        return Minimum(tree->left);
    }else{
        node *min=new node();
        min->key=tree->key;
        min->left=NULL;
        min->right=NULL;
        return min;
    }
}
// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    //No root
    if(root==NULL){
        return root;
    }else if(root->key<key){
        root->right= deleteNode(root->right,key);
        return root;
    }else if(root->key>key){
        root->left= deleteNode(root->left,key);
        return root;
    }else{
        if(root->left==NULL && root->right==NULL){        //no child
            root=NULL;
        }else if(root->left!=NULL && root->right==NULL){   //one child
            root=root->left;
        }else if(root->left==NULL && root->right!=NULL){    //one child
            root=root->right;
        }else{   //two child
            node *tempNode=root;
            node *min=Minimum(root->left);
            root->key=min->key;
            root->left=deleteNode(root->left,tempNode->key);
        }
        return root;
    }
}
// Driver code
int main() {
    struct node *root = NULL;
    int operation;
    int operand;
    cin >> operation;

    while (operation != -1) {
        switch(operation) {
            case 1: // insert
                cin >> operand;
                root = insertNode(root, operand);
                cin >> operation;
                break;
            case 2: // delete
                cin >> operand;
                root = deleteNode(root, operand);
                cin >> operation;
                break;
            default:
                cout << "Invalid Operator!\n";
                return 0;
        }
    }
    traverseInOrder(root);
}