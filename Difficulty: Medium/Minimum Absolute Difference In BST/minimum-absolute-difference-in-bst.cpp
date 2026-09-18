class Solution {
    void inorder(Node* root, Node*& prev, int& ans) {
        if (root == nullptr)
            return;

 
        inorder(root->left, prev, ans);

  
        if (prev != nullptr) {
            ans = min(ans, root->data - prev->data);
        }

        prev = root;

    
        inorder(root->right, prev, ans);
    }

public:
    int absDiff(Node* root) {
        Node* prev = nullptr;
        int ans = INT_MAX;

        inorder(root, prev, ans);

        return ans;
    }
};