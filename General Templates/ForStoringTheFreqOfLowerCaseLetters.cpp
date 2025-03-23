#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    vector<int>count(26,0);
    for(char& ch: s){
        count[ch -'a']++;
    }
    return 0;
}