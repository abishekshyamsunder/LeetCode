class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int siz = nums.size()-1;
        int rot_index = -1;
        int i = -1;
        // first find the pivot in log(n)
        while(start < end)
        {
            i = (start + end)/2;
            // cout<<"i:"<<i<<" s:"<<start<<" e:"<<end<<endl;
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
        {
            start = 0;
            end = nums.size()-1;
            
            while(start <= end)
            {
                i = (start + end)/2;
                if(nums[i] < target)
                {
                    start = i + 1;
                }
                else if(nums[i] > target)
                {
                    end = i - 1;
                }
                else if(nums[i]==target)
                    return i;
            }
        }    
        else
        {
            if(target <= nums[siz])
            {
                start = rot_index + 1;
                end = nums.size()-1;
            }
                
            else
            {
                end = rot_index;
                start = 0;
            }
            
            while(start <= end)
            {
                i = (start + end)/2;
                cout<<"i:"<<i<<" s:"<<start<<" e:"<<end<<endl;
                if(nums[i] < target)
                {
                    start = i + 1;
                }
                else if(nums[i] > target)
                {
                    end = i - 1;
                }
                else if(nums[i]==target)
                    return i;
            }
            
                
        }
        
        
        return -1;
    }
};
