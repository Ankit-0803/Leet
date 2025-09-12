class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        int n=intervals.size();
        sort(intervals.begin(), intervals.end());
        for(const auto& interval: intervals){
        //check if ending time of previous interval is less than starting time of current interval
        if(res.empty()|| res.back()[1]<interval[0]){
            res.push_back(interval);
        }
        //merge the overlapping interval
        else{
            res.back()[1]=max(res.back()[1], interval[1]);
        }
        }
        return res;
    }
};