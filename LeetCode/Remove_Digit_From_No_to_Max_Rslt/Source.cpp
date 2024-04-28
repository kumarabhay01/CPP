#include<iostream>
#include <string>
using namespace std;

string removeDigit(string number, char digit) {
	string result{};
	string temp{};
	//unsigned long long max = {}, tempMax{};
	int i = -1;
	for (char dig : number) {
		temp = number;
		++i;
		if (dig == digit) {
			temp.erase(temp.begin() + i);
			if (result < temp)
				result = temp;
		}
	}
	return result;
}

int main(){
	string str = "2998589353917872714814599237991174513476623756395992135212546127959342974628712329595771672911914471";
	char dig = '3';
	string result = removeDigit(str, dig);
	cout << result;
	return 0;
}
