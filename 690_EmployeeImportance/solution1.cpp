#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};


class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        if (employees.empty())
            return 0;

        int value;
        queue<Employee*> employee_queue;
        unordered_map<int, Employee*> employee_map;

        for (auto it=employees.begin(); it!=employees.end(); ++it)
            employee_map.insert(make_pair((*it)->id, *it));

        Employee *employe = employee_map.find(id)->second;
        employee_queue.push(employe);
        value = 0;
        while (!employee_queue.empty()) {
            employe = employee_queue.front();
            value += employe->importance;

            for (auto it=employe->subordinates.begin();
                 it!=employe->subordinates.end(); ++it)
                employee_queue.push(employee_map.find(*it)->second);

            employee_queue.pop();
        }

        return value;
    }
};

int main()
{
    Employee employee1 = {1, 2, {2}};
    Employee employee2 = {2, 3, {3}};
    Employee employee3 = {3, 5};
    vector<Employee*> emplyees = {&employee1, &employee2, &employee3};

    for (auto it=emplyees.begin(); it!=emplyees.end(); ++it) {
        cout << "[" << (*it)->id << ", "
             << (*it)->importance << ", [";
        vector<int> subordinates = (*it)->subordinates;
        for (auto it2=subordinates.begin(); it2!=subordinates.end(); ++it2)
            cout << *it2 << ", ";
        cout << "]]" << endl;
    }

    Solution solu;
    int id = 1;
    int value = solu.getImportance(emplyees, id);
    cout << "Total value: " << value << endl;

    return 0;
}
