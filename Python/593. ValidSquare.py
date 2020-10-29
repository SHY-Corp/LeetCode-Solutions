class Solution(object):
    def validSquare(self,p1,p2,p3,p4):
        def GetDist(p1, p2):
            return (p1[0]-p2[0])**2 + (p1[1]-p2[1])**2
        lists = [p1,p2,p3,p4]
        lists.sort()
        return GetDist(lists[0],lists[3]) == GetDist(lists[1], lists[2]) and GetDist(lists[0],lists[1]) == GetDist(lists[0], lists[2]) and GetDist(lists[0], lists[3])
       
