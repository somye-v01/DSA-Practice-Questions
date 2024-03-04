
class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size(),n1=0,n2=0;
        map<int,int> m1,m2;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (((i == j || j == n-1-i) && i <= (n-1)/2) || (j == (n-1)/2 && i > (n-1)/2)){
                    // Y 
                    m1[grid[i][j]]++;
                    n1++;
                } else {
                    //non-Y 
                    m2[grid[i][j]]++;
                    n2++;
                }
            }
        }
        int ans1 = n1-m1[0]+min(n2-m2[1],n2-m2[2]); 
        int ans2 = n1-m1[1]+min(n2-m2[0],n2-m2[2]); 
        int ans3 = n1-m1[2]+min(n2-m2[1],n2-m2[0]); 
        int ans = min({ans1,ans2,ans3});
        return ans;
    }
};

// class Solution {
// public:
//     int minimumOperationsToWriteY(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int c = n;
//         unordered_map<int,int>m;
//         unordered_map<int,int>m2;
//         int y = n/2;
//         // cout << "log1 here";
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < n; j++){
//                 // cout << "log2 here";
//                 if(i<=n/2 && i==j) m[grid[i][j]]++;
//                 else if(i>n/2 && j==y)  m[grid[i][j]]++;
//                 else if(i<=n/2 && j+i==n-1 && i!=j){
//                     // c-=3;
//                     // cout<<"reached here with value being pushed in m "<<grid[i][j]<<endl;
//                     m[grid[i][j]]++;
//                 }
//                 else{
//                     m2[grid[i][j]]++;
//                 }
//             }
//             // cout << "log3 here";
            
//         }
//         // cout << "log4 here";
//         // int x = n/2;
        
//         // while(x<n-1){
//         //     x++;
//         //     m[grid[x][y]]++;
//         // }
//         // cout << "log5 here";
//         for(auto x : m){
//             cout << x.first <<"->"<<x.second<<endl;
//         }
//         cout<<"2nd map"<<endl;
//         for(auto x : m2){
//             cout << x.first <<"->"<<x.second<<endl;
//         }
//         // unordered_set<int>els;
//         int maxel = -1;
//         int secmaxel = -1;
//         int totfreq = 0;
//         int maxfreq = 0;
//         int secmaxfreq = 0;
//         int cnt = 0;
//         for(auto x : m2){
//             if(x.second > maxfreq){
//                 totfreq+=x.second;
//                 secmaxfreq = maxfreq;
//                 secmaxel = maxel;
//                 maxfreq = x.second;
//                 maxel = x.first;
//                 cnt+=x.second;
//             }
//             else if(x.second>secmaxfreq){
//                     totfreq+=x.second;
//                     secmaxfreq = x.second;
//                     secmaxel = x.first;
//                     cnt+=x.second;
//                 }
            

//             else{
//                 totfreq+=x.second;
//             cnt+=x.second;
//             }
//         }
//         cout << "m map maxel here is: "<<maxel << " with frequency(maxfreq): "<<maxfreq<<endl;
//         cout << "m map maxel2 here is: "<<secmaxel << " with frequency(secmaxfreq): "<<secmaxfreq<<endl;
//         cout << "total frequency in m is "<<totfreq<<endl;
//         // for(auto it : m2){
//         //      if(it.second==maxfreq){
//         //         els.insert(maxel);
//         //         els.insert(it.first);
//         //     }
//         // }
//         // cnt-=maxfreq;
//         // int sz = 0;
//         // for(auto it : els){
//         //     cout << it <<" " <<endl;
//         //     sz++;
//         // }
//         cout << "maxel: "<<maxel << "   cnt val: "<<cnt<<endl;
        
//         // int cnt2 = 0;
//         // if(sz>=2){
//         //     for(auto x : m){
//         //     // if(x.first!=maxel){
//         //         if(x.second > maxfreq2){
//         //             maxel2 = x.first;
//         //         maxfreq2 = x.second;
//         //     }
//         //     cnt+=x.second;
//         //     // }
//         //     // }
//         // }
//         // cout << "new maxel2 is "<<maxel2 << endl;
//         // if(els.find(maxel2)!=els.end()){
//         //     cnt-=m[maxel2];
//         // }
//         // else{
//         //     cnt-=maxfreq2;
//         // }

//         // }
//         // else{
//         // if(m.find(maxel)!=m.end()){
//         //     cnt+=m[maxel];
//         // }
//         int maxel2 = -1;
//         int secmaxfreq2 = 0;
//         int maxfreq2 = 0;
//         for(auto x : m){
//             if(x.second > maxfreq2){
//                 secmaxfreq2 = maxfreq2;
//                 maxfreq2 = x.second;
//                 maxel2 = x.first;
//             }
//             else if(x.second>secmaxfreq2){
//                     secmaxfreq2 = x.second;
//                     // secmaxel2 = x.first;
//                     // cnt+=x.second;
//                 }
                
//             cnt+=x.second;
//         }
//         //  cout << "m2map maxel here is: "<<maxel << " maxfreq: "<<maxfreq<<endl;
//         cout << "cnt value here is : "<<cnt<<endl;
//         cout << "m2 map maxel here is: "<<maxel2 << " and max frequency is(maxfreq2): " <<maxfreq2 <<endl;
//         cout << "2nd highest frequency is:(secmaxfreq2) "<<secmaxfreq2<<endl;
//         if(maxel2==maxel){
//             if(maxfreq2==maxfreq){
//                 if(secmaxfreq>secmaxfreq2){
//                     cnt-=secmaxfreq2;
//                     cnt-= maxfreq;
//                 }
//                 else{
//                     cnt-=secmaxfreq;
//                     cnt-= maxfreq;
//                 }
//             }
//             else if(maxfreq2 > maxfreq){
//                 cnt-=maxfreq2;
//                 cnt-=secmaxfreq;
//             }
//             else{
//                 cnt-=maxfreq;
//                 cnt-=secmaxfreq2;
//             }
//         }
//         else{
//             // }
        
//         cnt-=maxfreq;
//         cnt-=maxfreq2;
//         }
//         // }
//         // if(m.find(maxel)!=m.end()){
//         //     cnt-=m[maxel];
//         // }
//         // if(m.)

//         return cnt;
//     }
        
// };