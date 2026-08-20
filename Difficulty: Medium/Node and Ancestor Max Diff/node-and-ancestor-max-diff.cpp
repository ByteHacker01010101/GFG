class Solution {
public:

    int solve(Node* root, int maxAncestor) {
        if (root == nullptr)
            return INT_MIN;

        int best = INT_MIN;

        
        best = max(best, maxAncestor - root->data);

        
        maxAncestor = max(maxAncestor, root->data);

        int left = solve(root->left, maxAncestor);
        int right = solve(root->right, maxAncestor);

        return max(best, max(left, right));
    }

    int maxDiff(Node* root) {
        if (root == nullptr)
            return 0;

        
        int left = solve(root->left, root->data);
        int right = solve(root->right, root->data);

        return max(left, right);
    }
};