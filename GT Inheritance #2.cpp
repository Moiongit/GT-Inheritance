#include<iostream>
#include<iomanip>
using namespace std;

class Number{
    private:
    int rawValue;

    public:
    Number (int rawValue): rawValue(rawValue){}

        void setRawValue(int r) {
            rawValue = r;
        }

        int getRawValue(){ 
            return rawValue;
        }
};

class WholeNumber: public Number{
    public:
    WholeNumber(int value): Number(value) {}

    void multiply(WholeNumber otherWhole) {
        setRawValue(getRawValue() * otherWhole.getRawValue());
    }

    string toString() {
        return to_string(getRawValue());
    }
    
};

class DecimalNumber: public Number{
    private:
    int decimalPlaces;

    public:
    DecimalNumber(int value, int decimalPlaces): Number(value), decimalPlaces(decimalPlaces) {} // Fixed: Removed duplicate Number initialization

    int getDecimalPlaces() {
        return decimalPlaces;
    }

    void setDecimalPlaces(int d) {
        decimalPlaces = d;
    }

    void multiply(DecimalNumber decimalNumber) {
        setRawValue(getRawValue() * decimalNumber.getRawValue());
        decimalPlaces += decimalNumber.getDecimalPlaces(); // Adjust decimal places after multiplication
    }

    string toString() {
        double actualValue = getRawValue();
        for (int i = 0; i < decimalPlaces; ++i) {
            actualValue /= 10;
        }
      
        ostringstream stream;
        stream << fixed << setprecision(decimalPlaces) << actualValue; // Ensure correct decimal places
        return stream.str();
    }
};

int main() {
    // WHOLE NUMBER MULTIPLICATION
    int whole1, whole2;
    cout << "Enter first whole number: ";
    cin >> whole1;
    cout << "Enter second whole number: ";
    cin >> whole2;

    WholeNumber w1(whole1);
    WholeNumber w2(whole2);
    w1.multiply(w2);

    cout << "WholeNumber Result (Multiplication): " << w1.toString() << endl;

    cout << endl;

    // DECIMAL NUMBER MULTIPLICATION
    int decRaw1, decPlaces1, decRaw2, decPlaces2;
    cout << "Enter first decimal number's raw value (e.g. 125 for 1.25): ";
    cin >> decRaw1;
    cout << "Enter number of decimal places for first decimal: ";
    cin >> decPlaces1;

    cout << "Enter second decimal number's raw value (e.g. 20 for 0.20): ";
    cin >> decRaw2;
    cout << "Enter number of decimal places for second decimal: ";
    cin >> decPlaces2;

    DecimalNumber d1(decRaw1, decPlaces1);
    DecimalNumber d2(decRaw2, decPlaces2);
    d1.multiply(d2);

    cout << "DecimalNumber Result (Multiplication): " << d1.toString() << endl;

    return 0;
}