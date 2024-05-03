class Solution {
public:

    vector<string> findstringstream(string& version1){
        stringstream ss(version1);
        string str = "";
        vector<string> temp;
        while(getline(ss, str, '.' )){
            temp.push_back(str);
        }
        return temp;
    }

    int compareVersion(string version1, string version2) {
        vector<string> v1 = findstringstream(version1);
        vector<string> v2 = findstringstream(version2);
        int n = v1.size();
        int m = v2.size();
        int i = 0;
        while(i < n || i < m){
            
            int num1 = (i<n) ? stoi(v1[i]) : 0;
            int num2 = (i<m ) ? stoi(v2[i]) : 0;
            if(num1>num2){
                return 1;
            }
            if(num1<num2){
                return -1;
            }
            else{
                i++;
            }
        }
        return 0;
    }
};