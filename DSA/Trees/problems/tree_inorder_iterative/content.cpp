// Tree Inorder Iterative using Stack
// Key trick: Nullify left child after processing to avoid infinite loop

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    
    Node(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node* root) {
    stack<Node*> st;
    st.push(root);
    
    while(!st.empty()) {
        Node* current = st.top();
        
        if(current->left == NULL) {
            cout << current->val << " ";
            st.pop();
            
            // If there's a right child, push it
            if(current->right != nullptr) {
                st.push(current->right);
            }
            continue;
        }
        
        Node* leftChild = current->left;
        current->left = nullptr;  // Key trick: nullify so we don't revisit
        st.push(leftChild);
    }
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    
    cout << "Inorder traversal of the tree: ";
    inorder(root);
    cout << endl;

    return 0;
}
