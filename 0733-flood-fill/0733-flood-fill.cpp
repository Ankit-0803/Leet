class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int val, int color){
        int m=image.size();
        int n=image[0].size();
        if(r<0 || r>=m || c<0 || c>=n || image[r][c]!=val ){
            return;
        }
        image[r][c]=color;
        dfs(image, r+1, c, val, color);
        dfs(image, r-1, c, val, color);
        dfs(image, r, c+1, val, color);
        dfs(image, r, c-1, val, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int val=image[sr][sc];
    if(color==val)return image;
    dfs(image, sr, sc, val, color);
    return image;
    }
};
// It immediately exits the current recursive call of the function.
// Control goes back to the previous recursive call (the parent cell).
// This prevents painting outside the image boundaries or painting wrong-colored cells.