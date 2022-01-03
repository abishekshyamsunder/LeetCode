class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> output;
        int start = -1, end = -1;
        for(int i = 0, j = 0;i<firstList.size() && j<secondList.size(); i,j)
        {
            vector<int> temp;
            if(firstList[i][1] < secondList[j][0])
                i++;
            else if(firstList[i][0] > secondList[j][1])
                j++;
            else
            {
                start = max(firstList[i][0],secondList[j][0]);
                end = min(firstList[i][1],secondList[j][1]);
                temp.push_back(start);
                temp.push_back(end);
                output.push_back(temp);
                if(firstList[i][1] > secondList[j][1])
                    j++;
                else
                    i++;
            }
        }
        return output;
    }
};
