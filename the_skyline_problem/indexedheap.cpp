#include <iostream>
#include <vector>

using namespace std;

class IndexedHeap {
	private:
		vector<pair<int, int> > heap;
			vector<int> heapLocation;
		int last;

		void siftUp(int k) {
			while (k > 0 && heap[(k-1)/2].first > heap[k].first) {
				pair<int, int> tmp = heap[k];
				heap[k] = heap[(k-1)/2];
				heapLocation[heap[k].second] = k;
				heap[(k-1)/2] = tmp;
				heapLocation[heap[(k-1)/2].second] = (k-1)/2;

				k = (k-1)/2;
			}
		}


		void siftDown(int k) {
			while (k*2+1 < last) {
				int toSwap = k;

				if (heap[k*2+1].first < heap[k].first)
					toSwap = k*2+1;

				if (k*2+2 < last && heap[k*2+2].first < heap[toSwap].first) 
					toSwap = k*2+2;

				if (toSwap != k) {
					pair<int, int> tmp = heap[k];
					heap[k] = heap[toSwap];
					heapLocation[heap[k].second] = k;
					heap[toSwap] = tmp;
					heapLocation[heap[toSwap].second] = toSwap;

					k = toSwap;
				}
				else
					break;
			}
		}

	public:
		IndexedHeap(int n): heap(n), heapLocation(n), last(0) { }
		void push(pair<int, int> p) {
			heap[last] = p;
			heapLocation[p.second] = last;

			siftUp(last);

			last++;
		}

		pair<int, int> pop() {
			pair<int, int> p = heap[0];
			heap[0] = heap[--last];
			siftDown(0);

			return p;
		}
};


int main() {
	IndexedHeap h(100);
	h.push(make_pair(3, 0));
	h.push(make_pair(1, 1));
	h.push(make_pair(4, 2));

	pair<int, int> p;
	for (int i =0; i<3; i++) {
		p = h.pop();
		cout << p.first << "  " << p.second << endl;
	}
}
