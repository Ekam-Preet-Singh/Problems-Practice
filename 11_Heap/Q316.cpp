#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mod 1000000007
#define inf 1e18
#define endl "\n"
#define pb push_back
#define vi vector<ll>
#define vs vector<string>
#define pii pair<ll, ll>
#define ump unordered_map
#define mp make_pair
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll, vi, greater<ll>>
#define all(n) n.begin(), n.end()
#define ff first
#define ss second
#define mid(l, r) (l + (r - l) / 2)
#define bitc(n) __builtin_popcount(n)
#define loop(i, a, b) for (int i = (a); i <= (b); i++)
#define looprev(i, a, b) for (int i = (a); i >= (b); i--)
#define iter(container, it) for (__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...)                             \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
#define logarr(arr, a, b)            \
    for (int z = (a); z <= (b); z++) \
        cout << (arr[z]) << " ";     \
    cout << endl;
template <typename T>
T gcd(T a, T b)
{
    if (a % b)
        return gcd(b, a % b);
    return b;
}
template <typename T>
T lcm(T a, T b) { return (a * (b / gcd(a, b))); }
vs tokenizer(string str, char ch)
{
    std::istringstream var((str));
    vs v;
    string t;
    while (getline((var), t, (ch)))
    {
        v.pb(t);
    }
    return v;
}

void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << *it << " = " << a << endl;
    err(++it, args...);
}
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

void file_i_o()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

/*
Q316.) Merge 2 Binary Max Heaps

INPUT:
2

4 3
10 5 6 2
12 7 9

10 3
12 11 7 7 5 5 3 2 1 1
9 5 1

OUTPUT:
Case #1: 1
Case #2: 1

*/

void maxHeapify(vector<int> &arr, int n, int idx)
{
    // Find largest of node and its children
    if (idx >= n)
    {
        return;
    }
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;
    int max;
    if (l < n && arr[l] > arr[idx])
    {
        max = l;
    }
    else
    {
        max = idx;
    }
    if (r < n && arr[r] > arr[max])
    {
        max = r;
    }

    // Put maximum value at root and
    // recur for the child with the
    // maximum value
    if (max != idx)
    {
        swap(arr[max], arr[idx]);
        maxHeapify(arr, n, max);
    }
}

// Builds a max heap of given arr[0..n-1]
void buildMaxHeap(vector<int> &arr, int n)
{
    // building the heap from first non-leaf
    // node by calling max heapify function
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
}

class Solution
{
public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {
        vector<int> merged(n + m, 0);
        for (int i = 0; i < n; i++)
        {
            merged[i] = a[i];
        }
        for (int i = 0; i < m; i++)
        {
            merged[n + i] = b[i];
        }

        buildMaxHeap(merged, n + m);
        return merged;
    }
};

bool isMerged(vector<int> &arr1, vector<int> &arr2, vector<int> &merged)
{
    if (arr1.size() + arr2.size() != merged.size())
    {
        return false;
    }
    arr1.insert(arr1.end(), arr2.begin(), arr2.end());
    sort(arr1.begin(), arr1.end());
    vector<int> mergedCopy = merged;
    sort(mergedCopy.begin(), mergedCopy.end());
    if (arr1 != mergedCopy)
    {
        return false;
    }
    for (int i = 1; i < merged.size(); i++)
    {
        if (merged[i] > merged[(i - 1) / 2])
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n, m, i;
    cin >> n >> m;
    vector<int> a(n, 0), b(m, 0);
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    vector<int> merged, copyA = a, copyB = b;
    Solution obj;
    merged = obj.mergeHeaps(a, b, n, m);
    bool flag = isMerged(copyA, copyB, merged);
    if (flag == false)
        cout << 0 << endl;
    else
        cout << 1 << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    file_i_o();

    ll t = 1;
    ll case_num = 1;
    cin >> t;
    while (t--)
    {
        cout << "Case #" << case_num++ << ": ";
        solve();
    }

    return 0;
}