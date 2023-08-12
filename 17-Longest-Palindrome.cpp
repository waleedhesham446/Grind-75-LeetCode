class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> alphabets(52, 0);
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char letter = s[i];
            bool isSmall = (letter >= 'a' && letter <= 'z');
            int index = isSmall ? (letter - 'a') : (letter - 'A' + 26);
            alphabets[index]++;
        }
        
        int even = 0;
        bool isOdd = false;

        for (int i = 0; i < 52; i++) {
            if (alphabets[i] % 2 != 0) {
                even += alphabets[i] - 1;
                isOdd = true;
            } else {
                even += alphabets[i];
            }
        }
        
        return even + int(isOdd);
    }
};
