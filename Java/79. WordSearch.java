package practice;

import java.util.HashSet;
import java.util.Set;

/**
 * Given a 2D board and a word, find if the word exists in the grid. The word can be constructed from
 * letters of sequentially adjacent cells, where "adjacent" cells are horizontally or vertically
 * neighboring. The same letter may not be used more than once.
 *
 * Examples are available on leetcode.
 *
 * This would be solved by a recursive algorithm. Keeping track of the used indices and the already formed
 * word at each point. Check code for more details
 */

class Solution {

    private static char[][] board;
    private static char[] wordArray;

    public boolean exist(char[][] board, String word) {
        WordSearch.board = board;
        wordArray = word.toCharArray();
        return findMatch();
    }

    public boolean findMatch() {
        boolean result = false;
        for (int i = 0; i < board.length; i++) {
            for (int j  = 0; j < board[i].length; j++) {
                if (board[i][j] == wordArray[0]) {
                    Set<String> usedPairs = new HashSet<>(wordArray.length);
                    usedPairs.add(getKey(i, j));
                    result = result || traverse(i, j, 1, usedPairs);
                }
            }
        }
        return result;
    }

    public boolean traverse(int i, int j, int currentIndex, Set<String> usedPairs) {
        //Do we have the word?
        if (currentIndex >= wordArray.length) return true;

        //Can we move up?
        if (i > 0 && board[i-1][j] == wordArray[currentIndex]) {
            if (usedPairs.add(getKey(i-1, j))) {
                if (traverse(i-1, j, currentIndex+1, usedPairs)) return true;
                usedPairs.remove(getKey(i-1, j));
            }
        }

        //Can we move down?
        if (i < board.length-1 && board[i+1][j] == wordArray[currentIndex]) {
            if (usedPairs.add(getKey(i+1, j))) {
                if (traverse(i+1, j, currentIndex+1, usedPairs)) return true;
                usedPairs.remove(getKey(i+1, j));
            }
        }

        //Can we move right?
        if (j < board[i].length-1 && board[i][j+1] == wordArray[currentIndex]) {
            if (usedPairs.add(getKey(i, j+1))) {
                if (traverse(i, j+1, currentIndex+1, usedPairs)) return true;
                usedPairs.remove(getKey(i, j+1));
            }
        }

        //Can we move left?
        if (j > 0 && board[i][j-1] == wordArray[currentIndex]) {
            if (usedPairs.add(getKey(i, j-1))) {
                if (traverse(i, j-1, currentIndex+1, usedPairs)) return true;
                usedPairs.remove(getKey(i, j-1));
            }
        }

        return false;
    }

    private String getKey(int i, int j) {
        return i + "-" + j;
    }

}
