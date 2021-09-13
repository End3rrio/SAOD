#include <iostream>
#include <bitset>

using namespace std;

bitset<32> Task1(unsigned int x)//17й 15й 1й в 1
{
	unsigned int mask = 0x00028002;
	cout << "task 1\n";
	cout << bitset<32>(x) << endl;
	cout << bitset<32>(x | mask) << endl;
	cout << (x | mask) << endl;
	return 1;
}

bitset<32> Task2(unsigned int x)//с 5го бита три справа
{
	unsigned int mask = 0xFFFFFFEF;
	cout << "task2\n";
	cout << bitset<32>(x) << endl;
	cout << bitset<32>(x & mask) << endl;
	cout << (x & mask) << endl;
	return 1;
}

bitset<32> Task3(unsigned int x)//64
{
	cout << "task3\n";
	cout << bitset<32>(x) << endl;
	cout << bitset<32>(x << 6) << endl;
	cout << (x << 6) << endl;
	return 1;
}

bitset<32> Task4(unsigned int x) //64
{
	cout << "task4\n";
	cout << bitset<32>(x) << endl;
	cout << bitset<32>(x >> 6) << endl;
	cout << (x >> 6) << endl;
	return 1;
}

bitset<32> Task5(unsigned int x)
{
	int n;
	cout << "For Task5 enter number of bite\n";
	cin >> n;
	cout << bitset<32>(x) << endl;
	unsigned int maska = 1 << 31;// 1000 0000 0000 0000 0000 0000 0000 0000
	cout << bitset<32>(x | (maska >> (32 - n - 1))) << endl;
	cout << (x | (maska >> (32 - n - 1))) << endl;
	return 1;
}

int main() {
	unsigned int x;
	cout << "Enter number\n";
	cin >> x;
	Task1(x);
	Task2(x);
	Task3(x);
	Task4(x);
	Task5(x);
	return 1;

}