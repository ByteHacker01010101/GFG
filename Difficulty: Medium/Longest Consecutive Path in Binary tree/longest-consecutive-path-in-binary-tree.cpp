class Solution {
public:
    int ans = 1;

    void dfs(Node* root, Node* parent, int len) {
        if (!root) return;

        if (parent && root->data == parent->data + 1)
            len++;
        else
            len = 1;

        ans = max(ans, len);

        dfs(root->left, root, len);
        dfs(root->right, root, len);
    }

    int longestConsecutive(Node* root) {
        if (!root) return -1;

        ans = 1;
        dfs(root, NULL, 1);

        return (ans == 1) ? -1 : ans;
    }
};