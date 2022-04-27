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
Q428.) Mobile Numeric Keypad Problem [ IMP ]

INPUT:
2

1

2

OUTPUT:
Case #1: 10
Case #2: 36

*/

class Solution
{

private:
    long long getCountUtil(char keypad[][3], int n)
    {
        if (keypad == NULL || n <= 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 10;
        }

        // left, up, right, down move from current location
        int row[] = {0, 0, -1, 0, 1};
        int col[] = {0, -1, 0, 1, 0};

        // taking n+1 for simplicity - count[i][j] will store
        // number count starting with digit i and length j
        long long count[10][n + 1];
        int i = 0, j = 0, k = 0, move = 0, ro = 0, co = 0, num = 0;
        long long nextNum = 0, totalCount = 0;

        // count numbers starting with digit i and of lengths 0 and 1
        for (i = 0; i <= 9; i++)
        {
            count[i][0] = 0;
            count[i][1] = 1;
        }

        // Bottom up - Get number count of length 2, 3, 4, ... , n
        for (k = 2; k <= n; k++)
        {
            for (i = 0; i < 4; i++) // Loop on keypad row
            {
                for (j = 0; j < 3; j++) // Loop on keypad column
                {
                    // Process for 0 to 9 digits
                    if (keypad[i][j] != '*' && keypad[i][j] != '#')
                    {
                        // Here we are counting the numbers starting with
                        // digit keypad[i][j] and of length k keypad[i][j]
                        // will become 1st digit, and we need to look for
                        // (k-1) more digits
                        num = keypad[i][j] - '0';
                        count[num][k] = 0;

                        // move left, up, right, down from current location
                        // and if new location is valid, then get number
                        // count of length (k-1) from that new digit and
                        // add in count we found so far
                        for (move = 0; move < 5; move++)
                        {
                            ro = i + row[move];
                            co = j + col[move];
                            if (ro >= 0 && ro <= 3 && co >= 0 && co <= 2 && keypad[ro][co] != '*' && keypad[ro][co] != '#')
                            {
                                nextNum = keypad[ro][co] - '0';
                                count[num][k] += count[nextNum][k - 1];
                            }
                        }
                    }
                }
            }
        }

        // Get count of all possible numbers of length "n" starting
        // with digit 0, 1, 2, ..., 9
        totalCount = 0;
        for (i = 0; i <= 9; i++)
        {
            totalCount += count[i][n];
        }
        return totalCount;
    }

public:
    long long getCount(int N)
    {
        char keypad[4][3] = {{'1', '2', '3'},
                             {'4', '5', '6'},
                             {'7', '8', '9'},
                             {'*', '0', '#'}};

        return getCountUtil(keypad, N);
    }
};

void solve()
{
    int n;
    cin >> n;

    Solution ob;
    cout << ob.getCount(n) << "\n";
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