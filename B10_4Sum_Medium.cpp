// Solution 1:
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> res;
        vector<vector<int>> output;

        if(nums.size() < 4) return {};

        for(int i = 0; i < nums.size() - 3; i++) {
            for(int j = i + 1; j < nums.size() - 2; j++) {
                int left = j + 1; 
                int right = nums.size() - 1;
                while(left < right) {
                    long long new_target =  (long long)target - (long long)nums[i] - (long long)nums[j];
                    long long current_sum = (long long)nums[left] + (long long)nums[right];
                    if(current_sum < new_target) left++;
                    else if(current_sum > new_target) right--;
                    else {
                        res.insert({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                    }
                }
            }
        }

        for(auto it: res) {
            output.push_back(it);
        }

        return output;
    }
};


// Solution 2:
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i=0; i<n-3; i++) {
            for (int j=i+1; j<n-2; j++) {
                long targetRemaining = long(target) - nums[i] - nums[j];
                int l = j+1, r = n-1;

                while(l < r){
                    if (nums[l] + nums[r] == targetRemaining) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                        while(l < n && nums[l]==nums[l-1]) l++;
                        while(r > j && nums[r]==nums[r+1]) r--;
                    }
                    else if (nums[l] + nums[r] < targetRemaining) {
                        l++;
                    }
                    else {
                        r--;
                    }
                }

                while (j+1 < n-2 && nums[j]==nums[j+1]) j++;
            }
            while (i+1 < n-3 && nums[i]==nums[i+1]) i++;
        }

        return ans;
    }
};
