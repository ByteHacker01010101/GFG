class Solution {
public:
    Node* constructTreeUtil(vector<int>& pre, vector<int>& preM,
                             int& preIndex, int l, int h, int n) {
        if (preIndex >= n || l > h) {
            return NULL;
        }

        Node* root = new Node(pre[preIndex]);
        preIndex++;

        if (preIndex >= n || l == h) {
            return root;
        }

        int i;
        for (i = l; i <= h; i++) {
            if (preM[i] == pre[preIndex]) {
                break;
            }
        }

        if (i <= h) {
            root->left = constructTreeUtil(pre, preM, preIndex, i, h, n);
            root->right = constructTreeUtil(pre, preM, preIndex, l, i - 1, n);
        }

        return root;
    }

    Node* constructBinaryTree(vector<int>& preorder, vector<int>& mirrorPreorder) {
        int n = preorder.size();
        int preIndex = 0;
        return constructTreeUtil(preorder, mirrorPreorder, preIndex, 0, n - 1, n);
    }
};