class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<vector<int>> v;

        sort(intervals.begin(), intervals.end());
        int st = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
            }
            else {
                v.push_back({st, end});
                st = intervals[i][0];
                end = intervals[i][1];
            }
        }
        v.push_back({st, end});

        return v;
    }
};