class Solution {
public:
    int climbStairs(int n) {
        vector<int> arr;
        arr.push_back(0);
        arr.push_back(1);
        arr.push_back(2);
        int temp;
        for(int i=3;i<=n;i++)
        {
            temp = arr[i-2] + arr[i-1];
            // cout<<temp<<endl;
            arr.push_back(temp);
        }
        return arr[n];
    }
};
