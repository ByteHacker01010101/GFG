class Solution {
public:
    int getCount(Node* root, int k) {
        if (root == NULL)
            return 0;

        vector<int> costs;

        queue<pair<Node*, int>> q;
        q.push({root, 1});

        while (!q.empty()) {
            Node* node = q.front().first;
            int level = q.front().second;
            q.pop();

            // Leaf node
            if (node->left == NULL && node->right == NULL) {
                costs.push_back(level);
                continue;
            }

            if (node->left)
                q.push({node->left, level + 1});

            if (node->right)
                q.push({node->right, level + 1});
        }

        // Visit cheapest leaves first
        sort(costs.begin(), costs.end());

        int ans = 0;

        for (int cost : costs) {
            if (cost > k)
                break;

            k -= cost;
            ans++;
        }

        return ans;
    }
};