class Solution {
public:
    string lexPalindromicPermutation(string s, string t) {
        int n = s.length();
        vector<int> c(26, 0);
        for (char ch : s) c[ch - 'a']++;
        char mid = 0;
        int odd = 0;
        for (int i = 0; i < 26; i++) {
            if (c[i] % 2) {
                odd++;
                mid = 'a' + i;
            }
        }
        if (odd > 1) return "";
        auto makeP = [&](const string& l) {
            string res = l;
            if (n % 2) res += mid;
            for (int i = (int)l.length() - 1; i >= 0; i--) res += l[i];
            return res;
        };
        string th = t.substr(0, n / 2);
        for (int i = th.length(); i >= 0; i--) {
            vector<int> cnt = c;
            string pref = "";
            bool ok = true;
            for (int j = 0; j < i; j++) {
                int idx = th[j] - 'a';
                if (cnt[idx] >= 2) {
                    cnt[idx] -= 2;
                    pref += th[j];
                } else {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            if (i == (int)th.length()) {
                string rem = "";
                for (int k = 0; k < 26; k++) rem.append(cnt[k] / 2, 'a' + k);
                string cand = makeP(pref + rem);
                if (cand > t) return cand;
                continue;
            }
            int nxt = -1;
            for (int k = th[i] - 'a' + 1; k < 26; k++) {
                if (cnt[k] >= 2) {
                    nxt = k;
                    break;
                }
            }
            if (nxt != -1) {
                cnt[nxt] -= 2;
                pref += (char)('a' + nxt);
                string rem = "";
                for (int k = 0; k < 26; k++) rem.append(cnt[k] / 2, 'a' + k);
                return makeP(pref + rem);
            }
        }
        return "";
    }
};