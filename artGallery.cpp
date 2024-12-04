#include <iostream>
#include <string>
using namespace std;

class ArtPiece {
private:
    string title;
    int yearCreated;

public:
    ArtPiece() : title("Unknown"), yearCreated(0) {}

    ArtPiece(const string &t, int y) : title(t), yearCreated(y > 0 ? y : 0) {}

    string getTitle() const { return title; }
    int getYearCreated() const { return yearCreated; }

    void setTitle(const string &t) { title = t; }
    void setYearCreated(int y) {
        if (y > 0) {
            yearCreated = y;
        } else {
            cout << "Invalid Year!" << endl;
        }
    }

    virtual void displayInfo() const {
        cout << "Title: " << title << ", Year Created: " << yearCreated << endl;
    }

    virtual ~ArtPiece() {
        cout << "Destructor called for ArtPiece: " << title << endl;
    }
};

class Painting : public ArtPiece {
private:
    string medium;

public:
    Painting() : ArtPiece(), medium("Unknown Medium") {}

    Painting(const string &t, int y, const string &m) : ArtPiece(t, y), medium(m) {}

    string getMedium() const { return medium; }
    void setMedium(const string &m) { medium = m; }

    void displayInfo() const   {
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

public:
    Artist() : name("Unknown Artist") {}

    explicit Artist(const string &n) : name(n) {}

    string getName() const { return name; }
    void setName(const string &n) {
        if (!n.empty()) {
            name = n;
        } else {
            cout << "Invalid Name!" << endl;
        }
    }

    virtual void displayInfo() const {
        cout << "Artist: " << name << endl;
    }

    virtual ~Artist() {
        cout << "Destructor called for Artist: " << name << endl;
    }
};

class ModernArtist : public Artist {
private:
    string style;

public:
    ModernArtist(const string &n, const string &s) : Artist(n), style(s) {}

    string getStyle() const { return style; }
    void setStyle(const string &s) { style = s; }

    void displayInfo() const   {
        Artist::displayInfo();
        cout << "Style: " << style << endl;
    }

    ~ModernArtist() {
        cout << "Destructor called for ModernArtist" << endl;
    }
};

class Exhibition {
private:
    Artist* artist;
    ArtPiece* artwork;

public:
    Exhibition(Artist* a, ArtPiece* art) : artist(a), artwork(art) {}

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
    Painting* painting = new Painting("Starry Night", 1889, "Oil on Canvas");
    ModernArtist* artist1 = new ModernArtist("Vincent van Gogh", "Post-Impressionism");

    Exhibition* exhibit = new Exhibition(artist1, painting);

    exhibit->displayExhibit();
    exhibit->updateArtYear(2024);
    exhibit->displayExhibit();

    delete exhibit;

    return 0;
}
