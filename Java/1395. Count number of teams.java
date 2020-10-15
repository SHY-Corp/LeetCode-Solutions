/**
 * The goal is to find the total number of valid teams. A team is valid if the player rating is in either direction ascending.
 */
class Solution {
    int totalInc = 0;
    int totalDec = 0;

    public void numTeamsInc(int[] rating, int idx, int count) {
        for (int i = idx + 1; i < rating.length; i++) {
            if (rating[idx] > rating[i]) {
                /**
                 * If we have already have two, we found a third one, which means we found a valid team and don't need to go further.
                 */
                if (count == 2) {
                    totalInc++;
                } else {
                    numTeamsInc(rating, i, count + 1);
                }
            }
        }
    }

    public void numTeamsDec(int[] rating, int idx, int count) {
        for (int i = idx + 1; i < rating.length; i++) {
            if (rating[idx] < rating[i]) {
                /**
                 * If we have already have two, we found a third one, which means we found a valid team and don't need to go further.
                 */
                if (count == 2) {
                    totalDec++;
                } else {
                    numTeamsDec(rating, i, count + 1);
                }
            }
        }
    }

    public int numTeams(int[] rating) {
        if (rating == null || rating.length == 0) return 0;

        for (int i = 0; i < rating.length - 1; i++) {
            numTeamsInc(rating, i, 1);
            numTeamsDec(rating, i, 1);
        }
        
        return totalInc + totalDec;
    }
}
