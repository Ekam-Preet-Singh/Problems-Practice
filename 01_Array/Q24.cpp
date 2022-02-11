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
Q24.) Find Longest consecutive subsequence

INPUT:
2

7
2 6 1 9 4 5 3

7
1 9 3 10 4 20 2

OUTPUT:
Case #1: 6
Case #2: 4

*/

class Solution
{
public:
    // Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
        // using a Set to store elements.
        unordered_set<int> S;
        int ans = 0;

        // inserting all the array elements in Set.
        for (int i = 0; i < n; i++)
            S.insert(arr[i]);

        // checking each possible sequence from the start.
        for (int i = 0; i < n; i++)
        {
            // if current element is starting element of a sequence then only
            // we try to find out the length of sequence.
            if (S.find(arr[i] - 1) == S.end())
            {

                int j = arr[i];
                // then we keep checking whether the next consecutive elements
                // are present in Set and we keep incrementing the counter.
                while (S.find(j) != S.end())
                {
                    j++;
                }

                // storing the maximum count.
                ans = max(ans, j - arr[i]);
            }
        }
        // returning the length of longest subsequence
        return ans;
    }
};

void solve()
{
    int n, i;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    Solution obj;
    cout << obj.findLongestConseqSubseq(a, n) << endl;
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