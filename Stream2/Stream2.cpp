// Stream2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
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


int main()
{

	string pach = "FIL.bin";
	ofstream fout;
	Point* pnt;
	pnt = new Point[4];
	pnt[3].setXY(7);
	fout.open(pach, ofstream::out);
	if (!fout.is_open()) {
		cout << "err: " << pach << endl;
	}
	else {
		fout.write((char*)&pnt, sizeof(Point)*4);
	}
	fout.close();

	ifstream fin;
	Point* pnt2;
	pnt2 = new Point[4];
	fin.open(pach);

	if (!fin.is_open()) {
		cout << "err: " << pach << endl;
	}
	else {
		while (fin.read((char*)&pnt2, sizeof(Point)*4)) {}
		for (size_t i = 0; i < 4; i++)
		{
			cout << pnt2[i];
		}
	}
	fin.close();
	
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
