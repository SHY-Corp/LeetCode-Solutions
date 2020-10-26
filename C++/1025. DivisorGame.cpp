/*
Problem 1025 - Divisor Game

Alice and Bob take turns playing a game, with Alice starting first.
Initially, there is a number N on the chalkboard.  On each player's turn, that player makes a move consisting of:
    - Choosing any x with 0 < x < N and N % x == 0.
    - Replacing the number N on the chalkboard with N - x.
Also, if a player cannot make a move, they lose the game.
Return True if and only if Alice wins the game, assuming both players play optimally.
*/

class Solution {
public:
    
    bool divisorGame(int N) {
        if(N % 2 == 0) return true;
        //if Alice receives an even number: Bob will always receive an odd number and will lose the game
        else
            return false; 
        
        
        //if Alice receives an odd number: Bob will always receive an even number and will win the game
    }
};
