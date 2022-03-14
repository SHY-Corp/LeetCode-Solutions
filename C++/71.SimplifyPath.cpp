class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string outputPath;

        for(int i=0; i<path.size(); i++)
        {
            //we ignore the very first '/'
            if(path[i]=='/')
                continue;

            //creating a temporary string between 2 '/' which we will process in the further steps
            string temp;

            //iterating the input string till we reach a '/'
            while(path[i]!='/' && i<path.size())
            {
                //adding the input path to the temp string
                temp+=path[i];
                i++;
            }

            //we ignore the '.' in the temporary string as it implies current directory
            if(temp==".")
                continue;

            //we pop an element from the stack if it is not empty so that our top element is now a previous
            //directory(implying that it refers to the directory above it)
            else if(temp=="..")
            {
                if(!s.empty())
                    s.pop();
            }
            //push the temp string(directory file name) to the stack
            else
                s.push(temp);
        }

        //add the elements in the stack to the output string(also, look at the order carefully while implementing)
        while(!s.empty())
        {
            outputPath = "/" + s.top() + outputPath;
            s.pop();
        }

        //if there is no directory or file
        if(outputPath.size()==0)
            return "/";

        return outputPath;
    }
};
