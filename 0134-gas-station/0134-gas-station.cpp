class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
         const int n = (int)gas.size();
        int totaltank=0, currtank=0, start=0;
        for(int i=0; i<n; i++){
            int gain=gas[i]-cost[i];
            totaltank+=gain;  //accumulate overall feasibility
            currtank+=gain;   //track viability for current start
            // If we can't reach station i+1 from current 'start',
            // then none of the stations in [start..i] can be valid starts.
            if(currtank<0){
                // Choose next station as new candidate start
                start=i+1;
                 // Reset current tank because we're starting afresh
                currtank=0;
            }
        }
        return (totaltank>=0)?start:-1;
    }
};