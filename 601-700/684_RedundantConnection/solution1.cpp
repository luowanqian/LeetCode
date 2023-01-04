#include <vector>
#include <iostream>
using namespace std;

class UF {
public:
    UF(int n);
    void connect(int p, int q);
    int find(int p);
    bool isConnected(int p, int q);
private:
    vector<int> m_id;
};

UF::UF(int n) : m_id(n)
{
    for (int i=0; i<n; i++)
        m_id[i] = i;
}

void UF::connect(int p, int q)
{
    m_id[find(p)] = find(q);
}

int UF::find(int p)
{
    while (p != m_id[p]) {
        p = m_id[p];
    }
    return p;
}

bool UF::isConnected(int p, int q)
{
    return find(p) == find(q);
}

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res;
        UF uf(edges.size()+1);
        for (int i=0; i<edges.size(); i++) {
            int p = edges[i][0];
            int q = edges[i][1];
            if (uf.isConnected(p, q)) {
                res.push_back(p);
                res.push_back(q);
                break;
            }
            uf.connect(p, q);
        }

        return res;
    }
};

int main()
{
    Solution solu;
    vector<vector<int>> edges = { {1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5} };
    vector<int> res = solu.findRedundantConnection(edges);
    for (int i=0; i<res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}