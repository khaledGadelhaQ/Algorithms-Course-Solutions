#include<iostream>
#include <bits/stdc++.h>

using namespace std;

/*

Time and space complexity:

Let (n) be the total number of employees and (m) be the total number of subordinates in the input.

1. Building the Map: Building the unordered map `mp` from the list of employees would take O(n) time.
2. Depth-First Search (DFS): Traversing the employee's hierarchy using DFS would take O(m) time because it potentially traverses each subordinate once.

Therefore, the overall time complexity of the solution is O(n + m).

Regarding space complexity, the main contributor is the unordered map `mp` that stores the employees. The space complexity can be considered as O(n) since the map can potentially store all the employees. Additionally, the recursive DFS call stack will also contribute to the space complexity, which can be O(m) in the worst case if the employee hierarchy resembles a linked list.

In summary:

- Time Complexity: O(n + m)
- Space Complexity: O(n + m)

*/

// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp;
        for (auto employee : employees) {
            mp[employee->id] = employee;
        }
        return dfs(mp, id);
    }

    int dfs(unordered_map<int, Employee*> &mp, int id) {
        int sum = mp[id]->importance;
        for (auto subordinate : mp[id]->subordinates) {
            sum += dfs(mp, subordinate);
        }
        return sum;
    }
};

int main(){
    return 0 ;
}