#include <iostream>
#include <cmath>


using namespace std;

long long chebyshev(long long r1, long long c1, long long r2, long long c2) {
    return max(abs(r1 - r2), abs(c1 - c2));
}

long long manhattan(long long r1, long long c1, long long r2, long long c2) {
    return abs(r1 - r2) + abs(c1 - c2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long n, rK, cK, rD, cD;
        cin >> n >> rK >> cK >> rD >> cD;
        
        long long cheb_dist = chebyshev(rK, cK, rD, cD);
        
        // If Doran can catch Krug on his first turn
        if (cheb_dist == 1) {
            cout << 1 << "\n";
            continue;
        }
        
        // Check if Krug can escape to infinity
        // Krug can escape if she can reach a corner before Doran catches her
        // and has enough room to maneuver
        
        // Calculate minimum moves for Krug to reach any corner
        long long krug_to_corner = min({rK + cK, rK + (n - cK), (n - rK) + cK, (n - rK) + (n - cK)});
        
        // Calculate minimum moves for Doran to reach the same corner or block Krug
        // Doran needs to reach a position where he can catch Krug
        long long doran_to_intercept = cheb_dist;
        
        // If Krug can reach a corner and Doran can't catch up in time
        // she might survive indefinitely
        if (krug_to_corner < doran_to_intercept) {
            cout << -1 << "\n";
            continue;
        }
        
        // Otherwise, calculate survival time
        // The survival time is roughly the Chebyshev distance
        // because Doran can close in by 1 per turn (assuming optimal play)
        
        // More precise: Krug tries to maximize distance, Doran tries to minimize
        // The game ends when Doran catches Krug
        
        // Key insight: Krug should move away from Doran optimally
        // If Krug is not near a boundary, she can maintain distance for longer
        
        // Calculate how far Krug is from boundaries
        long long dist_to_boundary = min({rK, cK, n - rK, n - cK});
        
        // If Krug has enough room and can maintain distance
        if (dist_to_boundary >= cheb_dist - 1) {
            cout << -1 << "\n";
        } else {
            // Krug will eventually be cornered
            // Survival time is roughly when she hits the boundary
            cout << dist_to_boundary + 1 << "\n";
        }
    }
    
    return 0;
}

// 7
// 2 0 0 1 1
// 3 1 1 0 1
// 1 1 0 0 1
// 6 1 3 3 2
// 9 4 1 4 1
// 82 64 2 63 2
// 1000000000 500000000 500000000 1000000000 0


