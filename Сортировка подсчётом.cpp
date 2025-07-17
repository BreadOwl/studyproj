#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


int main () {
    int n, i, j;
    cout << "Введите количество элементов массива" << std::endl;
    cin >> n;
    string b[n];
    for (i = 0; i < n; i++) {
        cout << "Введите элемент массива" << std::endl;
        cin >> b[i];
    }
    char q = 0;
    int m = 0;
    string t;
	int k = 122;
	string vs[k] = { 0 };
	for (i = 0; i < n; i++){
		vs[b[i]] = vs[b[i]] + 1;
	}
    for (i = 0; i < k; i++) {
		if (vs[i] != "0"){
			cout << vs[i] << std::endl;
		}
    }
    return 0;
}