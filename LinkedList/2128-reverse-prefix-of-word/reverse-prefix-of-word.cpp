class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = word.find(ch) ;
        if(i >= word.size()) return word;
        int mid = i/2;
        for(int j = 0; j <= mid; j++){
            swap(word[j],word[i--]);
        }
        return word;
    }
};