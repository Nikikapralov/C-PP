#include<vector>
#include<algorithm>

using std::vector, std::find;
template <typename type>

bool contains(vector<type> vec, type value) {
	if (find(vec.begin(), vec.end(), value) != vec.end()) {
		return true;
	}
	return false;
}

