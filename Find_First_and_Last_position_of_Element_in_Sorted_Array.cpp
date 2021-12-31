class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int left = -1;
        int right = -1;
        int start = 0;
        int end = nums.size();
        
        int i = -1;
        // find first occourance
        while(start < end)
        {
            i = (start + end)/2;
            if(nums[i] < target)
            {
                start = i + 1;
            }
            else if(nums[i] > target)
            {
                end = i;
            }
            else if(nums[i]==target && i==0)
            {
                left = i;
                break;
            }
            else if(nums[i]==target && nums[i-1] != target)
            {
                left = i;
                break;
            }
            else
            {
                end = i;
            }
        }
        
        start = 0;
        end = nums.size();
        
        while(start < end)
        {
            i = (start + end)/2;
            if(nums[i] < target)
            {
                start = i + 1;
            }
            else if(nums[i] > target)
            {
                end = i;
            }
            else if(nums[i]==target && i== end-1)
            {
                right = i;
                break;
            }
            else if(nums[i]==target && nums[i+1] != target)
            {
                right = i;
                break;
            }
            else
            {
                start = i+1;
            }
        }
        // cout<<left<<" "<<right<<endl;
        vector<int> retval;
        retval.push_back(left);
        retval.push_back(right);
        return retval;
    }
};
