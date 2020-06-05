#include <algorithm>
using std::sort;

int main() {
	int a[] = { 9, 4, 2, 6, -1, 0 };
	sort(a, a + 4);
	for (int i = 0; i < 6; ++i) {
		printf("%d ", a[i]);
	}

	return 0;
}