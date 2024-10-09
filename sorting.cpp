#include <bits/stdc++.h>
#define vll vector<ll>
#define vpii vector<pii>
#define vs vector<string>
#define el cout << '\n'
#define rt return;
#define mask(x) (1ll << (x))
#define bit(n,x) ((n >> x) & 1)
#define multiTest 0
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const int N = 1e3;
const int mod = 1e9 + 7;

class Sorting {
public:
    int pivot(vector<int> &a, int l, int r) {
        int j = l - 1;
        for (int i = l; i < r; i++) {
            if (a[i] <= a[r]) {
                ++j;
                swap(a[i], a[j]);
            }
        }
        swap(a[j+1], a[r]);
        return j + 1;
    }

    void quickSort(vector<int> &a, int l, int r) {
        if (l >= r) return;
        int pv = pivot(a, l, r);
        quickSort(a, l, pv - 1);
        quickSort(a, pv + 1, r);
    }

    void Merge(vector<int> &a, int l, int m, int r) {
        vector<int> tmp(r - l + 1);
        int i = l;
        int j = m + 1;
        int idx = 0;
        while (i <= m && j <= r) {
            if (a[i] <= a[j]) {
                tmp[idx++] = a[i++];
            }
            else {
                tmp[idx++] = a[j++];
            }
        }

        while (i <= m) tmp[idx++] = a[i++];
        while (j <= r) tmp[idx++] = a[j++];

        for (int i = 0; i < tmp.size(); i++) {
            a[l + i] = tmp[i];
        }
    }

    void mergeSort(vector<int> &a, int l, int r) {
        if (l >= r) return;
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        Merge(a, l, m, r);
    }

    void radixSort(vector<int> &a) {
        int n = a.size();
        int mx_num = *max_element(a.begin(), a.end());

        int exp = 1;
        while (mx_num / exp > 0) {
            vector<vector<int>> cnt(10);

            for (int j = 0; j < n; j++) {
                int digit = (a[j] / exp) % 10;
                cnt[digit].push_back(a[j]);
            }

            int idx = 0;
            for (int i = 0; i < 10; i++) {
                for (auto x : cnt[i]) {
                    a[idx++] = x;
                }
            }
            exp *= 10;
        }
    }

    void shellSort(vector<int> &a) {
        int n = a.size();
        vector<int> distance = {5, 3, 1};

        for (int dis : distance) {
            for (int i = dis; i < n; i++) {
                int tmp = a[i];
                int j = i - dis;
                while (j >= 0 && a[j] > tmp) {
                    a[j + dis] = a[j];
                    j -= dis;
                }
                a[j + dis] = tmp;
            }
        }
    }

    void bubbleSort(vector<int> &a) {
        int n = a.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (a[j] > a[j+1]) swap(a[j], a[j+1]);
            }
        }
    }

    void selectionSort(vector<int> &a) {
        int n = a.size();
        for (int i = 0; i < n - 1; i++) {
            int j = i;
            for (int k = i + 1; k < n; k++) {
                if (a[k] < a[j]) {
                    j = k;
                }
            }
            swap(a[i], a[j]);
        }
    }

    void insertionSort(vector<int> &a) {
        int n = a.size();
        for (int i = 1; i < n; i++) {
            int tmp = a[i];
            int j = i - 1;
            while (tmp < a[j]) {
                a[j + 1] = a[j];
                --j;
            }
            a[j + 1] = tmp;
        }
    }
};

void solve() {
    vector<int> a = {29, 10, 14, 37, 13, 12, 30, 20, 50, 5, 75, 11};

    Sorting sorter;
    sorter.quickSort(a, 0, a.size() - 1);
    for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#if multiTest
    ll t; cin >> t;
    while (t--) {
        solve();
    }
#else
    solve();
#endif

    return 0;
}
