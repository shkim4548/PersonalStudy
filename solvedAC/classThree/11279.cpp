#include <iostream>
#include <vector>
#include <array>
using namespace std;

const int HEAP_SIZE = 100001;
array<int, HEAP_SIZE> heap;
//vector<int> heap;
int heapCount = 0;

void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Init() {
	heapCount = 0;
}

int Size() {
	return heapCount;
}

/*
	1. 트리의 가장 마지막 노드 다음에 현재 삽입하고자 하는 데이터를 넣어준다.
	2. 부모노드와 비교하면서 부모노드보다 더 큰 값이라면 부모노드와 Swap해준다.
	3. 2번 조건을 만족하지 않을 때 까지 혹은 루트 노드가 아닐 때 까지 반복한다.
*/
void HEAP_push(int data) {
	heap[++heapCount] = data;


	int child = heapCount;
	int parent = child / 2;

	while (child > 1 && heap[parent] < heap[child]) {
		Swap(&heap[parent], &heap[child]);
		child = parent;
		parent = child / 2;
	}
}

/*
	1. 우리가 가져올 '최대값'을 미리 저장해준다.
	2. 가장 마지막 노드의 값과 루트 노드의 값을 Swap 해준다.
	3. 현재 노드에서 자식 노드와 비교 하면서 더 작은 값이라면 Swap해준다.
	4. 위치를 찾을 때 까지 3번 과정을 반복한다.
	5. 미리 저장해둔 최댓값을 return 시켜주고, 힙의 크기를 1 감소시켜준다.
*/

int HEAP_pop() {
	if (heap.empty())
		return 0;

	int result = heap[1];

	Swap(&heap[1], &heap[heapCount]);
	heapCount--;

	int parent = 1;
	int child = parent * 2;

	if (child + 1 <= heapCount) {
		child = (heap[child] > heap[child + 1]) ? child : child + 1;
	}

	while (child <= heapCount && heap[parent] < heap[child]) {
		Swap(&heap[parent], &heap[child]);
		parent = child;
		child = child * 2;
		if (child + 1 <= heapCount)
			child = (heap[child] > heap[child + 1]) ? child : child + 1;
	}
	return result;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	vector<int> v_print;

	int n, input, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input == 0) {
			cout << "tmp out : " << HEAP_pop() << '\n';
		}
		else 
			HEAP_push(input);
	}

	return 0;
}