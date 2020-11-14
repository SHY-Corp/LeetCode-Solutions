# 1414. Find the Minimum Number of Fibonacci Numbers Whose Sum Is K

# DESCRIPTION: This code will return min. num required so that their sum is equal to the give number k.

# ALGORITHM : This can be achieved by a GREEDY APPROACH. Firstly,we fill up an array('dp') with all the
# numbers which are less than the given number. NoW we iterate the dp from the dp from the back, and select
# the number at that index, check if it can be subtracted from 'k' , if yes, we subtract, else we move to
# previous index. We continue till 'k' is greater than 0.


def findMinFibonacciNumbers(k):
    # 50 is chosen as 50th fibonacci num is in billion and constrain is also
    # 1 billion

    dp = [1 for i in range(50)]

    # as dp[0] and dp[1] is 1.
    i = 2

    # filing the 'dp' array with fibonacci number
    while i < k:
        dp[i] = dp[i - 1] + dp[i - 2]

        # if the fibonacci number becomes greater than 'k', then it cannot form pair.
        if dp[i] > k:
            break
        i += 1

    # currently 'i' is pointing to the first number in fibonacci series which is greater than 'k'. So we
    # decrease 'i' by one.
    i = i - 1
    ans = 0
    while k > 0:
        temp = dp[i]
        i -= 1

        if temp <= k:
            k -= temp
            ans += 1
    return ans


# Example case:
k = 7
print(findMinFibonacciNumbers(k))

# This code is contributed by Kaushalendra Pandey.
