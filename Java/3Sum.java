// From LeetCode
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int maxVal = Integer.MIN_VALUE;
        int minVal = Integer.MAX_VALUE;
        int negNums = 0;
        int posNums = 0;
        List<List<Integer>> result = new LinkedList<>();
        int zeroNums = 0;

        // For all passed numbers in the nums[] array, find the min value, 
        // max value, number of zeroes, number of positives, and number of 
        // negatives.
        for (int num : nums) {
            if (num < minVal)  minVal = num;
            if (num > maxVal)  maxVal = num;
            if (num == 0)  
                zeroNums++;
            else if (num > 0)
                posNums++;
            else
                negNums++;
        }
        
        // If there are at least three zeroes in the passed numbers, then 
        // add the 3sum combination: 0+0+0
        if (zeroNums >= 3)  result.add(Arrays.asList(0, 0, 0));

        // If max < 0 or min > 0 then there cannot be any other valid 3sums. 
        // Must have both positive and negative values so some values can 
        // add to get zero.
        if (minVal >= 0 || maxVal <= 0)  return result;
        
        int[] negNumMap = new int[negNums];     // Array of all possible negative 3sum values.
        int[] posNumMap = new int[posNums];     // Array of all possible positive 3sum values.
        int posStart = 0;
        
        // If max or min values are too far from zero to use to make a 3sum, 
        // then adjust max and/or min closer to zero.  This could eliminate 
        // some of the outlying numbers that cannot be used to make a 3sum.
        // Those outlying numbers will be removed later when copying numbers 
        // to the arrays of positives and negatives.
        if (maxVal + 2 * minVal > 0)  maxVal = -2 * minVal;
        if (minVal + 2 * maxVal < 0)  minVal = -2 * maxVal;
        
        // Scan through all of the numbers to build arrays of negative 
        // numbers, positive numbers, and and array of counts of all 
        // the numbers.
        byte[] numMap = new byte[maxVal - minVal + 1]; // Contains a count for each possible number
                                                    // between the min and max values.  To see if 
                                                    // a number n exists in the passed array, just 
                                                    // check if numMap[n-minVal] is non-zero.  The  
                                                    // value in numMap[n-minVal] is the number of 
                                                    // occurrences of n in the original array.
        negNums = 0;
        posNums = 0;
        for (int num : nums) {                      // Loop through all numbers in passed array.
            if (num >= minVal && num <= maxVal) {   // Skip numbers that cannot possibly make a 3sum because 
                                                    // they are too large (too positive) or too small
                                                    // (too negative).
                if (numMap[num - minVal]++ != 0) {  // Count an occurrence if this number.  If already 
                    numMap[num - minVal] = 2;       // seen this number, then set the count to 2, because 
                                                    // anything greater than 2 isn't any different than a 
                                                    // count of 2, and this lets the counts fit into a byte.
                                                    // Because this number already seen, skip adding this 
                                                    // number to the positive or negative maps, thereby NOT 
                                                    // allowing duplicate numbers in the positive or 
                                                    // negative maps.
                } else {                            // Else we haven't seen this number yet, so unless zero,  
                                                    // add the number to the positive or negative map.
                    if (num > 0) {
                        posNumMap[posNums++] = num; // Add unique positive numbers to positive map.
                    } else if (num < 0) {
                        negNumMap[negNums++] = num; // Add unique negative numbers to negative map.
                    }
                }
            }
        }

        // Sort the arrays of positive and negative numbers.  If arrays 
        // are large, then .parallelSort() could be faster than .sort()
        Arrays.parallelSort(posNumMap, 0, posNums);
        Arrays.parallelSort(negNumMap, 0, negNums);
        
        // Loop through the negative numbers from highest negative number 
        // (closest to zero) to lowest (farthest from zero; most negative).  
        // By getting the negative numbers in this order (increasingly 
        // negative), the 3sum will need to include a positive number with 
        // the positive numbers being increasingly positive.
        for (int i = negNums - 1; i >= 0; i--) {
            int nv = negNumMap[i];                  // Get next neg number to try as first num of a 3sum.
            int minpv = (-nv) / 2;                  // Minimum positive value needed for the 3sum.  The 
                                                    // second 3sum value will be selected from the positive 
                                                    // numbers from half of the absolute value of the 
                                                    // negative number (first 3sum number), to a higher 
                                                    // positive number that would make the calculated third 
                                                    // 3sum number more negative than the first 3sum number.  
                                                    // This reduces the range of positive numbers to be tried 
                                                    // as the second 3sum number.
            
            while (posStart < posNums && posNumMap[posStart] < minpv)  posStart++;
                                                    // Skip over any positive values that are below the 
                                                    // minimum positive value needed for the 3sum (minpv). 
                                                    // Since the negitive value nv will be increasingly 
                                                    // negative, the minimum positive value will be 
                                                    // increasingly positive, so start skipping positive 
                                                    // values that are below the minimum, starting at the 
                                                    // index (posStart) of the previous negative value 
                                                    // rather than scanning through all positive numbers 
                                                    // again.
                
            for (int j = posStart; j < posNums; j++) {  // Scan through possible pos values for this 3sum.
                int pv = posNumMap[j];              // Next possible highest positive value for this 3sum.
                                                    // This could be the second value of the 3sum.
                int ln = 0 - nv - pv;               // Calculate the required third possible value for 
                                                    // this possible 3sum.
                
                if (ln >= nv && ln <= pv) {         // If the calculated third 3sum value is not between 
                                                    // the first and second 3sum values, then ignore this 
                                                    // 3sum combination.  This will eliminate duplicate 3sum 
                                                    // combinations, by having the first 3sum value being 
                                                    // the most negative number of the 3sum, and the second 
                                                    // 3sum value being the most positive number of the 3sum.
                    if (numMap[ln - minVal] == 0) { // If the calculated third value for the 3sum does not 
                        continue;                   // exist in the passed array, this skip invalid 3sum.
                    } else if (ln == pv || ln == nv) {  // If the calculated third 3sum value is the same as 
                                                    // first or second 3sum value, then this is only allowed 
                                                    // if the calculated number occurs more than once in the 
                                                    // original passed array.
                        if (numMap[ln - minVal] > 1)  // If occurrence count of third number is more than once.
                            result.add(Arrays.asList(nv, pv, ln));  // Valid 3sum with two numbers being the same.
                    } else {
                        result.add(Arrays.asList(nv, pv, ln));  // Valid 3sum with all numbers being different.
                    }
                } else if (ln < nv) {               // If third possible 3sum value is below negative first 
                    break;                          // possible value for this 3sum, then we don't need to 
                                                    // test any higher positive values, because they would 
                                                    // only make the third value even more negative.  We don't 
                                                    // want the third value to be more negative than the first 
                                                    // 3sum value because this combination of 3sum numbers could 
                                                    // be tested later as i gets closer to zero, and skipping 
                                                    // this more negative third 3sum value now, will prevent 
                                                    // duplicate 3sum combinations.
                }
            }
        }
        
        return result;
    }
}