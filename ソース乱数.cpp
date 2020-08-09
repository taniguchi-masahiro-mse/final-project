#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<random>
using namespace std;

int main() {
	vector<int>vec;
	ofstream outfile("—”.txt");
	random_device engine;
	uniform_int_distribution<unsigned>dist(1, 99);
	for (int i = 0;i < 20;++i) {
		vec.push_back(dist(engine));
	}
	sort(vec.begin(), vec.end());
	size_t m = vec.size();
	for (size_t k = 0;k < m;++k) {
		outfile << vec[k] << "\n";
	}
}