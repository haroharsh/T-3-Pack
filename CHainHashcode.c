// Hashing closed addressing using chain method
// This program implements a simple hash table using linked lists for collision resolution.


#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct Node {
    int key;
    struct Node* next;
};

struct Node** createHashTable() {
    int i;
    struct Node** hashTable = (struct Node**)malloc(TABLE_SIZE * sizeof(struct Node*));
    for (i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
    return hashTable;
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(struct Node** hashTable, int key) {
    int index = hashFunction(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

void delete(struct Node** hashTable, int key) {
    int index = hashFunction(key);
    struct Node* temp = hashTable[index];
    struct Node* prev = NULL;

    if (temp != NULL && temp->key == key) {
        hashTable[index] = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->key != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void display(struct Node** hashTable) {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        struct Node* temp = hashTable[i];
        printf("%d: ", i);
        while (temp != NULL) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct Node** hashTable = createHashTable();

    insert(hashTable, 5);
    insert(hashTable, 12);
    insert(hashTable, 67);
    insert(hashTable, 9);
    insert(hashTable, 16);

    display(hashTable);

    delete(hashTable, 12);

    display(hashTable);

    return 0;
}
