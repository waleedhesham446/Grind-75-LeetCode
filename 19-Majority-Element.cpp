#include <map>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int, int> m;
        for (auto it = nums.begin(); it != nums.end(); it++) {
            m[*it]++;
        }

        for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
            if (it->second > n/2) {
                return it->first;
            }
        }

        return -1;
    }
};
