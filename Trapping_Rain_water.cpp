class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left_max(height.size(),INT_MIN);
        vector<int> right_max(height.size(),INT_MIN);
        
        left_max[0] = height[0];
        for(int i=1;i<height.size();i++)
            left_max[i] = max(height[i],left_max[i-1]);
        
        right_max[height.size()-1] = height[height.size()-1];
        for(int i = height.size()-2;i>=0;i--)
            right_max[i] = max(height[i],right_max[i+1]);
        
        int ans = 0;
        for(int i=0;i<height.size();i++)
            ans = ans + min(left_max[i],right_max[i]) - height[i];
        return ans;
    }
};
