#include "27_Remove_element/remove_element.h"
#include <vector>



int main() {
    int result = remove_element(std::vector<int>({0,1,2,2,3,0,4,2}), 2);
    std::cout << result;
}
