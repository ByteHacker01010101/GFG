class Solution {
public:
    bool findPath(Node* root, int target, vector<char>& path) {
        if (root == NULL)
            return false;

        if (root->data == target)
            return true;

        // Go left
        path.push_back('L');
        if (findPath(root->left, target, path))
            return true;
        path.pop_back();

        // Go right
        path.push_back('R');
        if (findPath(root->right, target, path))
            return true;
        path.pop_back();

        return false;
    }

    int numberOfTurns(Node* root, int p, int q) {
        vector<char> pathP, pathQ;

        findPath(root, p, pathP);
        findPath(root, q, pathQ);

        // Find common path (up to LCA)
        int i = 0;

        while (i < pathP.size() &&
               i < pathQ.size() &&
               pathP[i] == pathQ[i]) {
            i++;
        }

        vector<char> path;

        // p -> LCA
        // Reverse the remaining path, but DO NOT swap L and R
        for (int j = (int)pathP.size() - 1; j >= i; j--) {
            path.push_back(pathP[j]);
        }

        // LCA -> q
        for (int j = i; j < (int)pathQ.size(); j++) {
            path.push_back(pathQ[j]);
        }

        // Count direction changes
        int turns = 0;

        for (int j = 1; j < (int)path.size(); j++) {
            if (path[j] != path[j - 1]) {
                turns++;
            }
        }

        return turns == 0 ? -1 : turns;
    }
};