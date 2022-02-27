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
Q88.) Recursively print all sentences that can be formed from list of word lists

INPUT:
3

3 2
you we
have are
sleep eat

2 3
you we have
are sleep eat

2 2
my name
is ekam

OUTPUT:
Case #1:
you have sleep
you have eat
you are sleep
you are eat
we have sleep
we have eat
we are sleep
we are eat
Case #2:
you are
you sleep
you eat
we are
we sleep
we eat
have are
have sleep
have eat
Case #3:
my is
my ekam
name is
name ekam

*/

// Function to print all combinations of phrases that can be formed
// by words from each of the given lists
void printAllCombinations(vector<vector<string>> const &lists, string result, int n)
{
    // base case
    if (lists.size() == 0)
    {
        return;
    }

    // if we have traversed each list
    if (n == lists.size())
    {
        // print phrase after removing trailing space
        cout << result.substr(1) << endl;
        return;
    }

    // get the size of the current list
    int m = lists[n].size();

    // do for each word in the current list
    for (int i = 0; i < m; i++)
    {
        // append current word to output
        string out = result + " " + lists[n].at(i);

        // recur for the next list
        printAllCombinations(lists, out, n + 1);
    }
}

void solve()
{
    int row, col;
    cin >> row >> col;
    vector<vector<string>> d;
    string val;
    for (int i = 0; i < row; i++)
    {
        vector<string> temp;
        for (int j = 0; j < col; j++)
        {
            cin >> val;
            temp.push_back(val);
        }
        d.push_back(temp);
        temp.clear();
    }

    printAllCombinations(d, "", 0);
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
        cout << "Case #" << case_num++ << ":\n";
        solve();
    }

    return 0;
}