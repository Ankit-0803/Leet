class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       //multi source bfs
       int m=mat.size();
       int n=mat[0].size();
       vector<vector<int>>dist(m, vector<int>(n,-1));
       queue<pair<int, int>>q;
       //push all the blocks with zero in the queue
       for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
           if(mat[i][j]==0){
              dist[i][j]=0;
              q.push({i,j});
           } 
        }
       }
       vector<pair<int, int>>directions{{-1,0}, {1,0}, {0,-1}, {0,1}};
       //expand bfs
       while(!q.empty()){
        auto [r,c]=q.front();
        q.pop();
        for(auto[dr,dc]:directions){
        int nr=dr+r;
        int nc=dc+c;
              if(nr>=0 && nr<m && nc>=0 && nc<n && dist[nr][nc]==-1){
                dist[nr][nc]=dist[r][c]+1;
                q.push({nr, nc});
              }
       }
    }
    return dist;
    }
};