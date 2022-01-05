class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        max_prod = 1
        min_prod = 1
        ret_max_prod = float('-inf')
        
        for n in nums:
            # print(max_prod,min_prod)
            # print(n,n*max_prod,n*min_prod)
            # print('---')
            temp1 = max(n, n*max_prod, n*min_prod)
            temp2 = min(n, n*max_prod, n*min_prod)
            
            min_prod = temp2
            max_prod = temp1
            
            ret_max_prod = max(ret_max_prod,max_prod)
            # print(max_prod,min_prod)
            
            
        
        return ret_max_prod
