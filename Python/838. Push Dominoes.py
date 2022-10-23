'''
838. Push Dominoes
https://leetcode.com/problems/push-dominoes/

There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

You are given a string dominoes representing the initial state where:

    dominoes[i] = 'L', if the ith domino has been pushed to the left,
    dominoes[i] = 'R', if the ith domino has been pushed to the right, and
    dominoes[i] = '.', if the ith domino has not been pushed.

Return a string representing the final state.
'''
class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        # There are three possible cases
        # R.L => Permanently stays in this position
        # .L => Will become LL in the next second
        # R. => Will become RR in the next second
        # Each iteration represents one second later state of the dominoes
        temp = ""
        # Run the loop until there are no changes to the state
        while temp != dominoes:
            temp = dominoes
            # Replace all the R.L with xxx as placeholder as they will never change state
            dominoes = dominoes.replace("R.L", "xxx")
            # Replace all the .L with LL as the left domino falls
            dominoes = dominoes.replace(".L", "LL")
            # Replace all the R. with RR as the right domino falls
            dominoes = dominoes.replace("R.", "RR")
        return dominoes.replace("xxx", "R.L")