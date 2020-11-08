/**
 * A string S of lowercase English letters is given.
 * We want to partition this string into as many parts as possible so that each letter appears in at most one part, 
 * and return a list of integers representing the size of these parts.
 * <p>
 * Example:
 * <p>
 * Input: S = "ababcbacadefegdehijhklij"
 * Output: [9,7,8]
 * Explanation:
 * The partition is "ababcbaca", "defegde", "hijhklij".
 * This is a partition so that each letter appears in at most one part.
 * A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
 * <p>
 * Note:
 * 1. S will have length in range [1, 500].
 * 2. S will consist of lowercase English letters ('a' to 'z') only
 */
class Solution {
    public List<Integer> partitionLabels(String S) {
        int[] lastIndexes = new int[26];
        List<Integer> partitions = new ArrayList<>();
        
        int i = 0;
        for(char character:S.toCharArray()) {
            lastIndexes[S.charAt(i) - 'a'] = i;
            ++i;
        }
        
        int stringLength = S.length();
        int previousPartitionEnd = 0;
        int partitionEnd = 0;
        for(i = 0 ; i < stringLength ; ++i) {
            int currentPartitionEnd = lastIndexes[S.charAt(i) - 'a'];
            if(partitionEnd < currentPartitionEnd) {
                partitionEnd = currentPartitionEnd;
            }
            
            if(i == partitionEnd) {
                partitions.add(partitionEnd - previousPartitionEnd + 1);
                previousPartitionEnd = partitionEnd + 1;
                partitionEnd = 0;
            }
        }
        
        return partitions;
    }
}