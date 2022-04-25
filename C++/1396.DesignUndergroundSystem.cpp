class UndergroundSystem {
public:
    //for storing check-in information in thr form - id : {stationName, arrival time}
    unordered_map<int, pair<string, int>> checkingIn;

    //for storing information while checking out int the form - station1_station2 : {time taken, count}
    unordered_map<string, pair<int, int>> checkingOut;

    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        //storing the check-in info
        checkingIn[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        //assigning the current check-in id information to checkIn
        auto checkIn = checkingIn[id];
        //erasing this record id here so that we don't count it repeatedly while updating the time
        checkingIn.erase(id);
        //storing the departure and arrival station names in a string
        string route = checkIn.first + " " + stationName;

        //storing the time taken to go from station A to station B
        checkingOut[route].first += t - checkIn.second;
        //incrementing the id count to further calculate the average
        checkingOut[route].second += 1;
    }

    double getAverageTime(string startStation, string endStation) {
        string routeTaken = startStation + " " +endStation;
        //path variable has the detail of customer id at the current station(checking out)
        auto& path = checkingOut[routeTaken];
        //the first variable stores the time take, the 2nd variable is the count of stations(start->end)
        return (double) path.first/path.second;
    }
};

/*
   Time Complexity : O(1)
   Space Complexity : O(n)
*/

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
