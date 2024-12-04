#include <iostream>
#include <string>
using namespace std;

class ArtPiece {
private:
    string title;
    int yearCreated;

public:
    ArtPiece(const string &t = "Unknown", int y = 0) : title(t), yearCreated(y > 0 ? y : 0) {}

    string getTitle() const { return title; }
    int getYearCreated() const { return yearCreated; }

    void setTitle(const string &t) { title = t; }
    void setYearCreated(int y) {
        if (y > 0) yearCreated = y;
        else cout << "Invalid Year!" << endl;
    }

    virtual void displayInfo() const {
        cout << "Title: " << title << ", Year Created: " << yearCreated << endl;
    }

    virtual ~ArtPiece() = default;
};

class Painting : public ArtPiece {
private:
    string medium;

public:
    Painting(const string &t = "Unknown", int y = 0, const string &m = "Unknown Medium")
        : ArtPiece(t, y), medium(m) {}

    string getMedium() const { return medium; }
    void setMedium(const string &m) { medium = m; }

    void displayInfo() const override {
        ArtPiece::displayInfo();
        cout << "Medium: " << medium << endl;
    }
};

class Artist {
private:
    string name;

public:
    Artist(const string &n = "Unknown Artist") : name(n) {}

    string getName() const { return name; }
    void setName(const string &n) {
        if (!n.empty()) name = n;
        else cout << "Invalid Name!" << endl;
    }

    virtual void displayInfo() const {
        cout << "Artist: " << name << endl;
    }

    virtual ~Artist() = default;
};

class ModernArtist : public Artist {
private:
    string style;

public:
    ModernArtist(const string &n, const string &s) : Artist(n), style(s) {}

    string getStyle() const { return style; }
    void setStyle(const string &s) { style = s; }

    void displayInfo() const override {
        Artist::displayInfo();
        cout << "Style: " << style << endl;
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

    ~Exhibition() {
        delete artist;
        delete artwork;
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
