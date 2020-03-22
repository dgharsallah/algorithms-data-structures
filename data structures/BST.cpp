#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#define ll long long
using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val) {
    value = val;
    left = NULL;
    right = NULL;
  }

  BST &insert(int val) {
    if (this == NULL) {
        BST* root = new BST(val);
        cout << "creating new node with val " << root->value << endl;
        return *root;
    }
    if (val < this->value)
        this->left = &this->left->insert(val);
    else
        this->right = &this->right->insert(val);
      return *this;
  }
  bool contains(int val) {
      if (this == NULL) return false;
      if (this->value == val) return true;
      if (val < this->value)
          return this->left->contains(val);
      else
          return this->right->contains(val);
  }
  BST &remove(int val) {
    // Write your code here.
    // Do not edit the return statement of this method.
      if (this->value == val) {
          // case 1: node has no children
          if (this->left == NULL && this->right == NULL) {
              BST* root = NULL;
              return *root;
          }
          // case 2: node has only right child
          if (this->left == NULL && this->right != NULL) {
              return *this->right;
          }
          // case 3: node has only left child
          if (this->left != NULL && this->right == NULL) {
              return *this->left;
          }
          // case 4: node has 2 children
          // we need to first get the minimum node in right subtree which is by going left
          // starting from the right child
          BST* cur = this->right;
          while(cur->left != NULL) cur = cur->left;
          // then we assign the value to our current node
          this->value = cur->value;
          // then we delete the node with the minimum value
          this->right = &this->right->remove(cur->value);
          return *this;
      }
      if (val < this->value)
          this->left = &this->left->remove(val);
      else this->right = &this->right->remove(val);
    return *this;
  }
};
int main() {
    cout << "Hi\n";
    BST *root = new BST(12);
    cout << root->value << endl;
    cout << root->contains(12) << endl;
    root = &root->insert(10).insert(9).insert(8).insert(14);
    cout << root->left->value << endl;
    root = &root->remove(12);
    root = &root->remove(14);
    cout << root->contains(10) << endl;
    return 0;
}
