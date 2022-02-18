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
Q51.) Write a Program to check whether a string is a valid shuffle of two strings or not

INPUT:
2

XY
12
Y21XX

XY
12
1XY2

OUTPUT:
Case #1: NO
Case #2: YES

*/

void solve()
{
    string s1, s2, res;
    cin >> s1 >> s2;
    cin >> res;

    int l1 = s1.length(), l2 = s2.length(), lr = res.length();

    // check length of result is same as
    // sum of result of first and second
    if ((l1 + l2) != lr)
    {
        cout << "NO\n";
    }
    else
    {
        // variables to track each character of 3 strings
        int i = 0, j = 0, k = 0;
        // iterate through all characters of result
        while (k < lr)
        {
            // check if first character of result matches with first character of first string
            if (i < l1 && s1[i] == res[k])
            {
                i++;
            }
            // check if first character of result matches the first character of second string
            else if (j < l2 && s2[j] == res[k])
            {
                j++;
            }
            // if the character doesn't match
            else
            {
                break;
            }
            // access next character of result
            k++;
        }
        // after accessing all characters of result
        // if either first or second has some characters left
        if (i < l1 || j < l2)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
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