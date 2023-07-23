#include<bits/stdc++.h>
using namespace std;

int main() {
    string n;
    string ans = "";
    getline(cin,n);
    // transform(n.begin(),n.end(),n.begin(),::tolower);
    int val = n.length();
    // for(int i = 0 ; i < val ; i++){
        for(char c : n){
        // if(!(c == 'A'|| c=='a' || c =='I' || c =='i' || c =='O' || c =='o' || c =='U' || c =='u' || c =='E' || c =='e' || c =='Y' || c =='y'))
        if(!(c == 'A'|| c=='a' || c =='I' || c =='i' || c =='O' || c =='o' || c =='U' || c =='u' || c =='E' || c =='e' || c =='Y' || c =='y'))
            ans = ans +'.'+ (char)tolower(c);

    }
    cout<<ans<<endl;
    return 0;
}
