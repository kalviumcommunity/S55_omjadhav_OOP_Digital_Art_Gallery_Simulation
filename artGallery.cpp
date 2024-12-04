#include <iostream>
#include <string>
using namespace std;

class ArtPiece {
public:
    virtual void displayInfo() const = 0;
    virtual void setYearCreated(int year) = 0;

};

class Painting : public ArtPiece {
private:
    string title;
    int yearCreated;
    string medium;

public:
    Painting(const string &t = "Unknown", int y = 0, const string &m = "Unknown Medium")
        : title(t), yearCreated(y > 0 ? y : 0), medium(m) {}

    void setYearCreated(int year)   {
        if (year > 0) yearCreated = year;
        else cout << "Invalid Year!" << endl;
    }

    void displayInfo() const   {
        cout << "Title: " << title << ", Year Created: " << yearCreated << ", Medium: " << medium << endl;
    }
};

class Artist {
public:
    virtual void displayInfo() const = 0;

};

class ModernArtist : public Artist {
private:
    string name;
    string style;

public:
    ModernArtist(const string &n = "Unknown Artist", const string &s = "Unknown Style")
        : name(n), style(s) {}

    void displayInfo() const   {
        cout << "Artist: " << name << ", Style: " << style << endl;
    }
};

class Exhibition {
private:
    Artist *artist;
    ArtPiece *artwork;

public:
    Exhibition(Artist *a, ArtPiece *art) : artist(a), artwork(art) {}

    void displayExhibit() const {
        if (artist) artist->displayInfo();
        if (artwork) artwork->displayInfo();
    }

    void updateArtYear(int newYear) {
        if (artwork) artwork->setYearCreated(newYear);
    }

  
};

int main() {
    Painting *painting = new Painting("Starry Night", 1889, "Oil on Canvas");
    ModernArtist *artist = new ModernArtist("Vincent van Gogh", "Post-Impressionism");

    Exhibition *exhibit = new Exhibition(artist, painting);

    cout << "Initial Exhibit Details:\n";
    exhibit->displayExhibit();

    exhibit->updateArtYear(2024);

    cout << "\nUpdated Exhibit Details:\n";
    exhibit->displayExhibit();

    delete exhibit;
    return 0;
}
