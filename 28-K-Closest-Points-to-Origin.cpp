class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        multiset<pair<int, vector<int>>> d_multiset;

        for (int i = 0; i < n; i++) {
            int d2 = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            d_multiset.insert({ d2, points[i] });
        }

        vector<vector<int>> ans(k);
        multiset<pair<int, vector<int>>>::iterator itr;
        int i = 0;
        for (itr = d_multiset.begin(); itr != d_multiset.end() && i < k; itr++) {
            ans[i++] = itr->second;
        }

        return ans;
    }
};
