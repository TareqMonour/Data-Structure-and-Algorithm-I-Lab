#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Node structure for adjacency list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Graph structure
typedef struct Graph {
    int numVertices;
    Node** adjList;
} Graph;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (Node**)malloc(numVertices * sizeof(Node*));

    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

// Depth-First Search function for topological sorting
void topologicalSortUtil(Graph* graph, int vertex, int visited[], int stack[], int* stackIndex) {
    visited[vertex] = 1;

    Node* temp = graph->adjList[vertex];
    while (temp != NULL) {
        int adjVertex = temp->data;
        if (!visited[adjVertex]) {
            topologicalSortUtil(graph, adjVertex, visited, stack, stackIndex);
        }
        temp = temp->next;
    }

    stack[(*stackIndex)++] = vertex;
}

// Topological Sorting function
void topologicalSort(Graph* graph) {
    int visited[MAX_VERTICES] = {0};
    int stack[MAX_VERTICES];
    int stackIndex = 0;

    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            topologicalSortUtil(graph, i, visited, stack, &stackIndex);
        }
    }

    // Print the topological order
    printf("Topological Order: ");
    while (stackIndex > 0) {
        printf("%d ", stack[--stackIndex]);
    }
    printf("\n");
}

int main() {
    // Example usage
    Graph* graph = createGraph(6);

    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSort(graph);

    return 0;
}
