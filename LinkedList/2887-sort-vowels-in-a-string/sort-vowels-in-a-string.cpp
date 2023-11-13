class Solution {
public:

    bool isvowel(char ch){
        ch = toupper(ch);
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
        return true;
    } else {
        return false;
    }
    }

    string sortVowels(string s) {
        vector<char> vowelindex;
        for(int i = 0; i < s.size(); i++){
            if(isvowel(s[i])){
                vowelindex.push_back( s[i] );
            }
        }
        sort(vowelindex.begin(), vowelindex.end());
        int j = 0;
        for(int i = 0; i < s.size(); i++){
            if(isvowel(s[i])){
                swap(vowelindex[j], s[i]);
                j++;
            }
        }
        return s;
    }
};