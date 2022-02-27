#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

struct DSU {
    vector<int> e;
    DSU(int n){ e = vector<int>(n, -1);}

    int get(int x) {
        return e[x] < 0 ? x : e[x] = get(e[x]);
    }

    bool same_set(int a, int b) {
        return (get(a) == get(b));
    }

    int size(int x) {
        return -e[get(x)];
    }

    bool unite(int x, int y) {
         x = get(x), y = get(y);

        if(x == y) return false;
        if(e[x] > e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x;
        return true;
    }
};

struct edge {
    int a, b, weight;
};

struct query {
    int weight, node, index;
};
bool compEdge(edge a, edge b) {
    return a.weight > b.weight; 
}

bool compWeight(query a, query b) {
    return a.weight > b.weight;
}

int n, q;
edge edges[100001];
vector<query> queries;
int main() {
    ifstream fin("mootube.in");
    ofstream fout("mootube.out");
    fin >> n >> q;
    for(int i = 0 ; i < n - 1; i++) {
        edge e;
        fin >> e.a >> e.b >> e.weight;
        edges[i] = e;
    }

    for(int i = 0; i < q; i++) {
        query p;
        fin >> p.weight >> p.node;
        p.index = i + 1;
        queries.push_back(p);
    }
    sort(edges, edges + n, compEdge);
    sort(queries.begin(), queries.end(), compWeight);

    DSU graph(n + 1);
    int answer[100001];
    int j = 0;
    for(int i = 0; i < q; i++) {
        int minWeight = queries[i].weight, startingNode = queries[i].node;
        while(true) {
            if(edges[j].weight >= minWeight) {
                graph.unite(edges[j].a, edges[j].b);
                j++;
            }
            else
                break;
        }
        answer[queries[i].index] = graph.size(startingNode);
    }
    for(int i = 1; i <= q; i++) {
        fout << answer[i] - 1 << endl;
    }
}