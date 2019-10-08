#include <iostream>
#include <string>
using namespace std;

int main()
{
	size_t count{ 0 };
	string read, target;
	getline(cin, read);
	getline(cin, target);
	
	if (read.size() < target.size())
	{
		cout << 0;
		return 0;
	}

	bool isTargetFounded;
	for (int i = 0; i < read.size() - target.size() + 1; i++)
	{
		for (size_t j = 0; j < target.size(); j++)
		{
			if (read[i + j] != target[j])
			{
				isTargetFounded = false;
				break;
			}
			else if (j == target.size() - 1)
			{
				isTargetFounded = true;
			}
		}

		if (isTargetFounded)
		{
			count++;
			i += target.size() - 1;
		}
	}

	cout << count;
}