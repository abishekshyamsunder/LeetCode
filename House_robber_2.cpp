class Solution {
public:
    int rob(vector<int>& nums) {
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        if(nums.size()==1)
            return nums[0];
        vector<int> stolen1;
        vector<int> stolen2;
        nums.insert(nums.begin(),0);
        stolen1.push_back(0);
        stolen1.push_back(nums[1]);
        
        stolen2.push_back(0);
        stolen2.push_back(0);
        
        int size = nums.size();
        int temp=-1;
        for(int i=2;i<size-1;i++)
        {
            temp = max(stolen1[i-2]+nums[i],stolen1[i-1]);
            // cout<<temp<<endl;
            stolen1.push_back(temp);
        }
        max1 = stolen1[size-2];
        
        for(int i=2;i<size;i++)
        {
            temp = max(stolen2[i-2]+nums[i],stolen2[i-1]);
            // cout<<temp<<":"<<endl;
            stolen2.push_back(temp);
        }
        max2 = stolen2[size-1];
        return max(max1,max2);
            
        
    }
};
