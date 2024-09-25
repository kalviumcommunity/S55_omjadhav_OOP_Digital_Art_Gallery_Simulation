#include <iostream>
#include <string>
using namespace std;

class ArtPiece {
    private:
        string title;
        int yearCreated;

    public:
        ArtPiece() {
            title = "Unknown";
            yearCreated = 0;
        }

        ArtPiece(string t, int y) {
            setTitle(t);
            setYearCreated(y);
        }

        string getTitle() const { return title; }
        int getYearCreated() const { return yearCreated; }

        void setTitle(string t) { title = t; }
        void setYearCreated(int y) {
            if (y > 0) {
                yearCreated = y;
            } else {
                cout << "Invalid Year!" << endl;
            }
        }

        void displayInfo() const {
            cout << "Title: " << getTitle() << ", Year Created: " << getYearCreated() << endl;
        }

        ~ArtPiece() {
            cout << "Destructor called for ArtPiece: " << title << endl;
        }
};

class Artist {
    private:
        string name;
        ArtPiece* artwork;

    public:
        Artist() {
            name = "Unknown Artist";
            artwork = nullptr;
        }

        Artist(string n, ArtPiece* art) {
            setName(n);
            artwork = art;
        }

        string getName() const { return name; }
        void setName(string n) {
            if (!n.empty()) {
                name = n;
            } else {
                cout << "Invalid Name!" << endl;
            }
        }

        void displayInfo() const {
            cout << "Artist: " << getName() << endl;
            if (artwork != nullptr) {
                artwork->displayInfo();
            }
        }

        void updateArtYear(int newYear) {
            if (artwork != nullptr) {
                artwork->setYearCreated(newYear);
            }
        }

        ~Artist() {
            cout << "Destructor called for Artist: " << name << endl;
            delete artwork;
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
