import numpy as np
class Solution:
    def numDecodings(self, s: str) -> int:
        alpha = []
        for i in range(1,27):
            alpha.append(str(i))
        
        # print(alpha)
        dp = np.zeros((len(s)),dtype=np.int32)
        # print(dp)
        for i in range(len(s)):
            sum_i = 0
            for j in reversed(range(i+1)):
                if(s[j:i+1] in alpha):
                    if(j!=0):
                        sum_i = sum_i + dp[j-1]
                    else:
                        sum_i = sum_i + 1
            dp[i] = sum_i
        
        print(dp)
        return dp[-1]
