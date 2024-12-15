class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int max_time = events[0][1];
        int idx = events[0][0];
        for(int i = 1; i < events.size(); i++) {
            int time_i = events[i][1] - events[i-1][1];
            if(time_i > max_time) {
                max_time = time_i;
                idx = events[i][0];
            }
            if(time_i == max_time && events[i][0] < idx) {
                idx = events[i][0];
            }
            cout << events[i][0] << " " << max_time << " ";
        }

        return idx;
    }
};
