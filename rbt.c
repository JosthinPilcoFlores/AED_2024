#include <stdlib.h>
#include "rbt.h"

RBNode* createRBNode(int key){
  RBNode* newNode = malloc(sizeof(RBNode));
  newNode->parent = NULL;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->color = RED;
  newNode->key = key ;
  return newNode;
}

RBTree* createRBTree(){
  RBTree* rbTree = malloc(sizeof(RBTree));
  rbTree->root = NULL;
  return rbTree;
}

void insertRBT(RBTree *t, RBNode *z){
  RBNode* x = t->root;
  RBNode* y = NULL;

  while(x != NULL){
    y = x;
    if(z->key < x->key)
      x = x->left;
    else
      x = x->right;
  }

  z->parent = y;

  if(y){
    if(z->key < y->key)
      y->left = z;
    else
      y->right = z;
  }else{
    t->root = z;
  }
  //rbInsertFixUp(t, z);
}

void leftRotate(RBTree* t, RBNode* x){
  RBNode* y = x->right;
  assert(y);
  x->right = y->left;
  if(y->left)
    y->left->parent = x;
  y->parent = x->parent;
  if(!x->parent)
    t->root = y;
  else if(x == x->parent->left)
    x->parent->left = y;
  else
    x->parent->right = y;
  y->left = x;
  x->parent = y;
}
