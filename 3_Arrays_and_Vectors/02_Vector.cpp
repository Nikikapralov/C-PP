#include <vector>
using namespace std;

vector<int> use_vector() {
    vector <int> vec {10, 20, 30, 40, 50};
    vec.at(0) = 100;
    vec.at(4) = 1000;
    return vec;
}