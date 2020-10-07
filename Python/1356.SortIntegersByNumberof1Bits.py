#Problem Statement
# Given an integer array arr. You have to sort the integers in the array in ascending order by the number of 1's in their binary representation
# and in case of two or more integers have the same number of 1's you have to sort them in ascending order.
# Return the sorted array.
#Input : List of numbers separated by a space (eg. 1 2 3 4)
#Output: Sorted list on basis of 1 bits (eg. 1 2 4 3)
arr = list(map(int,input().split()))
res = {}                            #dictionary that stores the number as key and number of 1 bits as value
for i in arr:
    res[i]=bin(i).count("1")        #bin function converts the integer to binary form as a string
res_new = sorted(res.items(), key=lambda res: res[1])       #sort the items according to the value(no. of 1 bits)
for i in res_new:
    print(i[0], end= " ")           #print according to keys(the given integers)
print()