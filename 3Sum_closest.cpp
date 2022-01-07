class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = 99999;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            int l = i+1;
            int r = nums.size()-1;
            while(l<r)
            {
                
                if(abs(target - closest) > abs(target - (nums[i] + nums[l] + nums[r])))
                    closest = (nums[i] + nums[l] + nums[r]);
                if(nums[i] + nums[l] + nums[r] > target)
                    r--;
                else if(nums[i] + nums[l] + nums[r] < target)
                    l++;
                else
                    break;
            }
        }
        return closest;
    }
};
