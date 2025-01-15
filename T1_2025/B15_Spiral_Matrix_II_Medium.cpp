class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        int a[21][21];
        int x = 0;
        int y = 0;
        int dx  = 1;
        int dy = 0;
        for(int i = 1; i <= n*n; i++) {
            a[y][x] = i;
            if(!(x+dx >= 0 && x+dx < n && y+dy >= 0 && y+dy < n) || a[y+dy][x+dx]) {
                int temp = dx;
                dx = -dy;
                dy = temp;
            }
            x+=dx;
            y+=dy;
        }
        for(int i = 0; i < n; i++) {
            vector<int> b;
            for(int j = 0; j < n; j++) {
                b.push_back(a[i][j]);
            }
            res.push_back(b);
        }

        return res;
    }
};
