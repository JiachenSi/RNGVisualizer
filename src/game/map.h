#include <vector>
#include <random>

using namespace std;

struct Map {
	int w ;
	int h;
	vector<bool> mapData;

	void init(int w, int h);
};



