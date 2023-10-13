
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

// this is a Breadth first search solution (BFS)

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
        int sum {0};
        queue<Employee*> q;
        q.push(mp[id]);
        while(!q.empty()){
            auto front = q.front(); 
            q.pop();
            for(auto employee : front->subordinates){
              q.push(mp[employee]);
            }
            sum += front->importance;

        }
        return sum;
    }
};

int main(){
    return 0;
}