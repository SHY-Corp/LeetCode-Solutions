# Given list of (x, y) coordinates checkStraightLine checks if it forms straight line
# 
class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        if len(coordinates) <= 2:
            # it is always possible to create line through 2 points (and also 1 and 0)
            return True

        x0, y0 = coordinates[0]
        x1, y1 = coordinates[1]

        if x0 == x1:
            # check if this is vertical line (all x are the same)
            return all([x == x0 for x, _ in coordinates])

        # 2 points define line, so find it's equation y = a*x + b
        a = (y0 - y1) / (x0 - x1)
        b = y0 - a * x0

        line = lambda x: a*x + b

        #check if all points lies on the line defined by (x0, y0) and (x1, y1)
        return all([y == line(x) for x, y in coordinates])
