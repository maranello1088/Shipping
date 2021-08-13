/*
    Shipping cost calculator

    Ask the user for package dimension in inches
    length, width, height - these should be integers

    All dimension must be 10 inches or less or we cannot ship it

    Base cost $2.50
    If package volume is greater than 100 cubic inches there is a 10% surcharge
    If package volume is greater than 500 cubic inches there is a 25% surcharge

*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    int length{}, width{}, height{};
    double baseCost{ 2.50 };

    const int tier1Threshold{ 100 };    // volume
    const int tier2Threshold{ 500 };    // volume

    const int maxDimensionLength{ 10 };  // in inches

    double tier1Surcharge{ 0.10 };  // 10% extra
    double tier2Surcharge{ 0.25 };  // 25% extra

    // All dimension must be 10 inches or less

    int packageVolume{};

    cout << "=======Welcome to the package cost calculator=======" << endl;
    cout << "Enter length, width, and height of the package separated by spaces : ";
    cin >> length >> width >> height;

    if (length > maxDimensionLength || width > maxDimensionLength || height > maxDimensionLength) {
        cout << "Sorry, package rejected - dimension exceeded" << endl;
    }
    else {
        double packageCost{};
        packageVolume = length * width * height;
        packageCost = baseCost;

        if (packageVolume > tier2Threshold) {
            packageCost += packageCost * tier2Surcharge;
            cout << " adding tier 2 surcharge " << endl;
        }
        else if (packageVolume > tier1Threshold) {
            packageCost += packageCost * tier1Surcharge;
            cout << " adding tier 1surcharge " << endl;
        }

        cout << fixed << setprecision(2); // This would set the precision to 2dp. To create a proper Dollar and cent value e.g $2.55 cents 
        cout << "The volume of your package is: " << packageVolume << endl;
        cout << "Your package will cost $" << packageCost << " to ship " << endl;

    }
    cout << endl;
    return 0;
}

