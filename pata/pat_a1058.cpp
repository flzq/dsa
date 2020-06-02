#include <cstdio>

void pat_a1058() {
	int ag, as, ak, bg, bs, bk;
	scanf("%d.%d.%d %d.%d.%d", &ag, &as, &ak, &bg, &bs, &bk);
	ag += bg;
	as += bs;
	ak += bk;

	as += ak / 29;
	ak = ak % 29;

	ag += as / 17;
	as = as % 17;

	printf("%d.%d.%d", ag, as, ak);
}


//int main() {
//	pat_a1058();
//
//	return 0;
//}