class Solution {
public: 
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k){
          int m=board.size();
          int n=board[0].size();
          if(k==word.size())return true;
          //If we are out of bounds OR current cell doesn't match required char → fail
          if(i<0||j<0||i>=m||j>=n||board[i][j]!=word[k])
           return false;
          //Save current cell character (since we'll temporarily overwrite it)
          // Mark as visited so it’s not reused in this path
           char temp=board[i][j];
           board[i][j]='#';
           //Explore all 4 directions: Down, Up, Right, Left
           bool found=dfs(board, word, i+1, j, k+1)||dfs(board, word, i-1, j, k+1)||dfs(board, word, i, j+1, k+1)
           ||dfs(board, word, i, j-1, k+1);
           //Backtrack → restore the original character
           board[i][j]=temp;
           // return whether we found the word from this path
           return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]==word[0]){
                    if(dfs(board, word, i, j, 0))return true;
                }
            }
        }
        return false;
        }
};