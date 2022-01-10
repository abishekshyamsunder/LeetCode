import copy
def cS(counter, target):
    ret_list = []
    flag = False
    for i in counter.keys():
        if i == target:
            ret_list.append([i])
            flag = True
        else:
            if i < target:
                temp_counter = copy.deepcopy(counter)
                temp_counter[i] = temp_counter[i] - 1
                if(temp_counter[i] == 0):
                    del temp_counter[i]
                poss = cS(temp_counter, target-i)
                if poss != []:
                    for item in poss:
                        ret_list.append([i] + item)
                        flag = True

    if flag == False:
        return []
    else:
        return ret_list
    
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        counter = {}
        for i in candidates:
            if i in counter.keys():
                counter[i] = counter[i] + 1
            else:
                counter[i] = 1
        x = cS(counter, target)
        print(x)
        ret_list2 = []
        for item in x:
            item.sort()
            if(item not in ret_list2):
                ret_list2.append(item)
        return ret_list2
        
        
