class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        int siz = nums.size()-1;
        int rot_index = -1;
        int i = -1;
        // first find the pivot in log(n)
        while(start < end)
        {
            i = (start + end)/2;
            if(nums[i] > nums[end] && nums[i] > nums[i+1])
            {
                rot_index = i;
                break;
            }
            else if(nums[i] > nums[end] &&  nums[i] <= nums[i+1])
            {
                start = i + 1;
            }
            else if(nums[i] < nums[end])
            {
                end = i;
            }
        }
        cout<<rot_index;
        if(rot_index == -1)
            return nums[0];
        else
            return nums[rot_index+1];
        
    }
};
