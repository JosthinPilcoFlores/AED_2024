#include <stdlib.h>
#include "rbt.h"

RBNode* createRBNode(int value){
  RBNode* newNode = malloc(sizeof(RBNode));
  newNode->parent = NULL;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->color = RED;
  newNode->value = value;
  return newNode;
}

