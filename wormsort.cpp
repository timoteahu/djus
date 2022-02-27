#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

struct edge {
    int a, b, weight;
};

bool comp(edge a, edge b) {
    return a.weight > b.weight;
}

int n, m, cows[100001];
edge edges[100001];
set<int> needs_moving;
int main() {
    ifstream fin("wormsort.in");
    ofstream fout("wormsort.out");
    fin >> n >> m;

    for(int i = 1; i <= n; i++) {
        fin >> cows[i];
        if(i != cows[i])
            needs_moving.insert(i);
    }

    for(int i = 0; i < m; i++) {
        fin >> edges[i].a >> edges[i].b >> edges[i].weight;
    }

    sort(edges, edges + m, comp);

    int answer = 1e9 + 1;
    for(int i = 0; i < m; i++) {
        if(needs_moving.empty()) 
            break;
        edge value = edges[i];
        if(*needs_moving.find(value.a) == value.a)
            needs_moving.erase(value.a);
            
        if(*needs_moving.find(value.b) == value.b) 
            needs_moving.erase(value.b);
        answer = min(answer , value.weight);
    }
    if(answer == 1e9 + 1)
        fout << -1;
    else
        fout << answer;

    
}