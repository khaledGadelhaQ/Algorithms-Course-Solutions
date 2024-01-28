#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, char from, char to , char buffer){
    if(n == 0) return;
    hanoi(n-1, from , buffer, to);
    cout<< "Moving disk " << n << " from "<< from << " to " << to << endl;
    hanoi(n-1, buffer, to, from);
}

int main(){
    hanoi(3,'A','C','B');
    return 0;
}