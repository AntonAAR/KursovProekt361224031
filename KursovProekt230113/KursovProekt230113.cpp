#include <iostream>
#include <string>

using namespace std;

class RadioStation {
private:
    string name;
    float frequency;
    int quality;
    string status;

public:
    RadioStation(const string& n, float f, int q, const string& s)
        : name(n), frequency(f), quality(q), status(s) {
    }

    string getName() const {
        return name;
    }

    float getFrequency() const {
        return frequency;
    }

    int getQuality() const {
        return quality;
    }

    string getStatus() const {
        return status;
    }

    void setStatus(const string& newStatus) {
        status = newStatus;
    }

    void updateStatus() {
        if (quality > 45) {
            status = "visible";
        }
        else if (quality >= 35 && quality <= 45) {
            status = "grayed_out";
        }
        else {
            status = "not_visible";
        }
    }

    void printInfo() const {
        cout << "Radio Station Info:\n";
        cout << "Name: " << name << "\n";
        cout << "Frequency: " << frequency << " MHz\n";
        cout << "Quality: " << quality << "%\n";
        cout << "Status: " << status << "\n";
    }

    void inputData() {
        updateStatus();
    }

    static void searchByFrequency(const RadioStation stations[], int size, float targetFrequency) {
        bool found = false;
        for (int i = 0; i < size; ++i) {
            if (stations[i].getFrequency() == targetFrequency) {
                cout << "Found Radio Station with Frequency " << targetFrequency << " MHz:\n";
                stations[i].printInfo();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "No radio station found with Frequency " << targetFrequency << " MHz.\n";
        }
    }

    static void searchByName(const RadioStation stations[], int size, const string& targetName) {
        bool found = false;
        for (int i = 0; i < size; ++i) {
            if (stations[i].getName() == targetName) {
                cout << "Found Radio Station with Name '" << targetName << "':\n";
                stations[i].printInfo();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "No radio station found with Name '" << targetName << "'.\n";
        }
    }
};

int main() {
    RadioStation stations[6] = {
        RadioStation("Rock 1", 95.5, 60, "visible"),
        RadioStation("Jazz FM", 101.5, 40, "grayed_out"),
        RadioStation("Classical Music", 88.0, 25, "not_visible"),
        RadioStation("Vitosha", 104.3, 45, "grayed_out"),
        RadioStation("BBC News", 100.0, 70, "visible"),
        RadioStation("The Voice", 91.2, 33, "not_visible")
    };

    cout << "\nAll Radio Stations:\n";
    for (int i = 0; i < 6; ++i) {
        stations[i].printInfo();
        cout << "\n";
    }

    cout << "\nRadio stations with 'visible' status:\n";
    for (int i = 0; i < 6; ++i) {
        if (stations[i].getStatus() == "visible") {
            cout << "Name: " << stations[i].getName() << ", Frequency: " << stations[i].getFrequency() << " MHz\n";
        }
    }

    int choice;
    cout << "\nSearch for a radio station by:\n";
    cout << "1. Frequency\n";
    cout << "2. Name\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        float targetFrequency;
        cout << "Enter frequency to search for: ";
        cin >> targetFrequency;

        RadioStation::searchByFrequency(stations, 6, targetFrequency);
    }
    else if (choice == 2) {
        string targetName;
        cout << "Enter name to search for: ";
        cin.ignore();
        getline(cin, targetName);

        RadioStation::searchByName(stations, 6, targetName);
    }
    else {
        cout << "Invalid choice. Please select 1 or 2.\n";
    }

    return 0;
}
