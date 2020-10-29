package DSA_450_PROBLEMS.Array;
//Input: nums = [1,1,1,2,2,3], k = 2

//Output: [1,2]

import java.util.*;

class Top_K_Frequent_Elements {
	public static void main(String[] args) {
		int arr[] = {1,1,1,2,2,3};
		int k = 2;
		
		System.out.println("Top k frequent elements are :");
		for( int i : topKFrequent( arr , k ) )
			System.out.print(i+" ");

	}

	public static int[] topKFrequent(int[] nums, int k) {

		int max = -1;
		Hashtable<Integer, Integer> ht = new Hashtable<Integer, Integer>();

		for (int i = 0; i < nums.length; i++) {
			if (ht.containsKey(nums[i]))
				ht.put(nums[i], ht.get(nums[i]) + 1);
			else
				ht.put(nums[i], 1);

			max = Math.max(max, ht.get(nums[i]));
		}
		ArrayList<ArrayList<Integer>> al = new ArrayList<ArrayList<Integer>>();
		for (int i = 0; i <= max; i++)
			al.add(new ArrayList<>());

		Set<Integer> keys = ht.keySet();

		for (int i : keys)
			al.get(ht.get(i)).add(i);

		int ans[] = new int[k];

		int index = 0;
		for (int i = al.size() - 1; i >= 0 && index <= k; i--) {
			for (int j = 0; j < al.get(i).size() && index < k; j++) {
				if (al.get(i).get(j) != null)
					ans[index++] = al.get(i).get(j);
			}
		}
		return ans;
	}
}
