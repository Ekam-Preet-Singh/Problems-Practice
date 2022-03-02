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
Q111.) K-th Element of Two Sorted Arrays

INPUT:
2

5 4 5
2 3 6 7 9
1 4 8 10

5 7 7
100 112 256 349 770
72 86 113 119 265 445 892

OUTPUT:
Case #1: 6
Case #2: 256

*/

class Solution
{
public:
    int kth(int *arr1, int *arr2, int *end1, int *end2, int k)
    {
        if (arr1 == end1)
        {
            return arr2[k];
        }
        if (arr2 == end2)
        {
            return arr1[k];
        }
        int mid1 = (end1 - arr1) / 2;
        int mid2 = (end2 - arr2) / 2;
        // Compare the middle elements of arrays arr1 and arr2, let us call these indices mid1 and mid2
        if (mid1 + mid2 < k)
        {
            if (arr1[mid1] > arr2[mid2])
            {
                return kth(arr1, arr2 + mid2 + 1, end1, end2, k - mid2 - 1);
            }
            else
            {
                return kth(arr1 + mid1 + 1, arr2, end1, end2, k - mid1 - 1);
            }
        }
        else
        {
            if (arr1[mid1] > arr2[mid2])
            {
                return kth(arr1, arr2, arr1 + mid1, end2, k);
            }
            else
            {
                return kth(arr1, arr2, end1, arr2 + mid2, k);
            }
        }
    }

    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        return kth(arr1, arr2, arr1 + n, arr2 + m, k - 1);
    }
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int arr1[n], arr2[m];
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    Solution ob;
    cout << ob.kthElement(arr1, arr2, n, m, k) << endl;
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