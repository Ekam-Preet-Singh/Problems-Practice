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
Q388.) Maximize The Cut Segments

INPUT:
2

4
2 1 1

5
5 3 2

OUTPUT:
Case #1: 4
Case #2: 2

*/

class Solution
{
public:
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int arr[3];
        arr[0] = x;
        arr[1] = y;
        arr[2] = z;

        // creating a dp[] array and initializing all values with 0.
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));

        for (int j = 0; j < 3; j++)
        {
            // updating the point where we can reach from x,y,z.
            for (int i = 1; i <= n; i++)
            {
                // we will update dp[i] if the point is x,y,z or if the
                // points are visited by some combination of x,y,z.
                if (i == arr[j] or (i > arr[j] and dp[i - arr[j]] > 0))
                {
                    dp[i] = max(dp[i - arr[j]] + 1, dp[i]);
                }
            }
        }
        // returning the result.
        return dp[n];
    }
};

void solve()
{
    // taking length of line segment
    int n;
    cin >> n;

    // taking types of segments
    int x, y, z;
    cin >> x >> y >> z;
    Solution obj;
    // calling function maximizeTheCuts()
    cout << obj.maximizeTheCuts(n, x, y, z) << endl;
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