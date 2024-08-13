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
        this->title = t;
        this->artist = a;
        this->medium = m;
        this->yearCreated = y;
    }

    void displayInfo() {
        cout << "Title - " << this->title << endl;
        cout << "Artist - " << this->artist << endl;
        cout << "Medium - " << this->medium << endl;
        cout << "Year Created - " << this->yearCreated << endl << endl;
    }

    void updateYear(int newYear) {
        this->yearCreated = newYear;
    }
};

class Artist {
public:
    string name;
    string style;
    vector<ArtPiece> artworks;

    Artist(string n, string s) {
        this->name = n;
        this->style = s;
    }

    void displayInfo() {
        cout << "Artist Name - " << this->name << endl;
        cout << "Artistic Style - " << this->style << endl;
        cout << "Artworks:" << endl;
        for (auto &art : this->artworks) {
            art.displayInfo();
        }
    }

    void addArtPiece(ArtPiece art) {
        this->artworks.push_back(art);
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
