#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <list>
#include <stack>
using namespace std;

/*
���Խṹ��˳�������ջ������

*/



#define MAX 100

/*
	˳����ʵ��
	SList: Sequence List
*/
struct SList {
	int data[MAX];
	int length;
};

// ��ʼ��˳���
void init_slist(struct SList* slist) {
	slist->length = 0;
}
// ��ӡ˳���
void print_slist(struct SList* slist) {
	printf("��ӡ˳���");
	for (int i = 0; i < slist->length; ++i) {
		printf("%d,", slist->data[i]);
	}
	putchar('\n');
}
// ����Ԫ��
// ������λ��Ϊk��������Ԫ��x
// ��λ��0��ʼ����
int insert(struct SList* slist, int k, int x) {
	if (k < 0 || k > slist->length || slist->length == MAX) {
		// ������λ�ò���[0, lenght]�������߱��Ѿ����ˣ��򲻲���
		// ���һ��λ�ÿ��Բ���
		return 0;
	}

	for (int i = slist->length; i > k; --i) {
		slist->data[i] = slist->data[i - 1];
	}
	slist->data[k] = x;
	slist->length++;
	return 1;

}
// ɾ��Ԫ��
// �ӱ���ɾ��λ��k����Ԫ�أ����ҷ���ɾ����ֵ
int del(struct SList* slist, int k, int* px) {
	if (k < 0 || k >= slist->length) {
		// ��ɾ��λ�ò���[0, length)�����򷵻ش���
		return 0;
	}

	*px = slist->data[k];
	for (int i = k+1; i < slist->length; ++i) {
		slist->data[i-1] = slist->data[i];
	}
	slist->length--;
	return 1;

}
// ����˳���
void test_SList() {
	// ��ʼ��
	struct SList slist;
	init_slist(&slist);
	// ����
	printf("����Ԫ��\n");
	insert(&slist, 0, 1);
	print_slist(&slist);
	insert(&slist, 0, 33);
	print_slist(&slist);
	insert(&slist, 1, 55);
	print_slist(&slist);
	insert(&slist, 3, 33);
	print_slist(&slist);
	// ɾ��
	int x;
	printf("ɾ��Ԫ��\n");
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
	�����ʵ��(����ͷ��㣩
*/
struct Node {
	int data;
	struct Node* next;
};
// ��ʼ������
// ����ͷ�ڵ������
void init_llist(struct Node** phead) {
	*phead = new Node();
	(*phead)->data = 0;
	(*phead)->next = nullptr;
}
// ��ӡ����
void print_llist(struct Node* head) {
	printf("��ӡ����");
	struct Node* tmp_head = head->next;
	while (tmp_head) {
		printf("%d,", tmp_head->data);
		tmp_head = tmp_head->next;
	}
	putchar('\n');
}
// ���������
int get_llist_length(struct Node* head) {
	int len = 0;
	struct Node* tmp_head = head->next;
	while (tmp_head) {
		++len;
		tmp_head = tmp_head->next;
	}

	return len;
}
// �������
struct Node* create_node(int x) {
	struct Node* t;
	t = new Node();
	t->data = x;
	t->next = nullptr;
	return t;
}
// �ҵ���k��λ�ã�k��0��ʼ����
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
// ��������
// �������k��λ�ò���x
// λ�ô�0��ʼ����
int insert_llist(struct Node* head, int k, int x) {
	// �ҵ���k-1��λ��
	// ()-[]-[]
	//     0  1
	int count = 0;
	head = find_kth(head, k - 1);
	/*while (head && count < k) {
		head = head->next;
		count++;
	}*/
	printf("����λ�ã�%d\n", k);
	if (head) {
		struct Node* t = create_node(x);
		t->next = head->next;
		head->next = t;
		printf("���룺%d\n", x);
		return 1;
	}
	else {
		printf("����Ĳ���λ��\n");
		return 0;
	}

}
// ɾ���ڵ�
// ɾ�������k��λ�õĽڵ㣬����ɾ����ֵ����
int del_llist(struct Node* head, int k, int* px) {
	// �ҵ���k-1��λ��
	// ()-
	int count = 0;
	head = find_kth(head, k - 1);
	/*while (head && count < k) {
		head = head->next;
		++count;
	}*/

	printf("ɾ��λ�ã�%d\n", k);
	if (head->next) {
		struct Node* t = head->next;
		head->next = t->next;
		*px = t->data;
		printf("ɾ���ˣ�%d\n", t->data);
		delete t;
		return 1;
	}
	else {
		printf("�����ɾ��λ��\n");
		return 0;
	}
}
// ��������
void test_LList() {
	// ��ʼ��ͷ�ڵ�
	printf("��ʼ����\n");
	struct Node* head;
	init_llist(&head);
	print_llist(head);
	// ����ڵ�
	printf("����ڵ㣺\n");
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
	// ɾ���ڵ�
	int x;
	printf("ɾ���ڵ㣺\n");
	del_llist(head, 0, &x);
	print_llist(head);
	del_llist(head, 2, &x);
	print_llist(head);
	del_llist(head, 2, &x);
	print_llist(head);




}


/*
ջ��ʵ��
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
���е�ʵ��
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
	// ʹ��vector
	// test_LList();
	//test_stack();
	//test_Queue();
	pta();


	return 0;
}