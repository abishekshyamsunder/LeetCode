class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int s = 0;
        int e = 1;
        int max_sum = (values[s] + values[e]) - (e - s);
        int max_val = max(values[0]-2,values[1]-1);
        for(int i=2;i<values.size();i++)
        {
            max_sum = max(max_sum,max_val + values[i]);
            max_val = max(max_val-1,values[i]-1);
        }
        return max_sum;
    }
};
