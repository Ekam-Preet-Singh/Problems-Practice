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
Q231.) Find maximum meetings in one room

INPUT:
2

6
1 3 0 5 8 5
2 4 6 7 9 9

8
75250 50074 43659 8931 11273 27545 50879 77924
112960 114515 81825 93424 54316 35533 73383 160252

OUTPUT:
Case #1: 4
Case #2: 3

*/

class Solution
{
public:
    // comparator function used in sorting the list of pairs
    // according to increasing order of the finish time.
    static bool pairCompare(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b)
    {
        if (a.first.second != b.first.second)
        {
            return a.first.second < b.first.second;
        }
        return a.second < b.second;
    }

    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {

        vector<pair<pair<int, int>, int>> x;

        // pushing the pair of starting and finish time and their
        // index as pair in another list.
        for (int i = 0; i < n; i++)
        {
            x.push_back({{start[i], end[i]}, i + 1});
        }

        // sorting the list.
        sort(x.begin(), x.end(), pairCompare);
        int last = 0;
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            // if the start time of this meeting is greater than or equal
            // to the finish time of previously selected meeting then
            // we increment the counter and update last.
            if (x[i].first.first > last)
            {
                res++;
                last = x[i].first.second;
            }
        }
        // returning the counter.
        return res;
    }
};

void solve()
{
    int n;
    cin >> n;
    int start[n], end[n];
    for (int i = 0; i < n; i++)
        cin >> start[i];

    for (int i = 0; i < n; i++)
        cin >> end[i];

    Solution ob;
    int ans = ob.maxMeetings(start, end, n);
    cout << ans << endl;
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