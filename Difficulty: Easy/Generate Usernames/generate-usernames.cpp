class Solution {
  public:
    vector<string> generateUsernames(vector<string>& arr) {
    unordered_set<string> reserved, used;
    unordered_map<string, int> nxt;

    for (auto &s : arr)
        reserved.insert(s);

    vector<string> ans;

    for (auto &s : arr) {
        if (!used.count(s)) {
            ans.push_back(s);
            used.insert(s);
        }
        else {
            int &k = nxt[s];

            if (k == 0) k = 1;

            string candidate;

            while (true) {
                candidate = s + to_string(k);

                if (!reserved.count(candidate) &&
                    !used.count(candidate))
                    break;

                k++;
            }

            ans.push_back(candidate);
            used.insert(candidate);
            k++;
        }
    }

    return ans;
}
};