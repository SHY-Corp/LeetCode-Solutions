/**
* Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
* 
* Example of the first 5 rows in a Pascal's triangle
*
*     1
*    1 1
*   1 2 1
*  1 3 3 1
* 1 4 6 4 1
* 
*/

class Solution {
    public List<List<Integer>> generate(int numRows) {
        
        List<List<Integer>> triangle = new ArrayList<>();
        if (numRows == 0) {
            // for the case when the numRows is zero, return an empty list
            return triangle;
        }
        
        initializePascalTriangle(triangle);
        
        // For every row
        for (int i = 1; i < numRows; i++) {
            List<Integer> line = new ArrayList<>();
            // every line starts with a 1
            line.add(1);
            
            // Fill the row
            for(int j = 1; j < i; j++) {
                int element = triangle.get(i-1).get(j) +
                              triangle.get(i-1).get(j-1);
                line.add(element);
            }
            
            // every line ends with a 1
            line.add(1);
            // add line to the triangle
            triangle.add(line);
        }
        
        // Return the filled triangle
        return triangle;
    }
    
    /**
    * Initialize the triangle object and add the first element
    */
    private void initializePascalTriangle(List<List<Integer>> triangle) {
        // Initialize a list of list
        triangle.add(new ArrayList<>());
        // Add the first element of the triangle
        triangle.get(0).add(1);
    }
}
