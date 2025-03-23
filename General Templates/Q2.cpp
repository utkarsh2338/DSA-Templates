#include<bits/stdc++.h>
#include
void f() {int N, K;
    cin>>N>>K;
    
    int utkarB1 = N, utkarB2 = N-1;
    int utkardiff1 = 0, utkardiff2 = 0;
    int utkarP1 = -1, utkarP2 = -1, utkarP3 = -1, utkarP4 = -1;
    for(int i=1; i<=min(1000, N); i++){
        int g1 = __gcd(utkarB1, i);
        int g2 = __gcd(utkarB2, i);
        int l1 = lcm(utkarB1, i);
        int l2 = lcm(utkarB2, i);
        
        if(abs(utkarB1-i) >= K){
            if(abs(g1-l1)>=2*K){
                utkarP1 = i;
                utkarP2 = utkarB1;
                break;
            }
        }
        if(abs(utkarB2-i)>=K){
            if(abs(g2-l2)>=2*K){
                utkarP3 = i;
                utkarP4 = utkarB2;
                break;
            }
        }
    }
    
    if(utkarP1==-1 && utkarP2==-1 && utkarP3==-1  && utkarP4==-1) cout<<-1<<" "<<-1<<endl;
    else if(utkarP1==-1 && utkarP2==-1) cout<<utkarP3<<" "<<utkarP4<<endl;
    else if(utkarP3==-1 && utkarP4==-1) cout<<utkarP1<<" "<<utkarP2<<endl;
    else{
        cout<<utkarP1<<" "<<utkarP2<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--) f();
    return 0;
}