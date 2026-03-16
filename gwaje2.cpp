#include<iostream>
#include<stdlib.h>
#include<time.h>

void lowtomax() {
	std::cout << std::endl;
	int a[] = { 2, 7, 8, 3, 11, 1, 15, 24, 16, 19, 9 };
	int b = 0;
	int length = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < length; i++) {
		int c = b;
		b = 912491456;
		for (int j = 0; j < length; j++) {
			if (a[j] == 0) {
				continue;
			}
			else if (c == a[j]) {
				a[j] -= c;
				continue;
			}
			else if (b > a[j]) {
				b = a[j];
			}
		}
		std::cout << b << ' ';
	}
	std::cout << std::endl;
}

void maxtolow() {
	std::cout << std::endl;
	int a[] = { 2, 7, 8, 3, 11, 1, 15, 24, 16, 19, 9 };
	int b = 0;
	int length = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < length; i++) {
		int c = b;
		b = 0;
		for (int j = 0; j < length; j++) {
			if (a[j] == 0) {
				continue;
			}
			else if (c == a[j]) {
				a[j] -= c;
				continue;
			}
			else if (b < a[j]) {
				b = a[j];
			}
		}
		std::cout << b << ' ';
	}
	std::cout << std::endl;
}

void median() {
	std::cout << std::endl;
	int a[] = { 2, 7, 8, 3, 11, 1, 15, 24, 16, 19, 9 };
	int b = 0;
	int length = sizeof(a) / sizeof(a[0]);
	const int len = sizeof(a) / sizeof(a[0]);
	int sorted[len];
	for (int i = 0; i < length; i++) {
		int c = b;
		b = 912491451;
		for (int j = 0; j < length; j++) {
			if (a[j] == 0) {
				continue;
			}
			else if (c == a[j]) {
				a[j] -= c;
				continue;
			}
			else if (b > a[j]) {
				b = a[j];
			}
		}
		sorted[i] = b;
	}
	if (length % 2 == 0) {
		std::cout << (sorted[(len / 2)] + sorted[((len / 2) - 1)]) / 2;
	}
	else {
		std::cout << sorted[(len / 2)];
	}
	std::cout << std::endl;
}

void close11() {
	std::cout << std::endl;
	int a[] = { 2, 7, 8, 3, 11, 1, 15, 24, 16, 19, 9 };
	int b = 0;
	int c;
	int length = sizeof(a) / sizeof(a[0]);
	const int len = sizeof(a) / sizeof(a[0]);
	int sorted[len];
	for (int i = 0; i < length; i++) {
		c = b;
		b = 912491451;
		for (int j = 0; j < length; j++) {
			if (a[j] == 0) {
				continue;
			}
			else if (c == a[j]) {
				a[j] -= c;
				continue;
			}
			else if (b > a[j]) {
				b = a[j];
			}
		}
		sorted[i] = b;
	}
	int sum = 0;
	for (int i = 0; i < length; i++) {
		b = 11 - a[i];
		c = 11 - a[i + 1];

		if (b < c) {
			sum = b;
		}
		else if (b > c) {
			sum = c;
		}
		else if (b == 0) {
			sum = a[i];
			break;
		}
		else if (c == 0) {
			sum = a[i + 1];
			break;
		}
	}
	std::cout << sum;

	std::cout << std::endl;
}

void f1to100() {
	std::cout << std::endl;
	int a[100];
	for (int i = 0, j = 1; i < 100; i++, j++) {
		a[i] = j;
		std::cout << a[i] << ' ';
	}
	std::cout << std::endl;
}

void easy5() {
	std::cout << std::endl;
	int a[] = { 2, 7, 8, 3, 11, 1, 15, 24, 16, 19, 9 };
	int b = 0;
	int length = sizeof(a) / sizeof(a[0]);
	const int len = sizeof(a) / sizeof(a[0]);
	int sorted[len];
	for (int i = 0; i < length; i++) {
		int c = b;
		b = 912491451;
		for (int j = 0; j < length; j++) {
			if (a[j] == 0) {
				continue;
			}
			else if (c == a[j]) {
				a[j] -= c;
				continue;
			}
			else if (b > a[j]) {
				b = a[j];
			}
		}
		sorted[i] = b;
	}
	int a1 = sorted[0];
	int a2 = sorted[1];
	int a3 = sorted[2];
	int a4 = sorted[3];
	int a5 = sorted[4];
	int a6 = sorted[5];
	int a7 = sorted[6];
	int a8 = sorted[7];
	int a9 = sorted[8];
	int a10 = sorted[9];
	int a11 = sorted[10];

	std::cout << a1 << ' ' << a2 << ' ' << a3 << ' ' << a4 << ' ' << a5 << ' ' << a6 << ' ' << a7 << ' ' << a8 << ' ' << a9 << ' ' << a10 << ' ' << a11;

	std::cout << std::endl;
}

void per30() {
	std::cout << std::endl;
	float sum = 0;
	int random;
	srand(time(NULL));
	for (int i = 0; i < 1000; i++) {
		random = (rand() % 100);
		if (random <= 30) {
			sum++;
		}
	}
	std::cout << sum / 1000;
	std::cout << std::endl;
}

void s3349() {
	std::cout << std::endl;
	int sum = 0;
	for (int i = 1; i <= 100; i++) {
		if (i >= 33 && i <= 49) {
			sum += i;
		}
	}
	std::cout << sum << std::endl;
}

