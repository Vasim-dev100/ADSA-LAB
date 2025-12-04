/*
  Simple AVL Tree (Insert, Delete, Inorder)
  - Clean, readable implementation
  - Menu-driven: Insert, Delete, Show Inorder, Exit
  Compile:
    gcc -std=c99 avl_readable.c -o avl_readable
    ./avl_readable
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int height;
    struct Node *left, *right;
} Node;

/* Utility */
int height(Node *n) { return n ? n->height : 0; }
int max(int a, int b) { return (a > b) ? a : b; }
Node* newNode(int k) {
    Node* p = (Node*)malloc(sizeof(Node));
    if (!p) { fprintf(stderr, "Memory allocation failed\n"); exit(1); }
    p->key = k; p->height = 1; p->left = p->right = NULL;
    return p;
}

/* Rotations */
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}

int getBalance(Node* n) { return n ? height(n->left) - height(n->right) : 0; }

/* Insert */
Node* insertNode(Node* node, int key) {
    if (!node) return newNode(key);
    if (key < node->key) node->left = insertNode(node->left, key);
    else if (key > node->key) node->right = insertNode(node->right, key);
    else return node; /* duplicate ignored */

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    /* Rebalance */
    if (balance > 1 && key < node->left->key) return rightRotate(node);          /* LL */
    if (balance < -1 && key > node->right->key) return leftRotate(node);        /* RR */
    if (balance > 1 && key > node->left->key) {                                 /* LR */
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {                                /* RL */
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

/* Find minimum node (used in delete) */
Node* minNode(Node* n) {
    Node* cur = n;
    while (cur && cur->left) cur = cur->left;
    return cur;
}

/* Delete */
Node* deleteNode(Node* root, int key) {
    if (!root) return root;
    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else {
        /* node found */
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) { /* no child */
                free(root);
                return NULL;
            } else { /* one child */
                *root = *temp;
                free(temp);
            }
        } else {
            /* two children: replace with inorder successor */
            Node* temp = minNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    /* update height & rebalance */
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);           /* LL */
    if (balance > 1 && getBalance(root->left) < 0) { root->left = leftRotate(root->left); return rightRotate(root); } /* LR */
    if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);         /* RR */
    if (balance < -1 && getBalance(root->right) > 0) { root->right = rightRotate(root->right); return leftRotate(root); } /* RL */

    return root;
}

/* Inorder traversal (prints sorted keys) */
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

/* Free tree */
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

/* Main menu */
int main(void) {
    Node* root = NULL;
    int choice, x, n, i;

    printf("=== AVL Tree (Insert, Delete, Inorder) ===\n");
    while (1) {
        printf("\n1) Insert  2) Delete  3) Show Inorder  4) Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 1) {
            printf("How many keys to insert? ");
            if (scanf("%d", &n) != 1) break;
            printf("Enter %d integer(s): ", n);
            for (i = 0; i < n; i++) {
                if (scanf("%d", &x) != 1) { i = n; break; }
                root = insertNode(root, x);
                printf(" [Inserted %d]", x);
            }
            printf("\nCurrent (inorder): ");
            inorder(root);
            printf("\n");
        } else if (choice == 2) {
            printf("Key to delete: ");
            if (scanf("%d", &x) != 1) break;
            root = deleteNode(root, x);
            printf("Deleted (if existed): %d\n", x);
            printf("Current (inorder): ");
            inorder(root);
            printf("\n");
        } else if (choice == 3) {
            printf("Inorder: ");
            inorder(root);
            printf("\n");
        } else break;
    }

    freeTree(root);
    printf("Exiting. Goodbye!\n");
    return 0;
}
