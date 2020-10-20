/**
* Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
*/

class Solution {
    public List<List<Integer>> generate(int numRows) {
        
        List<List<Integer>> triangle = new ArrayList<>();
        if (numRows == 0) {
            return triangle;
        }
        
        initializePascalTriangle(triangle);
        
        
        for (int i = 1; i < numRows; i++) {
            List<Integer> line = new ArrayList<>();
            line.add(1);
            
            for(int j = 1; j < i; j++) {
                int element = triangle.get(i-1).get(j) +
                              triangle.get(i-1).get(j-1);
                line.add(element);
            }
            
            line.add(1);
            triangle.add(line);
        }
        
        return triangle;
    }
    
    private void initializePascalTriangle(List<List<Integer>> triangle) {
        triangle.add(new ArrayList<>());
        triangle.get(0).add(1);
    }
}