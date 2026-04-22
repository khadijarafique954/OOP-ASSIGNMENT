#include <iostream>
using namespace std;

class Ride {
private:
    int distance;
    int time;

public:
    Ride() {
        distance = 0;
        time = 0;
    }

    Ride(int d, int t) {
        distance = d;
        time = t;
    }

    Ride(const Ride &r) {
        distance = r.distance;
        time = r.time;
    }

    int calculateFare() {
        return distance * 10;
    }

    int calculateFare(int rate) {
        return distance * rate;
    }

    int calculateFare(int rate, int extra) {
        return (distance * rate) + (time * extra);
    }

    Ride operator + (Ride r) {
        return Ride(distance + r.distance, time + r.time);
    }

    Ride operator - (Ride r) {
        return Ride(distance - r.distance, time - r.time);
    }

    Ride operator * (float factor) {
        return Ride(distance * factor, time * factor);
    }

    bool operator == (Ride r) {
        return (distance == r.distance && time == r.time);
    }

    bool operator < (Ride r) {
        return (distance + time < r.distance + r.time);
    }

    friend ostream& operator << (ostream &out, Ride r) {
        out << "Distance: " << r.distance << ", Time: " << r.time;
        return out;
    }
};

int main() {
    Ride r1;
    Ride r2(12, 6);
    Ride r3 = r2;

    cout << r2.calculateFare() << endl;
    cout << r2.calculateFare(15) << endl;
    cout << r2.calculateFare(15, 3) << endl;

    Ride combined = r2 + r3;
    Ride diff = r2 - r3;
    Ride surge = r2 * 1.5;

    cout << combined << endl;
    cout << diff << endl;
    cout << surge << endl;

    if (r2 == r3)
        cout << "Fares are equal" << endl;

    if (r2 < surge)
        cout << "Original ride is cheaper than surged ride" << endl;

    return 0;
}
