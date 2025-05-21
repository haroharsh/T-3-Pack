#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = 
      (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge between two vertices
void addEdge(struct Node* adj[], int i, int j) {
    struct Node* newNode = createNode(j);
    newNode->next = adj[i];
    adj[i] = newNode;

    newNode = createNode(i); // For undirected graph
    newNode->next = adj[j];
    adj[j] = newNode;
}

// Function to display the adjacency list
void displayAdjList(struct Node* adj[], int V) {
    for (int i = 0; i < V; i++) {
        printf("%d: ", i); // Print the vertex
        struct Node* temp = adj[i];
        while (temp != NULL) {
            printf("%d ", temp->data); // Print its adjacent
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
  
    // Create a graph with 4 vertices and no edges
    int V = 4;
    struct Node* adj[V];
    for (int i = 0; i < V; i++) {
        adj[i] = NULL; // Initialize adjacency list
    }

    // Now add edges one by one
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    printf("Adjacency List Representation:\n");
    displayAdjList(adj, V);

    return 0;
}

// Regular Graph
//      A simple graph is said to be regular if all vertices of graph G are of equal degree.
//      All complete graphs are regular but vice versa is not possible.
//      A regular graph is a type of undirected graph where every vertex has the same number of edges or neighbors.
//      In other words, if a graph is regular, then every vertex has the same degree. 