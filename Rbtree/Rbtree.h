//
// Created by jyc on 17-4-10.
//
#include <string.h>
#include <stdlib.h>
#ifndef WHEELS_RBTREE_H
#define WHEELS_RBTREE_H
typedef bool rbtree_color;
const rbtree_color BLACK = 0;
const rbtree_color RED = 1;
struct rbtree_node
{
    int key;
    rbtree_node *lchild;
    rbtree_node *rchild;
    rbtree_node *parent;
    rbtree_color color;
};

class Rbtree
{
private:
    rbtree_node *root;
    rbtree_node *sentinel;

public:
    Rbtree();
    ~Rbtree();
    void rbtree_init();
    int rbtree_empty();
    void rbtree_insert(rbtree_node *node);
    void rbtree_delete(rbtree_node *znode);
    int rbtree_min();
    size_t size();
    int tree_is_regular();
    void delete_tree();

private:
    void rotate_left(rbtree_node *node);
    void rotate_right(rbtree_node *node);
    void transplant(rbtree_node *unode,rbtree_node *vnode);
    void rbtree_insert_fixup(rbtree_node *node);
    void rbtree_delete_fixup(rbtree_node *xnode);
    int is_regular(rbtree_node* treenode);
    rbtree_node* tree_min(rbtree_node* node);
    int black_height(rbtree_node *node);
    size_t rbtree_size(rbtree_node *node);


private:
    rbtree_node * Minimum(rbtree_node *znode);
    bool is_red(rbtree_node* node);
    bool is_black(rbtree_node* node);
    void set_red(rbtree_node* node);
    void set_black(rbtree_node* node);

};


#endif //WHEELS_RBTREE_H
