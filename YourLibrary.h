#ifndef YOUR_LIBRARY_H
#define YOUR_LIBRARY_H

#include <iostream>
using namespace std;

class Ride {
private:
    float distance;
    float duration;
    float fare;

public:

    // 🔹 Function Overloading (Initialization methods)

    Ride() {
        distance = 0;
        duration = 0;
        fare = 0;
    }

    Ride(float d, float t) {
        distance = d;
        duration = t;
        fare = calculateFare();
    }

    Ride(const Ride &r) {
        distance = r.distance;
        duration = r.duration;
        fare = r.fare;
    }

    // 🔹 Function Overloading (Fare Calculation)
    float calculateFare() {
        fare = 50 + distance * 10 + duration * 2;
        return fare;
    }

    float calculateFare(float perKmRate) {
        fare = 50 + distance * perKmRate + duration * 2;
        return fare;
    }

    float calculateFare(float perKmRate, float perMinRate) {
        fare = 50 + distance * perKmRate + duration * perMinRate;
        return fare;
    }

    // 🔹 Operator Overloading

    // + (combine rides)
    Ride operator+(const Ride &r) {
        Ride temp;
        temp.fare = this->fare + r.fare;
        return temp;
    }

    // - (fare difference)
    Ride operator-(const Ride &r) {
        Ride temp;
        temp.fare = this->fare - r.fare;
        return temp;
    }

    // * (surge multiplier)
    Ride operator*(float multiplier) {
        Ride temp;
        temp.fare = this->fare * multiplier;
        return temp;
    }

    // == (compare fares)
    bool operator==(const Ride &r) {
        return this->fare == r.fare;
    }

    // < (cheaper ride check)
    bool operator<(const Ride &r) {
        return this->fare < r.fare;
    }

    // << (output display)
    friend ostream& operator<<(ostream &out, const Ride &r) {
        out << "Ride Fare: " << r.fare;
        return out;
    }
};

#endif
