# Competitive Programming Questions Using Disjoint Set Unions (DSU)

This repository contains a curated collection of competitive programming problems and solutions involving **Disjoint Set Unions (DSU)**, also known as the **Union-Find** data structure. DSU is a powerful technique used to efficiently manage partitioned sets, particularly in problems involving connectivity and graph components.

---

## 📖 What is Disjoint Set Union?

The **Disjoint Set Union** data structure supports two main operations:
1. **Union(x, y)**: Merges the sets containing `x` and `y`.
2. **Find(x)**: Finds the representative (or "parent") of the set containing `x`.

By using **Path Compression** and **Union by Rank/Size**, DSU can efficiently perform these operations in nearly constant time, making it a popular choice for graph and set problems.

---

## 🏆 Problem Categories

### 1. **Graphs and Connectivity**
- Detecting connected components
- Checking if adding an edge creates a cycle
- Finding the number of connected components in a graph

### 2. **Minimum Spanning Tree**
- Implementation of **Kruskal's Algorithm** using DSU to find the MST of a graph.

### 3. **Dynamic Connectivity**
- Efficiently handling queries that add or remove edges and check connectivity in a dynamic graph.

### 4. **Advanced Problems**
- Problems involving merging sets with specific constraints (e.g., bipartite graphs, union size queries).

---

## 📘 Example Problems and Solutions

### Problem 1: Connected Components in a Graph
**Description**: Given a graph with `N` nodes and `M` edges, find the number of connected components.

**Solution**:
- Initialize a DSU with `N` elements.
- For each edge, perform a union operation to merge the connected nodes.
- After processing all edges, count the number of unique representatives using the `find` operation.

**Code**:
```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> parent, rank;

void make_set(int n) {
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;
}

int find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find(parent[v]); // Path compression
}

void union_sets(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    make_set(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        union_sets(u - 1, v - 1);
    }

    int connected_components = 0;
    for (int i = 0; i < n; i++) {
        if (find(i) == i) connected_components++;
    }
    cout << "Number of connected components: " << connected_components << endl;
}
