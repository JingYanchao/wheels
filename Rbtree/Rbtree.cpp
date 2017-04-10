//
// Created by jyc on 17-4-10.
//
#include "Rbtree.h"
Rbtree::Rbtree()
{
    sentinel = (rbtree_node*)malloc(sizeof(rbtree_node));
    rbtree_init();
}

Rbtree::~Rbtree()
{
    delete_tree();
    free(sentinel);
}

void Rbtree::rbtree_init()
{
    rbtree_node* tree_root;
    tree_root = root = sentinel;
    set_black(sentinel);
    sentinel->key = 0;
    tree_root->lchild = nullptr;
    tree_root->rchild = nullptr;
    tree_root->parent = nullptr;
}


int Rbtree::rbtree_empty()
{
    return root == sentinel;
}

void Rbtree::rbtree_insert(rbtree_node *node)
{
    //空树,直接给节点赋值
    if(rbtree_empty())
    {
        root = node;
        root->parent = sentinel;
        root->rchild = sentinel;
        root->lchild = sentinel;
        return;
    }
    rbtree_node* y = sentinel;
    rbtree_node* x = root;
    //递归找到插入点
    while(x!=sentinel)
    {
        y = x;
        if(node->key<x->key)
        {
            x = x->lchild;
        }
        else
        {
            x = x->rchild;
        }
    }
    node->parent = y;
    if(y->key>node->key)
        y->lchild = node;
    else
        y->rchild = node;
    node->lchild = sentinel;
    node->rchild = sentinel;
    set_red(node);
    rbtree_insert_fixup(node);
}

void Rbtree::rbtree_delete(rbtree_node *znode)
{
    rbtree_node* y = znode;
    rbtree_node* x;
    bool y_original_color = y->color;
    //单链结构直接删除节点
    if(znode->lchild == sentinel)
    {
        x = znode->rchild;
        transplant(znode,znode->rchild);
        free(y);
    }
    else if(znode->rchild == sentinel)
    {
        x = znode->lchild;
        transplant(znode,znode->lchild);
        free(y);
    }
    else//删除的节点有两个儿子
    {
        y = Minimum(znode->rchild);
        int tmp = znode->key;
        znode->key = y->key;
        y->key = tmp;
        y_original_color = y->color;
        x = y->rchild;
        transplant(y,y->rchild);
        free(y);
    }
    //如果是红色,不影响黑高
    if(y_original_color == BLACK)
        rbtree_delete_fixup(x);
}

int Rbtree::rbtree_min()
{
    return tree_min(root)->key;
}

size_t Rbtree::size()
{
    return rbtree_size(root);
}


size_t Rbtree::rbtree_size(rbtree_node *node)
{
    if (node == sentinel)
        return 0;
    return rbtree_size(node->lchild) +
           rbtree_size(node->rchild) + 1;
}

void Rbtree::rotate_left(rbtree_node *node)
{
    rbtree_node* y = node->rchild;
    node->rchild = y->lchild;
    if(y->lchild != sentinel)
    {
        y->lchild->parent = node;
    }
    y->parent = node->parent;
    if(node->parent == sentinel)
    {
        root = y;
    }
    else if(node == node->parent->lchild)
    {
        node->parent->lchild = y;
    }
    else
    {
        node->parent->rchild = y;
    }
    y->lchild = node;
    node->parent = y;
}

void Rbtree::rotate_right(rbtree_node *node)
{
    rbtree_node* y = node->lchild;
    node->lchild = y->rchild;
    if(y->rchild!=sentinel)
    {
        y->rchild->parent = node;
    }
    y->parent = node->parent;
    if(node->parent == sentinel)
    {
        root = y;
    }
    else if(node == node->parent->lchild)
    {
        node->parent->lchild = y;
    }
    else
    {
        node->parent->rchild = y;
    }
    y->rchild = node;
    node->parent = y;
}
void Rbtree::transplant(rbtree_node *unode,rbtree_node *vnode)
{
    if(unode->parent == sentinel)
        root = vnode;
    else if(unode == unode->parent->lchild)
        unode->parent->lchild = vnode;
    else
        unode->parent->rchild = vnode;
    vnode->parent = unode->parent;
}

