
#include <iostream>
#include <sstream>

using namespace std;
int main() {

  stringstream mystream;
  mystream.seekp(0, ios::beg);
  mystream << "Sorting";


  
  cout << mystream.str() << endl;
  return 0;

}
