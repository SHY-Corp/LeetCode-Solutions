#Variable n has the number of coins. Two variables row and count are created and assigned to value 0 and 1 respectively.
#Loop continues till the value of variable row is greater than or equal to count as completely filled number of rows is 
#required. First we increase the row to 1 as fisrt row should have 1 coin. Then n is decreased by count for calulating
#the remaining number of coins. Then count is incremented by 1 as the next row should have 2 coins. This is continued 
#till be find the number of rows completely filled and that value is returned.
class Solution(object):
    def arrangeCoins(self, n):
        row = 0
        count = 1
        while(n >= count):
            row += 1
            n -= count 
            count += 1
        return row
