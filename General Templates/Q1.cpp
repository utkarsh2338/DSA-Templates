#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
   
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(n%3 == n%5) cnt++;
    }
    cout<<cnt<<endl;
    }
    


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        solve(n);
    }
    
    return 0;
}
