from itertools import permutations
import copy
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        ret_list = []
        def build_perm(cur,counter):
            if(list(counter.keys()) == []):
                ret_list.append(cur)

            for i in counter.keys():
                temp_cur = cur + [i]
                temp_counter = copy.deepcopy(counter)
                temp_counter[i] = temp_counter[i] - 1
                if(temp_counter[i] == 0):
                    del temp_counter[i]

                build_perm(temp_cur, temp_counter)
    
    
        counter = {}
        for i in nums:
            if i in counter.keys():
                counter[i] = counter[i] + 1
            else:
                counter[i] = 1
        
        build_perm([], counter)
        print(ret_list)
        
        
        
        perm = permutations(nums)
        return list(set(perm))
