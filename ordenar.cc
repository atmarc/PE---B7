#include <iostream>
#include <vector>
#include <map> 

using namespace std;

int main () {
    int x, y;
    map <long int,int> m;
    while (cin >> x >> y) {
        pair <long int,int> p = make_pair(x,y);
        m.insert(p);
    }
    auto it = m.begin();
    while (it != m.end()) {
        cout << it->first << ' ' << it->second << endl;
        ++it;
    }
}