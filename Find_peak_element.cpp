class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 1;
        int end = nums.size();
        nums.push_back(INT_MIN);
        nums.insert(nums.begin(),INT_MIN);
        int i = -1;
        while(start <= end)
        {
            i = (start + end)/2;
            if(nums[i]>nums[i+1] && nums[i]>nums[i-1])
                return i-1;
            else if(nums[i] > nums[i+1])
            {
                end = i;
            }
            else
                start = i + 1;
        }
        cout<<i;
        return 0;
    }
};
