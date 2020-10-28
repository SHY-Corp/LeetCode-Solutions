class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        p=paths[0][1]
        current=''
        for i in range(len(paths)):
            for l in range(len(paths)):
                if i != l:
                    current =paths[l][0]
                    if p==current:
                        p=paths[l][1]
        return p   #Return the destination city, that is, the city without any path outgoing to another city.             
