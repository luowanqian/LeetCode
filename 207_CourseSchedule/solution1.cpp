#include <iostream>
#include <vector>
using namespace std;

class Solution {
    bool m_finish = true;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> digraph(numCourses);

        int v, w;
        for (auto i=0; i!=prerequisites.size(); i++) {
            w = prerequisites[i][0];
            v = prerequisites[i][1];
            digraph[v].push_back(w);
        }

        vector<bool> marked(numCourses, false);
        vector<bool> on_stack(numCourses, false);
        for (int v=0; v!=numCourses; v++) {
            if (!marked[v]) {
                dfs(digraph, v, marked, on_stack);
            }
        }

        return m_finish;
    }

    void dfs(vector<vector<int>>& digraph, int v, vector<bool>& marked, vector<bool>& on_stack) {
        on_stack[v] = true;
        marked[v] = true;

        int w;
        vector<int>& adj = digraph[v];
        for (auto i=0; i!=adj.size(); i++) {
            w = adj[i];
            if (on_stack[w]) {
                m_finish = false;
                return;
            } else if (!marked[w])
                dfs(digraph, w, marked, on_stack);
        }

        on_stack[v] = false;
    }
};

void test(int num_courses, vector<vector<int>>& prerequisites)
{
    Solution solu;
    cout << solu.canFinish(num_courses, prerequisites) << endl;
}

int main()
{
    int num_courses;

    num_courses = 4;
    vector<vector<int>> prerequisites1;
    vector<int> edge1_1 = {3, 0};
    vector<int> edge1_2 = {0, 1};
    prerequisites1.push_back(edge1_1);
    prerequisites1.push_back(edge1_2);
    // desire true
    test(num_courses, prerequisites1);

    num_courses = 2;
    vector<vector<int>> prerequisites2;
    vector<int> edge2_1 = {0, 1};
    vector<int> edge2_2 = {1, 0};
    prerequisites2.push_back(edge2_1);
    prerequisites2.push_back(edge2_2);
    // desire false
    test(num_courses, prerequisites2);


    num_courses = 2;
    vector<vector<int>> prerequisites3;
    vector<int> edge3_1 = {1, 0};
    prerequisites3.push_back(edge3_1);
    // desire true
    test(num_courses, prerequisites3);

    return 0;
}