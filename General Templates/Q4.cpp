#include <bits/stdc++.h>
using namespace std;
#define int long long

// Function to count inversions using Merge Sort
int mergeAndCount(vector<int>& arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);
    
    int i = 0, j = 0, k = l, swaps = 0;
    
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            swaps += left.size() - i;
        }
    }
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
    
    return swaps;
}

// Function to count inversions in an array using merge sort
int countInversions(vector<int> arr, int l, int r) {
    if (l >= r) return 0;
    int m = (l + r) / 2;
    int count = countInversions(arr, l, m) + countInversions(arr, m + 1, r);
    count += mergeAndCount(arr, l, m, r);
    return count;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> original = a;
    int minInversions = countInversions(a, 0, n - 1);
    int best_l = 1, best_r = 1; // Default to a single element
    
    // If the array is already sorted, return any (l, l)
    if (minInversions == 0) {
        cout << 1 << " " << 1 << '\n';
        return;
    }

    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            vector<int> temp = original;

            if (l != r) { // Perform cyclic shift only if l != r
                int first = temp[l];
                for (int i = l; i < r; i++) temp[i] = temp[i + 1];
                temp[r] = first;
            }

            int newInversions = countInversions(temp, 0, n - 1);
            if (newInversions < minInversions) {
                minInversions = newInversions;
                best_l = l + 1, best_r = r + 1; // Convert to 1-based index
            }
        }
    }

    cout << best_l << " " << best_r << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
