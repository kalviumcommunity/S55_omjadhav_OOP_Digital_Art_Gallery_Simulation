#include <iostream>
#include <string>
using namespace std;

class ArtPiece {
private:
    string pieceTitle;
    int creationYear;

public:
    ArtPiece(const string& title, int year) : pieceTitle(title), creationYear(year) {}

    string getTitle() const { return pieceTitle; }
    int getYearCreated() const { return creationYear; }
    void setYearCreated(int year) { creationYear = year; }

    void displayInfo() const {
        cout << "Art Title: " << getTitle() << ", Created In: " << getYearCreated() << endl;
    }
};

class Artist {
private:
    string artistName;
    ArtPiece* artwork;

public:
    Artist(const string& name, ArtPiece* art) : artistName(name), artwork(art) {}
    ~Artist() {
        delete artwork;
    }

    void displayArtistInfo() const {
        cout << "Artist: " << artistName << endl;
        if (artwork) {
            artwork->displayInfo();
        } else {
            cout << "No artwork available." << endl;
        }
    }

    void updateArtCreationYear(int newYear) {
        if (artwork) {
            artwork->setYearCreated(newYear);
        }
    }
};

int main() {
    ArtPiece* newArt = new ArtPiece("The Persistence of Memory", 1931);
    Artist* newArtist = new Artist("Salvador Dalí", newArt);

    newArtist->displayArtistInfo();

    newArtist->updateArtCreationYear(2024);
    newArtist->displayArtistInfo();

    delete newArtist;

    return 0;
}
