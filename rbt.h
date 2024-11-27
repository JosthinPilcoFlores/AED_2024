#ifndef RBT_H
#define RBT_H
typedef enum {RED, BLACK} Color;
typedef struct {
  struct RBNode* parent;
  struct RBNode* left;
  struct RBNode* right;
  Color color;
  int value;
} RBNode;

RBNode* createRBNode(int value);

#endif
