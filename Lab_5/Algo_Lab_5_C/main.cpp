#include <string>
#include <iostream>

struct BST {
    int key;
    struct BST *left_child;
    struct BST *right_child;
};

struct BST *min_node(struct BST *&tree_node) {

    if (tree_node->left_child == NULL) return tree_node;
    else min_node(tree_node->left_child);

}

struct BST *add_tree(struct BST *&tree_node, int key_add) {

    if (tree_node == NULL) {
        tree_node = new BST;
        tree_node->key = key_add;
        tree_node->left_child = NULL;
        tree_node->right_child = NULL;
    } else if (tree_node->key < key_add) {
        add_tree(tree_node->right_child, key_add);
    } else if (tree_node->key > key_add) {
        add_tree(tree_node->left_child, key_add);
    }

    return tree_node;

}

struct BST *del_tree(struct BST *&tree_node, int key_del) {

    if (tree_node == NULL) {
        return tree_node;
    } else if (key_del < tree_node->key) {
        tree_node->left_child = del_tree(tree_node->left_child, key_del);
    } else if (key_del > tree_node->key) {
        tree_node->right_child = del_tree(tree_node->right_child, key_del);
    } else if (tree_node->left_child != NULL && tree_node->right_child != NULL) {
        tree_node->key = min_node(tree_node->right_child)->key;
        tree_node->right_child = del_tree(tree_node->right_child, tree_node->key);
    } else if (tree_node->left_child != NULL) {
        tree_node = tree_node->left_child;
    } else if (tree_node->right_child != NULL) {
        tree_node = tree_node->right_child;
    } else {
        tree_node = NULL;
    }

    return tree_node;

}

bool exists(struct BST *tree_node, int key_exists) {

    if (tree_node == NULL) return 0;

    if (tree_node->key == key_exists) return 1;

    if (tree_node->key < key_exists) {
        return exists(tree_node->right_child, key_exists);
    } else if (tree_node->key > key_exists) {
        return exists(tree_node->left_child, key_exists);
    }

}

struct BST *next_node(struct BST *&tree_node, int key_next) {

    struct BST *cur = tree_node;
    struct BST *next_node = NULL;

    while (cur != NULL) {
        if (cur->key > key_next) {
            next_node = cur;
            cur = cur->left_child;
        } else cur = cur->right_child;
    }

    return next_node;
}

struct BST *prev_node(struct BST *&tree_node, int key_prev) {

    struct BST *cur = tree_node;
    struct BST *prev_node = NULL;

    while (cur != NULL) {
        if (cur->key < key_prev) {
            prev_node = cur;
            cur = cur->right_child;
        } else cur = cur->left_child;
    }

    return prev_node;
}

using namespace std;

int main() {
    /*freopen("bstsimple.in", "r", stdin);
    freopen("bstsimple.out", "w", stdout);*/

    string command;
    struct BST *tree_node = NULL;
    long long key_command;

    while (cin >> command) {
        cin >> key_command;
        if (command == "insert") {
            add_tree(tree_node, key_command);
        } else if (command == "delete") {
            del_tree(tree_node, key_command);
        } else if (command == "exists") {
            (exists(tree_node, key_command)) ? (cout << "true\n") : (cout << "false\n");
        } else if (command == "next") {
            struct BST *nxt = next_node(tree_node, key_command);
            (nxt != NULL) ? (cout << nxt->key << "\n") : (cout << "none\n");
        } else if (command == "prev") {
            struct BST *prv = prev_node(tree_node, key_command);
            (prv != NULL) ? (cout << prv->key << "\n") : (cout << "none\n");
        }
    }

    return 0;
}
