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
Q155.) Merge K sorted Linked list

INPUT:
2

4
3 1 2 3
2 4 5
2 5 6
2 7 8

3
2 1 3
3 4 5 6
1 8

OUTPUT:
Case #1: 1 2 3 4 5 5 6 7 8 
Case #2: 1 3 4 5 6 8 

*/

// A Linked List node
struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

class Solution
{
public:
    // Function to merge two sorted list into one sorted list.
    Node *SortedMerge(Node *a, Node *b)
    {
        Node *result = NULL;

        // base cases when either of two lists is null.
        if (a == NULL)
        {
            return (b);
        }
        else if (b == NULL)
        {
            return (a);
        }
        // comparing data in both lists and storing the smaller in result and
        // recursively calling the SortedMerge function for next node in result.
        if (a->data <= b->data)
        {
            result = a;
            result->next = SortedMerge(a->next, b);
        }
        else
        {
            result = b;
            result->next = SortedMerge(a, b->next);
        }
        // returning the resultant list.
        return result;
    }

    // Function to merge K sorted linked list.
    Node *mergeKLists(Node *arr[], int K)
    {
        int N = K;
        int last = N - 1;
        while (last != 0)
        {
            int i = 0, j = last;
            while (i < j)
            {
                // calling SortedMerge function to merge two different list into
                // one list which has sorted elements.
                arr[i] = SortedMerge(arr[i], arr[j]);

                // going for the next pair of lists.
                i++, j--;

                // if all pairs are merged, we update the last.
                if (i >= j)
                {
                    last = j;
                }
            }
        }
        // returning the merged list.
        return arr[0];
    }
};

void solve()
{
    int N;
    cin >> N;
    struct Node *arr[N];
    for (int j = 0; j < N; j++)
    {
        int n;
        cin >> n;

        int x;
        cin >> x;
        arr[j] = new Node(x);
        Node *curr = arr[j];
        n--;

        for (int i = 0; i < n; i++)
        {
            cin >> x;
            Node *temp = new Node(x);
            curr->next = temp;
            curr = temp;
        }
    }
    Solution obj;
    Node *res = obj.mergeKLists(arr, N);
    printList(res);
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