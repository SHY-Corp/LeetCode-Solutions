 for i in range(0,nums.length):
            for j in range(i+1,nums.length):
                nums[j]=target-nums[i]
                if (target==nums[j]):
                    ans=[i, j]
                    print(ans)    
