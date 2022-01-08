class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ret_list = [[]]
        for i in nums:
            temp_list = []
            for l in ret_list:
                x = l + [i]
                temp_list.append(x)
            ret_list = ret_list + temp_list
            # print(ret_list)
        
        return ret_list
                
        
