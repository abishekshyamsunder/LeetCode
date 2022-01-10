def cS(candidates, target):
    ret_list = []
    flag = False
    for i in candidates:
        if i == target:
            ret_list.append([i])
            flag = True
        else:
            if i < target:
                poss = cS(candidates, target-i)
                if poss != []:
                    for item in poss:
                        ret_list.append([i] + item)
                        flag = True

    if flag == False:
        return []
    else:
        return ret_list
    
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        x = cS(candidates, target)
        print(x)
        ret_list2 = []
        for item in x:
            item.sort()
            if(item not in ret_list2):
                ret_list2.append(item)
        return ret_list2
        
        
