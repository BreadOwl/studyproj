#include <iostream>
#include <string>
#include <cstdlib>  //для выхода 
#include <stdlib.h>
using namespace std;

int nain(){
	cout << "Введите количество элементов массива" << std::endl;
	cin >> n;
	string a[n];
	for (i = 0, i < n; i++) {
		cout << "Введите элемент массива" << std::endl;
		cin >> mas[i];
	}	
	char q = 0;
    int m = 0;
    int t;
    while (q != 1) {
        for (j = 1; j < n; j++) {
            if (a[j-1] > a[j]) {
                t = a[j-1];
                a[j-1] = a[j];
                a[j] = t;
                m = m + 1;
            }
        }
        if (m == 0) {
            q = 1;
        } else {
            m = 0;
        }
    }
	for (i = 0, i < n; i++) {
	cout << a[i] << std::endl;
			}
	return 0;
}