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

        virtual void displayInfo() const {
            cout << "Title: " << getTitle() << ", Year Created: " << getYearCreated() << endl;
        }

        virtual ~ArtPiece() {
            cout << "Destructor called for ArtPiece: " << title << endl;
        }
};

class Painting : public ArtPiece {
    private:
        string medium;

    public:
        Painting() : ArtPiece() {
            medium = "Unknown Medium";
        }

        Painting(string t, int y, string m) : ArtPiece(t, y) {
            medium = m;
        }

        void displayInfo() const  {
            ArtPiece::displayInfo();
            cout << "Medium: " << medium << endl;
        }

        ~Painting() {
            cout << "Destructor called for Painting" << endl;
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

class ModernArtist : public Artist {
    private:
        string style;

    public:
        ModernArtist(string n, ArtPiece* art, string s) : Artist(n, art) {
            style = s;
        }

        void displayInfo() const {
            Artist::displayInfo();
            cout << "Style: " << style << endl;
        }
};

int main() {
    Painting* painting = new Painting("Starry Night", 1889, "Oil on Canvas");
    ModernArtist* artist1 = new ModernArtist("Vincent van Gogh", painting, "Post-Impressionism");

    artist1->displayInfo();
    artist1->updateArtYear(2024);
    artist1->displayInfo();

    delete artist1;

    return 0;
}
