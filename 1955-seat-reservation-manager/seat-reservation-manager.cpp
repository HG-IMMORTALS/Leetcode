
class SeatManager {
private:
    set<int> seats; 

public:
    SeatManager(int n) {
        if (n <= 0) {
            throw invalid_argument("Invalid value of n.");
        }
        for (int i = 1; i <= n; ++i) {
            seats.insert(i);
        }
    }

    int reserve() {
        if (seats.empty()) {
            return -1; 
        }
        
        int reservedSeat = *seats.begin(); 
        seats.erase(reservedSeat); 
        return reservedSeat;
    }

    void unreserve(int seatNumber) {
        if (seatNumber > 0) {
            seats.insert(seatNumber);
        }
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */