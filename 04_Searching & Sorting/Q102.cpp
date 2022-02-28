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
Q102.) merge 2 sorted arrays

INPUT:
2

4 5
1 3 5 7
0 2 6 8 9

2 3
10 12
5 18 20

OUTPUT:
Case #1: 0 1 2 3 5 6 7 8 9
Case #2: 5 10 12 18 20

*/

class Solution
{
public:
    // Function to find next gap.
    int nextGap(int gap)
    {
        if (gap <= 1)
        {
            return 0;
        }
        // Even | Odd
        return (gap / 2) + (gap % 2);
    }
    void merge(int arr1[], int arr2[], int n, int m)
    {
        int i, j, gap = n + m;
        for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
        {
            // comparing elements in the first array.
            for (i = 0; i + gap < n; i++)
            {
                if (arr1[i] > arr1[i + gap])
                {
                    swap(arr1[i], arr1[i + gap]);
                }
            }
            // comparing elements in both arrays.
            for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++)
            {
                if (arr1[i] > arr2[j])
                {
                    swap(arr1[i], arr2[j]);
                }
            }

            if (j < m)
            {
                // comparing elements in the second array.
                for (j = 0; j + gap < m; j++)
                {
                    if (arr2[j] > arr2[j + gap])
                    {
                        swap(arr2[j], arr2[j + gap]);
                    }
                }
            }
        }
    }
};

void solve()
{
    int n, m, i;
    cin >> n >> m;
    int arr1[n], arr2[m];
    for (i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    Solution ob;
    ob.merge(arr1, arr2, n, m);
    for (i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    for (i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << "\n";
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