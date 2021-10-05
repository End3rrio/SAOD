
#include <fstream>
#include <iostream>
#include <istream>
#include <string>

using namespace std;

//Задание 2. Разработка операций управления бинарным файлом
//Дано.Файл текстовый, элементы(записи) следующей структуры :
//Ключ – целого типа; Данные – строка длиной 10 символов.
//Результат.
//1. Разработать функцию, которая формирует бинарный файл записей из данных, заранее подготовленных в текстовом файле записей.
//2. Разработать функцию, которая выводит данные бинарного файла на монитор.
//3. Разработать функцию, которая ищет запись с заданным ключом и при успешном поиске возвращает порядковый номер записи в файле.
//6. Разработать функцию, которая, используя массив из п.5, считывает из файла запись с заданным ключом.

struct record
{
	int key;
	char data[20];
};

//1

void CreateBinFile(string nametf, string namebf)
{

	ifstream itf(nametf);
	fstream obf(namebf, ios::out);
	record r;
	int len = sizeof(r);

	while (!itf.eof()) 
	{
		itf >> r.key;
		itf.get();
		itf.getline(r.data, len, '\n');
		obf.write((char*)&r, len);
	}

	itf.close();
	obf.close();

}

//2

int outBinFile(string namebf) 
{

	fstream obf(namebf, ios::in);

	if (obf.is_open()) 
	{
		record r;
		int len = sizeof(r);
		obf.read((char*)&r, len);
		while (!obf.eof()) 
		{
			cout << r.key << " " << r.data << "\n";
			obf.read((char*)&r, len);
		}
		obf.close();
		return 0;
	}
	return 1;
}


//3. ищет запись с заданным ключом и при успешном поиске возвращает порядковый номер записи в файле или -1, если запись заданным ключом не задана.
int searchKeyInFile(string namebf, int key)
{

	fstream obf(namebf, ios::in);

	if (obf.is_open())
	{
		record r;
		int len = sizeof(r);
		obf.read((char*)&r, len);
		int i = 0;

		while (!obf.eof())
		{
			if (r.key == key)  
				cout << "Line: " << r.data << "\n";
			obf.read((char*)&r, len);
			i++;
		}
		obf.close();
	}
	return -1;
}

int readRecoredOfPosBinFile(string namebf, int pos, record &r)
{
	ifstream tfb(namebf, ios::in);

	if (tfb.is_open())
	{
		record r;
		int len = sizeof(r);
		

		while (!tfb.eof())
		{
			tfb.seekg(pos * sizeof(r), ios::beg);
			if (!tfb.bad())
			{
				tfb.read((char*)&r, len);
				cout << r.data;
				return 0;
			}
			else
				return 1;
		}
		return 2;
	}

}
int main()
{
	int n;
	CreateBinFile("Text.txt", "BinDataFile.dat");
	outBinFile("BinDataFile.dat");
	cout << "Input key: ";
	cin >> n;
	searchKeyInFile("BinDataFile.dat", n);

	record rr;
	int pos;
	cout << "pos = ";
	cin >> pos;
	int kod = readRecoredOfPosBinFile("BinDataFile.dat", pos, rr);
	
}
