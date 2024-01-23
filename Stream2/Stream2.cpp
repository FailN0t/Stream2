// Stream2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#pragma warning(disable : 4996)
using namespace std;

class Point {
	int x, y;
public:
	Point(int x, int y): x{x}, y{y} {}
	Point() : Point(0, 0){}

	void setXY(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}

	void print(ostream& ost) {
		ost << "x: " << x << " y: " << y << endl;
	}
	friend ostream& operator<< (ostream& ost, Point& pnt) {
		pnt.print(ost);
		return ost;
	}

	void operator= (Point& pnt) {
		this->x = pnt.x;
		this->y = pnt.y;
	}

};

class ArrPoint {
	Point* pnt;
	int size;
	static int count;
	char pach[255];
	char pachC[10] = "Count.bin";
	void name() {
		string pa = "fil" + to_string(count) + ".bin";
		strncpy(pach, pa.c_str(), pa.length() + 1);
	}
	bool wrtPach() {
		ofstream fout;
		fout.open(pach, ofstream::out);
		fout.close();
		fout.open(pach, ofstream::app);
		if (!fout.is_open()) {
			cout << "err: " << pach << endl;
			return false;
		}
		else {
			fout.write((char*)&size, sizeof(int));
			fout.write((char*)&pnt, sizeof(Point) * size);
		}
		fout.close();
		return true;
	}

	bool wrtCount() {
		ofstream fout;
		fout.open(pachC, ofstream::out);
		if (!fout.is_open()) {
			cout << "err: " << pach << endl;
			return false;
		}
		else {
			fout.write((char*)&count, sizeof(int));
		}
		fout.close();
		return true;
	}
	bool rdSize() {
		ifstream fin;
		fin.open(pach);

		if (!fin.is_open()) {
			cout << "err: " << pach << endl;
			return false;
		}
		else {
			fin.read((char*)&size, sizeof(int));
		}
		fin.close();
		return true;
	}

	bool rdPach() {
		ifstream fin;
		fin.open(pach);
		pnt = new Point[size];
		if (!fin.is_open()) {
			cout << "err: " << pach << endl;
			return false;
		}
		else {
			fin.read((char*)&size, sizeof(int));
			fin.read((char*)&pnt, sizeof(Point) * size);
		}
		fin.close();
		return true;
	}

public:
	ArrPoint(int i) : pnt{ new Point[i] }, size{ i } {

		count++;
		name();
		if (!wrtPach()) {
			cout << "error" << pach << endl;
		}
		if (!wrtCount()) {
			cout << "error" << pachC << endl;
		}
	}
	ArrPoint():ArrPoint(5){}
	ArrPoint(string pach) {
		if (!rdSize()) {
			cout << "error" << pach << endl;
		}
		if (!rdPach()) {
			cout << "error" << pach << endl;
		}
		count++;
		name();

	}
	void 
};

int ArrPoint::count = 0;


int main()
{

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
