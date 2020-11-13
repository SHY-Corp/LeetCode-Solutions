// Problem: https://leetcode.com/problems/reverse-words-in-a-string/

//  Solution:

class Reverse_Words {
    public String reverseWords(String s) {
        // remove possible incorrect formatting for s
        String reversedWords = "";
        s.strip();
        String[] words = s.split("\\s+");
        // split strings at " "
        for (int i = words.length - 1; i >= 0; i--) {
            // reverse order of the words
            reversedWords += words[i] + " ";
        }
        // return the words
        return reversedWords.strip();

    }

    public static void main(String[] args) {

        Reverse_Words Examples = new Reverse_Words();

        // Example 1:
        // Input: s = "the sky is blue"
        // Output: "blue is sky the"

        String s1 = "the sky is blue";

        System.out.println(Examples.reverseWords(s1));

        // Example 2:
        // Input: s = " hello world "
        // Output: "world hello"

        String s2 = " hello world ";

        System.out.println(Examples.reverseWords(s2));

        // Example 3:
        // Input: s = "a good example"
        // Output: "example good a"

        String s3 = "a good   example";

        System.out.println(Examples.reverseWords(s3));

        // Example 4:
        // Input: s = " Bob Loves Alice "
        // Output: "Alice Loves Bob"

        String s4 = "  Bob    Loves  Alice   ";

        System.out.println(Examples.reverseWords(s4));

        // Example 5:
        // Input: s = "Alice does not even like bob"
        // Output: "bob like even not does Alice"

        String s5 = "Alice does not even like bob";

        System.out.println(Examples.reverseWords(s5));
    }
}
