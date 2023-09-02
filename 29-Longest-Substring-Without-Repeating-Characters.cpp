class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int left = 0;
        set<char> char_set;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            if (char_set.count(c) == 0) {
                char_set.insert(c);
                maxLength = max(maxLength, right - left + 1);
            } else {
                while (char_set.count(c)) {
                    char_set.erase(s[left]);
                    left++;
                }
                char_set.insert(c);
            }
        }

        return maxLength;
    }
};
