// https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    /*
    [73, 74, 75, 71, 69, 72, 76, 73]
    */
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        unordered_map<int,int> temp2ind;
        for (int i = n-1; i >= 0; i--) {
            int candidate = T[i]+1;
            int index = INT_MAX;
            while (candidate <= 100) {
                if (temp2ind.find(candidate) != temp2ind.end())
                    index = min(index, temp2ind[candidate]);
                candidate++;
            }
            temp2ind[T[i]] = i;
            if (index == INT_MAX)
                T[i] = 0;
            else
                T[i] = index-i;
        }
        return T;
    }
};

