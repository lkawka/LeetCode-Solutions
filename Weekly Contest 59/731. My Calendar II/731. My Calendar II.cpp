class MyCalendarTwo {
private:
    vector<pair<int, int> > events;
    
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        end--;
        int overbooked = 0;
        vector<pair<int, int> > booked;
        for(auto& event: events) {
            if(!((start < event.first && end < event.first)||(start > event.second && end > event.second))){
                for(auto& b: booked) {
                    if(!((b.first < event.first && b.second < event.first)||(b.first > event.second && b.second > event.second))) {
                        return false;
                    }
                }
                booked.push_back(event);
            }
        }
        events.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */