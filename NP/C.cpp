#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

int main() {
    int x, y, n, ans = 0;
    
    std::cin >> n;
    
    std::set<int> stop;
    std::set<int> verices;
    std::vector<std::set<int>> adj(n);
    stop.clear();
    verices.clear();
    
    for (int i = 0; i != n; ++i) {
        adj[i].clear();
        stop.insert(i);
    }
    
    for (size_t i = 0; i != n; ++i) {
        std::cin >> y;
        
        for (size_t j = 0; j != y; ++j) {
            std::cin >> x;
            adj[i].insert(x);
        }
    }
    
    while (!stop.empty()) {
        for (size_t i = 0; i != n; ++i) {
            if (adj[i].size() == 0) {
                stop.erase(i);
            } else if (adj[i].size() == 1) {
                x = *adj[i].begin();
                stop.erase(i);
                stop.erase(x);
                adj[i].clear();
                adj[x].clear();
                verices.insert(x);
                
                for (size_t i = 0; i != n; ++i) {
                    if (adj[i].find(x) != adj[i].end()) {
                        adj[i].erase(x);
                    }
                }
            }
        }
        ans += verices.size();
        verices.clear();
    }
    std::cout << ans;
}
