class Solution(object):
    def equationsPossible(self, equations):
        """
        :type equations: List[str]
        :rtype: bool
        """
        dsu = DSU()
        for eq in equations:
            if eq[1] == '=':
                dsu.u(ord(eq[0]) - ord('a'), ord(eq[3]) - ord('a'))
        for eq in equations:
            if eq[1] == '!':
                if dsu.f(ord(eq[0]) - ord('a')) == dsu.f(ord(eq[3]) - ord('a')):
                    return False
        return True
                
class DSU(object):
    def __init__(self):
        self.m = range(26)
    
    def f(self, x):
        if self.m[x] != x:
            self.m[x] = self.f(self.m[x])
        return self.m[x]
    
    def u(self, x, y):
        px = self.f(x)
        py = self.f(y)
        self.m[px] = py
