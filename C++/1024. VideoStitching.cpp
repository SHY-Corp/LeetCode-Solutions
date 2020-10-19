/*
Problem 1024 - Video Stitching

You are given a series of video clips from a sporting event that lasted T seconds.
These video clips can be overlapping with each other and have varied lengths.
Each video clip clips[i] is an interval: it starts at time clips[i][0] and ends at time clips[i][1].
We can cut these clips into segments freely: for example, a clip [0, 7] can be cut into segments [0, 1] + [1, 3] + [3, 7].
Return the minimum number of clips needed so that we can cut the clips into segments that cover the entire sporting event ([0, T]).
If the task is impossible, return -1.
*/

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int major = T, qtClips = 0; //major value of second we need to find in clips
        while(true){
            int clipSize = -1;
            int clipIndex = -1;
            for(int i=0; i<clips.size(); i++){
                if(major >= clips[i][0] && major <= clips[i][1]){   //if this clip has the major value we're looking for
                    if((major - clips[i][0]) > clipSize){   //if it this clip is longer than the last one found: update clipSize and save its index
                        clipIndex = i;
                        clipSize = major - clips[i][0];
                    }
                }
            }
            if(clipIndex == -1) return -1;  //if we couldn't find the major second value we were lookinfg for: return -1
            else{
                qtClips++;  //if we could find the major second value we were looking for: increment the amount of clips to be returned
                major = clips[clipIndex][0];
                if(major == 0){
                    return qtClips; //if we could find the major second value we were looking for and it is equals to 0: return the amount of clips
                }
                vector<vector<int>>::iterator it = clips.begin(); 
                advance(it, clipIndex);
                clips.erase(it);    // erase the already selected clips from the vector
            }
        }
    }
};