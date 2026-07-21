class CountSquares {
    unordered_map<long long, int> pointCount;
    long long encode(int x, int y) {
        return static_cast<long long>(x) << 32 | static_cast<long long>(y);
    }
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        pointCount[encode(point[0], point[1])]++;
    }
    
    int count(vector<int> point) {
        int res = 0;
        int px = point[0];
        int py = point[1];
        for(auto[key, count]: pointCount) {
            int x = static_cast<int>(key >> 32);
            int y = static_cast<int>(key & 0xffffffff);

            if (abs(px - x) != abs(py - y) || px == x || py == y) continue;
            
            long long key1 = encode(px, y);
            long long key2 = encode(x, py);
            if (pointCount.contains(key1) && pointCount.contains(key2)) {
                res += (pointCount[key1] * pointCount[key2] * count);
            }
        }
        return res;
    }
};
