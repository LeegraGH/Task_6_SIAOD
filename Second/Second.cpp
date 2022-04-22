#include <iostream>

// Определить количество вхождений: положительных, отрицательных, нулевых значений в линейном однонаправленном списке.

using namespace std;

struct Node // узел списка
{
	int element; // данные узла
	Node* next; // указатель на следующий узел
	Node(int _element) : element(_element), next(nullptr) {};
};

struct List // однонаправленный список
{
	Node* first; // указатель на первый узел списка
	Node* last; // указатель на последний узел списка
	List() : first(nullptr), last(nullptr) {};

	void addNode(int element) // добавление узла в список
	{
		Node* p = new Node(element);
		if (first == nullptr)
		{
			first = p;
			last = p;
		}
		else
		{
			Node* temp = first;
			first = p;
			first->next = temp;
		}
	}

	void delNode(int element) // удаление узла по элементу
	{
		if (first->element == element)
		{
			Node* temp = first;
			first = first->next;
			delete temp;
			return;
		}
		else if (last->element == element)
		{
			Node* p = first;
			while (p->next != last)
			{
				p = p->next;
			}
			delete last;
			p->next = nullptr;
			last = p;
		}
		else
		{
			Node* p = first;
			Node* nxt = p->next;
			while (nxt->element != element)
			{
				p = p->next;
				nxt = p->next;
			}
			p->next = nxt->next;
			delete nxt;
		}
	}

	void outputList() // вывод списка
	{
		Node* p = first;
		while (p != nullptr)
		{
			cout << p->element << " ";
			p = p->next;
		}
	}
};

void createList(List& L)
{
	cout << "Введите количество элементов в списке: ";
	int n;
	cin >> n;
	cout << "Введенные вами элементы: ";
	if (n != 0)
	{
		for (int i = 0; i < n; i++)
		{
			int el;
			cin >> el;
			L.addNode(el);
		}
	}
}

int countPositive(Node* node, int k)
{
	if (node == nullptr) return k;
	if (node->element > 0) k += 1;
	node = node->next;
	countPositive(node, k);
}

int countNegative(Node* node, int k)
{
	if (node == nullptr) return k;
	if (node->element < 0) k += 1;
	node = node->next;
	countNegative(node, k);
}

int countZero(Node* node, int k)
{
	if (node == nullptr) return k;
	if (node->element == 0) k += 1;
	node = node->next;
	countZero(node, k);
}

int main()
{
	setlocale(LC_ALL, "Rus");
	List L;
	createList(L);
	int k = 0;
	cout << "Количество положительных значений в списке: " << countPositive(L.first, k) << endl;
	k = 0;
	cout << "Количество отрицательных значений в списке: " << countNegative(L.first, k) << endl;
	k = 0;
	cout << "Количество нулевых значений в списке: " << countZero(L.first, k);
	return(0);
}