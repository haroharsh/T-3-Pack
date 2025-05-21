// Hashing open addressing using linear probing


#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct HashTable {
    int keys[SIZE];
    int values[SIZE];
    int occupied[SIZE];
};

void initialize(struct HashTable *table) {
    int i;
    for (i = 0; i < SIZE; i++) {
        table->keys[i] = -1;
        table->values[i] = -1;
        table->occupied[i] = 0;
    }
}

int hash(int key) {
    return key % SIZE;
}

void insert(struct HashTable *table, int key, int value) {
    int index = hash(key);
    while (table->occupied[index]) {
        index = (index + 1) % SIZE;
    }
    table->keys[index] = key;
    table->values[index] = value;
    table->occupied[index] = 1;
}

int search(struct HashTable *table, int key) {
    int index = hash(key);
    while (table->occupied[index]) {
        if (table->keys[index] == key) {
            return table->values[index];
        }
        index = (index + 1) % SIZE;
    }
    return -1;
}

int main() {
    struct HashTable table;
    initialize(&table);

    insert(&table, 10, 100);
    insert(&table, 20, 200);
    insert(&table, 30, 300);
    insert(&table, 40, 400);

    int value1 = search(&table, 10);
    int value2 = search(&table, 30);
    int value3 = search(&table, 50);

    printf("Value for key 10: %d\n", value1);
    printf("Value for key 30: %d\n", value2);
    printf("Value for key 50: %d\n", value3);

    return 0;
}
