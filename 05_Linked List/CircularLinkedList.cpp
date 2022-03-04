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
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertionAtHead(Node *&head, int val)
{
    Node *n = new Node(val);
    if (head == NULL)
    {
        head = n;
        n->next = head;
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->next = head;
        head = n;
    }
}

void insertionAtTail(Node *&head, int val)
{

    Node *n = new Node(val);
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    n->next = n;
    if (head == NULL)
        head = n;
    else
    {
        n->next = head;
        temp->next = n;
    }
}

void insertionAtMid(Node *&head, int pos, int val)
{
    Node *n = new Node(val);
    Node *temp = head;
    if (head == NULL)
    {
        insertionAtHead(head, val);
    }
    else
    {
        pos--;
        while (pos--)
        {
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
    }
}

void deletionAtHead(Node *&head)
{
    Node *previous = head, *firstNode = head;
    if (previous->next == previous)
    {
        head = NULL;
        return;
    }
    while (previous->next != head)
    {
        previous = previous->next;
    }
    previous->next = firstNode->next;
    head = previous->next;
    delete (firstNode);
}

void deletionAtTail(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        Node *current = head, *temp = head, *previous;
        if (current->next == current)
        {
            head = NULL;
            return;
        }
        while (current->next != head)
        {
            previous = current;
            current = current->next;
        }

        previous->next = current->next;
        head = previous->next;
        delete (current);
    }
}

void deletionAtMid(Node *&head, int pos)
{
    Node *previous = head, *nxt = head;
    if (pos == 0)
    {
        deletionAtHead(head);
    }
    else
    {
        pos--;
        while (pos--)
        {
            previous = previous->next;
            nxt = previous->next;
        }
        previous->next = nxt->next;
        delete (nxt);
    }
}

void deleteAll(Node *&head)
{
    Node *aux, *temp = head;
    while (temp != head)
    {
        aux = temp->next;
        delete (temp);
        temp = aux;
    }
    head = NULL;
    cout << "<----DELETED---->\n";
}

void length(Node *&head)
{
    int cnt = 0;
    if (head == NULL)
    {
        cnt = 0;
    }
    else
    {
        Node *temp = head;
        do
        {
            temp = temp->next;
            cnt++;

        } while (temp != head);
    }
    cout << cnt << endl;
}

void display(Node *&head)
{
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
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
    insertionAtMid(head, 4, 6);
    display(head);

    cout << "Deletion at Head : ";
    deletionAtHead(head);
    display(head);

    cout << "Deletion at Tail : ";
    deletionAtTail(head);
    display(head);

    cout << "Deletion at Mid  : ";
    deletionAtMid(head, 3);
    display(head);

    cout << "Length of CLL    : ";
    length(head);

    cout << "Deletion at All  : ";
    deleteAll(head);

    cout << "Length after Del : ";
    length(head);
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    clock_t begin = clock();
    file_i_o();
#endif

    ll t = 1;
    // ll case_num = 1;
    // cin >> t;
    while (t--)
    {
        // cout << "Case #" << case_num++ << ": ";
        solve();
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}