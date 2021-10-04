class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        d_id_checkIn[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string start = d_id_checkIn[id].first;
        int startTime = d_id_checkIn[id].second;
        string places = start + "+" + stationName;
        if (d_places_time.find(places) == d_places_time.end()) {
            d_places_time[places] = {t-startTime, 1};
        } else {
            d_places_time[places] = {d_places_time[places][0]+t-startTime, d_places_time[places][1]+1};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        double time = d_places_time[startStation + "+" + endStation][0];
        double count = d_places_time[startStation + "+" + endStation][1];
        return time/count;
    }
    
private:
    unordered_map<int, pair<string, int>> d_id_checkIn;
    unordered_map<string, vector<int>> d_places_time;   
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
