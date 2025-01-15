#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct bTree {
    int info; //data in tree
    char message[100]; //message about node
    struct bTree* left; //left child(node) pointer
    struct bTree* right; //right child (node) pointer
} BTREE;

BTREE* root = NULL; //root of binary search tree

//function declarations
void Insert(BTREE* treeRoot, BTREE* newNode); //function that insert new node
void Traverse(BTREE* treeRoot); //function that shows tree with pre-order-traversal
BTREE* search(BTREE* treeRoot, int item); //function that search and return requested node
BTREE* Delete(BTREE* treeRoot, int item); //function that delete node
BTREE* readNode(); //function that reads node info

// Helper function to count nodes in the tree
int countNodes(BTREE* treeRoot, int count) {
    if (treeRoot == NULL) return count;
    count = countNodes(treeRoot->left, count);
    count++;
    count = countNodes(treeRoot->right, count);
    return count;
}

int main() {
    BTREE* n, * a;
    int i, count, choice;

    while (1) {
        printf(" 1. Insert a node \n");
        printf(" 2. Delete a node \n");
        printf(" 3. List nodes \n");
        printf(" 4. Search for a node \n");
        printf(" 5. Count number of nodes \n");
        printf(" 6. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            n = readNode();
            Insert(root, n);
        }
        else if (choice == 2) {
            printf("Enter node to be deleted: ");
            scanf("%d", &i);
            a = Delete(root, i);
            if (a != NULL)
                printf("Deleted\n");
            else
                printf("Item to be deleted is not found\n");
        }
        else if (choice == 3) {
            if (root != NULL) {
                Traverse(root);
            }
            else {
                printf("Tree is empty\n");
            }
        }
        else if (choice == 4) {
            printf("Enter node to be searched for: ");
            scanf("%d", &i);
            a = search(root, i);
            if (a == NULL)
                printf("Item is not found\n");
            else
                printf("%d %s\n", a->info, a->message);
        }
        else if (choice == 5) {
            count = countNodes(root, 0);
            printf("Number of nodes in the tree = %d\n", count);
        }
        else {
            break;  // Exit the loop and end the program
        }
    }

    return 0;
}

//function definitions
void Insert(BTREE* treeRoot, BTREE* newNode) {
    if (treeRoot == NULL) {
        root = newNode;
    }
    else {
        if (treeRoot->info > newNode->info) {
            if (treeRoot->left == NULL) {
                treeRoot->left = newNode;
            }
            else {
                Insert(treeRoot->left, newNode);
            }
        }
        else {
            if (treeRoot->right == NULL) {
                treeRoot->right = newNode;
            }
            else {
                Insert(treeRoot->right, newNode);
            }
        }
    }
}

void Traverse(BTREE* treeRoot) {
    if (treeRoot != NULL) {
        printf("%d %s\n", treeRoot->info, treeRoot->message);
        Traverse(treeRoot->left);
        Traverse(treeRoot->right);
    }
}

BTREE* search(BTREE* treeRoot, int item) {
    while ((treeRoot != NULL) && (treeRoot->info != item)) {
        if (treeRoot->info > item) {
            treeRoot = treeRoot->left;
        }
        else {
            treeRoot = treeRoot->right;
        }
    }
    return treeRoot;
}

BTREE* Delete(BTREE* treeRoot, int item) {
    BTREE* q, * qa, * s, * sa, * qc;
    if (treeRoot == NULL) {
        return NULL;
    }
    q = treeRoot;
    qa = NULL;
    while ((q != NULL) && (q->info != item)) {
        qa = q;
        if (q->info > item) {
            q = q->left;
        }
        else {
            q = q->right;
        }
    }

    if (q == NULL) {
        printf("Item not found.\n");
        return NULL;
    }

    // if q is found and it has 2 children
    if ((q->left != NULL) && (q->right != NULL)) {
        s = q->left;
        sa = q;
        while (s->right != NULL) {
            sa = s;
            s = s->right;
        }
        q->info = s->info;
        strcpy(q->message, s->message);
        q = s;
        qa = sa;
    }

    if (q->left != NULL) {
        qc = q->left;
    }
    else {
        qc = q->right;
    }

    if (q == treeRoot) {
        root = qc;
    }
    else {
        if (q == qa->right) {
            qa->right = qc;
        }
        else {
            qa->left = qc;
        }
    }
    free(q);
    return q;
}

BTREE* readNode() {
    BTREE* newNode;
    newNode = (BTREE*)malloc(sizeof(BTREE));
    if (newNode == NULL)
        return NULL;
    printf("Enter info: ");
    scanf("%d", &(newNode->info));
    printf("Enter message: ");
    scanf("%s", newNode->message);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
