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
Q212.) Replace every element with the least greater element on its right

INPUT:
2

15
8 58 71 18 31 32 63 92 43 3 91 93 25 80 28

15
18 63 80 25 32 43 80 93 80 25 93 -1 28 -1 -1

OUTPUT:
Case #1: 
Least Greater elements on the right side are 
18 63 80 25 32 43 80 93 80 25 93 -1 28 -1 -1 
Case #2: 
Least Greater elements on the right side are 
25 80 80 25 43 80 80 93 93 28 -1 -1 -1 -1 -1 

*/

// function to get the next least greater index for each and
// every temp.second of the temp array using stack this
// function is similar to the Next Greater element for each
// and every element of an array using stack difference is
// we are finding the next greater index not value and the
// indexes are stored in the temp[i].second for all i
vector<int> nextGreaterIndex(vector<pair<int, int>> &temp)
{
    int n = temp.size();
    // initially result[i] for all i is -1
    vector<int> res(n, -1);
    stack<int> stack;
    for (int i = 0; i < n; i++)
    {
        // if the stack is empty or this index is smaller
        // than the index stored at top of the stack then we
        // push this index to the stack
        if (stack.empty() || temp[i].second < stack.top())
            stack.push(
                temp[i].second); // notice temp[i].second is
                                 // the index
        // else this index (i.e. temp[i].second) is greater
        // than the index stored at top of the stack we pop
        // all the indexes stored at stack's top and for all
        // these indexes we make this index i.e.
        // temp[i].second as their next greater index
        else
        {
            while (!stack.empty() && temp[i].second > stack.top())
            {
                res[stack.top()] = temp[i].second;
                stack.pop();
            }
            // after that push the current index to the stack
            stack.push(temp[i].second);
        }
    }
    // now res will store the next least greater indexes for
    // each and every indexes stored at temp[i].second for
    // all i
    return res;
}
// now we will be using above function for finding the next
// greater index for each and every indexes stored at
// temp[i].second
vector<int> replaceByLeastGreaterUsingStack(int arr[],
                                            int n)
{
    // first of all in temp we store the pairs of {arr[i].i}
    vector<pair<int, int>> temp;
    for (int i = 0; i < n; i++)
    {
        temp.push_back({arr[i], i});
    }
    // we sort the temp according to the first of the pair
    // i.e value
    sort(temp.begin(), temp.end());
    // now indexes vector will store the next greater index
    // for each temp[i].second index
    vector<int> indexes = nextGreaterIndex(temp);
    // we initialize a result vector with all -1
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++)
    {
        // now if there is no next greater index after the
        // index temp[i].second the result will be -1
        // otherwise the result will be the element of the
        // array arr at index indexes[temp[i].second]
        if (indexes[temp[i].second] != -1)
            res[temp[i].second] = arr[indexes[temp[i].second]];
    }
    // return the res which will store the least greater
    // element of each and every element in the array at its
    // right side
    return res;
}

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    auto res = replaceByLeastGreaterUsingStack(a, n);
    cout << "\nLeast Greater elements on the right side are " << endl;
    for (int i : res)
        cout << i << " ";
    cout << endl;
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