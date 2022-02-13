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
Q30.) Chocolate Distribution problem

INPUT:
2

8
3 4 1 9 56 7 9 12
5

7
7 3 2 4 9 12 56
3

OUTPUT:
Case #1: 6
Case #2: 2

*/

class Solution
{
public:
    ll findMinDiff(vector<ll> a, ll n, ll m)
    {

        // Sort the given packets
        sort(a.begin(), a.end());

        ll start = 0, end = 0;
        // Largest number of chocolates
        ll mind = LONG_LONG_MAX;

        // Find the subarray of size m such that
        // difference between last (maximum in case
        // of sorted) and first (minimum in case of
        // sorted) elements of subarray is minimum.
        for (ll i = 0; i + m - 1 < n; i++)
        {
            ll diff = a[i + m - 1] - a[i];
            if (mind > diff)
            {
                mind = diff;
                start = i;
                end = i + m - 1;
            }
        }
        return a[end] - a[start];
    }
};

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a;
    ll x;
    for (ll i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }

    ll m;
    cin >> m;
    Solution ob;
    cout << ob.findMinDiff(a, n, m) << endl;
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