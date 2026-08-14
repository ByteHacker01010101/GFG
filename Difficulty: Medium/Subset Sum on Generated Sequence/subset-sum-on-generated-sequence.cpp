class Solution {
public:
    bool isPossible(vector<int>& arr, int s, int x) {
   
        if (x == 0)
            return true;

        unordered_set<long long> dp;
        dp.reserve(100000);

      
        dp.insert(0);

        
        long long total = s;

        if (s <= x) {
            vector<long long> add;

            for (long long v : dp) {
                if (v + s <= x)
                    add.push_back(v + s);
            }

            for (long long v : add)
                dp.insert(v);

            if (dp.count(x))
                return true;
        }

       
        for (int a : arr) {
            long long val = total + a;

         
            if (val > x)
                break;

            vector<long long> add;
            add.reserve(dp.size());

            for (long long v : dp) {
                if (v + val <= x)
                    add.push_back(v + val);
            }

            for (long long v : add)
                dp.insert(v);

            if (dp.count(x))
                return true;

            total += val;
        }

        return false;
    }
};