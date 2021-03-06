#include<iostream>
#include<vector>
#include<random>
#include<fstream>
#include<algorithm>
using namespace std;

//素数、奇数、偶数を判別するクラスの定義
class distinction {
	int primenumber;
	int oddnumber;
	int evennumber;
public:
	void setprimenumber(int newprimenumber) { primenumber = newprimenumber; }
	int getprimenumber() { return primenumber; }
	void setoddnumber(int newoddnumber) { oddnumber = newoddnumber; }
	int getoddnumber() { return oddnumber; }
	void setevennumber(int newevennumber) { evennumber = newevennumber; }
	int getevennumber() { return evennumber; }
};

//素数を判別する関数
bool Prime(int number)
{
	if (number < 2) return false;//0と1は素数ではない
	else if (number == 2) return true;//2は素数
	else if (number % 2 == 0) return false; // 偶数はあらかじめ除く

	double sqrtNum = sqrt(number);
	for (int i = 3; i <= sqrtNum; i += 2)
	{
		if (number % i == 0)
		{
			// 素数ではない
			return false;
		}
	}
	// 素数である
	return true;
}

int main() {
	
	vector<distinction>v1;
	vector<distinction>v2;
	vector<distinction>v3;
	ifstream infile("乱数.txt");
	int x;
	int y = 0;
	int z = 0;
	int r = 0;
	while (infile >> x) {
		if (x % 2 == 0) {
			v1.emplace_back();
			v1[y].setevennumber(x);//偶数を格納
			++y;
		}
		if (x % 2 != 0) {
			v2.emplace_back();
			v2[z].setoddnumber(x);//奇数を格納
			++z;
		}
		if (Prime(x) == true) {
			v3.emplace_back();
			v3[r].setprimenumber(x);//素数を格納
			++r;
		}
	}
	
	cout << "乱数を以下の3つに判別する"<<"\n";
	cout << "偶数"<<"\n";
	size_t s = v1.size();
	for (size_t i = 0;i < s;++i) {
		cout << v1[i].getevennumber() << ",";
	}
	
	cout <<"\n"<< "奇数"<<"\n";
	size_t t = v2.size();
	for (size_t j = 0;j < t;++j) {
		cout << v2[j].getoddnumber() << ",";
	}
	
	cout <<"\n"<< "素数"<<"\n";
	size_t u = v3.size();
	for (size_t h = 0;h < u;++h) {
		cout << v3[h].getprimenumber() << ",";
	}
	
	cout << endl;
}
