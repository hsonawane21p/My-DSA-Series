

#include <iostream>
using namespace std;

// Node structure for Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create a new node
Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Build tree recursively (user input)
Node* buildTree() {
    int x;
    cout << "Enter data (-1 to stop): ";
    cin >> x;

    if (x == -1) {
        return NULL;
    }

    Node* root = createNode(x);

    cout << "Enter left child of " << x << ": ";
    root->left = buildTree();

    cout << "Enter right child of " << x << ": ";
    root->right = buildTree();

    return root;
}



// Calculate height of tree
 int sumOfNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}

// Calculate sum of all nodes

int main() {
    
    
    cout << "\n=== Build Binary Tree ===\n\n";
    cout << "Instructions:\n";
    cout << "- Enter -1 to indicate no child/NULL\n";
    cout << "- Enter values in preorder fashion\n\n";
    
   Node* root = buildTree();
    
    if (root == NULL) {
        cout << "\nTree is empty.\n";
        cout << "\nPress any key to exit...";
    
        return 0;
    }
    
    int sum = sumOfNodes(root);
    cout << "\nSum of all nodes in the tree: " << sum << endl;

    cout << "\nThank you for using Binary Tree Operations!\n";
    cout << "\nPress any key to exit...";
    cin.get(); // Wait for user input before exiting
    cin.get(); // To consume the newline character
    return 0;

    
}
