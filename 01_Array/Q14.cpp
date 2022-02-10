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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

/*
Q14.) Merge Intervals

INPUT:
2

4
1 3
2 6
8 10
15 18

5
1 2
2 4
5 8
7 10
11 12

OUTPUT:
Case #1: 1 6 8 10 15 18
Case #2: 1 4 5 10 11 12

*/

class Solution
{
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        // If Empty or not
        if (intervals.size() == 0)
        {
            return ans;
        }
        // Sorting
        sort(intervals.begin(), intervals.end());

        int l = intervals[0][0];
        int r = intervals[0][1];

        // Traverse all input Intervals
        for (int i = 1; i < intervals.size(); i++)
        {
            // If this is not first Interval and overlaps
            // with the previous one
            if (r >= intervals[i][0])
            {
                // Merge previous and current Intervals
                r = max(r, intervals[i][1]);
            }
            else
            {
                //  add current interval to output list of intervals.
                ans.push_back({l, r});
                l = intervals[i][0];
                r = intervals[i][1];
            }
        }

        ans.push_back({l, r});

        return ans;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> Intervals(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        Intervals[i].push_back(x);
        Intervals[i].push_back(y);
    }
    Solution obj;
    vector<vector<int>> ans = obj.overlappedInterval(Intervals);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
    }
    cout << "\n";
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    clock_t begin = clock();
    file_i_o();
#endif

    ll t = 1;
    ll case_num = 1;
    cin >> t;
    while (t--)
    {
        cout << "Case #" << case_num++ << ": ";
        solve();
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}