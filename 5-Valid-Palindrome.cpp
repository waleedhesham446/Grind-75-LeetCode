class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int non_alphanumeric = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] >= 65 && s[i] <= 90) {
                s[i] += 32;
            } else if (
                !(s[i] >= 97 && s[i] <= 122) &&
                !(s[i] >= 48 && s[i] <= 57)
            ) {
                s[i] = '#';
                non_alphanumeric++;
            }
        }

        int m = n - non_alphanumeric;
        char* filtered_str = new char[m];
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != '#') {
                filtered_str[j++] = s[i];
            }
        }
        for (int i = 0; i < m/2; i++) {
            if (filtered_str[i] != filtered_str[m-i-1]) {
                return false;
            }
        }

        return true;
    }
};
