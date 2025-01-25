class Solution {
public:
    int N, K;
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb;
        N = n;
        K = k;
        cout << N << " " << K << "\n";
        Try(1, comb, res);

        return res;
    }

    void Try(int i, vector<int>& comb, vector<vector<int>>& res) {
        if(comb.size() == K) {
            res.push_back(comb);
            return;
        }

        for(int j = i; j <= N; j++) {
            comb.push_back(j);
            Try(j + 1, comb, res);
            comb.pop_back();
        }
    }
};
