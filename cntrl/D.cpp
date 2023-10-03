#include <iostream> 
#include <queue> 
#include <cstring> 
using namespace std; 
 
const int N = 1e6 + 5; 
 
int p, k; 
bool a[N]; 
 
bool canReach(int x){ 
    queue <int> q; 
    bool visited[p]; 
    memset(visited, false, sizeof visited); 
    q.push(0); 
    visited[0] = true; 
    int jumps = 0; 
    int last = 0; 
    while(!q.empty()){ 
        int size = q.size(); 
        while(size--){ 
            int curr = q.front(); 
            q.pop(); 
            if(curr == p - 1) return true; 
            for(int i = max(last, curr - x); i <= min(p - 1, curr + x); i++){ 
                if(a[i] && !visited[i]){ 
                    visited[i] = true; 
                    q.push(i); 
                } 
            } 
        } 
        last = q.back(); 
        jumps++; 
        if(jumps > k) return false; 
    } 
    return false; 
} 
 
int main() { 
    cin >> p; 
    for(int i = 0; i < p; i++){ 
        int x; 
        cin >> x; 
        a[i] = x; 
    } 
    cin >> k; 
    int lo = 0, hi = p - 1; 
    int ans = 0; 
    while(lo <= hi){ 
        int mid = lo + (hi - lo) / 2; 
        if(canReach(mid)){ 
            ans = mid; 
            hi = mid - 1; 
        }else{ 
            lo = mid + 1; 
        } 
    } 
    cout << ans; 
}