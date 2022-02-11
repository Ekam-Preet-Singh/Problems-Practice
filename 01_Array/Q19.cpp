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
Q19.) find common elements In 3 sorted arrays

INPUT:
2

6 5 8
1 5 10 20 40 80
6 7 20 80 100
3 4 15 20 30 70 80 120

3 3 3
1 2 3
4 5 6
7 8 9

OUTPUT:
Case #1: 20 80
Case #2: -1

*/
class Solution
{
public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        int i = 0, j = 0, k = 0;

        vector<int> res;
        int last = INT_MIN;
        // Loops ends when any of one array finishes
        while (i < n1 && j < n2 && k < n3)
        {
            // checking if all elements are same & No duplicate elements are there
            if (A[i] == B[j] && A[i] == C[k] && A[i] != last)
            {
                res.push_back(A[i]);
                // Checking duplicate element
                last = A[i];
                i++;
                j++;
                k++;
            }
            // Checking the min element in A[i]
            else if (min({A[i], B[j], C[k]}) == A[i])
            {
                i++;
            }
            // Checking the min element in B[i]
            else if (min({A[i], B[j], C[k]}) == B[j])
            {
                j++;
            }
            // Checking the min element in C[i]
            else
            {
                k++;
            }
        }
        return res;
    }
};

void solve()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int A[n1];
    int B[n2];
    int C[n3];

    for (int i = 0; i < n1; i++)
        cin >> A[i];
    for (int i = 0; i < n2; i++)
        cin >> B[i];
    for (int i = 0; i < n3; i++)
        cin >> C[i];

    Solution ob;

    vector<int> res = ob.commonElements(A, B, C, n1, n2, n3);
    if (res.size() == 0)
        cout << -1;
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

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
