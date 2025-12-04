#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node* createNode(int key) {
    Node *n = (Node*)malloc(sizeof(Node));
    if (!n) { fprintf(stderr, "Memory allocation failed\n"); exit(EXIT_FAILURE); }
    n->key = key;
    n->left = n->right = NULL;
    return n;
}

Node* insert(Node *root, int key) {
    if (root == NULL) return createNode(key);
    if (key < root->key) root->left = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);
    return root; // duplicate keys are ignored
}

int search(Node *root, int key) {
    if (!root) return 0;
    if (key == root->key) return 1;
    return (key < root->key) ? search(root->left, key) : search(root->right, key);
}

Node* findMin(Node *root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* deleteNode(Node *root, int key) {
    if (!root) return NULL;
    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) { Node *r = root->right; free(root); return r; }
        else if (!root->right) { Node *l = root->left; free(root); return l; }
        Node *succ = findMin(root->right);
        root->key = succ->key;
        root->right = deleteNode(root->right, succ->key);
    }
    return root;
}

void inorder(Node *root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

void preorder(Node *root) {
    if (!root) return;
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}

void freeTree(Node *root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    Node *root = NULL;
    int choice, key, n, i;

    while (1) {
        printf("\n--- BST Menu ---\n");
        printf("1. Create (insert multiple keys)\n");
        printf("2. Insert key\n");
        printf("3. Delete key\n");
        printf("4. Inorder traversal\n");
        printf("5. Preorder traversal\n");
        printf("6. Postorder traversal\n");
        printf("7. Clear tree\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("How many keys to insert? ");
                if (scanf("%d", &n) != 1) break;
                printf("Enter %d integers:\n", n);
                for (i = 0; i < n; i++) {
                    scanf("%d", &key);
                    root = insert(root, key);
                }
                break;

            case 2:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("Inserted %d\n", key);
                break;

            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                if (!search(root, key)) printf("Key %d not found\n", key);
                else { root = deleteNode(root, key); printf("Deleted %d\n", key); }
                break;

            case 4:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 6:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 7:
                freeTree(root);
                root = NULL;
                printf("Tree cleared\n");
                break;

            case 8:
                freeTree(root);
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    freeTree(root);
    return 0;
}
