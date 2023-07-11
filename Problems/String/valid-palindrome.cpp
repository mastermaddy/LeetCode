class Utils {
public:
    static bool isNumeric(char c) {
        return (c >= '0' && c <= '9');
    }
    static bool isAlpha(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
    static bool isAlphaNumeric(char c) {
        return isAlpha(c) || isNumeric(c);
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.length() - 1;
        while (start < end) {
            while (start < end && !Utils::isAlphaNumeric(s[start])) {
                start++;
            }
            while (start < end && !Utils::isAlphaNumeric(s[end])) {
                end--;
            }
            if (start < end && tolower(s[start]) == tolower(s[end])) {
                start++;
                end--;
                continue;
            }
            break;
        }
        return start >= end;
    }
};