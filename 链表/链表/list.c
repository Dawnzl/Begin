#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <malloc.h>
 struct node //���ṹ 
 { int data; //��������intΪ�� 
  struct node  *next;//	ָ���򣬱�����һ�����ĵ�ַ 
 };
 //����ͷ��� ,���������� 
 struct node *  init_list();
 
 // ��������׷�Ӷ����� 
 void appendlist( struct node *h);
 
 //��������� 
 void printlist(struct node *h ); 
 
 //����׷��һ����� 
 void appendone( struct node *h,int x);
 
 //������½����ڵ�һ�� 
 void insertfirst(struct node *h,int x);
 
 //ɾ������ֵΪx�Ľ�� 
 //����1��ɾ���ɹ�������0�����ݲ����� 
 int delnode(struct node *h,int x);
 
 //������x�����y 
//��x�������������� 
void  insert(struct node *h,int x,int y); //h�ǵ������ͷ���ָ��

 main()
 {  struct node *la;//����ͷ����ָ�� 
   
    la=init_list(); //����ͷ��� 
 //��������׷�Ӷ����� 
    printf("\n����������0��ʾ������\n");
	appendlist(la); //�������� 1 2 3 4 5 0 
    printlist(la); 
//����׷��һ�� 
 	 int m=20; //�������� 
  printf("\n    ����׷�� 20 ");
 appendone(la,m);
   printf("\n");
 	printlist(la);
//�����½����ڵ�һ�� 
   int z=10; //�������� 
 printf("\n    ���Բ���10�ڵ�һ�����  ");	
	 insertfirst(la,z);
 	 printf("\n");
 	 printlist(la);
//����ɾ�� 
 	int  t,d=2; //��������
   printf("\n    ����ɾ�� 2 "); 
   t=delnode(la,d);
   if(t)  printf("\nɾ���ɹ�\n");
    else  printf("\n���ݲ�����\n");
     printf("\n");
  	printlist(la);
//���Բ���	
   int k=4,s=6; //��������
  printf("\n    ������4�����6  ");	
  insert(la,k,s); 
    printf("\n");
  	printlist(la);
}

//��������� 
 void printlist(struct node *h ) //h�ǵ������ͷ���ָ�� 
 {struct node *p1;
   p1=h->next; //p1��ʼֵΪ��һ�����ĵ�ַ 
   while(p1!=NULL) //p1��Ϊ�� 
 	 { printf("%d--->",p1->data); //���p1ָ��Ľ������ֵ 
 	 	p1=p1->next;  //p1����Ϊ��ǰ������һ�����ĵ�ַ 
	  }
 }
 
//����ͷ��� ,����������  
struct node * init_list()
  {   int n; 
      struct node   *pn;
  	 n=sizeof( struct node);//�����ռ�õ��ڴ�ռ��С����λ�ֽ� 
     pn =( struct node *)malloc(n); //����ͷ���ռ䣬������ָ�룬
	                                //ǿ������ת��Ϊ������� 
     pn->next=NULL;  //��һ����ַ�ÿ� 
     return pn;  //����ͷ����ַ 
  }

//�����������������ݣ�����0��ʾ������� 
//�ú������赥����Ϊ�գ�ֻ��ͷ��� 
void appendlist( struct node *h)//h�ǵ������ͷ���ָ��
{ struct node *pn,*end=NULL; 
  //pnָ���½�㣬endָ���������һ����� 
int x = 0;
  //����Ϊ�յ�׷�� 
 //  end=h; 
 //  while(end->next!=NULL) //�������һ����� 
//      end=end->next;  //end����ƶ� 
 // ����Ϊ�յ�׷����������3����� 
 
  do{
  	 scanf("%d",&x);//�������� 
  	 if(x!=0)
  	 {    // �����µĽ��ռ�
  	  pn =( struct node *)malloc(sizeof( struct node)); 
  	  pn->data=x; //��������������� 
	  pn->next=NULL; //ָ�����ÿ� 
  	  
	  if(h->next==NULL)	 //������	
	   { h->next=pn;  //�½��������ͷ���֮��
	     end=pn;  //��ǰ���Ҳ�����һ����� 
		} 
	  else  //�ǿձ� 
	    { end->next=pn;  //�½�����������һ�����֮�� 
	      end=pn;  //����endָ�����һ����� 
	    }
	   }
   	 
  }while(x!=0);

}

//����ĩβ׷��һ���½��  
void appendone( struct node *h,int x)//h�ǵ������ͷ���ָ��
{ struct node *pn,*end;
 //pnָ���½�㣬endָ���������һ�����
   end=h; 
   while(end->next!=NULL) //�������һ����� 
      end=end->next;  //end����ƶ� 
   
   //�����µĽ��ռ� 
    pn =( struct node *)malloc(sizeof( struct node));
    pn->data=x;  //��ֵ 
	pn->next=NULL;//ָ�����ÿ� 
  	  
	  if(h->next==NULL)	  //������		
	   {h->next=pn;  //�½��������ͷ���֮��
	    end=pn;  //����endָ�����һ����� 
		} 
	  else   //�ǿձ�  
	    { end->next=pn; //�½�����������һ�����֮�� 
	      end=pn;   //����endָ�����һ����� 
	    }
}
 
 //������½����ڵ�һ�� 
void insertfirst(struct node *h,int x)//h�ǵ������ͷ���ָ��
{  struct node *pn;
   //�����µĽ��ռ� 
    pn =( struct node *)malloc(sizeof( struct node));
    pn->data=x; //��ֵ 
	pn->next=NULL;//ָ�����ÿ� 
   
    pn->next=h->next;//�����½���ָ����ָ��ǰ�ĵ�һ����� 
	h->next=pn;	//�½����Ϊ��һ�� 
	
	
}

//ɾ������ֵΪx�Ľ�� 
int delnode(struct node *h,int x)//h�ǵ������ͷ���ָ��
{ struct node *p1,*p2;
  p1=h->next; //p1ָ���һ����� 
  p2=h; //p2��p1��ǰһ�� 
  while(p1!=NULL&&p1->data!=x)  //����xֱ������ĩβ 
	{ p2=p1;  //p2����p1��ֵ 
	  p1=p1->next; //p1����ƶ� 
	}
  if(p1!=NULL) //�ҵ� 
    { p2->next=p1->next;  //�޸�ǰ���ָ���ϵ
	  free(p1) ;  //�ͷŽ��ռ�
	  return 1; //ɾ���ɹ�
	  }
   else  
     return 0;    //û���ҵ� 
}

//������x�����y 
//��x�������������� 
void  insert(struct node *h,int x,int y) //h�ǵ������ͷ���ָ��
{
struct node *p1 ,*p2,*pn;
    //�����µĽ��ռ� 
    pn =( struct node *)malloc(sizeof( struct node));
    pn->data=y; //��ֵ 
	pn->next=NULL;//ָ�����ÿ� 
 
 //����x 
  p1=h->next; //p1ָ���һ����� 
  p2=h;  //p2��p1��ǰһ�� 
  while(p1!=NULL&&p1->data!=x)  //����xֱ������ĩβ 
	{ p2=p1; //p2����p1 
	  p1=p1->next; //p1����ƶ� 
	}
  if(p1!=NULL) //�ҵ� x
    { pn->next=p1->next;  //�޸�ǰ���ָ���ϵ
	  p1->next=pn;
	  }
   else  //û���ҵ� ���ǿ����� 
     p2->next=pn;  //�������    	
}

