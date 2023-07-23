#include <map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> map;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            map[nums[i]] = target - nums[i];
        }
        std::map<int, int>::iterator it = map.begin();

        int first = 0, second = 0;
        while(it != map.end()) {
            if (map[it->second] == it->first) {
                first = it->first;
                second = it->second;
                break;
            }
            ++it;
        }

        int first_index = -1, second_index = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == first && first_index == -1) {
                first_index = i;
            } else if (nums[i] == second && second_index == -1) {
                second_index = i;
            }
        }

        vector<int> answer{ first_index, second_index };

        return answer;
    }
};
