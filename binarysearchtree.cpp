


#include"BST.h"
#include <iostream>

using namespace std;

Tree::Tree() {
    root = NULL;

}
Tree_test::Tree_test() {}
// complexity constant 4
Tree::node* Tree::create_node(int node_val) {
    node* new_node = new node;
    new_node->value = node_val;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

// complexity O(log(n))
void Tree::node_add(int node_val) {

    return add_private(node_val, root);

}

void Tree::add_private(int node_val, node* ptr) {

    if (root == NULL) {
        root = create_node(node_val);
    }

    else if (node_val <= ptr->value) {

        if (ptr->left != NULL) {
            add_private(node_val, ptr->left);
        }
        else {

            ptr->left = create_node(node_val);

        }
    }

    else if (node_val > ptr->value) {
        if (ptr->right != NULL) {
            add_private(node_val, ptr->right);
        }
        else {

            ptr->right = create_node(node_val);
        }
    }
    
}

//complexity O(n); 
void Tree::ordered_print() {
    ordered_print_private(root);
}
void Tree::ordered_print_private(node* ptr) {

    if (root != NULL) {
        if (ptr->left != NULL) {
            ordered_print_private(ptr->left);
        }
        cout << ptr->value << "  ";
        if (ptr->right != NULL) {
            ordered_print_private(ptr->right);
        }
    }
    else {
        cout << "The Tree is empty.\n";
    }
}


Tree::node* Tree::return_node(int val) {

    return return_node_private(val, root);
}

Tree::node* Tree::return_node_private(int val, node* ptr) {

    if (ptr != NULL) {
        if (ptr->value == val) {
            return ptr;
        }
        else {
            if (val < ptr->value) {
                return return_node_private(val, ptr->left);
            }
            else {
                return return_node_private(val, ptr->right);
            }
        }
    }
    else {
        return NULL;
    }
}

// complexity O(n)
int Tree::find_smallest() {

    return findsmallestprivate(root);
}

int Tree::findsmallestprivate(node* ptr) {

    if (root == NULL) {
        return 0;

    }
    else {
        if (ptr->left != NULL) {
            return findsmallestprivate(ptr->left);
        }
        else {
            return ptr->value;
        }
    }


}

//complexity O(log(n))
void Tree::remove_node(int val) {

    remove_nodeprivate(val, root);
}

void Tree::remove_nodeprivate(int val, node* parent) {

    if (root != NULL) {

        if (root->value == val) {
            remove_root();
        }
        else {
            if (val < parent->value && parent->left != NULL) {

                parent->left->value == val? 
                    remove_match(parent, parent->left, true): 
                    remove_nodeprivate(val, parent->left);

                    
                

            }
            else if(val > parent->value && parent->right != NULL){
                parent->right->value == val ? 
                remove_match(parent, parent->right, false):
                remove_nodeprivate(val, parent->right);

            }
            else {
                cout << "node wasn't found in the tree." << endl;
            }
        }
        
    }
    else {
        cout << "the tree is empty." << endl;
    }

}


void Tree::remove_root() {

    if (root != NULL) {
        node* delptr = root;
        int rootval = root->value;
        int smallestright;

        // 0 children
        if (root->left == NULL && root->right == NULL) {
            root = NULL;
            delete delptr;
        }
        // 1 child
        else if (root->left == NULL && root->right != NULL) {
            root = root->right;
            delptr->right = NULL;
            delete delptr;

        }
        else if (root->left != NULL && root->right == NULL) {
            root = root->left;
            delptr->left = NULL;
            delete delptr;
        }
        //2 children
        else {
            smallestright = findsmallestprivate(root->right);
            remove_nodeprivate(smallestright, root);
            root->value = smallestright;
            cout << endl << "new root value is " << root->value << endl;
        }

    }
    else {
        cout << "empty tree.";
    }
}


void Tree::remove_match(node* parent, node* match, bool left) {

    node* delptr;
    int matchval = match->value;
    int smallestright;

    // 0 children
    if (match->left == NULL && match->right == NULL) {
        delptr = match;
        cout << "\nnode " << match->value << " was removed \n";
        left = true ? parent->left = NULL : parent->right = NULL;
        delete delptr;
        
    }
    // 1 child
    //right child
    else if (root->left == NULL && root->right != NULL) {
        left = true ? parent->left = match->right : parent->right = match->right;
        match->right = NULL;
        cout << "\nnode " << match->value << " was removed \n";
        delptr = match;
        delete match;

    }
    //left child
    else if (root->left != NULL && root->right == NULL) {
        left = true ? parent->left = match->left : parent->right = match->left;
        match->left = NULL;
        cout << "\nnode " << match->value << " was removed \n";
        delptr = match;
        delete match;
    }
    //2 children
    else {
        smallestright = findsmallestprivate(match->right);
        remove_nodeprivate(smallestright, match);
        match->value = smallestright;

    }



}


void Tree_test::create_node_test() {
    cout << create_node(10) << endl;
    
}


void Tree_test::add_test() {
    
    node_add(21);
    node_add(7);
    node_add(12);
    node_add(9);
    node_add(70);
    node_add(53);
    node_add(42);

    ordered_print();

}

void Tree_test::return_node_test(){

    add_test();

    cout << endl << return_node(70)->value << endl;


}

void Tree_test::remove_test() {
    add_test();

    remove_node(21);
    ordered_print();
    remove_node(9);
    ordered_print();
    remove_node(42);
}






int main(){

    Tree birch;   
    Tree_test oak;
    oak.create_node_test();
    //oak.add_test();
    //oak.remove_test();
    oak.return_node_test();
    cout << endl << "exit success" << endl;


}