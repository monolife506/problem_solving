// 3053번 : 택시 기하학

#include <iostream>
#include <iomanip>
#define PI 3.14159265358979323846
using namespace std;

int main()
{
	double R; cin >> R;
	cout << setprecision(6) << fixed;
	cout << PI * R * R << endl;
	cout << 2 * R * R << endl;
}