class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>>maxHeap;
        for(auto& p:points){
            int dist=p[0]*p[0]+p[1]*p[1];
            maxHeap.push({dist, p});
        
        //keep only k elements in the heap
        if(maxHeap.size()>k){
            maxHeap.pop(); //remove farthiest point
        }
      }
      //collect result
      vector<vector<int>>res;
      while(!maxHeap.empty()){
        res.push_back(maxHeap.top().second);
        maxHeap.pop();
      }
      return res;
    }
};