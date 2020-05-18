#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <list>
#include <stack>
using namespace std;

/*
线性结构：顺序表、链表、栈、队列

*/



#define MAX 100

/*
	顺序表的实现
	SList: Sequence List
*/
struct SList {
	int data[MAX];
	int length;
};

// 初始化顺序表
void init_slist(struct SList* slist) {
	slist->length = 0;
}
// 打印顺序表
void print_slist(struct SList* slist) {
	printf("打印顺序表：");
	for (int i = 0; i < slist->length; ++i) {
		printf("%d,", slist->data[i]);
	}
	putchar('\n');
}
// 插入元素
// 往表中位置为k处，插入元素x
// 从位置0开始插入
int insert(struct SList* slist, int k, int x) {
	if (k < 0 || k > slist->length || slist->length == MAX) {
		// 若插入位置不在[0, lenght]处，或者表已经满了，则不插入
		// 最后一个位置可以插入
		return 0;
	}

	for (int i = slist->length; i > k; --i) {
		slist->data[i] = slist->data[i - 1];
	}
	slist->data[k] = x;
	slist->length++;
	return 1;

}
// 删除元素
// 从表中删除位置k处的元素，并且返回删除的值
int del(struct SList* slist, int k, int* px) {
	if (k < 0 || k >= slist->length) {
		// 若删除位置不在[0, length)处，则返回错误
		return 0;
	}

	*px = slist->data[k];
	for (int i = k+1; i < slist->length; ++i) {
		slist->data[i-1] = slist->data[i];
	}
	slist->length--;
	return 1;

}
// 测试顺序表
void test_SList() {
	// 初始化
	struct SList slist;
	init_slist(&slist);
	// 插入
	printf("插入元素\n");
	insert(&slist, 0, 1);
	print_slist(&slist);
	insert(&slist, 0, 33);
	print_slist(&slist);
	insert(&slist, 1, 55);
	print_slist(&slist);
	insert(&slist, 3, 33);
	print_slist(&slist);
	// 删除
	int x;
	printf("删除元素\n");
	del(&slist, 1, &x);
	print_slist(&slist);
	del(&slist, 1, &x);
	print_slist(&slist);
	del(&slist, 1, &x);
	print_slist(&slist);
	del(&slist, 0, &x);
	print_slist(&slist);

}

/*
	链表的实现(带有头结点）
*/
struct Node {
	int data;
	struct Node* next;
};
// 初始化链表
// 带有头节点的链表
void init_llist(struct Node** phead) {
	*phead = new Node();
	(*phead)->data = 0;
	(*phead)->next = nullptr;
}
// 打印链表
void print_llist(struct Node* head) {
	printf("打印链表：");
	struct Node* tmp_head = head->next;
	while (tmp_head) {
		printf("%d,", tmp_head->data);
		tmp_head = tmp_head->next;
	}
	putchar('\n');
}
// 获得链表长度
int get_llist_length(struct Node* head) {
	int len = 0;
	struct Node* tmp_head = head->next;
	while (tmp_head) {
		++len;
		tmp_head = tmp_head->next;
	}

	return len;
}
// 创建结点
struct Node* create_node(int x) {
	struct Node* t;
	t = new Node();
	t->data = x;
	t->next = nullptr;
	return t;
}
// 找到第k个位置，k从0开始计算
struct Node* find_kth(struct Node* head, int k) {
	if (k < 0) {
		return head;
	}
	int count = 0;
	while (head->next && count < k) {
		head = head->next;
		++count;
	}
	/*if (head) {
		head = head->next;
	}*/

	return head->next;
}
// 插入链表
// 在链表第k个位置插入x
// 位置从0开始计算
int insert_llist(struct Node* head, int k, int x) {
	// 找到第k-1个位置
	// ()-[]-[]
	//     0  1
	int count = 0;
	head = find_kth(head, k - 1);
	/*while (head && count < k) {
		head = head->next;
		count++;
	}*/
	printf("插入位置：%d\n", k);
	if (head) {
		struct Node* t = create_node(x);
		t->next = head->next;
		head->next = t;
		printf("插入：%d\n", x);
		return 1;
	}
	else {
		printf("错误的插入位置\n");
		return 0;
	}

}
// 删除节点
// 删除链表第k个位置的节点，并将删除的值返回
int del_llist(struct Node* head, int k, int* px) {
	// 找到第k-1个位置
	// ()-
	int count = 0;
	head = find_kth(head, k - 1);
	/*while (head && count < k) {
		head = head->next;
		++count;
	}*/

	printf("删除位置：%d\n", k);
	if (head->next) {
		struct Node* t = head->next;
		head->next = t->next;
		*px = t->data;
		printf("删除了：%d\n", t->data);
		delete t;
		return 1;
	}
	else {
		printf("错误的删除位置\n");
		return 0;
	}
}
// 测试链表
void test_LList() {
	// 初始化头节点
	printf("初始化：\n");
	struct Node* head;
	init_llist(&head);
	print_llist(head);
	// 插入节点
	printf("插入节点：\n");
	insert_llist(head, 0, 1);
	print_llist(head);
	insert_llist(head, 0, 22);
	print_llist(head);
	insert_llist(head, 1, 33);
	print_llist(head);
	insert_llist(head, 3, 55);
	print_llist(head);
	insert_llist(head, 5, 66);
	print_llist(head);
	// 删除节点
	int x;
	printf("删除节点：\n");
	del_llist(head, 0, &x);
	print_llist(head);
	del_llist(head, 2, &x);
	print_llist(head);
	del_llist(head, 2, &x);
	print_llist(head);




}


