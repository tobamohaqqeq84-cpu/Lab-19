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
  if (count > 0)
    cout << "   > Average Rating: " << (total /count) << endl;
}
};

vector<string> redCommentsFormFile (const string& filename){
  vector<string> comments;
  ifstream file(filename);

  if (!file){
    cerr << "Error: Could not open file  " << filename << "'." << endl;
    return comments;
  }
  string line;
  while(getline(file, line)){
    if (!line.empty())
      comments.push_back(line);
    
  }
  file.close();
  return comments;
}
double randomRating(){
  double r = (rand()% 41 +10)/10.0;
  return r;
  
}
 int main() {
   srand(time(0));
    vector<string> comments = redCommentsFormFile ("reviews.txt");
   if (comments.empty()) {
     cout << "No comments found. please check reviews." << endl;
     return 1;
   }

vector<Movie> movies = {
  Movie("The Shawshank Redemption"),
  Movie("The Godfather"),
  Movie("The Dark Knight"),
  Movie("The Godfather Part II"),
};
 for (auto& m : movies) {
   for (int i  = 0; i<3; i++){
     string comment = comments[rand() % comments.size()];
     double rating = randomRating();
     m.addReview(rating, comment);
     
   }
 }
cout << "Movie Reviews Summary" << endl;
for(auto& m : movies)
  m.displayReviews();

      return 0;}

