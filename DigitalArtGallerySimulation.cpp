#include <iostream>
#include <string>
using namespace std;


class ArtPiece {
private:
    string title;
    string artist;

public:
    ArtPiece(string title, string artist)
        : title(title), artist(artist) {}


    bool hasSameTitle(const ArtPiece& other) const {
        return this->title == other.title;
    }

    void display() const {
        cout << "Title: " << title << ", Artist: " << artist << endl;
    }
};

int main() {
    ArtPiece art1("Starry Night", "Vincent van Gogh");
    ArtPiece art2("Starry Night", "Another Artist");

    art1.display();
    art2.display();

    if (art1.hasSameTitle(art2)) {
        cout << "Both artworks have the same title." << endl;
    } else {
        cout << "The artworks have different titles." << endl;
    }

    return 0;
}
