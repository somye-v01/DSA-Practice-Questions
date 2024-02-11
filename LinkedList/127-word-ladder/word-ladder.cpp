class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(),wordList.end());
        queue<pair<string,int>>q; 
        q.push({beginWord,1});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            string currstr = p.first;
            int currnum = p.second;
            if(currstr == endWord) {
                return currnum;
            }
            for(int i = 0; i < currstr.size(); i++){
                for(int ch = 'a'; ch <= 'z'; ch++){
                    char temp = currstr[i];
                    currstr[i] = ch;
                    if(s.find(currstr)!=s.end()){
                        q.push({currstr,currnum+1});
                        s.erase(currstr);
                    }
                    currstr[i] = temp;
                }
            }
        }
        return 0;
    }
};