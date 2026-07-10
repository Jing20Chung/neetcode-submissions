class LRUCache {
private:
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> order;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            order.erase(it->second.second);
            order.push_back(key);
            it->second.second = --order.end();
            return it->second.first;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            order.erase(it->second.second);
        }
        order.push_back(key);
        if (order.size() > capacity) {
            cache.erase(order.front());
            order.pop_front();
        }
        cache[key] = {value, --order.end()};
    }
};
