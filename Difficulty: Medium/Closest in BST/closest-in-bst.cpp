class Solution {
  public:
    int minDiff(Node* root, int k) {
        int ans = INT_MAX;

        while (root) {
            ans = min(ans, abs(root->data - k));

            if (ans == 0)
                return 0;

            if (k < root->data)
                root = root->left;
            else
                root = root->right;
        }

        return ans;
    }
};