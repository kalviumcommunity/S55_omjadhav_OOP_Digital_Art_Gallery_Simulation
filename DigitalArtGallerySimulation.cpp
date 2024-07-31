#include <iostream>
#include <vector>
#include <string>
using namespace std;


class ArtPiece {
public:
    string title;
    string artist;
    string medium;
    string description;

    ArtPiece(string t, string a, string m, string d)
        : title(t), artist(a), medium(m), description(d) {}

    void display() const {
        cout << "Title: " << title << endl;
        cout << "Artist: " << artist << endl;
        cout << "Medium: " << medium << endl;
        cout << "Description: " << description << endl;
    }
};

int main() {

    ArtPiece art1("Starry Night", "Vincent van Gogh", "Oil on canvas",
                  "A dreamy interpretation of the artist's asylum room view.");

    art1.display();

    return 0;
}
