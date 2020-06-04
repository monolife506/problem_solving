// 1931번 : 회의실 배정

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct session
{
	unsigned int start;
	unsigned int end;
};

bool cmp(session& A, session& B)
{
	if (A.end != B.end)
	{
		return A.end < B.end; 
	}
	else
	{
		return A.start < B.start;
	}
}

int main()
{
	size_t N; cin >> N;
	vector<session> schedule(N);
	for (session& s : schedule)
	{
		cin >> s.start >> s.end;
	}
	sort(schedule.begin(), schedule.end(), cmp);
	
	size_t count{ 1 }, shifter{ 0 };
	for (size_t i = 1; i < N; i++)
	{
		if (schedule[shifter].end <= schedule[i].start)
		{
			count++; shifter = i;
		}
	}

	cout << count;
}