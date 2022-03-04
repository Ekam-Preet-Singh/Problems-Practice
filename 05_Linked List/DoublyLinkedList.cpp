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
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

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

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
    Node() {}
};

void insertionAtHead(Node *&head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    if (head != NULL)
    {
        head->prev = temp;
    }
    head = temp;
}

void insertionAtTail(Node *&head, int val)
{
    if (head == NULL)
    {
        insertionAtHead(head, val);
    }
    else
    {
        Node *n = new Node(val);
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
    }
}

void insertionAtMid(Node *&head, int pos, int val)
{
    pos--;
    if (head == NULL)
    {
        insertionAtHead(head, val);
    }
    else
    {
        Node *n = new Node(val);
        Node *temp = head;
        while (--pos)
        {
            temp = temp->next;
        }
        n->next = temp->next;
        n->prev = temp;
        if (temp->next)
        {
            temp->next->prev = n;
            temp->next = n;
        }
    }
}

void deletionAtHead(Node *&head)
{
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete (temp);
}

void deletionAtTail(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete (temp->next);
        temp->next = NULL;
    }
}

void deletionAtMid(Node *&head, int pos)
{
    if (pos == 0)
    {
        deletionAtHead(head);
    }
    else
    {
        Node *temp = head;
        pos--;
        while (temp != NULL && pos--)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }
        delete (temp);
    }
}
void deleteAllNodes(Node *&head)
{
    Node *temp = new Node();
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    cout << "<----DELETED---->";
}

void display(Node *&head)
{
    Node *last;
    while (head != NULL)
    {
        cout << head->data << " ";
        last = head;
        head = head->next;
    }
    cout << endl;
    while (last != NULL)
    {
        cout << last->data << " ";
        last = last->prev;
    }
    cout << endl;
}

void solve()
{

    Node *head = NULL;
    int n, val = 0;
    cin >> n;

    cout << "Insertion at Head: ";
    insertionAtHead(head, val);
    display(head);

    for (int i = 0; i < n; i++)
    {
        cin >> val;
        insertionAtTail(head, val);
    }
    cout << "Insertion at Tail: ";
    display(head);

    cout << "Insertion at Mid : ";
    insertionAtMid(head, 1, 1);
    display(head);

    cout << "Deletion at Head : ";
    deletionAtHead(head);
    display(head);

    cout << "Deletion at Tail : ";
    deletionAtTail(head);
    display(head);

    cout << "Deletion at Mid  : ";
    deletionAtMid(head, 2);
    display(head);

    cout << "Deletion at All  : ";
    deleteAllNodes(head);
    display(head);

    // Node *head = NULL;
    // int n, val=0;
    // cin >> n;
    // insertionAtHead(head, val);
    // for (int i = 0; i < n ; i++)
    // {
    //     cin >> val;
    //     insertionAtTail(head, val);
    // }
    // insertionAtMid(head, 4, 6);
    // display(head);
    // deletionAtMid(head, 3);
    // deletionAtHead(head);
    // deletionAtTail(head);
    // display(head);
    // deleteAllNodes(head);
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