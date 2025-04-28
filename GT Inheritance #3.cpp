#include <iostream>
using namespace std;

class Beverage {
private:
    string name;
    int volume;
    bool isChilled;

public:
    Beverage(string name, int volume, bool isChilled) : name(name), volume(volume), isChilled(isChilled) {}

    bool isEmpty() {
        return volume == 0;
    }

    string toString() {
        return name + " (" + to_string(volume) + "mL) " +
               (isChilled ? "Chilled" : "Not Chilled");
    }

    string getName() {
        return name;
    }

    int getVolume() {
        return volume;
    }

    bool getIsChilled() {
        return isChilled;
    }
};

class Water : public Beverage {
private:
    string type;

public:
    Water(int volume, bool isChilled, string type) : Beverage("Water", volume, isChilled), type(type) {}

    Water(int volume, bool isChilled) : Beverage("Water", volume, isChilled) {
        type = "Regular";
    }

    string getType() {
        return type;
    }
};

class Beer : public Beverage {
private:
    double alcoholicContent;

public:
    Beer(int volume, bool isChilled, double alcoholicContent) : Beverage("Beer", volume, isChilled), alcoholicContent(alcoholicContent) {}

    double getAlcoholicContent() {
        return alcoholicContent;
    }

    string getType() {
        if (alcoholicContent < 0.03)
            return "Flavored";
        else if (alcoholicContent < 0.06)
            return "Regular";
        else
            return "Strong";
    }
};

int main() {
    int volume;
    bool isChilled;
    string input, choice, waterType;

    // Water input
    cout << "Enter water volume (mL): ";
    cin >> volume;

    cout << "Is the water chilled? (yes/no): ";
    cin >> choice;
    if (choice == "yes") {
        isChilled = true;
    } else {
        isChilled = false;
    }

    cout << "Do you want to specify water type? (yes/no): ";
    cin >> choice;
    if (choice == "yes") {
        cout << "Enter water type (Purified, Regular, Distilled): ";
        cin >> waterType;
    } else {
        waterType = "Regular";
    }

    Water water(volume, isChilled, waterType);

    cout << "\nWater Details:\n";
    cout << water.getName() << " (" << water.getVolume() << "mL) is " 
         << (water.getIsChilled() ? "Chilled" : "Not Chilled") 
         << " [" << water.getType() << "]" << endl;

    cout << "\n----------------------------------------\n";

    // Beer input
    cout << "Enter beer volume (mL): ";
    cin >> volume;

    cout << "Is the beer chilled? (yes/no): ";
    cin >> choice;
    if (choice == "yes") {
        isChilled = true;
    } else {
        isChilled = false;
    }

    double alcoholicContent;
    cout << "Enter alcohol content (e.g., 0.045 for 4.5%): ";
    cin >> alcoholicContent;

    Beer beer(volume, isChilled, alcoholicContent);

    cout << "\nBeer Details:\n";
    cout << beer.getName() << " (" << beer.getVolume() << "mL) is " 
         << (beer.getIsChilled() ? "Chilled" : "Not Chilled anymore") 
         << " (" << alcoholicContent * 100 << "% alcoholic content) [" << beer.getType() << "]" << endl;

    return 0;
}
