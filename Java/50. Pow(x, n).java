// Implement pow(x, n), which calculates x raised to the power n (i.e. xn)
class Solution {
	public double myPow(double x, int n) {
		long N = n;
		
		if(N < 0) {
			x = 1 / x;
			N = -N;
		}

		double answer = 1;
		double product = x;

		for(long i = N; i > 0; i /=2) {
			if( (i % 2 == 1) ){
				answer = answer * product;
			}
			product *= product;
		}

		return answer;
	}
}
