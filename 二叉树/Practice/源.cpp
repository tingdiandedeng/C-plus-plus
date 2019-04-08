#include<iostream>
using namespace std;
template <typename T>
struct BSnode
{
	T d;
	BSnode* lchild;
	BSnode* rchild;
};
template <typename T>
class BS_Tree
{
public:
	BS_Tree() { BT = NULL; return; }
	void insert_BS_Tree(T);
	void intrav_BS_Tree();
private:
	BSnode<T>* BT;
};
template <typename T>
void BS_Tree<T>::intrav_BS_Tree()
{
	BSnode<T>* p;
	p = BT;
	intrav(p);
	return;
}
template <typename T>
static int intrav(BSnode<T>* p)
{
	if (p != NULL)
	{
		intrav(p->lchild);
		cout << p->d << " ";
		intrav(p->rchild);
	}
	return 0;
}
template <typename T>
void BS_Tree<T>::insert_BS_Tree(T x)
{
	BSnode<T>*p, *q;
	p = new BSnode<T>;
	p->d = x;
	p->lchild = NULL; p->rchild = NULL;
	q = BT;
	if (q == NULL) BT = p;
	else
	{
		while ((q->lchild != p) && (q->rchild != p))
		{
			if (x < q->d)
			{
				if (q->lchild != NULL) q = q->lchild;
				else q->lchild = p;
			}
			else
			{
				if (q->rchild != NULL) q = q->rchild;
				else q->rchild = p;
			}
		}
	}
	return;
}
int main()
{
	int k, a;
	int d[12] = { 04,18,13,79,33,45,06,23,35,12,34,76 };
	BS_Tree<int> b;
	for (k = 0; k < 12; k++)
		b.insert_BS_Tree(d[k]);
	cout << "中序输出结果为：\n";
	b.intrav_BS_Tree();
	cout << endl;
	cout << "输入你想插入的数字：\n";
	cin >> a;
	b.insert_BS_Tree(a);
	cout << "插入新数字后，结果为：\n";
	b.intrav_BS_Tree();
	cout << endl;
	return 0;
}