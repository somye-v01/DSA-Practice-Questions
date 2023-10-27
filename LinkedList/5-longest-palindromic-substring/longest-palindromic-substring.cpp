class Solution {
public:

// bool palindrome(string s){
//             int i = 0;
//             int j = s.size()-1;
//             while(i<j){
//                 if(s[i]!=s[j]){
//                     return false;
//                 }
//                 i++;
//                 j--;
//             }
//             return true;
//         }
        

    string longestPalindrome(string s) {
        if(s.size()==0){
        return "";
        }
        //ababa
        //abba
     
        string ans;
        int n = s.size();
        int maxlen = -1;
        int start = 0;
         for(int i = 0; i < n; i++){
             int left = i, right = i;
             while(left >= 0 && right < n && s[left]==s[right]){
                 //ababa - for odd palindromes
                if(maxlen < right - left +1){
                start = left;
                maxlen = right - left +1;
                }
                left--;
                right++;
             }
                //for even - abba
                left = i,right =i+1;
                while(left >= 0 && right < n && s[left]==s[right]){
             
                if(maxlen < right - left +1){
                start = left;
                maxlen = right - left +1;
                }
                left--;
                right++;
             }
         }
        return s.substr(start,maxlen);

        // int maxlen = -1;
        // for(int i = 0; i < n; i++){

        //     for(int j = i+1; j < n; j++){
        //         if( palindrome(s.substr(i,j-i+1)) == true ){
        //             int len = j-i+1;
        //             int temp = maxlen;
        //             maxlen = max(maxlen,len);
        //             if(temp != maxlen){ // new string is palindrome with high length
        //             ans = s.substr(i,j-i+1);
        //             }
        //         }
        //     }
        // }
        // if(ans.size()!=0){
        // return ans;
        // }
        // else{
        //     char ch = s[0];
        //     return string()+ch;
        // }
        
        
    }
};

// int i = 0;
//         int j = s.size()-1;
//         while(i<j){
//         if(palindrome(s.substr(i,j-i+1)) == true){
//             return s.substr(i,j-i+1);
//         }
//         else if(palindrome(s.substr(i+1,j-i+1)) == true){   
//             return s.substr(i+1,j-i+1); //i + 1 covered
//         }
//         else if(palindrome(s.substr(i,(j-1)-i+1)) == true) {
//             return s.substr(i,(j-1)-i+1);
//         }
//         i++;
//         j--;
//         }