/*
栈的实现
*/
class Stack {
	int* data;
	int capacity;
	int top;
public:
	Stack(int c) : capacity(c), top(0) {
		data = new int[c];
	}
	bool is_full() {
		return top == capacity;
	}
	bool is_empty() {
		return top == 0;
	}
	bool push(const int& x) {
		if (is_full()) {
			return false;
		}
		else {
			data[top] = x;
			++top;
			return true;
		}
	}
	void print() {
		if (is_empty()) {
			printf("the stack is empty\n");
		}
		else {
			for (int i = 0; i < top; ++i) {
				printf("%d,", data[i]);
			}
			printf("\n");
		}
	}
	bool pop(int* px) {
		if (is_empty()) {
			return false;
		}
		else {
			--top;
			*px = data[top];
			return true;
		}
	}
	int size() {
		return top;
	}



	~Stack() {
		delete[] data;
	}

};
void test_stack() {
	Stack st(5);
	st.push(6);
	st.push(8);
	st.push(55);
	st.push(77);
	st.push(88);
	st.push(0);
	st.print();
	int x;
	st.pop(&x);
	printf("%d\n", x);
	st.print();
	printf("%d\n", st.size());
}


/*
队列的实现
*/
struct QNode {
	int data;
	QNode* next;
	QNode(int x) : data(x), next(nullptr) {}
};
class Queue {
private:
	QNode* front;
	QNode* rear;
public:
	Queue() : front(nullptr), rear(nullptr) {}
	~Queue() {
		QNode* tmp;
		while (front) {
			tmp = front;
			front = front->next;
			delete tmp;
		}
	}
	bool is_empty() {
		return front == nullptr;
	}
	bool push(int x) {
		QNode* tmp = new QNode(x);
		if (is_empty()) {
			front = rear = tmp;
			return true;
		}
		else {
			rear->next = tmp;
			rear = tmp;
		}
	}
	bool pop(int* px) {
		if (is_empty()) {
			return false;
		}
		else {
			*px = front->data;
			QNode* tmp = front;
			front = front->next;
			delete tmp;
			if (is_empty()) {
				rear = nullptr;
			}
			return true;
		}
	}
	void print() {
		if (is_empty()) {
			printf("Queue is empty\n");
		}
		else {
			QNode* tmp = front;
			while (tmp) {
				printf("%d,", tmp->data);
				tmp = tmp->next;
			}
			printf("\n");
		}

	}

};
void test_Queue() {
	Queue q;
	q.push(11);
	q.push(22);
	q.push(33);
	q.push(44);
	q.push(55);
	q.print();
	int x;
	x = 0;
	q.pop(&x);
	printf("%d\n", x);
	x = 0;
	q.pop(&x);
	printf("%d\n", x);
	x = 0;
	q.pop(&x);
	printf("%d\n", x);
	x = 0;
	q.pop(&x);
	printf("%d\n", x);
	x = 0;
	q.pop(&x);
	printf("%d\n", x);
	x = 0;
	q.pop(&x);
	printf("%d\n", x);

	q.print();
}

void pta() {
	int N{ 0 };
	int size{ 0 };
	char str[10];
	scanf("%d", &N);
	Queue q;
	while (true) {
		scanf("%s", str);
		if (str[0] == '#') {
			break;
		}
		else if (str[0] == 'I') {
			int id;
			scanf("%d", &id);
			if (size == N) {
				printf("%d rejected.\n", id);
			}
			else {
				q.push(id);
				++size;
				printf("%d joined. Total:%d\n", id, size);
			}
		}
		else {
			if (size == 0) {
				printf("No one!\n");
			}
			else {
				int id;
				q.pop(&id);
				--size;
				printf("%d called. Total:%d\n", id, size);
			}
		}
	}

}

int main(void) {
	//test_SList();
	// 使用vector
	// test_LList();
	//test_stack();
	//test_Queue();
	pta();


	return 0;
}