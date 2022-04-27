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
Q394.) Maximum Sum Increasing Subsequence

INPUT:
2

5
1 101 2 3 100

7
20 8 27 37 9 12 46

OUTPUT:
Case #1: 106
Case #2: 130

*/

class Solution
{

public:
    int maxSumIS(int arr[], int n)
    {
        int i, j, max = 0;
        int msis[n];

        /* Initialize msis values
        for all indexes */
        for (i = 0; i < n; i++)
        {
            msis[i] = arr[i];
        }

        /* Compute maximum sum values
        in bottom up manner */
        for (i = 1; i < n; i++)
        {
            for (j = 0; j < i; j++)
            {
                if (arr[i] > arr[j] && msis[i] < msis[j] + arr[i])
                {
                    msis[i] = msis[j] + arr[i];
                }
            }
        }

        /* Pick maximum of
        all msis values */
        for (i = 0; i < n; i++)
        {
            if (max < msis[i])
            {
                max = msis[i];
            }
        }

        return max;
    }
};

void solve()
{
    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    Solution ob;
    cout << ob.maxSumIS(a, n) << "\n";
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