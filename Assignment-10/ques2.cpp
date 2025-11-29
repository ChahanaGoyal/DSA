#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
void findCommon(vector<int> &B,unordered_set<int> &hashSet){
    cout << "Common elements: ";
    for(int num : B) {
        if(hashSet.find(num) != hashSet.end()) {
            cout << num << " ";
        }
    }
}
int main() {
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {3, 4, 5, 6};
    unordered_set<int> hashSet;
    for(int num : A) {
        hashSet.insert(num);
    }
    findCommon(B,hashSet);
    return 0;
}