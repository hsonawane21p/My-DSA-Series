

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

// ============================================
// BASIC OPERATIONS
// ============================================

// Count total number of nodes
int countNodes(Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Calculate height of tree
int height(Node* root) {
    if (root == NULL) return 0;
    
    int leftH = height(root->left);
    int rightH = height(root->right);
    
    return 1 + (leftH > rightH ? leftH : rightH);
}

// Calculate sum of all nodes
int sumNodes(Node* root) {
    if (root == NULL) return 0;
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

// Find maximum value in tree
int maxNode(Node* root) {
    if (root == NULL) return -32768;
    
    int leftMax = maxNode(root->left);
    int rightMax = maxNode(root->right);
    
    int maxVal = root->data;
    if (leftMax > maxVal) maxVal = leftMax;
    if (rightMax > maxVal) maxVal = rightMax;
    
    return maxVal;
}

// Find minimum value in tree
int minNode(Node* root) {
    if (root == NULL) return 32767;
    
    int leftMin = minNode(root->left);
    int rightMin = minNode(root->right);
    
    int minVal = root->data;
    if (leftMin < minVal) minVal = leftMin;
    if (rightMin < minVal) minVal = rightMin;
    
    return minVal;
}

// Count leaf nodes
int leafNodes(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return leafNodes(root->left) + leafNodes(root->right);
}

// ============================================
// TREE TRAVERSALS
// ============================================

// Inorder: Left -> Root -> Right
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder: Root -> Left -> Right
void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder: Left -> Right -> Root
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Level Order Traversal using array-based queue
void levelOrder(Node* root) {
    if (root == NULL) return;
    
    Node* queue[100];
    int front = 0, rear = 0;
    
    queue[rear++] = root;
    
    while (front < rear) {
        Node* current = queue[front++];
        cout << current->data << " ";
        
        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }
}

// ============================================
// SEARCH OPERATIONS
// ============================================

// Search for a value in tree
int search(Node* root, int key) {
    if (root == NULL) return 0;
    if (root->data == key) return 1;
    return search(root->left, key) || search(root->right, key);
}

// ============================================
// ANCESTOR OPERATIONS
// ============================================

// Print all ancestors of a given node
int printAncestors(Node* root, int target) {
    if (root == NULL) return 0;
    
    if (root->data == target) return 1;
    
    if (printAncestors(root->left, target) || 
        printAncestors(root->right, target)) {
        cout << root->data << " ";
        return 1;
    }
    
    return 0;
}

// Find Lowest Common Ancestor (LCA)
Node* findLCA(Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    
    if (root->data == n1 || root->data == n2)
        return root;
    
    Node* leftLCA = findLCA(root->left, n1, n2);
    Node* rightLCA = findLCA(root->right, n1, n2);
    
    if (leftLCA && rightLCA) return root;
    
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

// ============================================
// INORDER PREDECESSOR & SUCCESSOR
// ============================================

// Store inorder traversal in array
void storeInorder(Node* root, int arr[], int &index) {
    if (root == NULL) return;
    storeInorder(root->left, arr, index);
    arr[index++] = root->data;
    storeInorder(root->right, arr, index);
}

// Find predecessor and successor
void findPreSuc(Node* root, int key, int &pre, int &suc) {
    int arr[100];
    int index = 0;
    storeInorder(root, arr, index);
    
    pre = -1;
    suc = -1;
    
    for (int i = 0; i < index; i++) {
        if (arr[i] == key) {
            if (i > 0) pre = arr[i-1];
            if (i < index-1) suc = arr[i+1];
            break;
        }
    }
}

// ============================================
// MIRROR TREE
// ============================================

// Mirror/Invert the tree
void mirrorTree(Node* root) {
    if (root == NULL) return;
    
    // Swap left and right children
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    // Recursively mirror subtrees
    mirrorTree(root->left);
    mirrorTree(root->right);
}

// ============================================
// IDENTICAL TREES
// ============================================

// Check if two trees are identical
int areIdentical(Node* root1, Node* root2) {
    // Both empty
    if (root1 == NULL && root2 == NULL) return 1;
    
    // One empty, one not
    if (root1 == NULL || root2 == NULL) return 0;
    
    // Check current node and recursively check subtrees
    return (root1->data == root2->data) &&
           areIdentical(root1->left, root2->left) &&
           areIdentical(root1->right, root2->right);
}

// ============================================
// DIAMETER OF TREE
// ============================================

// Diameter: longest path between any two nodes
int diameterHelper(Node* root, int &diameter) {
    if (root == NULL) return 0;
    
    int leftH = diameterHelper(root->left, diameter);
    int rightH = diameterHelper(root->right, diameter);
    
    // Update diameter if path through current node is longer
    int currentDiameter = leftH + rightH + 1;
    if (currentDiameter > diameter) diameter = currentDiameter;
    
    return 1 + (leftH > rightH ? leftH : rightH);
}

int diameter(Node* root) {
    int diam = 0;
    diameterHelper(root, diam);
    return diam;
}

// ============================================
// BALANCED TREE
// ============================================

// Check if tree is height-balanced
int checkBalance(Node* root) {
    if (root == NULL) return 0;
    
    int leftH = checkBalance(root->left);
    if (leftH == -1) return -1;
    
    int rightH = checkBalance(root->right);
    if (rightH == -1) return -1;
    
    int diff = leftH - rightH;
    if (diff < 0) diff = -diff;
    
    if (diff > 1) return -1;
    
    return 1 + (leftH > rightH ? leftH : rightH);
}

int isBalanced(Node* root) {
    return checkBalance(root) != -1;
}

// ============================================
// PATH OPERATIONS
// ============================================

// Print all paths from root to leaf
void printPathsHelper(Node* root, int path[], int len) {
    if (root == NULL) return;
    
    path[len] = root->data;
    len++;
    
    // If leaf node, print path
    if (root->left == NULL && root->right == NULL) {
        cout << "[ ";
        for (int i = 0; i < len; i++) {
            cout << path[i] << " ";
        }
        cout << "]  ";
    } else {
        printPathsHelper(root->left, path, len);
        printPathsHelper(root->right, path, len);
    }
}

void printAllPaths(Node* root) {
    int path[100];
    printPathsHelper(root, path, 0);
}

// Check if there's a path with given sum
int hasPathSum(Node* root, int sum) {
    if (root == NULL) return 0;
    
    if (root->left == NULL && root->right == NULL)
        return sum == root->data;
    
    return hasPathSum(root->left, sum - root->data) ||
           hasPathSum(root->right, sum - root->data);
}

// ============================================
// UTILITY FUNCTIONS
// ============================================

// Delete entire tree
void deleteTree(Node* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Copy a tree
Node* copyTree(Node* root) {
    if (root == NULL) return NULL;
    
    Node* newNode = createNode(root->data);
    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);
    
    return newNode;
}

// ============================================
// MENU SYSTEM
// ============================================

void displayMenu() {
    cout << "\n========================================\n";
    cout << "     BINARY TREE OPERATIONS MENU\n";
    cout << "========================================\n";
    cout << "1.  Show Tree Properties\n";
    cout << "2.  Tree Traversals\n";
    cout << "3.  Search for a Value\n";
    cout << "4.  Find Ancestors\n";
    cout << "5.  Find Predecessor & Successor\n";
    cout << "6.  Find Lowest Common Ancestor\n";
    cout << "7.  Mirror/Invert Tree\n";
    cout << "8.  Check if Tree is Balanced\n";
    cout << "9.  Calculate Diameter\n";
    cout << "10. Print All Root-to-Leaf Paths\n";
    cout << "11. Check Path Sum\n";
    cout << "12. Compare with Another Tree\n";
    cout << "0.  Exit\n";
    cout << "========================================\n";
    cout << "Enter choice: ";
}

// ============================================
// MAIN FUNCTION
// ============================================

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
    
    int choice;
    
    do {
        
        displayMenu();
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "\n=== Tree Properties ===\n";
                cout << "Total nodes      : " << countNodes(root) << endl;
                cout << "Height           : " << height(root) << endl;
                cout << "Sum of all nodes : " << sumNodes(root) << endl;
                cout << "Maximum value    : " << maxNode(root) << endl;
                cout << "Minimum value    : " << minNode(root) << endl;
                cout << "Leaf nodes       : " << leafNodes(root) << endl;
                break;
            
            case 2:
                cout << "\n=== Tree Traversals ===\n";
                cout << "Inorder    : "; inorder(root); cout << endl;
                cout << "Preorder   : "; preorder(root); cout << endl;
                cout << "Postorder  : "; postorder(root); cout << endl;
                cout << "Level Order: "; levelOrder(root); cout << endl;
                break;
            
            case 3: {
                int key;
                cout << "\nEnter value to search: ";
                cin >> key;
                if (search(root, key))
                    cout << key << " found in the tree!\n";
                else
                    cout << key << " not found in the tree.\n";
                break;
            }
            
            case 4: {
                int target;
                cout << "\nEnter node to find ancestors: ";
                cin >> target;
                cout << "Ancestors of " << target << ": ";
                if (!printAncestors(root, target))
                    cout << "Node not found!";
                cout << endl;
                break;
            }
            
            case 5: {
                int key, pre, suc;
                cout << "\nEnter value: ";
                cin >> key;
                findPreSuc(root, key, pre, suc);
                cout << "Predecessor: ";
                if (pre == -1) cout << "None"; else cout << pre;
                cout << "\nSuccessor  : ";
                if (suc == -1) cout << "None"; else cout << suc;
                cout << endl;
                break;
            }
            
            case 6: {
                int n1, n2;
                cout << "\nEnter two node values: ";
                cin >> n1 >> n2;
                Node* lca = findLCA(root, n1, n2);
                if (lca != NULL)
                    cout << "LCA of " << n1 << " and " << n2 << " is: " << lca->data << endl;
                else
                    cout << "LCA not found!\n";
                break;
            }
            
            case 7:
                mirrorTree(root);
                cout << "\nTree has been mirrored!\n";
                cout << "Inorder traversal: ";
                inorder(root);
                cout << "\n\nNote: Tree is now mirrored. Mirror again to restore.\n";
                break;
            
            case 8:
                cout << "\nTree is ";
                if (isBalanced(root))
                    cout << "BALANCED\n";
                else
                    cout << "NOT BALANCED\n";
                break;
            
            case 9:
                cout << "\nDiameter of tree: " << diameter(root) << endl;
                cout << "(Longest path between any two nodes)\n";
                break;
            
            case 10:
                cout << "\n=== All Root-to-Leaf Paths ===\n";
                printAllPaths(root);
                cout << endl;
                break;
            
            case 11: {
                int targetSum;
                cout << "\nEnter target sum: ";
                cin >> targetSum;
                if (hasPathSum(root, targetSum))
                    cout << "Path with sum " << targetSum << " exists!\n";
                else
                    cout << "No path with sum " << targetSum << " exists.\n";
                break;
            }
            
            case 12: {
                cout << "\n=== Build Second Tree ===\n";
                Node* root2 = buildTree();
                if (areIdentical(root, root2))
                    cout << "\nTrees are IDENTICAL!\n";
                else
                    cout << "\nTrees are NOT IDENTICAL.\n";
                deleteTree(root2);
                break;
            }
            
            case 0:
                cout << "\nExiting...\n";
                break;
            
            default:
                cout << "\nInvalid choice!\n";
        }
        
        if (choice != 0) {
            cout << "\nPress any key to continue...";
            
        }
        
    } while (choice != 0);
    
    // Clean up memory
    deleteTree(root);
    
    cout << "\nThank you for using Binary Tree Operations!\n";
    
}
