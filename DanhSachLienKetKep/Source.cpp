#include <iostream>

using namespace std;

struct node
{
	int data;
	node* next; //con trỏ tới 
	node* pre;  //con trỏ lui
};
typedef node* NODEPTR;

struct Dlist
{
	NODEPTR first;
	NODEPTR last;
};

void khoiTao(Dlist& list)
{
	list.first = NULL;
	list.last = NULL;
}

NODEPTR khoiTaoNode(int x)
{
	NODEPTR p = new node;
	p->data = x;
	p->next = NULL;
	p->pre = NULL;
	return p;
}

void themCuoi(Dlist &list, int x)
{
	NODEPTR p = khoiTaoNode(x);
	if (list.last == NULL)
	{
		list.first = p;
		list.last = p;
	}
	else {
		list.last->next = p;
		p->pre = list.last;
		list.last = p;
	}
}

void themDau(Dlist& list, int x)
{
	NODEPTR p = khoiTaoNode(x);
	if (list.first == NULL)
	{
		list.first = p;
		list.last = p;
	}
	else
	{
		p->next = list.first;
		list.first ->pre =p;
		list.first = p;
	}
}


void nhap(Dlist& list)
{
	int x;
	do {
		cout << "\n Nhap Gia Tri Nguyen: (-99 De Thoat)"; cin >> x;
		if (x == -99) break;
		themCuoi(list, x);
	} while (1);
}

void xuatNguoc(Dlist list)
{
	NODEPTR p = list.last;
	while (p != NULL)
	{
		cout << " " << p->data;
		p = p->pre;
	}
}

void xuatThuan(Dlist list)
{
	NODEPTR p = list.first;
	while (p != NULL)
	{
		cout << " " << p->data;
		p = p->next;
	}
}

NODEPTR timPhanTuX(Dlist &list, int x)
{
	NODEPTR p = list.last;
	while (p != NULL)
	{
		if (p->data == x)
			return p;
		p = p->pre;
	}
	return p;
}

void xoaDauThuan(Dlist& list)
{
	NODEPTR p = list.first;
	if (list.first == NULL)
	{
		list.first = p;
		list.last = p;
	}
	else
	{
		list.first = list.first->next;
		p->next = NULL;
		delete p;
	}
}

void xoaDauNguoc(Dlist& list)
{
	NODEPTR p = list.last;
	if (list.last == NULL)
	{
		list.first = p;
		list.last = p;
	}
	else
	{
		list.last = list.last->pre;
		p->pre = NULL;
		delete p;
	}
}

void xoaCuoiThuan(Dlist& list)
{
	/*NODEPTR p = list.last;
	list.last = list.last->pre;
	list.last->next = NULL;
	if (list.last == NULL)
	{
		list.last = NULL;
	}
	p->pre = NULL;
	delete p;*/
	if (list.first == NULL)
	{
		cout << "\n Danh Sach Rong ";
	}
	else if (list.first == list.last)
	{
		delete list.first;
		list.first = list.last = NULL;
	}
	else {
		NODEPTR p = list.last;
		list.last->pre->next = NULL;
		list.last = list.last->pre;
		delete p;
	}
}

int main()
{
	Dlist list;
	khoiTao(list);
	nhap(list);
	cout << "\n\n\t\t Xuat Danh Sach Theo Chieu Thuan: ";
	xuatThuan(list);
	cout << "\n\n\t\t Xuat Danh Sach Theo Chieu Nguoc: ";
	xuatNguoc(list);
	int x;
	cout << "\n Nhap Gia Tri X: "; cin >> x;
	NODEPTR kq = new node;
	kq= timPhanTuX(list, x);
	if (kq == NULL)
	{
		cout << "\n Khong Tim Thay X ";
	}
	else
	{
		cout << "\n Da Tim Thay X " << kq->data<<" Trong Danh Sach ";
	}
	/*cout << "\n Xoa Phan Tu Dau Tien Trong Danh Sach Theo Chieu Thuan ";
	xoaDauThuan(list);
	xuatThuan(list);*/
	/*cout << "\n Xoa Phan Tu Dau Tien Trong Danh Sach Theo Chieu Nguoc ";
	xoaDauNguoc(list);
	xuatNguoc(list);*/
	cout << "\n Xoa Phan Tu Cuoi Cung Trong Danh Sach Theo Chieu Thuan ";
	xoaCuoiThuan(list);
	xuatThuan(list);
	return 0;
}