class Solution {
    public int twoCitySchedCost(int[][] costs) {
        int n = costs.length / 2;
        int[] diff = new int[costs.length];
        int sum = 0;
        for (int i = 0; i < costs.length; ++i) {
            sum += costs[i][0];
            diff[i] = costs[i][1] - costs[i][0];
        }
        Arrays.sort(diff);
        for (int i = 0; i < n; ++i) {
            sum += diff[i];
        }
        return sum;
    }
}