void Rbtree::rbtree_insert_fixup(rbtree_node *node)
{
    while(is_red(node->parent))
    {
        if(node->parent == node->parent->parent->lchild)//父节点是祖父的左节点
        {
            if(is_red(node->parent->parent->rchild))//叔叔节点是红色
            {
                set_black(node->parent);
                set_black(node->parent->parent->rchild);
                set_red(node->parent->parent);
                node = node->parent->parent;
            }
            else//叔叔节点是黑色
            {
                if(node == node->parent->lchild)
                {
                    rotate_right(node->parent->parent);
                    set_black(node->parent);
                    set_red(node->parent->rchild);
                    node = node->parent;
                }
                else if(node == node->parent->rchild)
                {
                    rotate_left(node->parent);
                    rotate_right(node->parent);
                    set_black(node);
                    set_red(node->rchild);
                }
            }
        }
        else//父节点是祖父的右节点
        {
            if(is_red(node->parent->parent->lchild))//叔叔节点是红色
            {
                set_black(node->parent);
                set_black(node->parent->parent->lchild);
                set_red(node->parent->parent);
                node = node->parent->parent;
            }
            else
            {
                if(node == node->parent->rchild)
                {
                    rotate_left(node->parent->parent);
                    set_black(node->parent);
                    set_red(node->parent->lchild);
                    node = node->parent;

                }
                else if(node == node->parent->lchild)
                {
                    rotate_right(node->parent);
                    rotate_left(node->parent);
                    set_black(node);
                    set_red(node->lchild);
                }
            }
        }
    }
    root->color = BLACK;
}
void Rbtree::rbtree_delete_fixup(rbtree_node *xnode)
{
    while(xnode!=root&&xnode->color==BLACK)
    {
        if(xnode == xnode->parent->lchild)//左儿子
        {
            rbtree_node* w = xnode->parent->rchild;
            if(is_red(w)) //case 1
            {
                set_black(w);
                set_red(xnode->parent);
                rotate_left(xnode->parent);
                w = xnode->parent->rchild;
            }
            if(w->lchild->color == BLACK&&w->rchild->color == BLACK)//case 2
            {
                w->color = RED;
                xnode = xnode->parent;
            }
            else if(w->rchild->color == BLACK)//case 3
            {
                w->lchild->color = BLACK;
                w->color = RED;
                rotate_right(w);
                w = xnode->parent->rchild;
            }
            else
            {
                w->color = xnode->parent->color;
                xnode->parent->color = BLACK;
                w->rchild->color = BLACK;
                rotate_left(xnode->parent);
                xnode = root;
            }

        }
        else
        {
            rbtree_node* w = xnode->parent->lchild;
            if(is_red(w)) //case 1
            {
                set_black(w);
                set_red(xnode->parent);
                rotate_right(xnode->parent);
                w = xnode->parent->lchild;
            }
            if(w->lchild->color == BLACK&&w->rchild->color == BLACK)//case 2
            {
                w->color = RED;
                xnode = xnode->parent;
            }
            else if(w->lchild->color == BLACK)//case 3
            {
                w->lchild->color = BLACK;
                w->color = RED;
                rotate_left(w);
                w = xnode->parent->lchild;
            }
            else
            {
                w->color = xnode->parent->color;
                xnode->parent->color = BLACK;
                w->lchild->color = BLACK;
                rotate_right(xnode->parent);
                xnode = root;
            }
        }
    }
    xnode->color = BLACK;
}
int Rbtree::tree_is_regular()
{
    if(!is_black(root)||!is_black(sentinel))
    {
        return 0;
    }
    else
    {
        return is_regular(root);
    }
}
int Rbtree::is_regular(rbtree_node* treenode)
{
    if(treenode == sentinel)
        return 1;
    if(treenode->color == RED&&treenode->parent->color == RED)
        return 0;
    if (black_height(treenode->lchild) != black_height(treenode->rchild))
        return 0;

    /* 二叉树基本性质 */
    if ( (treenode->parent->lchild == treenode && treenode->key > treenode->parent->key)
         || (treenode->parent->rchild == treenode && treenode->key < treenode->parent->key))
        return 0;

    if (!is_regular(treenode->lchild) || !is_regular(treenode->rchild))
        return 0;

    return 1;
}
rbtree_node* Rbtree::tree_min(rbtree_node* node)
{
    while(node->lchild != sentinel)
    {
        node = node->lchild;
    }
    return node;
}

int Rbtree::black_height(rbtree_node *node)
{
    if (node == sentinel)
        return 0;

    return black_height(node->lchild) + is_black(node);
}


void Rbtree::delete_tree()
{
    while(!rbtree_empty())
    {
        rbtree_delete(root);
    }

}


//找寻刚好比znode节点大的那个值
rbtree_node * Rbtree::Minimum(rbtree_node *znode)
{
    while(znode->lchild!=sentinel)
    {
        znode = znode->lchild;
    }
    return znode;
}
bool Rbtree::is_red(rbtree_node* node)
{
    return node->color == RED;
}
bool Rbtree::is_black(rbtree_node* node)
{
    return node->color == BLACK;
}
void Rbtree::set_red(rbtree_node* node)
{
    node->color = RED;
}
void Rbtree::set_black(rbtree_node* node)
{
    node->color = BLACK;
}

