#include <iostream>
#include <string>
using namespace std;

class ArtPiece {
    private:
        string title;
        int yearCreated;
    
    public:
        ArtPiece(string t, int y) {
            title = t;
            yearCreated = y;
        }

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
        Artist(string n, ArtPiece* art) {
            name = n;
            artwork = art;
        }

        void displayInfo() const {
            cout << "Artist: " << name << endl;
            artwork->displayInfo();
        }

        void updateArtYear(int newYear) {
            artwork->setYearCreated(newYear);
        }
};

int main() {
    ArtPiece* art1 = new ArtPiece("Starry Night", 1889);
    Artist* artist1 = new Artist("Vincent van Gogh", art1);

    artist1->displayInfo();

    artist1->updateArtYear(2024);
    artist1->displayInfo();

    delete artist1;
    delete art1;

    return 0;
}
