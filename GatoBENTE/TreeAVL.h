#ifndef TREE_AVL_H
#define TREE_AVL_H

struct TreeAVL {
  int data;
  struct TreeAVL* left;
  struct TreeAVL* right;
  struct TreeAVL* padre;
};

struct TreeAVL* NewNode( int );

struct TreeAVL* InsertBST( struct TreeAVL*, int );

int Height( struct TreeAVL* );

int BalanceFactor( struct TreeAVL* );

#endif