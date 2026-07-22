struct Group {
    int start;
    int length;
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int ones = 0;
        for (char c : s) {
            if (c == '1') ones++;
        }

        vector<Group> zero_groups;
        vector<int> zero_id;
        zero_id.reserve(n);

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0') {
                    zero_groups.back().length++;
                } else {
                    zero_groups.push_back({i, 1});
                }
            }
            zero_id.push_back(zero_groups.empty() ? -1 : (int)zero_groups.size() - 1);
        }

        int m = zero_groups.size();
        if (m == 0) {
            return vector<int>(queries.size(), ones);
        }

        vector<int> pair_sums;
        if (m > 1) {
            pair_sums.resize(m - 1);
            for (int i = 0; i < m - 1; i++) {
                pair_sums[i] = zero_groups[i].length + zero_groups[i + 1].length;
            }
        }

        int p_size = pair_sums.size();
        int k_max = p_size > 0 ? log2(p_size) + 1 : 1;
        vector<vector<int>> st(k_max, vector<int>(p_size, 0));

        if (p_size > 0) {
            for (int i = 0; i < p_size; i++) st[0][i] = pair_sums[i];
            for (int k = 1; k < k_max; k++) {
                for (int i = 0; i + (1 << k) <= p_size; i++) {
                    st[k][i] = max(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
                }
            }
        }

        auto query_st = [&](int l, int r) {
            if (l > r || p_size == 0) return 0;
            int k = log2(r - l + 1);
            return max(st[k][l], st[k][r - (1 << k) + 1]);
        };

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int l = q[0], r = q[1];
            int gl = zero_id[l];
            int gr = zero_id[r];

            int left = (gl == -1) ? 0 : (zero_groups[gl].start + zero_groups[gl].length - l);
            int right = (gr == -1) ? 0 : (r - zero_groups[gr].start + 1);

            int res = ones;

            if (s[l] == '0' && s[r] == '0' && gl + 1 == gr) {
                res = max(res, ones + left + right);
            }

            int start_pair = gl + 1;
            int last_group = (s[r] == '1') ? gr : gr - 1;
            int end_pair = last_group - 1;

            if (start_pair <= end_pair && start_pair >= 0 && end_pair < p_size) {
                res = max(res, ones + query_st(start_pair, end_pair));
            }

            if (s[l] == '0' && gl + 1 <= last_group && gl + 1 < m) {
                res = max(res, ones + left + zero_groups[gl + 1].length);
            }

            if (s[r] == '0' && gl < gr - 1) {
                res = max(res, ones + right + zero_groups[gr - 1].length);
            }

            ans.push_back(res);
        }

        return ans;
    }
};