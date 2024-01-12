class Solution: 
    def check_pow(self, n):
        while(n != 0):
            if(n == 1):
                return True
            n /= 2
        return False

# Solution s1
s1=Solution()
print(s1.check_pow(4))
# print(check_pow(