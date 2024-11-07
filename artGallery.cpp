#include <iostream>
#include <vector>
using namespace std;

class ArtPiece {
public:
    string title;
    string artist;
    string medium;
    int yearCreated;

    ArtPiece(string t, string a, string m, int y) {
        title = t;
        artist = a;
        medium = m;
        yearCreated = y;
    }

    void displayInfo() {
        cout << "Title - " << title << endl;
        cout << "Artist - " << artist << endl;
        cout << "Medium - " << medium << endl;
        cout << "Year Created - " << yearCreated << endl << endl;
    }

    void updateYear(int newYear) {
        yearCreated = newYear;
    }
};

class Artist {
public:
    string name;
    string style;
    vector<ArtPiece> artworks;

    Artist(string n, string s) {
        name = n;
        style = s;
    }

    void displayInfo() {
        cout << "Artist Name - " << name << endl;
        cout << "Artistic Style - " << style << endl;
        cout << "Artworks:" << endl;
         for (int i = 0; i < artworks.size(); i++) {
            artworks[i].displayInfo();
            cout << endl;   
        }
    }

    void addArtPiece(ArtPiece art) {
        artworks.push_back(art);
    }
};

int main() {
    Artist artist1("Vincent van Gogh", "Post-Impressionism");
    ArtPiece art1("Starry Night", "Vincent van Gogh", "Oil on Canvas", 1889);
    ArtPiece art2("Sunflowers", "Vincent van Gogh", "Oil on Canvas", 1888);

    artist1.addArtPiece(art1);
    artist1.addArtPiece(art2);

    artist1.displayInfo();

    art1.updateYear(2024);
    artist1.displayInfo();

    return 0;
}
