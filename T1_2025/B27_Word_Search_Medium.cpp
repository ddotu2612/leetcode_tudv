class Solution {
public:
    int M, N;
    bool exist(vector<vector<char>>& board, string word) {
        M = board.size();
        N = board[0].size();
        vector<vector<int>> visited(M, vector<int>(N, false));
        vector<pair<int, int>> s;
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                if(board[i][j] == word[0]) {
                    s.push_back({i, j});
                }
            }
        }
        if(s.empty()) return false;

        bool check = false;
        for(int i = 0; i < s.size(); i++) {
            check = dfs(s[i].first, s[i].second, board, visited, word, 0);
            if(check) return true;
        }

        return false;
    }

    bool dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>& visited, string word, int idx) {
        // cout << i << " " << j << " " << idx << "\n";
        if(idx == word.length() - 1) return true;
        visited[i][j] = true;
        bool check = false;
        if(i-1 >= 0 && !visited[i-1][j] && board[i-1][j] == word[idx+1]) {
            check = check || dfs(i-1, j, board, visited, word, idx+1);
            if(check) return true;
        }
        if(i+1 < M && !visited[i+1][j] && board[i+1][j] == word[idx+1]) {
            check = check || dfs(i+1, j, board, visited, word, idx+1);
            if(check) return true;
        }
        if(j-1 >= 0 && !visited[i][j-1] && board[i][j-1] == word[idx+1]) {
            check = check || dfs(i, j-1, board, visited, word, idx+1);
            if(check) return true;
        }
        if(j+1 < N && !visited[i][j+1] && board[i][j+1] == word[idx+1]) {
            check = check || dfs(i, j+1, board, visited, word, idx+1);
            if(check) return true;
        }
        visited[i][j] = false;
        return check;
    }
};
