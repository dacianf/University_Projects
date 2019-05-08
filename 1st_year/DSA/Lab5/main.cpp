#include <iostream>
#include "SecondPriorityQueue.h"
#include "TestP6.h"
using namespace std;
bool rl(TPriority p1, TPriority p2) {
	if (p1 <= p2) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	testP6();
	/*auto pq{ SecondPriorityQueue(rl) };
	pq.push(1, 6);
	pq.push(2, 3);
	pq.push(3, 9);
	pq.push(7, 4);
	pq.push(4, 1);
	pq.push(5, 2);
	pq.push(3, 7);
	pq.print();
	cout << pq.top().first<<" -- "<< pq.top().second;
	pq.pop();
	pq.print();*/
	return 0;
}