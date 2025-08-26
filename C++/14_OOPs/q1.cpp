// Create a class 'book' with name, price and number of pages as its attributes. The class should contain following member functions :
// • countBooks(int price) : This function will return count of all the books that have a price less than the given price.
// • isBookPresent(string title) : This will return a boolean value indicating whether any book with the given title
#include<iostream>
using namespace std;
class book{
    public:
    string name;
    int price;
    int np;
    int countBooks(int p){
        if(price<p) return 1;
        else return 0;
    }
    bool isBookPresent(string title){
        if(name==title) return true;
        else return false;
    }
};
int main(){
    book harrypotter;
    harrypotter.name="harrypotter:india";
    harrypotter.price=779;
    harrypotter.np=349;
    cout<<harrypotter.countBooks(800)<<endl;
    cout<<harrypotter.isBookPresent("harrypotter:india");
    return 0;
}