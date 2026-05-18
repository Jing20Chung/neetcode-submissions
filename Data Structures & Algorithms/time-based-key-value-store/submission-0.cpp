class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> record;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        record[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (record.find(key) == record.end()) return "";

        const auto& data = record[key];
        string result = "";
        int l = 0, r = data.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (data[mid].first == timestamp) {
                return data[mid].second;
            }
            else if (data[mid].first > timestamp) {
                r = mid - 1;
            }
            else {
                result = data[mid].second;
                l = mid + 1;
            }
        }
        return result;
    }
};
