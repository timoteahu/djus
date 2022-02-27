#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>


using namespace std;

struct DSU {
    vector<int> e;
    DSU(int n) { e = vector<int>(n, -1); }

    int get(int x) {
        return e[x] < 0 ? x : e[x] = get(e[x]); 
    }

    bool same_set(int a, int b) { return get(a) == get(b);}

    int size(int x) {return -e[get(x)]; }

    bool unite(int x, int y) {
        x = get(x), y = get(y);

        if(x == y) return false;
        if(e[x] > e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x;
        return true;
    } 
};

int n, m;
int main() {
    cin >> n >> m;
    DSU roads(n);

    cout<< "";
    int total = n;
    int max_comp = -1;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if(!roads.same_set(a, b)) {
            max_comp = max(max_comp, roads.size(a) + roads.size(b));
            // max_comp -= roads.getValue(a); max_comp -= roads.getValue(b);
            roads.unite(a, b);
            total--;
        }
        cout << total << " " << max_comp << "\n";
    }
}