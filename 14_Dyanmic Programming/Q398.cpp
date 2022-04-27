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
Q398.) Egg Dropping Problem

INPUT:
2

1 2

2 10

OUTPUT:
Case #1: 2
Case #2: 4

*/

class Solution
{
public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eggDrop(int n, int k)
    {
        // creating a 2D table where entry eggFloor[i][j] will represent
        // minimum number of trials needed for i eggs and j floors.
        int eggFloor[n + 1][k + 1];
        int res;
        int i, j, x;

        // we need one trial for one floor and 0 trials for 0 floors.
        for (i = 1; i <= n; i++)
        {
            eggFloor[i][1] = 1;
            eggFloor[i][0] = 0;
        }

        // we always need j trials for one egg and j floors.
        for (j = 1; j <= k; j++)
        {
            eggFloor[1][j] = j;
        }

        // filling rest entries in table using optimal substructure property.
        for (i = 2; i <= n; i++)
        {
            for (j = 2; j <= k; j++)
            {
                eggFloor[i][j] = INT_MAX;
                for (x = 1; x <= j; x++)
                {
                    res = 1 + max(eggFloor[i - 1][x - 1], eggFloor[i][j - x]);
                    if (res < eggFloor[i][j])
                    {
                        eggFloor[i][j] = res;
                    }
                }
            }
        }
        // returning the result in eggFloor[n][k].
        return eggFloor[n][k];
    }
};

void solve()
{
    // taking eggs and floors count
    int n, k;
    cin >> n >> k;
    Solution ob;
    // calling function eggDrop()
    cout << ob.eggDrop(n, k) << endl;
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