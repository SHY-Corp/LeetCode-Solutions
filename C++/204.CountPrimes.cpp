class Solution {
public:
    int countPrimes(int n) {
        //assuming all the numbers upto n as prime, therefore marking them as true
        vector<bool> prime(n+1, true);

        //we start counting prime nos. from 2, so marking 0 and 1 as false
        prime[0]=false;
        prime[1]=false;

        //mathematical rule about a no. n: it will always have 2 factors, one of which is <= sqrt(n) and
        //another one being >= sqrt(n)
        for(int i=2; i*i<=n; i++)
        {
            //iterating over the nos. between 2 and n, and marking them as false
            if(prime[i])
            {
                //incrementing j in steps of i, so that we can avoid checking already false-marked values
                for(int j=i*i; j<=n; j+=i)
                    prime[j] = false;
            }
        }

        //the count of remaining nos. that are marked as true gives us the final count
        int count = 0;
        for(int i=2; i<n; i++)
        {
            if(prime[i])
                count++;
        }
        return count;
    }
};

/*

- 0 is neither a prime, nor a composite no.
- for a no. to be prime, it should be divisible by exactly 2 numbers: 1 and the no. itself and the fact that
  1 can be divided by 1 and itself, it is not seen as a prime no.

TC: O(n*log(log(n))
    =>O(n*log(log(n)))TC for finding prime nos. + extra O(n) time for counting prime nos.~ O(n*log(log(n))
SC: O(n), extra n size boolean array
*/
