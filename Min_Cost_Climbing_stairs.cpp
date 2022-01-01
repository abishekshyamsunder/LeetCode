class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> arr;
        arr.push_back(0);
        arr.push_back(0);
        cost.insert(cost.begin(), 0);
        int n = cost.size();
        int temp1, temp2;
        for(int i=2;i<=n;i++)
        {
            temp1 = arr[i-2] + cost[i-2];
            temp2 = arr[i-1] + cost[i-1];
            if(temp1<temp2)
                arr.push_back(temp1);
            else
                arr.push_back(temp2);
            // cout<<arr[i]<<endl;
        }
        return arr[n];
    }
};
