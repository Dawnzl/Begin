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

void PrevOrder(BTNode* root)//ǰ��
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

void InOrder(BTNode* root)  //����
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


void PostOrder(BTNode* root)//����
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




//�ڵݹ�����У�����������ʱ����������᲻���������¿�ʼ
//����һ�����Σ�ͨ������������
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
	//�����㷨����˼·��ǰ�������ͬ��int�ķ���ֵ�᲻�ϼ�¼����
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;

}

int TreeLeafSize(BTNode* root)//Ҷ�ӽ��
{
	//������Ҷ��
	if (root == NULL)
	{
		return 0;
	}
	//����Ϊ�սڵ���Ҷ��
	if (root->left == NULL & root->right == NULL)
	{
		return 1;
	}

	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

//k>0 ���k��Ľڵ����
//���Էֻ�����������k-1�ĸ��� + ��������k-1�ĸ���
int TreeKLevelSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return TreeKLevelSize(root->left, k - 1) +
		TreeKLevelSize(root->right, k - 1);
}

//����������ֵΪx���Ǹ��ڵ� 
//˼·��
//1.root == NULL return NULL
//2.root �ڵ㲻��������Ҫ�ҵģ��ȵ������ң����û���ٵ�������
//3.�����û�У���ǰ��û������Ҫ�ҵĽڵ㣬����NULL
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	//�����
	if (root->data == x)
		return root;
	//��������ȥ��
	BTNode* lret = TreeFind(root->left, x);
	if (lret)
		return lret;
	//����������
	BTNode* rret = TreeFind(root->right, x);
	if (rret)
		return rret;
	//��������Ǿͷ���NULL
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

//���ٶ�������������򵥣�
void BinaryTreeDestory(BTNode* root)
//void BinaryTreeDestory(BTNode*& root)
//c++�Խṹȡ��������ֱ���ں������ÿ�Ұָ�루������ȡ����ֱ�����ã�
{
	if (root == NULL)
		return NULL;
	//�������������ٺ��������Լ�
	//Ҷ�ӽ������������������NULL��free���Լ�
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}

////���ֶ��ÿհ汾���ٶ�������������򵥣�
//void BinaryTreeDestory(BTNode** pproot)
//{
//	if (*pproot == NULL)
//		return NULL;
//	//�������������ٺ��������Լ�
//	//Ҷ�ӽ������������������NULL��free���Լ�
//	BinaryTreeDestory(&(*pproot)->left);
//	BinaryTreeDestory(&(*pproot)->right);
//	//��ʱ�����ٺ����Ĵ���Ҫ����ָ�룬�������ҵ�������������Ҫ�������ĵ�ַ�����������
//
//	free(*pproot);
//	*pproot = NULL;//�����ֶ��ÿհ汾
//}

//������������ö��У�//�е�����
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

		//���ֵ�һ��NULL���˳�����ʱ������ֻʣ��NULL
		if (front == NULL)
			break;

		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
		
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		//ֻҪ����һ���ǿվͲ�����ȫ������
		if (front)
			return false;
	}
	QueueDestroy(&q);
	return true;

}



int main()
{

	//�ֶ�����
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
	A = NULL;//�ÿ�Ұָ��

	
	return 0;
}