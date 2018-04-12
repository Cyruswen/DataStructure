#include"book.h"
//TestBookListInit(){
//	TestType;
//	BookNode* phead;
//	BookListInit(&phead);
//	BookListPrint(phead,"初始化数组");
//}
//
//TestBookListInsert(){
//	TestType;
//	BookNode* phead;
//	BookListInit(&phead);
//	BookListInsert(&phead,"温凯凯","男",22,"17782794952","陕西科技大学六公寓");
//	BookListPrint(phead,"打印信息");
//	BookListInsert(&phead,"马晨佩","女",21,"18292000978","陕西科技大学四公寓");
////	BookListInsert(&phead,"赵悦","女",21,"15591848265","陕西科技大学九公寓");
//	BookListPrint(phead,"打印信息");
//}
//TestBookListFindPos(){
//	TestType;
//	BookNode* phead;
//	BookListInit(&phead);
//	BookListInsert(&phead,"温凯凯","男",22,"17782794952","陕西科技大学六公寓");
//	BookListInsert(&phead,"马晨佩","女",21,"18292000978","陕西科技大学四公寓");
//	BookListInsert(&phead,"赵悦","女",21,"15591848265","陕西科技大学九公寓");
//	BookNode* to_findname;
//	to_findname = BookListFindPos(phead,"马晨佩");
//	printf("name = %p\n",to_findname);
//	BookNode* to_findphone;
//	to_findphone = BookListFindPos(phead,"17782794952");
//	printf("telephone = %p\n",to_findphone);
//}
//
//TestBookListErase(){
//	TestType;
//	BookNode* phead;
//	BookListInit(&phead);
//	BookListInsert(&phead,"温凯凯","男",22,"17782794952","陕西科技大学六公寓");
//	BookListInsert(&phead,"马晨佩","女",21,"18292000978","陕西科技大学四公寓");
//	BookListInsert(&phead,"赵悦","女",21,"15591848265","陕西科技大学九公寓");
//	BookListInsert(&phead,"傻子","男",22,"18712221222","思思思思思思");
////	BookListErase(&phead,"傻子");
//	BookListErase(&phead,"赵悦");
//	BookListPrint(phead,"删除操作");
//}
//
//TestBookListFind(){
//	TestType;
//	BookNode* phead;
//	BookListInit(&phead);
//	BookListInsert(&phead,"温凯凯","男",22,"17782794952","陕西科技大学六公寓");
//	BookListInsert(&phead,"马晨佩","女",21,"18292000978","陕西科技大学四公寓");
//	BookListInsert(&phead,"赵悦","女",21,"15591848265","陕西科技大学九公寓");
//	BookListInsert(&phead,"傻子","男",22,"18712221222","思思思思思思");
//	BookListFind(phead,"赵悦");
//	BookListFind(phead,"17782794952");
//	BookListFind(phead,"张少敏");
//}
//
//TestBookListDestroy(){
//	TestType;
//	BookNode* phead;
//	BookListInit(&phead);
//	BookListDestroy(&phead);
//	BookListInsert(&phead,"温凯凯","男",22,"17782794952","陕西科技大学六公寓");
//	BookListInsert(&phead,"马晨佩","女",21,"18292000978","陕西科技大学四公寓");
//	BookListInsert(&phead,"赵悦","女",21,"15591848265","陕西科技大学九公寓");
//	BookListInsert(&phead,"傻子","男",22,"18712221222","思思思思思思");
//	BookListDestroy(&phead);
//	BookListPrint(phead," 销毁电话 ");
//}
//
//TestBookListChange(){
//	TestType;
//	BookNode* phead;
//	BookListInit(&phead);
//	BookListInsert(&phead,"温凯凯","男",22,"17782794952","陕西科技大学六公寓");
//	BookListInsert(&phead,"马晨佩","女",21,"18292000978","陕西科技大学四公寓");
//	BookListInsert(&phead,"赵悦","女",21,"15591848265","陕西科技大学九公寓");
//	BookListInsert(&phead,"傻子","男",22,"18712221222","思思思思思思");
//	BookListChange(&phead,"傻子",1,"智障");
//	BookListChange(&phead,"18712221222",2,"女");
//	BookListChange(&phead,"18712221222",4,"18710618809");
//	BookListChange(&phead,"18710618809",3,"32");
//	BookListChange(&phead,"智障",5,"陕西科技大学十一公寓");
//	BookListPrint(phead," 修改信息 ");
//}
//
//int main(){
//	TestBookListInit();
//	TestBookListInsert();
//	TestBookListFindPos();
//	TestBookListErase();
//	TestBookListFind();
//	TestBookListDestroy();
//	TestBookListChange();
//	return 0;
//}
//   1.修改姓名 2.修改性别
//   3.修改年龄 4.修改电话号码
//   5.修改地址
//	 1.添加联系人 2.删除联系人 3.修改联系人 4.查找联系人 5.查看所有联系人 6.清空联系人

int main(){
	BookNode* phead;
	BookListInit(&phead);
    char uname[20];
    char ugender[8];
    int uage;
    char utelephone[20];
    char uaddress[100];

	while(1){
        int choose = 0;
        TelephoneBookMenu();
        printf("请选择：");
        scanf("%d",&choose);
		switch(choose){
            case 0:
                    exit(1);
			case 1: 
               {    
                    printf("请输入姓名：\n");
					scanf("%s",uname);	
					printf("请输入性别：\n");
					scanf("%s",ugender);
					printf("请输入年龄：\n");
					scanf("%d",&uage);
					printf("请输入电话号：\n");
					scanf("%s",utelephone);
					printf("请输入地址：\n");
					scanf("%s",uaddress);
			    	BookListInsert(&phead,uname,ugender,uage,utelephone,uaddress);
               }
				    break;
	    	case 2:
	    		{
	    			printf("请输入删除联系人姓名:\n");
	    			scanf("%s",uname);
	    			BookListErase(&phead,uname);
	    		}break;
            case 3:
                {
                   int choose2 = 0;
                   char newmsg[100];
                   printf("请输入修改联系人姓名\n");
                   scanf("%s",uname);
                   printf("#############################################################\n");
                   printf("#########1.修改姓名 ##############2.修改年龄#################\n");
                   printf("#############################################################\n");
                   printf("#########3.修改电话号码###########4.修改地址#################\n");
                   printf("#############################################################\n");
                   printf("请选择：");
                   scanf("%d",&choose2);
                   printf("请输入修改信息：\n");
                   scanf("%s",newmsg);
                   BookListChange(&phead,uname,choose2,newmsg);
               }break;
           case 4:
               {
                   printf("请输入查找联系人姓名：\n");
                   scanf("%s",uname);
                   BookListFind(phead,uname);
               }break;
           case 5:
               {
                   BookListPrint(phead,"联系人信息");
               }break;
           case 6:
               {
                   BookListDestroy(&phead);
               }break;
		}
	}
}
