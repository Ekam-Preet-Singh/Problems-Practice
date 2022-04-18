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
Q224.) Maximum trains for which stoppage can be provided

INPUT:
2

5 2
1000 1030 1
1010 1020 1
1025 1040 1
1130 1145 2
1130 1140 2

6 3
1000 1030 1
1010 1030 1
1000 1020 2
1030 1230 2
1200 1230 3
0900 1050 1

OUTPUT:
Case #1:
Maximum Stopped Trains = 3
Case #2:
Maximum Stopped Trains = 5

*/

// number of platforms and trains
#define n 2
#define m 5

// function to calculate maximum trains stoppage
int maxStop(int arr[][3])
{
    // declaring vector of pairs for platform
    vector<pair<int, int>> vect[n + 1];

    // Entering values in vector of pairs
    // as per platform number
    // make departure time first element
    // of pair
    for (int i = 0; i < m; i++)
    {
        vect[arr[i][2]].push_back(make_pair(arr[i][1], arr[i][0]));
    }

    // sort trains for each platform as per
    // dept. time
    for (int i = 0; i <= n; i++)
    {
        sort(vect[i].begin(), vect[i].end());
    }

    // perform activity selection approach
    int count = 0;
    for (int i = 0; i <= n; i++)
    {
        if (vect[i].size() == 0)
        {
            continue;
        }

        // first train for each platform will
        // also be selected
        int x = 0;
        count++;
        for (int j = 1; j < vect[i].size(); j++)
        {
            if (vect[i][j].second >=
                vect[i][x].first)
            {
                x = j;
                count++;
            }
        }
    }
    return count;
}

void solve()
{
    int arr[m][3] = {1000, 1030, 1,
                     1010, 1020, 1,
                     1025, 1040, 1,
                     1130, 1145, 2,
                     1130, 1140, 2};
    cout << "\nMaximum Stopped Trains = " << maxStop(arr);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    file_i_o();

    ll t = 1;
    ll case_num = 1;
    // cin >> t;
    while (t--)
    {
        cout << "Case #" << case_num++ << ": ";
        solve();
    }

    return 0;
}