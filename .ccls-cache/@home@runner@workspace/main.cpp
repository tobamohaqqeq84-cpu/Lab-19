//Toba Mohaqqeq
//COMSC-210
//LAB-19


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
 using namespace std;

    struct Review {
        double rating;
        string comment;
        Review* next;
    };
    class Movie {
        private:
            string title;
            Review* head;
        public:
            Movie (string t = "Untitled") {
              title = t;
              head = nullptr;
            }
~Movie() {
  Review* current = head;
  while (current){
    Review* temp =current;
    current = current->next;
    delete temp;
  }
  head = nullptr;
}
void addReview(double rating, const string& comment){
    Review* newReview = new Review;
    newReview->rating = rating;
    newReview->comment = comment;
    newReview->next = head;
    head = newReview;
}
void displayReviews() const{
  cout << "\nMovie Title: " << title << endl;
  if (!head) {
    cout << "No reviews available." << endl;
    return;
  }
  Review* current = head;
  int count = 0;
  double total = 0; 

    while (current){
      cout << fixed << setprecision(1);
      cout << "    > Review #" << ++count << ": " << current->rating         << " - " << current->comment << endl;
      total += current->rating;
      current = current->next;
    }
  
}
}

    
