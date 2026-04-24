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


    Ride operator+(const Ride &r) {
        Ride temp;
        temp.fare = this->fare + r.fare;
        return temp;
    }

    Ride operator-(const Ride &r) {
        Ride temp;
        temp.fare = this->fare - r.fare;
        return temp;
    }

    Ride operator*(float multiplier) {
        Ride temp;
        temp.fare = this->fare * multiplier;
        return temp;
    }

    bool operator==(const Ride &r) {
        return this->fare == r.fare;
    }

    bool operator<(const Ride &r) {
        return this->fare < r.fare;
    }

    friend ostream& operator<<(ostream &out, const Ride &r) {
        out << "Ride Fare: " << r.fare;
        return out;
    }
};

#endif
