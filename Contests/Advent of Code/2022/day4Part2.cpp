#include <iostream>
#include <string>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    string line;
    int ans = 0;
    
    while (getline(cin, line)) {
        size_t commaPos = line.find(',');
        
        string firstPair = line.substr(0, commaPos);
        string secondPair = line.substr(commaPos + 1);
        
        pair<int, int> p1, p2;
        p1.first = stoi(firstPair.substr(0, firstPair.find('-')));
        p1.second = stoi(firstPair.substr(firstPair.find('-') + 1));
        p2.first = stoi(secondPair.substr(0, secondPair.find('-')));
        p2.second = stoi(secondPair.substr(secondPair.find('-') + 1));
        
        if (p1.first <= p2.first && p1.second >= p2.first) {
            ans++;
        } else if (p2.first <= p1.first && p2.second >= p1.first) {
            ans++;
        }
    }
    
    cout << ans << endl;
    return 0;
}
