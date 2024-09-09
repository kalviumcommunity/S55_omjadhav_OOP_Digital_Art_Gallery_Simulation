#include <iostream>
#include <string>
using namespace std;

class ArtPiece {
    public:
        string title;
        string artist;
        string medium;
        int yearCreated;
        static int totalArtPieces;   

        ArtPiece(string t, string a, string m, int y) {
            this->title = t;
            this->artist = a;
            this->medium = m;
            this->yearCreated = y;
            totalArtPieces++;   
        }

        void displayInfo() {
            cout << "Title: " << this->title << endl;
            cout << "Artist: " << this->artist << endl;
            cout << "Medium: " << this->medium << endl;
            cout << "Year Created: " << this->yearCreated << endl << endl;
        }

        void updateYear(int newYear) {
            this->yearCreated = newYear;
        }

        static void displayTotalArtPieces() {
            cout << "Total Art Pieces: " << totalArtPieces << endl;   
        }
};


int ArtPiece::totalArtPieces = 0;

class Artist {
    public:
        string name;
        string style;
        ArtPiece* artworks[2];
        static int totalArtists;   

        Artist(string n, string s, ArtPiece* art1, ArtPiece* art2) {
            this->name = n;
            this->style = s;
            this->artworks[0] = art1;
            this->artworks[1] = art2;
            totalArtists++;   
        }

        void displayInfo() {
            cout << "Artist: " << this->name << endl;
            cout << "Style: " << this->style << endl;
            cout << "Artworks:" << endl;
            for(int i = 0; i < 2; i++) {
                artworks[i]->displayInfo();  
            }
        }

        void updateArt(int index, int newYear) {
            artworks[index]->updateYear(newYear);  
        }

        ~Artist() {
            for(int i = 0; i < 2; i++) {
                delete artworks[i];
            }
        }

        static void displayTotalArtists() {
            cout << "Total Artists: " << totalArtists << endl;   
        }
};


int Artist::totalArtists = 0;

int main() {
    ArtPiece* art1 = new ArtPiece("Starry Night", "Vincent van Gogh", "Oil on canvas", 1889);
    ArtPiece* art2 = new ArtPiece("Sunflowers", "Vincent van Gogh", "Oil on canvas", 1888);
    ArtPiece* art3 = new ArtPiece("The Persistence of Memory", "Salvador Dali", "Oil on canvas", 1931);
    ArtPiece* art4 = new ArtPiece("Galatea of the Spheres", "Salvador Dali", "Oil on canvas", 1952);

    Artist* artist1 = new Artist("Vincent van Gogh", "Post-Impressionism", art1, art2);
    Artist* artist2 = new Artist("Salvador Dali", "Surrealism", art3, art4);

    Artist* artists[2] = {artist1, artist2};


    for(int i = 0; i < 2; i++) {
        artists[i]->displayInfo();
    }


    artists[0]->updateArt(0, 2024);
    artists[0]->displayInfo();


    ArtPiece::displayTotalArtPieces();
    Artist::displayTotalArtists();


    delete artist1;
    delete artist2;

    return 0;
}
