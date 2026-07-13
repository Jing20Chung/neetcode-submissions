class MyCalendar {
    map<int, int> booked;
public:
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        auto nextEvent = booked.upper_bound(startTime);
        if (nextEvent != booked.end() && nextEvent->first < endTime) {
            return false;
        }

        if (nextEvent != booked.begin()) {
            auto prevEvent = prev(nextEvent);
            if (prevEvent->second > startTime) {
                return false;
            }
        }

        booked[startTime] = endTime;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */