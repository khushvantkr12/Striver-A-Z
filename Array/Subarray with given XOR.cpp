int Solution::solve(vector<int> &A, int B) {
    //this ques is same as subarray sum equal k
    //.
    map<int,int>mp;
    mp[0]=1;
    int count=0;
    int XOR_VALUE=0;
    for(int i=0; i<A.size(); i++){
       XOR_VALUE^=A[i];
        if(mp.find(XOR_VALUE^B)!=mp.end()){
            count+=mp[XOR_VALUE^B];
        }
        mp[XOR_VALUE]++;
    }
    return count;
}
Input 1:

 A = [4, 2, 2, 6, 4]
 B = 6
 prop of XOR-->a^a=0,a^0=a 
 0^4=4 then take xor with B to insure that we get 0 and if it exist in map then increment count..mp[4]=1
 4^2=6 then take xor with B to insure that we get 0 and if it exist in map then increment count..mp[6]=1
 4^2^2=4 then take xor with B to insure that we get 0 and if it exist in map then increment count..mp[4]=2
 4^2^2^6=2 agar tm yaha pe dekhoge ki agar hm isme se 4 ko hata de to mera 6 aajayega..so kyo na hm iss pura
 ka xor le le 'B' ke sath taaki pata chl jaaye ki kisko hatane se mera xor equal B horha hai..so yaha pe 
 agar xor liye B ke sath to 2 cancel 2 and 6 cancel 6 so 4 baacha iska mtlb 4 ko remove kro..aur uska freq ko 
 add kr do..to yaha pe valid substring hoga [2,2,6 and 6]..thats why add 2 in count