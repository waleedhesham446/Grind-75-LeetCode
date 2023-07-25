class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_size = s.size();
        int t_size = t.size();
        if (s_size != t_size) {
            return false;
        }

        vector<int> chars(26, 0);
        for (int i = 0; i < s_size; i++) {
            chars[s[i]-'a']++;
        }
        for (int i = 0; i < t_size; i++) {
            chars[t[i]-'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (chars[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
