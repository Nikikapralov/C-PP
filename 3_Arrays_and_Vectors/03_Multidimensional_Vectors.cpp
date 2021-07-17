#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector <int> vector_1;
    vector <int> vector_2;
    vector_1.push_back(10);
    vector_1.push_back(20);
    for (int i = 0; i < vector_1.size(); i++){
        cout << vector_1.at(i) << endl;
    }
    cout << "Size: " << vector_1.size() << endl;
    
    vector_2.push_back(1);
    vector_2.push_back(2);
    for (int i = 0; i < vector_2.size(); i++){
        cout << vector_2.at(i) << endl;
    }
    cout << "Size: " << vector_2.size() << endl;
    
    vector <vector<int>> vector_2d;
    vector_2d.push_back(vector_1);
    vector_2d.push_back(vector_2);
    
    cout << vector_2d.at(0).at(0) << endl;
    
    
}
