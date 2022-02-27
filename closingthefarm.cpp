#include <iostream>
#include <vector>
#include <set>

using namespace std;
struct DSU {
    vector<int> e;
    DSU(int n) {
        e = vector<int>(n, -1);
    }

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
vector<int> adj[200001];
int closing[200001], activated[200001];
int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < n; i++) {
        cin >> closing[n - 1 - i];
    }

    int answer[200001];
    int components 0;
    for(int i = 0; i < n; i++) {
        int node = closing[i];
        activated[node] = true;
        components++;

        for(int j = 0; j < adj[node].size(); j++) {
            if(activated[node] && activated[j] && (get(node) != get(j))) {
                
            }
        }
    }

}