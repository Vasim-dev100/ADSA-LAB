/* Simple B-Tree (Insert & Delete-by-rebuild)
   After each operation the program prints all elements (sorted).
   Minimum degree T = 3 (change at top)
   Compile: gcc -std=c99 simple_btree_show.c -o simple_btree_show
*/

#include <stdio.h>
#include <stdlib.h>

#define T 3            /* minimum degree */

typedef struct BNode {
    int keys[2*T-1];
    struct BNode *C[2*T];
    int n;      /* number of keys */
    int leaf;   /* 1 if leaf */
} BNode;

/* create node */
BNode* createNode(int leaf) {
    BNode* x = malloc(sizeof(BNode));
    if (!x) { perror("malloc"); exit(1); }
    x->leaf = leaf; x->n = 0;
    for (int i=0;i<2*T;i++) x->C[i]=NULL;
    return x;
}

/* split child y of x at index i */
void splitChild(BNode *x, int i, BNode *y) {
    BNode *z = createNode(y->leaf);
    z->n = T-1;
    for (int j=0;j<T-1;j++) z->keys[j] = y->keys[j+T];
    if (!y->leaf) for (int j=0;j<T;j++) z->C[j] = y->C[j+T];
    y->n = T-1;
    for (int j=x->n-1;j>=i;j--) x->keys[j+1] = x->keys[j];
    for (int j=x->n;j>=i+1;j--) x->C[j+1] = x->C[j];
    x->keys[i] = y->keys[T-1];
    x->C[i+1] = z;
    x->n += 1;
}

/* insert in non-full node */
void insertNonFull(BNode *x, int k) {
    int i = x->n - 1;
    if (x->leaf) {
        while (i>=0 && x->keys[i] > k) {
            x->keys[i+1] = x->keys[i];
            i--;
        }
        x->keys[i+1] = k;
        x->n += 1;
    } else {
        while (i>=0 && x->keys[i] > k) i--;
        i++;
        if (x->C[i]->n == 2*T-1) {
            splitChild(x, i, x->C[i]);
            if (x->keys[i] < k) i++;
        }
        insertNonFull(x->C[i], k);
    }
}

/* insert wrapper (root may change) */
BNode* insert(BNode *root, int k) {
    if (!root) {
        BNode *r = createNode(1);
        r->keys[0] = k; r->n = 1;
        return r;
    }
    if (root->n == 2*T-1) {
        BNode *s = createNode(0);
        s->C[0] = root;
        splitChild(s, 0, root);
        int i = (s->keys[0] < k) ? 1 : 0;
        insertNonFull(s->C[i], k);
        return s;
    } else {
        insertNonFull(root, k);
        return root;
    }
}

/* collect all keys (inorder) into a dynamic array */
void collectKeys(BNode *root, int **arr, int *sz, int *cap) {
    if (!root) return;
    for (int i=0;i<root->n;i++) {
        if (!root->leaf) collectKeys(root->C[i], arr, sz, cap);
        if (*sz >= *cap) {
            *cap *= 2;
            int *tmp = realloc(*arr, (*cap)*sizeof(int));
            if (!tmp) { perror("realloc"); exit(1); }
            *arr = tmp;
        }
        (*arr)[(*sz)++] = root->keys[i];
    }
    if (!root->leaf) collectKeys(root->C[root->n], arr, sz, cap);
}

/* free tree */
void freeTree(BNode *root) {
    if (!root) return;
    for (int i=0;i<=root->n;i++) freeTree(root->C[i]);
    free(root);
}

/* delete key by rebuild: collect, remove first occurrence, rebuild */
BNode* deleteKey(BNode *root, int k) {
    if (!root) return NULL;
    int cap = 16, sz = 0;
    int *arr = malloc(cap * sizeof(int));
    if (!arr) { perror("malloc"); exit(1); }
    collectKeys(root, &arr, &sz, &cap);
    int found = 0;
    int *keep = malloc(sz * sizeof(int));
    if (!keep){ perror("malloc"); exit(1); }
    int m = 0;
    for (int i=0;i<sz;i++) {
        if (!found && arr[i] == k) { found = 1; continue; }
        keep[m++] = arr[i];
    }
    free(arr);
    if (!found) { free(keep); return root; } /* nothing to delete */
    freeTree(root);
    root = NULL;
    for (int i=0;i<m;i++) root = insert(root, keep[i]);
    free(keep);
    return root;
}

/* print all elements (sorted) */
void printAll(BNode *root) {
    if (!root) { printf("Elements: (empty)\n"); return; }
    int cap = 16, sz = 0;
    int *arr = malloc(cap * sizeof(int));
    if (!arr){ perror("malloc"); exit(1); }
    collectKeys(root, &arr, &sz, &cap);
    printf("Elements (%d): ", sz);
    for (int i=0;i<sz;i++) {
        if (i) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
    free(arr);
}

/* Simple demo menu: Insert, Delete, Exit */
int main(void) {
    BNode *root = NULL;
    int choice, k, n, i;

    printf("Simple B-Tree demo (minimum degree T = %d)\n", T);

    while (1) {
        printf("\n1) Insert  2) Delete  3) Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 1) {
            printf("How many keys to insert? ");
            if (scanf("%d", &n) != 1) break;
            printf("Enter %d integer(s): ", n);
            for (i=0;i<n;i++) {
                scanf("%d", &k);
                root = insert(root, k);
                printf(" [Inserted %d]", k);
            }
            printf("\n");
            printAll(root);            /* show all elements after insertion */
        } else if (choice == 2) {
            printf("Key to delete: ");
            if (scanf("%d", &k) != 1) break;
            root = deleteKey(root, k);
            printf("Deleted (if existed) %d\n", k);
            printAll(root);            /* show all elements after deletion */
        } else break;
    }

    freeTree(root);
    puts("Exiting.");
    return 0;
}
