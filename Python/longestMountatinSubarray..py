# QUESTION : LONGEST MOUNTAIN SUBARRAY.
# DESCRIPTION: In this question we have to find the max length of subarray which is a mountain.

# Approach : The basic condition for a subarray to be a mountain is that there should be a peak (a largest element).
# We can find the peak , and then iterate to the left and to right till our condition is satisfied and then calculate
# the length.


def longest_mountain_subarray(a):
    max_len = 0
    for i in range(1, len(a) - 1):

        # Finding peak.
        if a[i] > a[i + 1] and a[i] > a[i - 1]:

            # pointer which will move to the left.
            l = i

            # pointer which will move to right.
            r = i

            while l > 0 and a[l] > a[l - 1]:
                l -= 1

            while r < len(a) - 1 and a[r] > a[r + 1]:
                r += 1

            # calculating max length.
            max_len = max(max_len, (r - l) + 1)

    return max_len


# Example test case.
a = [2, 1, 4, 7, 3, 2, 5]
print(longest_mountain_subarray(a))
