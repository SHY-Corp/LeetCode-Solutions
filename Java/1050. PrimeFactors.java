/**
 *Implemented a basic program to calculate the prime factors of a given number (see prime factors kata).
 *The given number should be just an integer and the program would return a list of the prime factors of the given integer.
 */

import java.util.ArrayList;
import java.util.List;

class Solution {
    public static List<Integer> factorsOf(int n)
    {
        ArrayList<Integer> factors = new ArrayList<>();

        for (int divisor = 2; n > 1; divisor++)
            for (; n % divisor == 0; n /= divisor)
                factors.add(divisor);

        return factors;
    }
}
