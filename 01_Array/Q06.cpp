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
https://practice.geeksforgeeks.org/problems/intersection-of-two-arrays2404/1
Q6.) Find the Union and Intersection of the two sorted arrays.

INPUT:
4

5 3
1 2 3 4 5
1 2 3

6 2
85 25 1 32 54 6
85 2

5 3
89 24 75 11 23
89 2 4

6 5
1 2 3 4 5 6
3 4 5 6 7

OUTPUT:
Case #1:
Union: 5
Intersection: 3
Case #2:
Union: 7
Intersection: 1
Case #3:
Union: 7
Intersection: 1
Case #4:
Union: 7
Intersection: 4

*/

// Function to return the count of the number of elements in
// the intersection of two arrays.
int NumberofElementsInIntersection(int a[], int b[], int n, int m)
{
    // using set to store the elements.
    unordered_set<int> s1;
    int count = 0;

    // we insert all the elements of first array in set s1.
    for (int i = 0; i < n; i++)
    {
        s1.insert(a[i]);
    }

    // iterating over the second array.
    for (int i = 0; i < m; i++)
    {
        // if current element already exists in set, we update the counter.
        if (s1.find(b[i]) != s1.end())
        {

            // erasing element from set because if same element is present
            // again in the array we don't need to count it again.
            s1.erase(b[i]);

            // incrementing the counter.
            count++;
        }
    }
    // returning the counter.
    return count;
}

int doUnion(int a[], int n, int b[], int m)
{

    // using set to store the elements.
    unordered_set<int> s;

    // we insert all the elements of first array in set.
    for (int i = 0; i < n; i++)
        s.insert(a[i]);

    // we insert all the elements of second array in set.
    // Set does not contain duplicates.
    for (int i = 0; i < m; i++)
        s.insert(b[i]);

    // returning the size of set which is total number of elements in set.
    return s.size();
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    cout << "Union: " << doUnion(a, n, b, m) << endl;
    cout << "Intersection: " << NumberofElementsInIntersection(a, b, n, m) << endl;
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
        cout << "Case #" << case_num++ << ": \n";
        solve();
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}
