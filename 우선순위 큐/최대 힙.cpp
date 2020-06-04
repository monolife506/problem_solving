// 11279번: 최대 힙

#include <cstdio>
using namespace std;

template <typename T>
class Heap
{
public:
    Heap(size_t N) : heapSize(N)
    {
        lastNode = 0;
        heapArr = new T[heapSize + 1];
    }

    ~Heap()
    {
        delete[] heapArr;
    }

    void push(const T &item)
    {
        heapArr[++lastNode] = item;
        push_swap(lastNode);
    }

    T pop()
    {
        if (lastNode == 0)
            return 0;

        T rootValue = heapArr[1];
        heapArr[1] = heapArr[lastNode--];
        pop_swap(1);
        return rootValue;
    }

private:
    T *heapArr;
    size_t heapSize;
    size_t lastNode;

    T max_index(const T &indexA, const T &indexB)
    {
        return (heapArr[indexA] > heapArr[indexB]) ? indexA : indexB;
    }

    void push_swap(const int upperIndex)
    {
        int lowerIndex = upperIndex / 2;
        if (lowerIndex <= 0)
            return;

        int maxIndex = max_index(lowerIndex, upperIndex);
        if (maxIndex == upperIndex)
        {
            T tmp = heapArr[lowerIndex];
            heapArr[lowerIndex] = heapArr[upperIndex];
            heapArr[upperIndex] = tmp;
            push_swap(lowerIndex);
        }
    }

    void pop_swap(const int lowerIndex)
    {
        int upperIndexA = lowerIndex * 2;
        int upperIndexB = upperIndexA + 1;
        int maxUpperIndex;

        if (upperIndexA > lastNode)
            return;
        else if (upperIndexB > lastNode)
            maxUpperIndex = upperIndexA;
        else
            maxUpperIndex = max_index(upperIndexA, upperIndexB);

        int maxIndex = max_index(lowerIndex, maxUpperIndex);
        if (maxIndex == maxUpperIndex)
        {
            T tmp = heapArr[lowerIndex];
            heapArr[lowerIndex] = heapArr[maxUpperIndex];
            heapArr[maxUpperIndex] = tmp;
            pop_swap(maxUpperIndex);
        }
    }
};

int main()
{
    size_t N;
    scanf("%d", &N);

    Heap<int> H(N);
    for (size_t i = 0; i < N; i++)
    {
        int input;
        scanf("%d", &input);

        if (input == 0)
        {
            int poped = H.pop();
            printf("%d\n", poped);
        }
        else
            H.push(input);
    }
}