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

// Fast I/O
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// Manhattan Distance
int manhattan_dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// Line Equation (Ax + By + C = 0)
tuple<int, int, int> line_equation(int x1, int y1, int x2, int y2) {
    int A = y2 - y1;
    int B = x1 - x2;
    int C = A * x1 + B * y1;
    return {A, B, -C}; // Ax + By + C = 0
}

// Convex Hull (Graham's Scan)
vector<pair<int, int>> convex_hull(vector<pair<int, int>> points) {
    sort(all(points));
    vector<pair<int, int>> hull;
    
    auto cross = [](pair<int, int> O, pair<int, int> A, pair<int, int> B) {
        return (A.first - O.first) * (B.second - O.second) - 
               (A.second - O.second) * (B.first - O.first);
    };

    for (auto p : points) {
        while (sz(hull) > 1 && cross(hull[sz(hull) - 2], hull.back(), p) <= 0)
            hull.pop_back();
        hull.pb(p);
    }

    int t = sz(hull) + 1;
    for (int i = sz(points) - 2; i >= 0; i--) {
        while (sz(hull) >= t && cross(hull[sz(hull) - 2], hull.back(), points[i]) <= 0)
            hull.pop_back();
        hull.pb(points[i]);
    }

    hull.pop_back();
    return hull;
}

// Fast Dijkstra Algorithm
vector<int> dijkstra(int n, vector<vector<pair<int, int>>> &graph, int src) {
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;

        for (auto &[v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// Binary Search Helper
int binary_search(vector<int> &arr, int key) {
    int l = 0, r = sz(arr) - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return -1; // Not found
}

// Custom Comparator for Sorting Pairs
bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

// Bit Manipulation Helpers
bool get_bit(int num, int pos) { return (num & (1LL << pos)) != 0; }
int set_bit(int num, int pos) { return num | (1LL << pos); }
int clear_bit(int num, int pos) { return num & ~(1LL << pos); }

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
