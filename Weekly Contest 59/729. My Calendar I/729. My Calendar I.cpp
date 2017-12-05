class MyCalendar {
private:
    vector<pair<int, int> > events;
    
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto& event: events) {
            if(!((start < event.first && end <= event.first)||(start > event.second && end-1 > event.second)))
                return false;
        }
        events.push_back({start, end-1});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */