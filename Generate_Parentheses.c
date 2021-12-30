class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        brackets = [["()"]]
        for i in range(1,n):
            cur_set = set()
            for perm in brackets[i-1]:
                for j in range(len(perm)):
                    temp = perm[:j] + "()" + perm[j:]
                    cur_set.add(temp)
            brackets.append(list(cur_set))
        
        i = 0
        for item in brackets[n-1]:
            print(i,": ",item)
            i = i + 1
        return brackets[n-1]
