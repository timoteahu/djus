#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <algorithm>

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

struct point {
    int x, y, index;
};

struct d {
    int dist, indexA, indexB;
};

bool comp(d a, d b) {
    return a.dist < b.dist;
}

int n;
point points[1001];
vector<d> v;
int main() {
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");
    fin >> n;
    for(int i = 0; i < n; i++) {
        fin >> points[i].x >> points[i].y;
        points[i].index = i;
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            d thing;
            thing.dist = pow(abs(points[j].x - points[i].x), 2) + pow(abs(points[j].y - points[i].y), 2);
            thing.indexA = points[i].index; thing.indexB = points[j].index;
            v.push_back(thing);
        }
    }

    sort(v.begin(), v.end(), comp);
    DSU graph(n);
    int answer = -1;
    for(int i = 0; i < v.size(); i++) {
        if(!graph.same_set(v[i].indexA, v[i].indexB)) {
            graph.unite(v[i].indexA, v[i].indexB);
            answer = v[i].dist;
        }
        // cout << v[i].dist << " " << v[i].indexA << " " << v[i].indexB << endl;
    }
    fout << answer;

}