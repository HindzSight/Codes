#include<bits/stdc++.h>
using namespace std;



int main()
{
    vector<vector<int>> board = {{0,0},{0,1},{0,2},{0,3},{0,4},{1,0},{1,1},{1,2},{1,3},{1,4},{2,0},{2,1},{2,2},{2,3},{2,4},{3,0},{3,1},{3,2},{3,3},{3,4},{4,0},{4,1},{4,2},{4,3},{4,4},{5,0}};
        string ans = "";
        string q1 = "zb";
        int v1 = 0, v2 = 0;
        for (char c : q1) {
            int targetRow = (c - 'a') / 5;
            int targetCol = (c - 'a') % 5;
            while (v1 > targetRow) {
                ans += 'U';
                v1--;
            }
            while (v2 > targetCol) {
                ans += 'L';
                v2--;
            }
            while (v1 < targetRow) {
                ans += 'D';
                v1++;
            }
            while (v2 < targetCol) {
                ans += 'R';
                v2++;
            }
            ans += '!';
        }
        cout<<ans;
    return 0;
}
    /*
    vector<vector<int>> board = {{0,0},{0,1},{0,2},{0,3},{0,4},{1,0},{1,1},{1,2},{1,3},{1,4},{2,0},{2,1},{2,2},{2,3},{2,4},{3,0},{3,1},{3,2},{3,3},{3,4},{4,0},{4,1},{4,2},{4,3},{4,4},{5,0}};
        string q1 = "zb";
        string ans = "";

        int v1 = board[int(q1[0])-97][0];
        int v2 = board[int(q1[0])-97][1];

    while (v2 != 0) {
        if (v2 > 0) {
            ans += "R";
            v2--;
        } else if (v2 < 0) {
            ans += "L";
            v2++;
        }
    }

    while (v1 != 0) {
        if (v1 > 0) {
            ans += "D";
            v1--;
        } else if (v1 < 0) {
            ans += "U";
            v1++;
        }
    }

    if (v1 == 0 && v2 == 0) {
        ans += "!";
    }

    else if(v1 == 5 && v2 == 0){
            ans += "U";
            v1 = 4;
            v2 = 0;
        }
        cout<<"v1 : "<<v1<<" "<<"v2 : "<<v2<<endl; 

        for(int i = 1 ; i < q1.length() ;i++){
            // cout<<board[int(val)-97][0]<<" "<<board[int(val)-97][1]<<endl;
            // ans[i][0] = ans[i-1][0] - board[q1[i]][0];
            // ans[i][1] = ans[i-1][1] - board[q1[i]][1];
            v1 = board[int(q1[i])-97][0] - board[int(q1[i-1])-97][0];
            v2 = board[int(q1[i])-97][1] - board[int(q1[i-1])-97][1];

            while (v2 != 0) {
            if (v2 > 0) {
                ans += "R";
                v2--;
            } else if (v2 < 0) {
                ans += "L";
                v2++;
            }
        }

        while (v1 != 0) {
            if (v1 > 0) {
                ans += "D";
                v1--;
            } else if (v1 < 0) {
                ans += "U";
                v1++;
            }
        }
        if (v1 == 0 && v2 == 0) {
            ans += "!";
        }
        else if(v1 == 5 && v2 == 0){
            ans += "U";
            v1 = 4;
            v2 = 0;
        }
        cout<<"v1 : "<<v1<<" "<<"v2 : "<<v2<<endl; 

        }
        cout<<"Answer : "<<ans;
*/
/*
class Solution {
public:
    string alphabetBoardPath(string q1) {
        vector<vector<int>> board = {{0,0},{0,1},{0,2},{0,3},{0,4},{1,0},{1,1},{1,2},{1,3},{1,4},{2,0},{2,1},{2,2},{2,3},{2,4},{3,0},{3,1},{3,2},{3,3},{3,4},{4,0},{4,1},{4,2},{4,3},{4,4},{5,0}};
        string ans = "";

        int v1 = 0, v2 = 0;
        for (char c : q1) {
            int targetRow = (c - 'a') / 5;
            int targetCol = (c - 'a') % 5;
            while (v1 > targetRow) {
                ans += 'U';
                v1--;
            }
            while (v2 > targetCol) {
                ans += 'L';
                v2--;
            }
            while (v1 < targetRow) {
                ans += 'D';
                v1++;
            }
            while (v2 < targetCol) {
                ans += 'R';
                v2++;
            }
            ans += '!';
        }

        return ans;
    }
};
*/