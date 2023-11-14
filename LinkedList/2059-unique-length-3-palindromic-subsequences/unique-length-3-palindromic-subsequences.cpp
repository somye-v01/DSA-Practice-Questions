class Solution {
public:

    int countunique(string s, int st, int e){
        unordered_set<char> se;
        for(int i = st+1; i < e; i++){
            se.insert(s[i]);
        }
        return se.size();
    }

    int countPalindromicSubsequence(string s) {
        //2 same letters ke beech me ek ya ek element se zyada letters ka gap hona chahiye.
       int i = 0;
       int j = s.size() - 1;
       int ans = 0;
       unordered_set<char> se;
       while( i < j ){
           while(se.find(s[i])!=se.end()){
               i++;
           }
           if(s[i] == s[j]){
               ans+=countunique(s,i,j);
               se.insert(s[i]);
               i++;
               j = s.size()-1;
           }
           else{
               j--;
               if(j == i+1){
                   i++;
                   j = s.size() - 1;
               }
           }
       }
       return ans;
    }
};

// //unordered_map<char,int> m;
//         for(char ch : s){
//             m[ch]++;
//         }
//         int count;
//         for(int i = 0; i < s.size() - 2; i++){
//             int dist_count = 0;
//             if(m[s[i]] >= 2 ){
//                 for(int j = i+2; j < s.size(); j++){
//                     if(s[i] != s[j]){
//                         dist_count++;
//                     }
//                     if(s[i]==s[j]){
//                         count++;
//                     }
//                 }
//             }
//         }