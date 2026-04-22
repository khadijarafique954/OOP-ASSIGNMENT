#include "YourLibrary.h"

int main() {

    // 🔹 Object creation (constructor overloading)
    Ride r1;
    Ride r2(12, 6);
    Ride r3 = r2;

    // 🔹 Function overloading demonstration
    cout << "Default Fare: " << r2.calculateFare() << endl;
    cout << "Rate-based Fare: " << r2.calculateFare(15) << endl;
    cout << "Full custom Fare: " << r2.calculateFare(15, 3) << endl;

    // 🔹 Operator overloading demonstration
    Ride combined = r2 + r3;
    Ride diff = r2 - r3;
    Ride surge = r2 * 1.5;

    cout << combined << endl;
    cout << diff << endl;
    cout << surge << endl;

    // 🔹 Comparison operators
    if (r2 == r3)
        cout << "Fares are equal\n";

    if (r2 < surge)
        cout << "Original ride is cheaper than surged ride\n";

    return 0;
}
