#include "map.h";
#include "rngFunctions.h"
#include <random>

using namespace std;

void Map::init(int w, int h) {
	this->w = w;
	this->h = h;
	mapData.resize(w * h);

	ranlux24_base rng(random_device{}());
	for (auto& e : mapData) { 
		// Change the rng function used here to experiment
		//e = getRandomBool(rng); // set each element to true / false
		e = getRand();
	} 
}