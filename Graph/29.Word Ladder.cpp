//https://leetcode.com/problems/word-ladder/description/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //approach is simple take set store all wordlist,then make start with beginword and push it into queue,then change each word to a-z and find if this is inside the set,f this is inside then push that word in queue,then further check for that word and find it in set and also every time when you find word increment it by +1..

        set<string>s(wordList.begin(),wordList.end());

        queue<pair<string,int>>q;
        q.push({beginWord,1});
        int maxi=0;

        while(!q.empty()){
            string x=q.front().first;
            int y=q.front().second;
            q.pop();

            if(x==endWord){
              maxi=y;
              break;
            }

            for(int i=0; i<x.size(); i++){
                for(char j='a'; j<='z'; j++){
                   
                    string word=x;
                    word[i]=j;
                    if(s.find(word)!=s.end()){
                        q.push({word,y+1});
                        s.erase(word);//dekkho suppose "hot" se "dot" banaya tum fir tm "hot" ko pop kkiya queue se..lekin tm usko set se nhi hataya to dekho dikkat kya hoga.."dot" pe hm iterate maarenge atoz tk to wo ek time pe "hot" bn jayega aur set usko khoj lega aur phir se usko queue me push kr dega..isiliye hmko usko erase karna padega..samjha
                    }
                }
            }

        }
        return maxi;
    }
};