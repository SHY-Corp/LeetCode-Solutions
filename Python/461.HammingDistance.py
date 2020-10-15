#The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
#we will store the representation in bits of the 2 integers in lists and we'll be comparing element by element
class Solution(object):
    def hammingDistance(self, x, y):
        a=list(bin(x)[2:])    #bin() transforms an integer into its representation in bits
        b=list(bin(y)[2:])     # bin(5) = 0b101    , we'll copy everything starting from third position till the end. that's our number
        
        # now these next if statements are used to make the lists of equal size because 12 is 1100 and 5 is 101 the number of bits is not equal

        if len(a) > len(b):
            b=['0']*(len(a)-len(b))+b                 
        elif len(a) < len(b) :
            a= ['0']*(len(b)-len(a))+a

        #continuing from here is easy, we'll just compare element by element and store the number of different bits in d variable

        d=0
        for i in range(len(a)):
            if a[i] != b[i]:
                d+=1

        return d
