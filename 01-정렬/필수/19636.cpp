#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

// 변수를 구조체를 사용해서 잘 정리하지 못함

struct result {
	int weight;
	int meta;
	string stat;
};

result MetaWeight(int weight, int day, int cma, int meta, int limit) {

	result res;
	int con = meta;

	for (int i = 0; i < day; i++) {
		weight += cma;
		if (abs(cma) > limit) {
			meta += floor(static_cast<double>(cma) / 2);
			cma -= floor(static_cast<double>(cma) / 2);
		}
		if (weight <= 0 || meta <= 0) {
			res.stat = "Danger Diet";
			break;
		}
		if (con - meta > 0) res.stat = "YOYO";
		else res.stat = "NO";
	}


	res.weight = weight;
	res.meta = meta;

	return res;
}

int main()
{
	result r;
	int con, limit;
	int day, Dcon, Dactive;
	int Dweight = 0;
	int Fweight, Fmeta = 0;

	string stat, Fstat;

	cin >> r.weight >> con >> limit;
	cin >> day >> Dcon >> Dactive;

	r.meta = con;
	Dweight = r.weight;
	int cma = Dcon - Dactive - r.meta;

	for (int i = 0; i < day; i++) {
		Dweight += cma;
		if (Dweight <= 0) {
			stat = "Danger Diet";
			break;
		}
	}

	if (stat == "Danger Diet") cout << stat << "\n";
	else cout << Dweight << " " << r.meta << "\n";


	Fweight = MetaWeight(r.weight, day, cma, r.meta, limit).weight;
	Fmeta = MetaWeight(r.weight, day, cma, r.meta, limit).meta;
	Fstat = MetaWeight(r.weight, day, cma, r.meta, limit).stat;

	if (Fstat == "Danger Diet") cout << Fstat;
	else cout << Fweight << " " << Fmeta << " " << Fstat << "\n";

}