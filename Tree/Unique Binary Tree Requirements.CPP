//https://www.geeksforgeeks.org/problems/unique-binary-tree-requirements/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=unique-binary-tree-requirements

class Solution
{
public:
    bool isPossible(int a,int b)
    {
        //code here
        if((a==2||b==2)&& a!=b){
            return 1;
        }
        return 0;
    }
};