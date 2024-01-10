#include <iostream>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <climits>
#include <cstring>
#include <vector>
#include <map>

using namespace std;
FILE *f;

struct Tree{
    int left, right, parent, symbol;
    Tree() {
        symbol = -1;
    }
};
Tree tree[530];

int main()
{
    f = fopen("/Users/arpo/CLionProjects/untitled1/inputraz.txt", "rb");
    freopen("/Users/arpo/CLionProjects/untitled1/output.raz", "w", stdout);
    unsigned char ch;
    int p = 5;
    int size_tree;
    fscanf(f,"%d", &p);
    size_tree = p;
    cout << p << ' ' << size_tree << endl;
    for (int i = 0; i < size_tree; i++) {
        fscanf(f, "%d %d %d %d\n", &tree[i].left, &tree[i].right, &tree[i].parent, &tree[i].symbol);
    }
    for (int i = 0; i < size_tree; i++) {
        cout << tree[i].left << ' ' << tree[i].right << ' ' << tree[i].parent << ' ' << tree[i].symbol << endl;
    }
    while (fscanf(f, "%c", &ch)) {
        int d = ch;
        //cout << d << ' ' << endl;
        int k = 7;
        int pos  = size_tree - 1;
        while (k >= 0) {
            bool b = (bool((ch >> k)  &  1u));
            //cout << b << endl;
            if (b == 0) {
                pos = tree[pos].left;
            } else if (b == 1) {
                pos = tree[pos].right;
            }
            if (tree[pos].left == -1 && tree[pos].right == -1) {
                char sym =tree[pos].symbol;
                cout << sym;
                pos = size_tree - 1;
            }
            //cout << pos << endl;
            k -= 1;
        }
        break;
    }

    fclose(f);

}
