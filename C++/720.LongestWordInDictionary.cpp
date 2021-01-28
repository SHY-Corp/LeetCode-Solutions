//There are 2 classes in this solution: Trienode and Solution. I have solved this using trie data structure

class Trienode{

public: unordered_map<char, Trienode*> t;  //each node is storing a map to its child node
        bool end;                     // to check if node is s leaf node or not.

//Trienode constructor in which end is initially false indicating node is NOT a leaf node
       Trienode()
        {
          this-> end = false; 
        }    
};

class Solution {
public:
    string result;
    string longestWord(vector<string>& words) {
       
      Trienode* root = new Trienode();
      
      //for every string in words, insert that string in root 
      for(string s: words)
      {
          insert(root,s);    
          
      }
      
      //for every string in word, check the length of that string. If less than result, continue, else
      //search for string in root. If true and the length of both the string and result is equal, return
      //the minimum of 2(lexicographically), otherwise store that string in result(update result) 
      //and return the result.

      for(string s: words)
      {
          if(result.size() > s.size())
              continue;
          if(search(root,s))
          {
             if(s.size() == result.size())
                result = min(s, result);
             else
                result = s; 
          }  
      }
        
      return result;
    }
    
//Iterative function to insert string in a trie
    void insert(Trienode* root, string s)
    {
      //start from root node
      Trienode* temp = root;
      char a;
        
      for(char a: s)
      {
         //create a new node if path doesn't exist

          if(temp->t.find(a) == temp->t.end())
          {
               temp->t[a] = new Trienode();
          }
          //go to next node
          temp = temp->t[a];    
      }
        //mark the current node as leaf node
        temp->end = true;
        
    }

//Iterative function to search a string in a trie. It returns true
//if the string is found in the Trie, else it returns false
    bool search(Trienode* root, string s)
    {
        if(root==NULL)
          return false;  //false when trie is empty
       
        Trienode* node = root;
        char b;
        int count = 0;
        
        for(char b: s)
        {
          //go to next node
            node = node->t[b];
          
          //if we have reached the end, increment the count
            if(node->end == true)
                count++;
        }
       //return true if current node is the leaf node by checking if it is equal to 
       //the size of the string or not.
       return count == s.size(); 
    }
};


