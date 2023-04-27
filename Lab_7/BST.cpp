#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root == nullptr){
    return;
  }else{
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
  }
  


}

// Insert a node
struct node *insertNode(struct node *node, int key) {

  struct node *temp = new struct node();
  temp->key = key;
  if (node== nullptr){ // checking if the tree is empty
    node = temp;
  }  else{
    if( node->key >= key ){
      node->left = insertNode ( node->left , key );
    }else{
      node->right = insertNode(node->right , key);
    }
  }

  
  return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  //first searching for the number in the bst
  if ( root == nullptr ){

    return root ;

  }if( root->key > key  ){

    root->left = deleteNode(root->left , key);

  }else if(  root->key < key )  {

    root->right = deleteNode(root->right , key);

  }else{
    //when the node is in a leaf
    if (root->left == nullptr && root->right == nullptr){
            root = nullptr;
        }
    //if the node only one child
        else if (root ->left == nullptr){
            struct node* temp = root;
            root = temp->right;
            delete temp;
        }else if (root->right == nullptr){
            struct node* temp = root;
            root = temp->left;
            delete temp;
        }else{
            //if the node has 2 childs
            struct node* temp1 = root->left;
            while(temp1->right != nullptr){
                temp1 = temp1->right;
            }
            int a = temp1 ->key;
            root->key = a;
            root ->left = deleteNode(root->left , a);

  


    }

  } return root;
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
