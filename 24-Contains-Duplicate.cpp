class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // map<int, int> m;
        // for (auto it = nums.begin(); it != nums.end(); it++) {
        //     m[*it]++;
        // }
        // for (auto it = m.begin(); it != m.end(); it++) {
        //     if (it->second > 1) {
        //         return true;
        //     }
        // }

        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num) > 0) {
                return true;
            }
            seen.insert(num);
        }

        return false;
    }
};
