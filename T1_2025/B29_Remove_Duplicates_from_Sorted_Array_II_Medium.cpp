// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int n = nums.size();
//         map<int, int> m;
//         int MAX_INT = 1E5;
//         int k = 0;
//         for(int i = 0; i < n; i++) {
//             m[nums[i-k]]++;
//             // cout << "i: " << i << "; m[" << nums[i] << "]: " << m[nums[i]] << "\n";
//             if(m[nums[i-k]] > 2) {
//                 m[nums[i-k]]--;
//                 nums.erase(nums.begin() + i - k);
//                 k++;
//                 nums.push_back(MAX_INT);
//             }
//         }
//         return n - k;
//     }
// };

// C2:
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1; 
        int cur = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i-1]) {
                cnt++;
                if(cnt <= 2) nums[cur++] = nums[i];
            } else {
                cnt = 1;
                nums[cur++] = nums[i];
            }
        }
        return cur;
    }
};

