#include <iostream>
using namespace std;

int main()
{
	int H, M;
	cin >> H >> M;
	if (M >= 45)
		M -= 45;
	else
	{
		H--;
		if (H == -1)
			H = 23;
		M = M + 15;
	}
	cout << H << " " << M << endl;
}