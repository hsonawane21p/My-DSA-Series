// Graph

#include <iostream>
using namespace std;

const int MAX = 50;

// Node structure for adjacency list
struct Node {
    int vertex;
    Node* next;
};

// Adjacency list array
Node* adjList[MAX];

void initAdjList(int n) {
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
    }
}

void addEdgeToList(int u, int v) {
    // Add v → u's list
    Node* newNode = new Node();
    newNode->vertex = v;
    newNode->next = adjList[u];
    adjList[u] = newNode;

    // Add u → v's list (undirected)
    newNode = new Node();
    newNode->vertex = u;
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

void printAdjList(int n) {
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        Node* temp = adjList[i];
        while (temp != NULL) {
            cout << temp->vertex;
            if (temp->next != NULL)
                cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
}

// BFS using adjacency MATRIX
void bfs(int adj[MAX][MAX], int start, int n) {
    int queue[MAX];
    int front = -1, rear = -1;
    int visited[MAX] = {0};

    front = rear = 0;
    queue[rear] = start;
    visited[start] = 1;

    cout << "\nBFS Traversal starting from vertex "
         << start << " : ";

    while (front <= rear) {
        int current = queue[front];
        front++;
        cout << current << " ";

        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                rear++;
                queue[rear] = i;
                visited[i] = 1;
            }
        }
    }
    cout << endl;
}

// DFS using adjacency MATRIX (recursive)
void dfs(int adj[MAX][MAX], int vertex, int n, int visited[]) {
    cout << vertex << " ";
    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && visited[i] == 0) {
            dfs(adj, i, n, visited);
        }
    }
}

void dfsTraversal(int adj[MAX][MAX], int start, int n) {
    int visited[MAX] = {0};
    cout << "\nDFS Traversal starting from vertex "
         << start << " : ";
    dfs(adj, start, n, visited);
    cout << endl;
}

int main() {
    int adj[MAX][MAX] = {0};  // adjacency matrix
    int vertex, edge;
    int u, v;

    cout << "Enter number of vertices (max "
         << MAX << "): ";
    cin >> vertex;

    if (vertex <= 0 || vertex > MAX) {
        cout << "\nInvalid number of vertices!";
        return 0;
    }

    initAdjList(vertex);

    cout << "Enter number of edges: ";
    cin >> edge;

    cout << "\nEnter " << edge
         << " edges (u v) - 0-based indexing:\n";

    for (int i = 0; i < edge; i++) {
        cin >> u >> v;

        if (u < 0 || u >= vertex ||
            v < 0 || v >= vertex ||
            u == v) {
            cout << "Invalid edge ("
                 << u << " " << v
                 << ") - ignored.\n";
            i--;
            continue;
        }

        adj[u][v] = 1;
        adj[v][u] = 1;

        addEdgeToList(u, v);
    }

    // Print Adjacency Matrix
    cout << "\nAdjacency Matrix:\n\n";
    cout << "   ";
    for (int j = 0; j < vertex; j++) {
        cout << j << " ";
    }
    cout << "\n";

    for (int i = 0; i < vertex; i++) {
        cout << i << "  ";
        for (int j = 0; j < vertex; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    // Print Adjacency List
    printAdjList(vertex);

    // BFS
    int start;
    cout << "\nEnter starting vertex for BFS (0 to "
         << vertex-1 << "): ";
    cin >> start;

    if (start < 0 || start >= vertex) {
        cout << "\nInvalid starting vertex!";
    } else {

        bfs(adj, start, vertex);

        // DFS
        cout << "\nEnter starting vertex for DFS (0 to "
             << vertex-1 << "): ";
        cin >> start;

        if (start < 0 || start >= vertex) {
            cout << "\nInvalid starting vertex!";
        } else {
            dfsTraversal(adj, start, vertex);
        }
    }

    cout << "\n\nPress Enter to exit...\n";
    cin.get();
    cin.get();

    return 0;
}
