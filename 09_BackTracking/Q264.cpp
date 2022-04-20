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
Q264.) Combinational Sum

INPUT:
2

4
7 2 6 5
16

11
6 5 7 1 8 2 9 9 7 7 9
6

OUTPUT:
Case #1: (2 2 2 2 2 2 2 2)(2 2 2 2 2 6)(2 2 2 5 5)(2 2 5 7)(2 2 6 6)(2 7 7)(5 5 6)
Case #2: (1 1 1 1 1 1)(1 1 1 1 2)(1 1 2 2)(1 5)(2 2 2)(6)

*/

class Solution
{
public:
    void combinationSumUtil(vector<int> &A, int sum,
                            vector<vector<int>> &result, vector<int> current, int pos)
    {
        // pushing the combination in result if the sum becomes equal to 0.
        if (sum == 0)
        {
            result.push_back(current);
            return;
        }
        // returning if conditions are out of bound.
        if (sum < 0 || pos >= A.size())
        {
            return;
        }

        // pushing to current for possible answer.
        current.push_back(A[pos]);

        // calling function recursively for further inclusions.
        combinationSumUtil(A, sum - A[pos], result, current, pos);

        // backtracking to remove already present number in combination
        // and provide space for further additions and possible answers.
        current.pop_back();

        // calling function recursively to move to next index as all possible
        // combination for current index have been done.
        combinationSumUtil(A, sum, result, current, pos + 1);
    }

    // Function to return a list of indexes denoting the required
    // combinations whose sum is equal to given number.
    vector<vector<int>> combinationSum(vector<int> &A, int B)
    {

        sort(A.begin(), A.end());
        vector<vector<int>> result;
        vector<int> current, C;
        int i, j;

        // storing only distinct elements in list C.
        for (i = 0; i < A.size(); i++)
        {
            j = i + 1;
            while (j < A.size() && A[i] == A[j])
            {
                j++;
            }
            C.push_back(A[i]);
            i = j - 1;
        }
        combinationSumUtil(C, B, result, current, 0);

        // returning the result.
        return result;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> A;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }
    int sum;
    cin >> sum;
    Solution ob;
    vector<vector<int>> result = ob.combinationSum(A, sum);
    if (result.size() == 0)
    {
        cout << "Empty";
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << '(';
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if (j < result[i].size() - 1)
                cout << " ";
        }
        cout << ")";
    }
    cout << "\n";
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