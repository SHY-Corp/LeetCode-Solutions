#simple program to check anagram strings

def check_anagram(data1,data2):
    str1_list = list(data1)
    str1_list.sort()
    str2_list = list(data2)
    str2_list.sort()

    if(str1_list == str2_list):
        return True
    else:
        return False
        
    #start writing your code here

print(check_anagram("eat","tae"))