void sinput() {
	std::cout << std::endl;
	int sum = 0;
	int a;
	int b;
	std::cin >> a;
	std::cin >> b;
	for (int i = 1; i <= 100; i++) {
		if (i >= a && i <= b) {
			sum += i;
		}
	}
	std::cout << sum << std::endl;
}
void shib1() {
	std::cout << std::endl;
	int a[] = { 2, 7, 8, 3, 11, 1, 15, 24, 16, 19, 9 };
	int b = 0;
	int length = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < length; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < length; i++) {
		int c = b;
		b = 912491456;
		for (int j = 0; j < length; j++) {
			if (a[j] == 0) {
				continue;
			}
			else if (c == a[j]) {
				a[j] -= c;
				continue;
			}
			else if (b > a[j]) {
				b = a[j];
			}
		}
		std::cout << b << ' ';
	}
	std::cout << std::endl;
}

void shib2() {
	std::cout << std::endl;
	int a[] = { 2, 7, 8, 3, 11, 1, 15, 24, 16, 19, 9 };
	int b = 0;
	int length = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < length; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < length; i++) {
		int c = b;
		b = 0;
		for (int j = 0; j < length; j++) {
			if (a[j] == 0) {
				continue;
			}
			else if (c == a[j]) {
				a[j] -= c;
				continue;
			}
			else if (b < a[j]) {
				b = a[j];
			}
		}
		std::cout << b << ' ';
	}
	std::cout << std::endl;
}

void shib3() {
	std::cout << std::endl;
	int a[] = { 2, 7, 8, 3, 11, 1, 15, 24, 16, 19, 9 };
	int b = 0;
	int length = sizeof(a) / sizeof(a[0]);
	const int len = sizeof(a) / sizeof(a[0]);
	int sorted[len];
	for (int i = 0; i < length; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < length; i++) {
		int c = b;
		b = 912491451;
		for (int j = 0; j < length; j++) {
			if (a[j] == 0) {
				continue;
			}
			else if (c == a[j]) {
				a[j] -= c;
				continue;
			}
			else if (b > a[j]) {
				b = a[j];
			}
		}
		sorted[i] = b;
	}
	if (length % 2 == 0) {
		std::cout << (sorted[(len / 2)] + sorted[((len / 2) - 1)]) / 2;
	}
	else {
		std::cout << sorted[(len / 2)];
	}
	std::cout << std::endl;
}

void shib4() {
	std::cout << std::endl;
	int a[] = { 2, 7, 8, 3, 11, 1, 15, 24, 16, 19, 9 };
	int b = 0;
	int c;
	int length = sizeof(a) / sizeof(a[0]);
	const int len = sizeof(a) / sizeof(a[0]);
	int sorted[len];
	for (int i = 0; i < length; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < length; i++) {
		c = b;
		b = 912491451;
		for (int j = 0; j < length; j++) {
			if (a[j] == 0) {
				continue;
			}
			else if (c == a[j]) {
				a[j] -= c;
				continue;
			}
			else if (b > a[j]) {
				b = a[j];
			}
		}
		sorted[i] = b;
	}
	int sum = 0;
	for (int i = 0; i < length; i++) {
		b = 11 - a[i];
		c = 11 - a[i + 1];

		if (b < c) {
			sum = b;
		}
		else if (b > c) {
			sum = c;
		}
		else if (b == 0) {
			sum = a[i];
			break;
		}
		else if (c == 0) {
			sum = a[i + 1];
			break;
		}
	}
	std::cout << sum;

	std::cout << std::endl;
}

void shib5() {
	std::cout << std::endl;
	int b;
	std::cin >> b;
	int a[255];
	for (int i = 0, j = 1; i < b; i++, j++) {
		a[i] = j;
		std::cout << a[i] << ' ';
	}
	std::cout << std::endl;
}

void shib6() {
	std::cout << std::endl;
	int a[] = { 2, 7, 8, 3, 11, 1, 15, 24, 16, 19, 9 };
	int b = 0;
	int length = sizeof(a) / sizeof(a[0]);
	const int len = sizeof(a) / sizeof(a[0]);
	int sorted[len];
	for (int i = 0; i < length; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < length; i++) {
		int c = b;
		b = 912491451;
		for (int j = 0; j < length; j++) {
			if (a[j] == 0) {
				continue;
			}
			else if (c == a[j]) {
				a[j] -= c;
				continue;
			}
			else if (b > a[j]) {
				b = a[j];
			}
		}
		sorted[i] = b;
	}
	int a1 = sorted[0];
	int a2 = sorted[1];
	int a3 = sorted[2];
	int a4 = sorted[3];
	int a5 = sorted[4];
	int a6 = sorted[5];
	int a7 = sorted[6];
	int a8 = sorted[7];
	int a9 = sorted[8];
	int a10 = sorted[9];
	int a11 = sorted[10];

	std::cout << a1 << ' ' << a2 << ' ' << a3 << ' ' << a4 << ' ' << a5 << ' ' << a6 << ' ' << a7 << ' ' << a8 << ' ' << a9 << ' ' << a10 << ' ' << a11;

	std::cout << std::endl;
}

int main() {

	lowtomax();
	maxtolow();
	median();
	close11();
	f1to100();
	easy5();
	per30();
	s3349();
	sinput();
	shib1();
	shib2();
	shib3();
	shib4();
	shib5();
	shib6();


	return 0;
}