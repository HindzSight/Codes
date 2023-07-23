#include<bits/stdc++.h>
using namespace std;

int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map <vector<int>,int> hash;
        for(int i = 0 ; i < n ; i++)
            hash[grid[i]]++;
        
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            vector<int> col;
            for(int j = 0 ; j < n ; j++){
                col.push_back(grid[j][i]);
            }
            if(hash[col]>0) ans += hash[col];
        }
        return ans;
    }

int main(){

    vector<vector<int>> grid = {{3,2,1},{1,7,6},{2,7,7}}; // 1
    cout<<equalPairs(grid)<<endl; 
    return 0;
}