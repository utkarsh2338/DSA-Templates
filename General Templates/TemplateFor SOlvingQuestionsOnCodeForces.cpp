/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
 
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define lli long long int
#define ll long long 
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
 
const int mod = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
 
// // Binary string conversion functions
string bin(int num) {
    string binaryStr = "";
    while (num > 0) {
        binaryStr = (num % 2 == 0 ? "0" : "1") + binaryStr;
        num /= 2;
    }
    return binaryStr == "" ? "0" : binaryStr;
}
 
int binary(string& binaryString) {
    int num = 0;
    for (char bit : binaryString) {
        num = num * 2 + (bit - '0');
    }
    return num;
}
 
// // Modulo operations
// ll mod_add(ll a, ll b, ll mod = mod) { return (a + b) % mod; }
// ll mod_sub(ll a, ll b, ll mod = mod) { return (a - b + mod) % mod; }
// ll mod_mul(ll a, ll b, ll mod = mod) { return (a * b) % mod; }
// ll mod_pow(ll base, ll exp, ll mod = mod) {
//     ll res = 1;
//     while(exp > 0) {
//         if(exp % 2) res = mod_mul(res, base, mod);
//         base = mod_mul(base, base, mod);
//         exp /= 2;
//     }
//     return res;
// }
// ll mod_inv(ll a, ll mod = mod) { return mod_pow(a, mod - 2, mod); }
 
// // GCD and LCM
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
 
// Binary search
int binary_search(vi &arr, int x) {
    int idx = lower_bound(all(arr), x) - arr.begin();
    return (idx < arr.size() && arr[idx] == x) ? idx : -1;
}
 
// Prime checking
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}
 
vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}
 
// // Sorting checks
bool is_sorted_asc(vector<ll>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) 
            return false;
    }
    return true;
}
 
// bool is_sorted_desc(const vector<int>& arr) {
//     for (int i = 1; i < arr.size(); i++) {
//         if (arr[i] > arr[i - 1]) 
//             return false;
//     }
//     return true;
// }
 
// bool is_sorted(const vector<int>& arr) {
//     return is_sorted_asc(arr) || is_sorted_desc(arr);
// }
 
//isPerfectSquare
// bool isPerfect(ll n) {
//     if (n < 0) return false; 
//     ll root = sqrt(n);       
//     return root * root == n; 
// }
 
ll powerOfTwo(ll n) {
    ll result = 1, base = 2;
    while (n > 0) {
        if (n & 1) result *= base;
        base *= base;
        n >>= 1;
    }
    return result;
}
 
// // Print array
void printarr(vll &arr){
    for(ll i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
 
vll factors(int n) {
    vll res;
    for(int i = 1; i * i <= n; i++) {
        if(n%i == 0) {
            res.pb(i);
            if(i != n/i) res.pb(n/i);
        }
    }
    return res;
}
 
struct comp {
    bool operator()(const vector<ll>& a, const vector<ll>& b) const {
        return a < b;
    }
};
 
bool isValid(int i, int j, int n, int m){
    if(i<0 || j<0 || i>=n || j>=m) return false;
    return true;
}
 
// -------------------------------------------------------------------------------------------
//|                               PLATA o PLOMO  ?????                                        |
// -------------------------------------------------------------------------------------------
// Solve function
 
void solve() {
    
}
 
int main() {
    fast_io;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}