class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ret_dict = {():1}
        nums.sort()
        ret_list = []
        for i in nums:
            temp_dict = {}
            for key in ret_dict.keys():
                x = key + (i,)
                temp_dict[x] = 1
            for key in temp_dict.keys():
                ret_dict[key] = 1
        for key in ret_dict.keys():
            print(list(key))
            ret_list.append(list(key))
        return ret_list
