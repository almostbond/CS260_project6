#pragma once

// I ran into a lot of trouble trying to implement the remove fucntion when working with my own code so I have decided to follow a video guide
// so that I can get a working project. most of my own code work sans the remove funciton, but that seems to be a pretty important part.

class Tree {

private:

    struct node {
        int value;
        node* left;
        node* right;

    };

    node* root;

    void add_private(int node_val, node* ptr);
    void ordered_print_private(node* ptr);
    node* return_node_private(int val, node* ptr);
    int findsmallestprivate(node*);
    void remove_nodeprivate(int val, node* parent);
    void remove_root();
    void remove_match(node* parent, node* match, bool left);

public:
    Tree();
    node* create_node(int node_val);
    void node_add(int node_val);
    void ordered_print();
    node* return_node(int val);
    int find_smallest();
    void remove_node(int val);
};





class Tree_test : public Tree {

public:
    Tree_test();
    void create_node_test();
    void add_test();
    void remove_test();
    void return_node_test();




};