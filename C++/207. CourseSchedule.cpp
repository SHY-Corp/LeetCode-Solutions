/* There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses? */

class Solution {
public:
	//if course is done, similar to visited
    map<int, int> done;
	//if we are still visiting/studying a course and its subcourses/recursion stack
	map<int, int> pending;
	//our graph
    map<int, vector<int>> mp;
    
    bool iscyclicutil(int v){
		//if course is not visited yet
        if(!done[v])
        {
            done[v]=1;
            pending[v]=1;
            for(auto j : mp[v])
			{   //if a subcourse is not visited yet but the subcourse has a cycle then return true that 
			    //there is a cycle
                if(!done[j]&&iscyclicutil(j))
                    return true;
				//if the subcourse itself is in pending state that means a cycle exists
                else
                    if(pending[j])
                        return true;
            }
        }
		//if the course and all its courses couldnt return true for cycle it means we are done studying that course
		//remove it from pending list
        pending[v]=0;
        return false;
    }
    //function to check for cycles in the graph, if a cycle exists that means a superior course 
	//is dependent on junior course, where we should return false
    bool iscyclic(){
        for(auto i : mp)
            if(iscyclicutil(i.first))
                return true;
        
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //making adjacency list
        int nedges=prerequisites.size();
        for(int i=0;i<nedges;i++)
        {
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        //detecting a cycle, if exists, that means, iscyclic is true, return false
        return !iscyclic();
    }
};


