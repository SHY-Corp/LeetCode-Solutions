import java.util.*;
class HelloWorld {
  // Function to check if a given row is valid. It will return:
  // -1 if the row contains an invalid value
  // 0 if thr row contains repeated values
  // 1 is the row is valid.
  public static int valid_row(int row, int [][] grid){
    int temp[] = grid[row];
    Set<Integer>set = new HashSet<Integer>(); 
    for (int value : temp) {
      // Checking for values outside 0 and 9; 
      // 0 is considered valid because it 
      // denotes an empty cell.
      // Removing zeros and the checking for values and
      // outside 1 and 9 is another way of doing 
      // the same thing.
      if (value < 0 || value > 9){
        System.out.println( "Invalid value" );
        return -1;
      }
      //Checking for repeated values.
      else if (value != 0){
        if (set.add(value) == false) {
        return 0;
        }
      }
    }
    return 1;
  }
  // Function to check if a given column is valid. It will return:
  // -1 if the column contains an invalid value
  // 0 if the column contains repeated values
  // 1 is the column is valid.
  public static int valid_col(int col, int [][] grid){
  Set<Integer>set = new HashSet<Integer>(); 
  for (int i =0 ; i< 9; i++) {
    // Checking for values outside 0 and 9; 
    // 0 is considered valid because it 
    // denotes an empty cell.
    // Removing zeros and the checking for values and
    // outside 1 and 9 is another way of doing 
    // the same thing.
    if (grid[i][col] < 0 || grid[i][col] > 9){
      System.out.println( "Invalid value" );
      return -1;
    }
    // Checking for repeated values.
    else if (grid[i][col] != 0){
      if (set.add(grid[i][col]) == false) {
      return 0;
      }
    }
  }
  return 1;
  }
// Function to check if all the subsquares are valid. It will return:
// -1 if a subsquare contains an invalid value
// 0 if a subsquare contains repeated values
// 1 if the subsquares are valid.
  public static int valid_subsquares(int [][] grid){
  for (int row = 0 ; row < 9; row = row + 3) {
    for (int col = 0; col < 9; col = col + 3) {
      Set<Integer>set = new HashSet<Integer>(); 
      for(int r = row; r < row+3; r++) {
        for(int c= col; c < col+3; c++){
        // Checking for values outside 0 and 9; 
        // 0 is considered valid because it 
        // denotes an empty cell.
        // Removing zeros and the checking for values and
        // outside 1 and 9 is another way of doing 
        // the same thing.
          if (grid[r][c] < 0 || grid[r][c] > 9){
            System.out.println( "Invalid value" );
            return -1;
            }
            // Checking for repeated values.
          else if (grid[r][c] != 0){
            if (set.add(grid[r][c]) == false) {
            return 0;
            }
          }
        }
      }
    }   
  }
  return 1;
  }
  //Function to check if the board invalid.
  public static void valid_board(int [][] grid){
  // Checking the rows and columns.
  for (int i =0 ; i< 9; i++) {
    int res1 = valid_row(i, grid);
    int res2 = valid_col(i, grid);
    // if a row or column is invalid, then the board is invalid.
    if (res1 < 1 || res2 < 1) {
        System.out.println( "The board is invalid." );
        return;
    }
  }
  int res3 = valid_subsquares(grid);
  // if any one the subsquares is invalid, then the board is invalid.
  if (res3 < 1) {
    System.out.println( "The board is invalid." );
  }
  else {
    System.out.println( "The board is valid." );
  }
  }
  // Function to print the board.
  public static void print_board(int [][] grid){
  for (int[] row : grid) {
    System.out.print("[");
    for (int y : row) {
      System.out.print(y + ", ");
    }
  System.out.println("]");
  }
  }
  public static void main( String args[] ) {
    // A valid board.
    int [] [] board = {
    {1, 4, 7, 0, 0, 0, 0, 0, 3},
    {2, 5, 0, 0, 0, 1, 0, 0, 0},
    {3, 0, 9, 0, 0, 0, 0, 0, 0},
    {0, 8, 0, 0, 2, 0, 0, 0, 4},
    {0, 0, 0, 4, 1, 0, 0, 2, 0},
    {9, 0, 0, 0, 0, 0, 6, 0, 0},
    {0, 0, 3, 0, 0, 0, 0, 0, 9},
    {4, 0, 0, 0, 0, 2, 0, 0, 0},
    {0, 0, 1, 0, 0, 8, 0, 0, 7},
    };
    print_board(board);
    valid_board(board);
    // An invalid board. The first row contains
    // repeated values.   
    int [] [] board2 = {
    {1, 4, 4, 0, 0, 0, 0, 0, 3},
    {2, 5, 0, 0, 0, 1, 0, 0, 0},
    {3, 0, 9, 0, 0, 0, 0, 0, 0},
    {0, 8, 0, 0, 2, 0, 0, 0, 4},
    {0, 0, 0, 4, 1, 0, 0, 2, 0},
    {9, 0, 0, 0, 0, 0, 6, 0, 0},
    {0, 0, 3, 0, 0, 0, 0, 0, 9},
    {4, 0, 0, 0, 0, 2, 0, 0, 0},
    {0, 0, 1, 0, 0, 8, 0, 0, 7},
    };
    print_board(board2);
    valid_board(board2);      
  }
}