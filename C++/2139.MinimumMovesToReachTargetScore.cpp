class Solution {
public:
    int minMoves(int target, int maxDoubles) {

        //x is the integer =1 from which we will start the game
        int x = 1;
        int moves = 0;

        //reducing the value of target to reach x, so we need to ensure that target>x and we don't run out
        //on maxDoubles
        while(target > x && maxDoubles!=0)
        {
            //decrement by 1 if the target is odd, to make it even
            if(target%2==1)
                target--;

            //divide by 2 if the target is even, and decrement the maxDoubles
            else
            {
                target = target/2;
                maxDoubles--;
            }
          //incrementing the move variable as one of the above operations took place
          moves++;
        }

        //target-x is the remaining number of subtractions(-1) which we will add to the moves
        moves = moves + (target - x); //or target - 1
        return moves;
    }
};
