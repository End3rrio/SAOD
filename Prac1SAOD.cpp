#include <iostream>
#include <bitset>

using namespace std;

bitset<32> Task1(unsigned int x)// 1111 1111 1111 1111 1111 1111 1100 0111
{
	unsigned int mask = 0x00028002;
	cout << "task 1\n";
	cout << "mask = " << bitset<32>(mask) << endl;
	cout <<"x = " << bitset<32>(x) << endl;
	cout <<"x|mask = " <<  bitset<32>(x | mask) << "= " << (x | mask) << endl;
	return 1;
}

bitset<32> Task2(unsigned int x)
{
	unsigned int mask = 0xFFFFFFC7;
	cout << "task 2\n";
	cout << "mask = " << bitset<32>(mask) << endl;
	cout << "x = " << bitset<32>(x) << endl;
	cout << "x&mask = " << bitset<32>(x & mask) << "= " << (x & mask) << endl;
	return 1;
}

bitset<32> Task3(unsigned int x)//64
{
	cout << "task3\n";
	cout << "x = " << bitset<32>(x) << endl;
	cout <<"x<<6 = " << bitset<32>(x << 6) << "= " << (x << 6) << endl;
	return 1;
}

bitset<32> Task4(unsigned int x) //64
{
	cout << "task4\n";
	cout << "x = " << bitset<32>(x) << endl;
	cout << "x>>6 = " << bitset<32>(x >> 6) << "= " << (x >> 6) << endl;
	return 1;
}

bitset<32> Task5(unsigned int x)
{
	int n;
	cout << "For Task5 enter number of bite\n";
	cin >> n;
	cout << "x = " << bitset<32>(x) << endl;
	unsigned int mask = 1 << 31;// 1000 0000 0000 0000 0000 0000 0000 0000
	cout << "new mask = " << bitset<32>(mask >> (32 - n - 1)) << endl;
	cout << bitset<32>(x | (mask >> (32 - n - 1))) << endl;
	cout << (x | (mask >> (32 - n - 1))) << endl;
	return 1;
}

int main() {
	unsigned int x;
	cout << "Enter number\n";
	cin  >> hex >> x;
	//Task1(x);
	//Task2(x);
	//Task3(x);
	//Task4(x);
	Task5(x);
	return 1;

}
