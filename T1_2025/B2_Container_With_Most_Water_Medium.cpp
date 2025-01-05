class Solution {
public:
    int maxArea(vector<int>& height) {
        int mArea = 0;
        int l = 0;
        int r = height.size() - 1;
        while(l <= r) {
            mArea = max(mArea, (r - l)*min(height[l], height[r]));
            if(height[l] > height[r]) r--;
            else l++;
        }

        return mArea;
    }
};
