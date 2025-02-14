#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
    	val = x;
    	left = NULL;
    	right = NULL;
	}
};

// Function to perform in-order traversal and find the Kth smallest element
void inOrderTraversal(TreeNode* node, int k, int& count, int& result) {
    if (node == NULL || result != 0) {
        return;
    }

    // Traverse the left subtree
    inOrderTraversal(node->left, k, count, result);

    // Process the current node
    count++;
    if (count == k) {
        result = node->val;
        return;
    }

    // Traverse the right subtree
    inOrderTraversal(node->right, k, count, result);
}

// Function to find the Kth smallest element in a BST
int kthSmallest(TreeNode* root, int k) {
    int result = 0;
    int count = 0;
    inOrderTraversal(root, k, count, result);
    return result;
}

int main() {
    // Constructing a BST
    //       5
    //      / \
    //     3   6
    //    / \   \
    //   2   4   7
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    int k = 5;
    cout << "The " << k << "th smallest element is: " << kthSmallest(root, k) << endl;

    // Clean up memory (optional, but good practice)
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
