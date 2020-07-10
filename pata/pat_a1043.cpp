#include <cstdio>

struct Node_pat_a1043 {

};

int keys_pat_a1043[1010];

void pat_a1043() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &keys_pat_a1043[i]);
	}
	// ÅÐ¶ÏBST»òÕß mirror image of BST
	bool is_bst{ true }; // true: bst; false: mirror image of bst
	bool is_preorder{ false }; // preorder of bst or mirror image of bst
	if (keys_pat_a1043[0] < keys_pat_a1043[1]) {
		is_bst = true;

	}
	else {
		is_bst = false;
	}
}

//int main() {
//	pat_a1043();
//	return 0;
//}