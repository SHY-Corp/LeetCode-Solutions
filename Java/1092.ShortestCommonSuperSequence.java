class Solution {
    public String shortestCommonSupersequence(String str1, String str2) {
        
        int m = str1.length(); 
		int n = str2.length(); 

		int dp[][] = new int[m + 1][n + 1]; 

		// Fill table in bottom up manner 
		for (int i = 0; i <= m; i++) 
		{ 
			for (int j = 0; j <= n; j++) 
			{ 
				
				// Below steps follow recurrence relation 
				if (i == 0) 
				{ 
					dp[i][j] = j; 
				} 
				else if (j == 0) 
				{ 
					dp[i][j] = i; 
				} 
				else if (str1.charAt(i - 1) == str2.charAt(j - 1)) 
				{ 
					dp[i][j] = 1 + dp[i - 1][j - 1]; 
				} 
				else
				{ 
					dp[i][j] = 1 + Math.min(dp[i - 1][j], dp[i][j - 1]); 
				} 
			} 
		} 

		int index = dp[m][n]; 

		int i = m, j = n; 
		while (i > 0 && j > 0) 
		
		{  
			if (str1.charAt(i - 1) == str2.charAt(j - 1)) 
			
			{ 
				// Put current character in result 
				str += (str1.charAt(i - 1)); 

				// reduce values of i, j and index 
				i--; 
				j--; 
				index--; 
			} 
			
			
			else if (dp[i - 1][j] > dp[i][j - 1]) 
			{ 
				
				// Put current character of Y in result 
				str += (str2.charAt(j - 1)); 

				// reduce values of j and index 
				j--; 
				index--; 
			} 
			else
			{ 
				
			
				str += (str1.charAt(i - 1)); 
				i--; 
				index--; 
			} 
		} 

		while (i > 0) 
		{ 
			str += (str1.charAt(i - 1)); 
			i--; 
			index--; 
		} 

		
		while (j > 0) 
		{ 
		str += (str2.charAt(j - 1)); 
			j--; 
			index--; 
		} 

		str = reverse(str); 
		return str; 
	} 

	static String reverse(String input) 
	{ 
		char[] temparray = input.toCharArray(); 
		int left, right = 0; 
		right = temparray.length - 1; 

		for (left = 0; left < right; left++, right--) 
		{ 
			// Swap values of left and right 
			char temp = temparray[left]; 
			temparray[left] = temparray[right]; 
			temparray[right] = temp; 
		} 
		return String.valueOf(temparray); 
    }
}
