class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;
        for (char c : target)
            cnt[c - 'a']--;
        for (int i = n - 1; i >= 0; i--) {
            int x = target[i] - 'a';
            cnt[x]++; 

            bool validPrefix = true;
            for (int k = 0; k < 26; k++) {
                if (cnt[k] < 0) {
                    validPrefix = false;
                    break;
                }
            }
            if (!validPrefix) continue;

            for (int j = x + 1; j < 26; j++) {
                if (cnt[j] > 0) {
                    string ans = target.substr(0, i);
                    ans += char('a' + j);
                    cnt[j]--;

                    for (int k = 0; k < 26; k++) {
                        while (cnt[k] > 0) {
                            ans += char('a' + k);
                            cnt[k]--;
                        }
                    }
                    return ans;
                }
            }
        }

        return "";
    }
};