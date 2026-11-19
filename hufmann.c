#include <stdio.h>
#include <stdlib.h>

struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
};

struct Node* createNode(char ch, int freq) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->ch = ch;
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void sort(struct Node* nodes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nodes[i]->freq > nodes[j]->freq) {
                struct Node* temp = nodes[i];
                nodes[i] = nodes[j];
                nodes[j] = temp;
            }
        }
    }
}

void printCodes(struct Node* root, int code[], int top) {
    if (root->left) {
        code[top] = 0;
        printCodes(root->left, code, top + 1);
    }

    if (root->right) {
        code[top] = 1;
        printCodes(root->right, code, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c : ", root->ch);

        for (int i = 0; i < top; i++)
            printf("%d", code[i]);

        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter number of characters: ");
    scanf("%d", &n);

    struct Node* nodes[n];

    printf("Enter characters and their frequencies:\n");

    for (int i = 0; i < n; i++) {
        char ch;
        int freq;

        scanf(" %c %d", &ch, &freq);

        nodes[i] = createNode(ch, freq);
    }

    while (n > 1) {
        sort(nodes, n);

        struct Node* left = nodes[0];
        struct Node* right = nodes[1];

        struct Node* newNode = createNode('$', left->freq + right->freq);

        newNode->left = left;
        newNode->right = right;

        nodes[0] = newNode;

        for (int i = 1; i < n - 1; i++)
            nodes[i] = nodes[i + 1];

        n--;
    }

    int code[100];

    printf("\nHuffman Codes:\n");
    printCodes(nodes[0], code, 0);

    return 0;
}