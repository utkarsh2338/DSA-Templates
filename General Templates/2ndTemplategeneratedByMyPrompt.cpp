#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = 1e18;
const double EPS = 1e-9;
const double PI = acos(-1.0);

// Fast input-output
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// Binary Exponentiation (modular)
ll binpow(ll base, ll exp, ll mod = MOD) {
    ll res = 1;
    while (exp) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

// Modular Inverse (Fermat’s Theorem)
ll mod_inv(ll x, ll mod = MOD) {
    return binpow(x, mod - 2, mod);
}

// GCD and LCM
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

// Prime check
bool is_prime(ll n) {
    if (n < 2) return false;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

// Sieve of Eratosthenes
vector<int> sieve(int n) {
    vector<int> primes, is_prime(n + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.pb(i);
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = 0;
        }
    }
    return primes;
}

// Factorial
vector<ll> fact, inv_fact;
void precompute_factorial(int n, ll mod = MOD) {
    fact.resize(n + 1, 1);
    inv_fact.resize(n + 1, 1);
    for (int i = 2; i <= n; i++)
        fact[i] = fact[i - 1] * i % mod;
    inv_fact[n] = mod_inv(fact[n], mod);
    for (int i = n - 1; i >= 1; i--)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
}

// nCr (Combinations)
ll nCr(int n, int r, ll mod = MOD) {
    if (r > n || r < 0) return 0;
    return fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod;
}

// Prefix Sum
vector<int> prefix_sum(const vector<int> &a) {
    int n = sz(a);
    vector<int> ps(n + 1, 0);
    for (int i = 0; i < n; i++)
        ps[i + 1] = ps[i] + a[i];
    return ps;
}

// Coordinate Compression
vector<int> compress(vector<int> a) {
    vector<int> sorted_a = a;
    sort(all(sorted_a));
    sorted_a.erase(unique(all(sorted_a)), sorted_a.end());
    for (auto &x : a)
        x = lower_bound(all(sorted_a), x) - sorted_a.begin();
    return a;
}

// Distance between two points
double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Angle between two vectors
double angle(double x1, double y1, double x2, double y2) {
    return atan2(y2 - y1, x2 - x1);
}

// Area of Triangle using 3 Points
double triangle_area(double x1, double y1, double x2, double y2, double x3, double y3) {
    return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

// Shoelace Theorem - Area of Polygon
double polygon_area(vector<pair<double, double>> &points) {
    int n = sz(points);
    double area = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += points[i].first * points[j].second - points[j].first * points[i].second;
    }
    return abs(area) / 2.0;
}

// Point inside a polygon (Ray-Casting Algorithm)
bool is_inside_polygon(vector<pair<int, int>> &polygon, int x, int y) {
    int n = sz(polygon), cnt = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        int xi = polygon[i].first, yi = polygon[i].second;
        int xj = polygon[j].first, yj = polygon[j].second;
        if (yi > y != yj > y && x < (xj - xi) * (y - yi) / (yj - yi) + xi)
            cnt++;
    }
    return cnt % 2 == 1;
}

// Debugging
#define debug(x) cerr << #x << " = " << (x) << endl;

// Main function
void solve() {
    // Write your solution here
}

int32_t main() {
    fast_io();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
