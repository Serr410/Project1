#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void calc(string a, string b, int x, int y) {
	vector<int> veca, vecb;
	int an = 0, bn = 0, copy;
	for (char& c : a) {         //Initial creation of vector
		if (c < 48 || c > 57) {
			cout << "Invalid data. Error. If for some reason you decide to use fractional numbers, letters or other symbols, restart program and exclude them from input.";
			exit(0);
		} else if (x == 0) {
			veca.push_back(1);
			break;
		} else if (veca.size() == 1 && veca[0] == 0) {
		    veca[0] = c - '0';
		    an = c - '0';
		} else {
			veca.push_back(c - '0');
			an = an * 10 + c - '0';
		}
	}
	for (char& c : b) {
		if (c < 48 || c > 57) {
			cout << "Invalid data. Error. If for some reason you decide to use fractional numbers, letters or other symbols, restart program and exclude them from input.";
			exit(0);
		} else if (y == 0) {
			vecb.push_back(1);
			break;
		} else if (vecb.size() == 1 && vecb[0] == 0) {
		    vecb[0] = c - '0';
		    bn = c - '0';
		} else {
			vecb.push_back(c - '0');
			bn = bn * 10 + c - '0';
		}
	}

	reverse(veca.begin(), veca.end());
	reverse(vecb.begin(), vecb.end());
	int i = 0, flag = veca.size();
	for (int j = 0; j < x - 1; j ++) {
		for (int i = 0; i < veca.size(); i ++) {    //Multiplication inside of each element
			veca[i] = veca[i] * an;
		}

		i = 0, flag = veca.size();                   //Trasitions between elements
		while (i < flag) {
			if (i == veca.size() - 1 && veca[i] / 10 != 0) {
				veca.push_back(0);
				flag ++;
			}
			while (veca[i] / 10 != 0) {
				veca[i + 1] = veca[i + 1] + veca[i] / 10;
				veca[i] = veca[i] % 10;
			}
			i ++;
		}
	}
	for (int j = 0; j < y - 1; j ++) {
		for (int i = 0; i < vecb.size(); i ++) {
			vecb[i] = vecb[i] * bn;
		}

		i = 0, flag = vecb.size();
		while (i < flag) {
			if (i == vecb.size() - 1 && vecb[i] / 10 != 0) {
				vecb.push_back(0);
				flag ++;
			}
			while (vecb[i] / 10 != 0) {
				vecb[i + 1] = vecb[i + 1] + vecb[i] / 10;
				vecb[i] = vecb[i] % 10;
			}
			i ++;
		}
	}

	bool first;
	i = 0;
	if ((veca.size() > vecb.size()) || veca[veca.size() - 1] > vecb[vecb.size() - 1] && veca.size() == vecb.size()) { //Finding out which number is greater
		flag = vecb.size();
		first = true;
	} else {
		flag = veca.size();
		first = false;
	}
	if (first) {
		i = vecb.size();
		vecb.push_back(0);
	} else {
		i = veca.size();
		veca.push_back(0);
	}
	i = 0;
	int j = 0;
	while(i < flag) {
		if (first) {
			veca[i] = veca[i] - vecb[i];
			j = i;
			while (veca[j] < 0 && j < veca.size() - 1) {
				veca[j + 1] = veca[j + 1] - 1;
				veca[j] = veca[j] + 10;
				j ++;
			}
		} else {
			vecb[i] = vecb[i] - veca[i];
			j = i;
			while (vecb[j] < 0 && j < vecb.size() - 1) {
				vecb[j + 1] = vecb[j + 1] - 1;
				vecb[j] = vecb[j] + 10;
				j ++;
			}
		}
		i ++;
	}
	reverse(veca.begin(), veca.end());
	reverse(vecb.begin(), vecb.end());

	if (first) {                                              //cout result and fixing occasional minus or\and zero
		cout << "First one is greater by ";
		for (int i = 0; i < veca.size(); i ++) {
			while (veca[i] == 0 && i == 0 && veca.size() > 1) veca.erase(veca.begin() + i);
			cout << veca[i];
		}
	} else {
		for (int j = 0; j < vecb.size(); j ++) {
			if (vecb[j] != 0) {
				first = true;
				break;
			}
		}
		if (!first) {
			cout << "Numbers are equal to each other";
		} else {
			cout << "Second one is greater by ";
			for (int i = 0; i < vecb.size(); i ++) {
				while (vecb[i] == 0 && i == 0 && vecb.size() > 1) vecb.erase(vecb.begin() + i);
				cout << vecb[i];
			}
		}
	}
}

int main() {
	cout << "Please, input 2 numbers not greater than 40000 and power equal or lower than of a 10 for both of them in that exact order: " << endl;
	string a, b;
	int x, y;
	cin >> a >> b >> x >> y;
	calc(a, b, x, y);

	return 0;
}
