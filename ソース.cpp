#include<iostream>
#include<vector>
#include<random>
#include<fstream>
#include<algorithm>
using namespace std;

//�f���A��A�����𔻕ʂ���N���X�̒�`
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

//�f���𔻕ʂ���֐�
bool Prime(int number)
{
	if (number < 2) return false;//0��1�͑f���ł͂Ȃ�
	else if (number == 2) return true;//2�͑f��
	else if (number % 2 == 0) return false; // �����͂��炩���ߏ���

	double sqrtNum = sqrt(number);
	for (int i = 3; i <= sqrtNum; i += 2)
	{
		if (number % i == 0)
		{
			// �f���ł͂Ȃ�
			return false;
		}
	}
	// �f���ł���
	return true;
}

int main() {
	
	vector<distinction>v1;
	vector<distinction>v2;
	vector<distinction>v3;
	ifstream infile("����.txt");
	int x;
	int y = 0;
	int z = 0;
	int r = 0;
	while (infile >> x) {
		if (x % 2 == 0) {
			v1.emplace_back();
			v1[y].setevennumber(x);//�������i�[
			++y;
		}
		if (x % 2 != 0) {
			v2.emplace_back();
			v2[z].setoddnumber(x);//����i�[
			++z;
		}
		if (Prime(x) == true) {
			v3.emplace_back();
			v3[r].setprimenumber(x);//�f�����i�[
			++r;
		}
	}
	
	cout << "�������ȉ���3�ɔ��ʂ���"<<"\n";
	cout << "����"<<"\n";
	size_t s = v1.size();
	for (size_t i = 0;i < s;++i) {
		cout << v1[i].getevennumber() << ",";
	}
	
	cout <<"\n"<< "�"<<"\n";
	size_t t = v2.size();
	for (size_t j = 0;j < t;++j) {
		cout << v2[j].getoddnumber() << ",";
	}
	
	cout <<"\n"<< "�f��"<<"\n";
	size_t u = v3.size();
	for (size_t h = 0;h < u;++h) {
		cout << v3[h].getprimenumber() << ",";
	}
	
	cout << endl;
}
