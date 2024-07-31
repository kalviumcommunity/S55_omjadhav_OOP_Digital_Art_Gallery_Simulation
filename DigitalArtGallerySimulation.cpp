#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ArtPiece {
private:
    string title;
    string artist;
    string medium;

public:
    ArtPiece(string t, string a, string m)
        : title(t), artist(a), medium(m) {}

    void display() const {
        cout << "Title: " << title << ", Artist: " << artist
             << ", Medium: " << medium << endl;
    }
};

class Gallery {
private:
    vector<ArtPiece> artworks;

public:
    void addArtPiece(const ArtPiece& art) {
        artworks.push_back(art);
    }

    void showArtworks() const {
        for (const auto& art : artworks) {
            art.display();
        }
    }
};

class User {
protected:
    string name;

public:
    User(string n) : name(n) {}
    virtual void interact() const = 0;
};

class Artist : public User {
public:
    Artist(string n) : User(n) {}

    void interact() const override {
        cout << "Artist " << name << " is creating art." << endl;
    }
};

class Visitor : public User {
public:
    Visitor(string n) : User(n) {}

    void interact() const override {
        cout << "Visitor " << name << " is viewing the gallery." << endl;
    }
};

int main() {
    ArtPiece art1("Starry Night", "Vincent van Gogh", "Oil on canvas");
    ArtPiece art2("Mona Lisa", "Leonardo da Vinci", "Oil on wood");

    Gallery gallery;
    gallery.addArtPiece(art1);
    gallery.addArtPiece(art2);

    gallery.showArtworks();

    Artist artist("Vincent");
    Visitor visitor("John");

    artist.interact();
    visitor.interact();

    return 0;
}
