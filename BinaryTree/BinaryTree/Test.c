#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"Queue.h"

typedef char BTDataType;
struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
};

typedef struct BinaryTreeNode BTNode;

void PrevOrder(BTNode* root)//前序
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

void InOrder(BTNode* root)  //中序
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}


void PostOrder(BTNode* root)//后序
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);

}




//在递归调用中，不能设置临时变量。否则会不断置零重新开始
//设置一个传参，通过参数算总数
void TreeSize1(BTNode* root, int* psize)
{
	if (root == NULL)
	{
		return;
	}
	++(*psize);
	TreeSize1(root->left, psize);
	TreeSize1(root->right, psize);
}

int TreeSize(BTNode* root)
{
	//分治算法，其思路和前序遍历相同，int的返回值会不断记录个数
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;

}

int TreeLeafSize(BTNode* root)//叶子结点
{
	//空树无叶子
	if (root == NULL)
	{
		return 0;
	}
	//左右为空节点是叶子
	if (root->left == NULL & root->right == NULL)
	{
		return 1;
	}

	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

//k>0 求第k层的节点个数
//可以分化成左子树的k-1的个数 + 右子树的k-1的个数
int TreeKLevelSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return TreeKLevelSize(root->left, k - 1) +
		TreeKLevelSize(root->right, k - 1);
}

//查找树里面值为x的那个节点 
//思路：
//1.root == NULL return NULL
//2.root 节点不是我们所要找的，先到左数找，如果没有再到右树找
//3.如果都没有，则当前树没有我们要找的节点，返回NULL
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	//如果是
	if (root->data == x)
		return root;
	//到左子树去找
	BTNode* lret = TreeFind(root->left, x);
	if (lret)
		return lret;
	//到右子树找
	BTNode* rret = TreeFind(root->right, x);
	if (rret)
		return rret;
	//如果都不是就返回NULL
	return NULL;
}

BTNode* CreateTreeNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));

	printf("node:%p\n ", node);

	node->data = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}

//销毁二叉树（后序最简单）
void BinaryTreeDestory(BTNode* root)
//void BinaryTreeDestory(BTNode*& root)
//c++对结构取别名可以直接在函数中置空野指针（将参数取别名直接引用）
{
	if (root == NULL)
		return NULL;
	//把左右子树销毁后再销毁自己
	//叶子结点面临左右子树返回NULL后free掉自己
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}

////非手动置空版本销毁二叉树（后序最简单）
//void BinaryTreeDestory(BTNode** pproot)
//{
//	if (*pproot == NULL)
//		return NULL;
//	//把左右子树销毁后再销毁自己
//	//叶子结点面临左右子树返回NULL后free掉自己
//	BinaryTreeDestory(&(*pproot)->left);
//	BinaryTreeDestory(&(*pproot)->right);
//	//此时的销毁函数的传参要二级指针，解引用找到左右子树后需要将子树的地址放入参数才行
//
//	free(*pproot);
//	*pproot = NULL;//不用手动置空版本
//}

//层序遍历（利用队列）//有点问题
void TreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		printf("%c ", front->data);
		if (front->left)
		{
			QueuePush(&q, front->left);
		}

		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}
	printf("\n");

	QueueDestroy(&q);
}

bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		printf("front:%p \n", front);

		QueuePop(&q);

		//出现第一个NULL就退出，此时队列里只剩下NULL
		if (front == NULL)
			break;

		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
		
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		//只要出现一个非空就不是完全二叉树
		if (front)
			return false;
	}
	QueueDestroy(&q);
	return true;

}



int main()
{

	//手动接树
	BTNode* A = CreateTreeNode('A');
	BTNode* B = CreateTreeNode('B');
	BTNode* C = CreateTreeNode('C');
	BTNode* D = CreateTreeNode('D');
	BTNode* E = CreateTreeNode('E');
	BTNode* F = CreateTreeNode('F');

	A->left = B;
	A->right = C;
	B->left = D;
	C->left = E;
	C->right = F;

	PrevOrder(A);
	printf("\n");

	InOrder(A);
	printf("\n");

	PostOrder(A);
	printf("\n");

	int size = 0;
	TreeSize1(A, &size);
	printf("size = %d\n",size);

	printf("size = %d\n", TreeSize(A));

	printf("TreeLeafSize:%d\n", TreeLeafSize(A));
	printf("TreeKLevelSize:%d\n", TreeKLevelSize(A, 3));
	printf("TreeFind:%p\n", TreeFind(A, 'E'));
	printf("TreeFind:%p\n", TreeFind(A, 'X'));

	TreeLevelOrder(A);

	printf("BinaryTreeComplete:%d\n", BinaryTreeComplete(A));

	BinaryTreeDestory(A);
	A = NULL;//置空野指针

	
	return 0;
}