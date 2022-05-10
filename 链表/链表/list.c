#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <malloc.h>
 struct node //结点结构 
 { int data; //数据域，以int为例 
  struct node  *next;//	指针域，保存下一个结点的地址 
 };
 //创建头结点 ,产生单链表 
 struct node *  init_list();
 
 // 链表连续追加多个结点 
 void appendlist( struct node *h);
 
 //输出单链表 
 void printlist(struct node *h ); 
 
 //链表追加一个结点 
 void appendone( struct node *h,int x);
 
 //插入的新结点放在第一个 
 void insertfirst(struct node *h,int x);
 
 //删除数据值为x的结点 
 //返回1，删除成功，返回0，数据不存在 
 int delnode(struct node *h,int x);
 
 //在数据x后插入y 
//若x不存在则放置最后 
void  insert(struct node *h,int x,int y); //h是单链表的头结点指针

 main()
 {  struct node *la;//链表头结点的指针 
   
    la=init_list(); //创建头结点 
 //测试连续追加多个结点 
    printf("\n输入整数，0表示结束：\n");
	appendlist(la); //测试数据 1 2 3 4 5 0 
    printlist(la); 
//测试追加一个 
 	 int m=20; //测试数据 
  printf("\n    测试追加 20 ");
 appendone(la,m);
   printf("\n");
 	printlist(la);
//测试新结点放在第一个 
   int z=10; //测试数据 
 printf("\n    测试插入10在第一个结点  ");	
	 insertfirst(la,z);
 	 printf("\n");
 	 printlist(la);
//测试删除 
 	int  t,d=2; //测试数据
   printf("\n    测试删除 2 "); 
   t=delnode(la,d);
   if(t)  printf("\n删除成功\n");
    else  printf("\n数据不存在\n");
     printf("\n");
  	printlist(la);
//测试插入	
   int k=4,s=6; //测试数据
  printf("\n    测试在4后插入6  ");	
  insert(la,k,s); 
    printf("\n");
  	printlist(la);
}

//输出单链表 
 void printlist(struct node *h ) //h是单链表的头结点指针 
 {struct node *p1;
   p1=h->next; //p1初始值为第一个结点的地址 
   while(p1!=NULL) //p1不为空 
 	 { printf("%d--->",p1->data); //输出p1指向的结点数据值 
 	 	p1=p1->next;  //p1更新为当前结点的下一个结点的地址 
	  }
 }
 
//创建头结点 ,产生单链表  
struct node * init_list()
  {   int n; 
      struct node   *pn;
  	 n=sizeof( struct node);//结点所占用的内存空间大小，单位字节 
     pn =( struct node *)malloc(n); //申请头结点空间，返回其指针，
	                                //强制类型转换为结点类型 
     pn->next=NULL;  //下一结点地址置空 
     return pn;  //返回头结点地址 
  }

//连续输入多个整型数据，输入0表示输入结束 
//该函数假设单链表为空，只有头结点 
void appendlist( struct node *h)//h是单链表的头结点指针
{ struct node *pn,*end=NULL; 
  //pn指向新结点，end指向链表最后一个结点 
int x = 0;
  //链表不为空的追加 
 //  end=h; 
 //  while(end->next!=NULL) //查找最后一个结点 
//      end=end->next;  //end向后移动 
 // 链表不为空的追加增加以上3行语句 
 
  do{
  	 scanf("%d",&x);//输入数据 
  	 if(x!=0)
  	 {    // 申请新的结点空间
  	  pn =( struct node *)malloc(sizeof( struct node)); 
  	  pn->data=x; //结点数据域存放数据 
	  pn->next=NULL; //指针域置空 
  	  
	  if(h->next==NULL)	 //空链表	
	   { h->next=pn;  //新结点链接在头结点之后
	     end=pn;  //当前结点也是最后一个结点 
		} 
	  else  //非空表 
	    { end->next=pn;  //新结点链接在最后一个结点之后 
	      end=pn;  //更新end指向最后一个结点 
	    }
	   }
   	 
  }while(x!=0);

}

//链表末尾追加一个新结点  
void appendone( struct node *h,int x)//h是单链表的头结点指针
{ struct node *pn,*end;
 //pn指向新结点，end指向链表最后一个结点
   end=h; 
   while(end->next!=NULL) //查找最后一个结点 
      end=end->next;  //end向后移动 
   
   //申请新的结点空间 
    pn =( struct node *)malloc(sizeof( struct node));
    pn->data=x;  //赋值 
	pn->next=NULL;//指针域置空 
  	  
	  if(h->next==NULL)	  //空链表		
	   {h->next=pn;  //新结点链接在头结点之后
	    end=pn;  //更新end指向最后一个结点 
		} 
	  else   //非空表  
	    { end->next=pn; //新结点链接在最后一个结点之后 
	      end=pn;   //更新end指向最后一个结点 
	    }
}
 
 //插入的新结点放在第一个 
void insertfirst(struct node *h,int x)//h是单链表的头结点指针
{  struct node *pn;
   //申请新的结点空间 
    pn =( struct node *)malloc(sizeof( struct node));
    pn->data=x; //赋值 
	pn->next=NULL;//指针域置空 
   
    pn->next=h->next;//设置新结点的指针域指向当前的第一个结点 
	h->next=pn;	//新结点作为第一个 
	
	
}

//删除数据值为x的结点 
int delnode(struct node *h,int x)//h是单链表的头结点指针
{ struct node *p1,*p2;
  p1=h->next; //p1指向第一个结点 
  p2=h; //p2是p1的前一个 
  while(p1!=NULL&&p1->data!=x)  //查找x直到链表末尾 
	{ p2=p1;  //p2保存p1的值 
	  p1=p1->next; //p1向后移动 
	}
  if(p1!=NULL) //找到 
    { p2->next=p1->next;  //修改前后的指向关系
	  free(p1) ;  //释放结点空间
	  return 1; //删除成功
	  }
   else  
     return 0;    //没有找到 
}

//在数据x后插入y 
//若x不存在则放置最后 
void  insert(struct node *h,int x,int y) //h是单链表的头结点指针
{
struct node *p1 ,*p2,*pn;
    //申请新的结点空间 
    pn =( struct node *)malloc(sizeof( struct node));
    pn->data=y; //赋值 
	pn->next=NULL;//指针域置空 
 
 //查找x 
  p1=h->next; //p1指向第一个结点 
  p2=h;  //p2是p1的前一个 
  while(p1!=NULL&&p1->data!=x)  //查找x直到链表末尾 
	{ p2=p1; //p2保存p1 
	  p1=p1->next; //p1向后移动 
	}
  if(p1!=NULL) //找到 x
    { pn->next=p1->next;  //修改前后的指向关系
	  p1->next=pn;
	  }
   else  //没有找到 或是空链表 
     p2->next=pn;  //插入最后    	
}

