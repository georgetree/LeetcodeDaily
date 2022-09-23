class Solution:
    def concatenatedBinary(self, n: int) -> int:
        temp = ""
        for i in range(1,n+1):
            temp = temp + bin(i)[2:]
        res = int(temp,2)
        return res % (10**9+7)