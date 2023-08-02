class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> alphabets(26, 0);
        int n = magazine.size();
        int m = ransomNote.size();

        for (int i = 0; i < n; i++) {
            alphabets[magazine[i] - 'a']++;
        }
        std::cout << alphabets[0] << std::endl;
        for (int i = 0; i < m; i++) {
            alphabets[ransomNote[i] - 'a']--;
            if (alphabets[ransomNote[i] - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};
