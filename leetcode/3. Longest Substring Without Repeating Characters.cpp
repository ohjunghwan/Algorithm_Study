class Solution {
public:
    int visit[600];

    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int result = 0;
        int current_len = 0;

        for (char alpha : s) {
            if (visit[alpha]) {
                while (s[start] != alpha) {
                    visit[s[start]] = 0;
                    current_len--;
                    start++;
                }
                start++;
                current_len--;
            }

            visit[alpha] = 1;
            result = max(result, ++current_len);
        }

        return result;
    }
};