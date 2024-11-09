#include <iostream>
#include <string>
using namespace std;

class ArtPiece {
private:
    string title;
    int yearCreated;

public:
    ArtPiece(const string& t, int y) : title(t), yearCreated(y) {}

    string getTitle() const { return title; }
    int getYearCreated() const { return yearCreated; }
    void setYearCreated(int y) { yearCreated = y; }

    void displayInfo() const {
        cout << "Title: " << getTitle() << ", Year Created: " << getYearCreated() << endl;
    }
};

class Artist {
private:
    string name;
    ArtPiece* artwork;

public:
    Artist(const string& n, ArtPiece* art) : name(n), artwork(art) {}
    ~Artist() {
        delete artwork;
    }

    void displayInfo() const {
        cout << "Artist: " << name << endl;
        if (artwork) {
            artwork->displayInfo();
        } else {
            cout << "No artwork available." << endl;
        }
    }

    void updateArtYear(int newYear) {
        if (artwork) {
            artwork->setYearCreated(newYear);
        }
    }
};

int main() {
    ArtPiece* art1 = new ArtPiece("Starry Night", 1889);
    Artist* artist1 = new Artist("Vincent van Gogh", art1);

    artist1->displayInfo();

    artist1->updateArtYear(2024);
    artist1->displayInfo();

    delete artist1;

    return 0;
}
