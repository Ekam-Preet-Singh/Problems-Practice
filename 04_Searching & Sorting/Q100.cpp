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
Q100.) maximum sum such that no 2 elements are adjacent

INPUT:
2

6
5 5 10 100 10 5

3
1 2 3

OUTPUT:
Case #1: 110
Case #2: 4

*/

class Solution
{
public:
    // Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // storing sum up to current element including and
        // excluding it in respective variables.
        int incl_curr = arr[0];
        int excl_curr = 0;

        // storing sum up to previous element including and
        // excluding it in respective variables.
        int incl_prev = incl_curr;
        int excl_prev = excl_curr;

        for (int i = 1; i < n; i++)
        {
            // updating sum up to current element excluding it as maximum
            // of sum upto previous element excluding and including it.
            excl_curr = max(incl_prev, excl_prev);

            // updating sum up to current element including it as sum up to
            // previous element excluding it + current element.
            incl_curr = excl_prev + arr[i];

            // updating sum upto previous element including and
            // excluding it for next iteration.
            excl_prev = excl_curr;
            incl_prev = incl_curr;
        }

        // returning the maximum of sum up to current element
        // including and excluding it.
        return max(excl_curr, incl_curr);
    }
};

void solve()
{
    // taking number of houses
    int n;
    cin >> n;
    int a[n];

    // inserting money of each house in the array
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    Solution ob;
    // calling function FindMaxSum()
    cout << ob.FindMaxSum(a, n) << endl;
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