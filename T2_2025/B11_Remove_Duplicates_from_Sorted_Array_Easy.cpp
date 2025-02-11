class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int n = nums.size();
        // int cnt = 0;
        // for(int i = 1; i < n; i++) {
        //     if(nums[i-cnt] == 101) break;
        //     if(nums[i-cnt] == nums[i-1-cnt]) {
        //         cout << i-1-cnt << " ";
        //         nums.erase(nums.begin() + i-1-cnt);
        //         cnt++;
        //         nums.push_back(101);
        //     }
        // }
        // return n - cnt;

        // C2:
        int n = nums.size();
        set<int> s;
        for(int i = 0; i < n ; i++) {
            s.insert(nums[i]);
        }
        nums.erase(nums.begin(), nums.end());
        for(int x: s) nums.push_back(x);
        for(int i = s.size() + 1; i <= n; i++) {
            nums.push_back(101);
        }
        return s.size();
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for(int j=1;j<n;j++){
            if(nums[j]!= nums[i]){
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;
    }
};
