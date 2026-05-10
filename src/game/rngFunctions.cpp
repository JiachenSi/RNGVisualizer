#include <random>

using namespace std;

bool getRandomBool(ranlux24_base& rng) {
	uniform_int_distribution<int> dist(0, 1);
	return dist(rng);
}

bool getRand() {
	return rand() % 2;
}