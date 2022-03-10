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
Q152.) Flatten a Linked List

INPUT:
2

4
4 2 3 4
5 7 8 30 10 20 19 22 50 28 35 40 45

4
4 1 3 1
5 7 8 30 10 19 22 50 28

OUTPUT:
Case #1: 5 7 8 10 19 20 22 28 30 35 40 45 50 
Case #2: 5 7 8 10 19 22 28 30 50 

*/

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node *merge(Node *a, Node *b)
{

    if (a == NULL)
    {
        return b;
    }

    if (b == NULL)
    {
        return a;
    }

    Node *result;
    if (a->data < b->data)
    {
        result = a;
        result->bottom = merge(a->bottom, b);
    }
    else
    {
        result = b;
        result->bottom = merge(a, b->bottom);
    }

    return result;
}

Node *flatten(Node *root)
{
    // Base cases
    if (root == NULL || root->next == NULL)
    {
        return root;
    }
    return merge(root, flatten(root->next));
}

void printList(Node *Node)
{
    while (Node != NULL)
    {
        cout << Node->data << " ";
        Node = Node->bottom;
    }
}

void solve()
{
    int n, m, flag = 1, flag1 = 1;
    struct Node *temp = NULL;
    struct Node *head = NULL;
    struct Node *pre = NULL;
    struct Node *tempB = NULL;
    struct Node *preB = NULL;
    cin >> n;
    int work[n];
    for (int i = 0; i < n; i++)
        cin >> work[i];
    for (int i = 0; i < n; i++)
    {
        m = work[i];
        --m;
        int data;
        cin >> data;
        temp = new Node(data);
        temp->next = NULL;
        temp->bottom = NULL;

        if (flag)
        {
            head = temp;
            pre = temp;
            flag = 0;
            flag1 = 1;
        }
        else
        {
            pre->next = temp;
            pre = temp;
            flag1 = 1;
        }
        for (int j = 0; j < m; j++)
        {

            int temp_data;
            cin >> temp_data;
            tempB = new Node(temp_data);

            if (flag1)
            {
                temp->bottom = tempB;
                preB = tempB;
                flag1 = 0;
            }
            else
            {
                preB->bottom = tempB;
                preB = tempB;
            }
        }
    }
    Node *fun = head;
    Node *fun2 = head;

    Node *root = flatten(head);
    printList(root);
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