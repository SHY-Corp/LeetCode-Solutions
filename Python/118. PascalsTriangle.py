# a function that receives a number a will create
# a pascal triangle of that height


class Solution(object):

    def generate(self, num):
        """
        creates a two dimensional array holding a pascal triangle of
        the desired height
        :param num: int the height of the triangle
        :return: List[List[int]] a matrix of the pascal triangle
        """
        
        # when the num is zero, return an empty list
        if num == 0:
            return []

        # the base of the triangle
        return_triangle = [[1]]

        # keeps adding a layer
        for i in range(1, num):

            # creates a new line
            new_line = []

            # beginning of line is always 1
            new_line.append(1)

            # middle of line gets filled by upper level
            for j in range(1, i):
                new_line.append(return_triangle[i - 1][j] +
                                return_triangle[i - 1][j - 1])

            # end of line
            new_line.append(1)

            # adds the line
            return_triangle.append(new_line)

        # returns the triangle
        return return_triangle
