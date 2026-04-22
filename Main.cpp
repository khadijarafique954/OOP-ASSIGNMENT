#include "YourLibrary.h"

int main() {

    // 🔹 Constructor overloading
    Ride r1;                  // default
    Ride r2(10, 5);           // parameterized
    Ride r3 = r2;             // copy

    // 🔹 Function overloading
    cout << "Default Fare: " << r2.calculateFare() << endl;
    cout << "Custom KM Rate: " << r2.calculateFare(15) << endl;
    cout << "Full Custom: " << r2.calculateFare(15, 3) << endl;

    // 🔹 Operator overloading
    Ride total = r2 + r3;
    Ride diff = r2 - r3;
    Ride surge = r2 * 1.5;

    cout << total << endl;
    cout << diff << endl;
    cout << surge << endl;

    if (r2 == r3)
        cout << "Both rides have equal fare\n";

    if (r2 < surge)
        cout << "Original ride is cheaper than surged ride\n";

    return 0;
}
