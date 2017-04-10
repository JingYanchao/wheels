//
// Created by jyc on 17-4-10.
//
#include "Rbtree.h"
#include <assert.h>
#include <stdio.h>
void testcase1()//测试空树
{
    printf("start the 1st test\n");
    Rbtree rbt;
    assert(rbt.tree_is_regular());
};

void testcase2()//测试插入与删除
{
    printf("start the 2rd test\n");
    Rbtree rbt;
    int values[10] = {1,10,12,18,19,21,26,24,6,8};
    for (int i = 0; i < 10; i++)
    {
        rbtree_node* tree_node = (rbtree_node*)malloc(sizeof(rbtree_node));
        tree_node->key = values[i];
        rbt.rbtree_insert(tree_node);
        assert(rbt.tree_is_regular());
        assert(rbt.size()==(i+1));
        assert(rbt.rbtree_min() == 1);
    }
    assert(rbt.rbtree_min() == 1);
    rbt.delete_tree();
    assert(rbt.tree_is_regular());
    assert(rbt.size()==0);
}

void testcase3()//测试插入与删除
{
    printf("start the 3nd test\n");
    Rbtree rbt;
    int values[10] = {5,3,12,52,19,28,26,36,8,100};
    for (int i = 0; i < 10; i++)
    {
        rbtree_node* tree_node = (rbtree_node*)malloc(sizeof(rbtree_node));
        tree_node->key = values[i];
        rbt.rbtree_insert(tree_node);
        assert(rbt.tree_is_regular());
        assert(rbt.size()==(i+1));
    }
    assert(rbt.rbtree_min() == 3);
    rbt.delete_tree();
    assert(rbt.tree_is_regular());
    assert(rbt.size()==0);
}


void testcase4()//测试插入与删除
{
    printf("start the 4th test\n");
    Rbtree rbt;
    int values[10] = {5,34,12,-1,19,28,-8,26,36,12};
    for (int i = 0; i < 10; i++)
    {
        rbtree_node* tree_node = (rbtree_node*)malloc(sizeof(rbtree_node));
        tree_node->key = values[i];
        rbt.rbtree_insert(tree_node);
        assert(rbt.tree_is_regular());
        assert(rbt.size()==(i+1));
    }
    assert(rbt.rbtree_min() == -8);
    rbt.delete_tree();
    assert(rbt.tree_is_regular());
    assert(rbt.size()==0);
}

void testall()
{
    testcase1();
    testcase2();
    testcase3();
    testcase4();
}

int main()
{
    testall();
}
