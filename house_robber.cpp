class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        nums.insert(nums.begin(),0);
        vector<int> stolen;
        stolen.push_back(0);
        stolen.push_back(nums[1]);
        int siz = nums.size();
        int temp = -1;
        for(int i=2;i<siz;i++)
        {
            temp = max(stolen[i-2]+nums[i], stolen[i-1]);
            // cout<<temp<<endl;
            stolen.push_back(temp);
        }
        return stolen[siz-1];
        
    }
};
