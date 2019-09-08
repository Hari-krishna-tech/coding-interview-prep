// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // base case:
        int n = nums.size();
        if (n == 0 || n == 1)
            return n;
        int i = 0, j = 1;
        while (j < n) {
            if (nums[i] != nums[j]) {
                nums[i+1] = nums[j];
                i++;
            }
            j++;
        }
        
        return i+1;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1)
            return n;
        
        int idx = 1; // idx - actual index
        int cur = nums[0];
        
        for (int i = 1; i < n; i++) {
            if (cur != nums[i]) { // not duplicate
                nums[idx] = nums[i]; // set it to such first non-duplicate
                idx++;
                cur = nums[i];
            }
        }
        
        return idx;
    }
};