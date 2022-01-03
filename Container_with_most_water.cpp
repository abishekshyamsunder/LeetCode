class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int area = min(height[l],height[r])*(r-l);
        int temp;
        while(l<r)
        {
            if(height[l]<height[r])
                l++;
            else
                r--;
            temp = min(height[l],height[r])*(r-l);
            area = max(temp,area);
        }
        return area;
    }
};
