#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stu//学生节点
{
    char name[20];//
    char number[20];//
    char sex[10];//
    int chinese;//
    int math;//
    int english;//
    float average;//
    struct stu* pNext;
} stunote;
stunote* head=NULL;//声明链表头
stunote* end=NULL;//生命链表尾
void addnote(char number[20],char name[20],char sex[10],int chinese,int math,int english,float average);//添加学生信息
void addhead(char number[20],char name[20],char sex[10],int chinese,int math,int english,float average);//在头部添加学生信息
void addend(char number[20],char name[20],char sex[10],int chinese,int math,int english,float average);//在尾部添加学生信息
void add(stunote* pTemp,char number[20],char name[20],char sex[10],int chinese,int math,int english,float average);//在指定位置添加学生信息
void freelinkdata();//清空链表
void showdata(stunote *);//打印数据
void showorder();//显示指令
stunote* findstu(char* number);//查找指定学生
void deletestunote(stunote* pNode);//删除指定的学生
void savetofile();//保存信息到文件中
void readfile();//读取文件中的学生信息
void paixumeun();
stunote *paixu(stunote *head);                       //排序
int main (void)
{
    int nOrder = -1;
    char name[20] = {'\0'};
    char number[20] = {'\0'};
    char sex[10]= {'\0'};
    int chinese=-1;
    int math=-1;
    int english=-1;
    int nFlag = 1;
    float average;
    int n;//输入学生的数目
    int i=1;//i为第几名学生
    struct stunote * prev, * pTemp;
    printf("      学生管理系统\n");
    printf("        操作命令：\n");
    //printf("1.输入学生信息\n");
    printf("  1.在尾部增加一个学生信息\n");
    printf("   11.在起始位置增加一个学生信息\n");
    printf("   111.在指定位置添加一个学生信息\n");
    printf("  2.查找指定学生的信息（姓名/学号）\n");
    printf("  3.删除指定学生的信息\n");
    printf("  4.修改指定学生的信息\n");
    printf("  5.显示所有学生的信息\n");
    printf("  6.按平均成绩排序（降序）\n");
    //printf("7.读取指定文件里的学生信息\n");
    printf("  7.保存学生的信息到文件中\n");
    printf("  8.恢复删除的学生的信息\n");
    printf("  0.退出系统\n\n");
    readfile();//读取文件
    while (nFlag)
    {
        printf("请输入指令(10查看指令):\n");
        scanf("%d", &nOrder);
        switch (nOrder)
        {

        /*case 1://输入学生信息
            printf("需要输入多少学生的信息？");
            scanf("%d",&n);
            if (n>0)
            {
                printf("输入第%d名学生的学号、姓名、性别、语文分数、数学分数、英语分数\n",i);
                scanf("%s %s %s %d %d %d",number,name,sex,&chinese,&math,&english);
                average=(chinese+math+english)/3;
                addnote(number,name,sex,chinese,math,english,average);
                prev = pTemp;
                i++;
                n--;
            }
            break;*/
        case 1://输入学生信息（尾部）
            printf("输入学生的学号、姓名、性别、语文分数、数学分数、英语分数\n");
            scanf("%s %s %s %d %d %d",number,name,sex,&chinese,&math,&english);
            average=(chinese+math+english)/3;
            addnote(number,name,sex,chinese,math,english,average);//调用addnote
            break;
        case 11://添加一个学生信息（在开始）
            printf("输入学生的学号、姓名、性别、语文分数、数学分数、英语分数\n");
            scanf("%s %s %s %d %d %d",number,name,sex,&chinese,&math,&english);
            average=(chinese+math+english)/3;
            addhead(number,name,sex,chinese,math,english,average);//调用addhead
            break;
        case 111://指定位置添加学生信息
            printf("输入插入处的学生学号");
            scanf("%s",number);
            stunote* pTemp;
            pTemp = findstu(number);
            if (NULL != pTemp)
            {
                printf("输入学生的学号、姓名、性别、语文分数、数学分数、英语分数\n");
                scanf("%s %s %s %d %d %d",number,name,sex,&chinese,&math,&english);
                average=(chinese+math+english)/3;
                add(pTemp,number,name,sex,chinese,math,english,average);
            }
            break;
        case 2://查找指定学生
            printf("输入指定学号\n");
            scanf("%s",number);
            pTemp = findstu(number);
            if (NULL != pTemp) //输出学生信息
            {
                printf("学号:%s, 姓名:%s, 性别:%s, 语文分数:%d， 数学分数:%d, 英语分数:%d, 平均分数:%f\n", pTemp->number, pTemp->name, pTemp->sex,pTemp->chinese, pTemp->math,pTemp->english,pTemp->average);
            }
            break;
        case 3://删除指定学生的信息
            printf("输入要删除的学生的学号\n");
            scanf("%s", number);
            pTemp = findstu(number);//查找
            if (NULL != pTemp) //删除一个节点
            {
                deletestunote(pTemp);
            }
            break;
        case 4://修改指定学生信息
            printf("输入指定学生的学号\n");//查找指定学生的信息
            scanf("%s", number);
            pTemp = findstu(number);//查找
            if (NULL != pTemp) //打印
            {
                printf("请输入学号\n");//修改学号
                scanf("%s", number);
                strcpy(pTemp->number, number);
                printf("请输入姓名\n");//修改名字
                scanf("%s", name);
                strcpy(pTemp->name, name);
                printf("请输入性别\n");//修改名字
                scanf("%s", sex);
                strcpy(pTemp->sex,sex);
                printf("请输入语文分数\n");//修改语文分数
                scanf("%d", &chinese);
                pTemp->chinese = chinese;
                printf("请输入数学分数\n");//修改数学分数
                scanf("%d", &math);
                pTemp->math = math;
                printf("请输入英语分数\n");//修改英语分数
                scanf("%d", &english);
                pTemp->english = english;
                average=(chinese+math+english)/3;//平均分更改
                pTemp->average = average;
            }
            break;
        case 5://显示所有学生的信息
            showdata(head);
            break;
        case 6://按平均成绩排序（降序）
            //printf("尚未实现_(:зゝ∠)_\n");
            //system("cls");
            //paixumeun();

            head=paixu(head);
            printf("请输入指令(10查看指令):\n");
            getchar();
            break;
        //case 7://读取文件里的学生信息
        //printf("尚未实现_(:зゝ∠)_\n");
        //break;
        case 7://保存学生的信息到文件中
            savetofile();
            break;
        case 8://恢复删除的学生的信息
            freelinkdata();
            head = NULL;
            end = NULL;
            readfile();
            break;
        case 10://查看指令
            showorder();
            break;
        case 0:
            nFlag = 0;
            break;
        default:
            printf("not right\n");
        }
    }
    savetofile();//保存学生信息
    freelinkdata();//释放链表
    return 0;
}
void addnote(char number[20],char name[20],char sex[10],int chinese,int math,int english,float average)//添加学生信息
{
    stunote* pTemp = (stunote*)malloc (sizeof (stunote));//创建一个节点

    if (NULL == number || NULL == name || NULL ==sex|| chinese < 0|| math<0|| english<0)//检验参数的合法性
    {
        printf("学生信息输入错误！\n");
        return;
    }
    //赋值
    strcpy(pTemp->number, number);
    strcpy(pTemp->name, name);
    strcpy(pTemp->sex, sex);
    pTemp->chinese = chinese;
    pTemp->math = math;
    pTemp->english=english;
    pTemp->average=average;
    pTemp->pNext = NULL;
    //接在链表上
    if (NULL == head || NULL == end)
    {
        head = pTemp;
    }
    else
    {
        end->pNext = pTemp;
    }
    end = pTemp;
}
void addhead(char number[20],char name[20],char sex[10],int chinese,int math,int english,float average)//在头部添加学生信息
{
    stunote* pTemp = (stunote*)malloc(sizeof(stunote));//创建一个节点
    if (NULL == number || NULL == name || chinese < 0||math<0||english<0)//检验参数的合法性
    {
        printf("学生信息输入错误！\n");
        return;
    }
    strcpy(pTemp->number, number);//复制字符
    strcpy(pTemp->name, name);
    strcpy(pTemp->sex,sex);
    pTemp->chinese = chinese;
    pTemp->math = math;
    pTemp->english=english;
    pTemp->pNext = NULL;
    if (NULL == head || NULL == end)
    {
        end = pTemp;
    }
    else
    {
        pTemp->pNext = head;
    }

    head = pTemp;
}
void add(stunote* pTemp,char number[20],char name[20],char sex[20],int chinese,int math,int english,float average)//在指定位置添加学生信息
{
    stunote* pNewTemp = (stunote*)malloc(sizeof(stunote));//创建节点
    strcpy(pNewTemp->number, number);//赋值
    strcpy(pNewTemp->name, name);
    strcpy(pNewTemp->sex,sex);
    pNewTemp->chinese = chinese;
    pNewTemp->math = math;
    pNewTemp->english = english;
    pNewTemp->pNext = NULL;
    //判断插入位置是否为未结点
    if (pTemp == end)
    {
        end->pNext = pNewTemp;
        end = pNewTemp;
    }
    else
    {
        pNewTemp->pNext =  pTemp->pNext;
        pTemp->pNext =  pNewTemp;
    }
}
void freelinkdata()//清空链表
{
    stunote* pTemp = head;
    while (head != NULL)
    {
        //记录结点
        pTemp = head;
        //向后移动一个
        head = head->pNext;
        //删除节点
        free(pTemp);
    }
}
void showdata(stunote *phead)//打印数据
{
    stunote* pTemp = phead;
    while (NULL != pTemp)
    {
        printf("学号:%s, 姓名:%s, 性别:%s语文分数:%d， 数学分数:%d, 英语分数:%d, 平均分数:%f\n",pTemp->number, pTemp->name, pTemp->sex,pTemp->chinese, pTemp->math,pTemp->english,pTemp->average);
        pTemp = pTemp->pNext;//向下走一步
    }
}
void showorder()//显示指令
{
    printf("操作命令：\n");
    printf(" 1.在尾部增加一个学生信息\n");
    printf("  11.在起始位置增加一个学生信息\n");
    printf("  111.在指定位置添加一个学生信息\n");
    printf("2.查找指定学生的信息（姓名/学号）\n");
    printf("3.删除指定学生的信息\n");
    printf("4.修改指定学生的信息\n");
    printf("5.显示所有学生的信息\n");
    printf("6.按平均成绩排序（降序）\n");
    //printf("7.读取文件里的学生信息\n");
    printf("7.保存学生的信息到文件中\n");
    printf("8.恢复删除的学生的信息\n");
    printf("0.退出系统\n");
    printf("请输入指令(10查看指令):\n");
}
stunote* findstu(char* number)//查找指定学生
{
    stunote* pTemp = head;
    //判断参数的合法性
    if (NULL == number)
    {
        printf("学号输入错误！\n");
        return NULL;
    }
    //判断链表是否为空
    if (NULL == head || NULL ==end)
    {
        printf("链表为NULL！\n");
        return NULL;
    }
    //遍历链表
    while (NULL != pTemp)
    {
        if (0 == strcmp(pTemp->number, number))
        {
            return pTemp;
        }
        pTemp = pTemp->pNext;
    }
    printf("查无此节点！\n");
    return NULL;
}
void deletestunote(stunote* pNode)//删除指定的学生
{
    //只有一个节点
    if (head == end)
    {
        free(head);
        head = NULL;
        end = NULL;
        return;
    }
    //如果是首节点
    if (head == pNode)
    {
        free(head);
        head = head->pNext;
        return;
    }
    //如果是尾节点
    stunote* pTemp = head;
    if (end == pNode)
    {
        while (pTemp->pNext != pNode)
        {
            pTemp = pTemp->pNext;
        }
        pTemp->pNext = NULL;
        end = pTemp;
        free(pNode);
        return;
    }
    //如果是中间节点
    if (pNode != head && pNode != end && head != end)
    {
        while (pTemp->pNext != pNode)
        {
            pTemp = pTemp->pNext;
        }
        pTemp->pNext = pNode->pNext;
        free(pNode);
        return;
    }
}
void savetofile()//保存信息到文件中
{
    FILE* pFile = NULL;
    stunote* pTemp = head;
    char strBuf[30] = {0};
    char strScore[30] = {0};
    //判断链表中是否为null
    if (head == NULL)
    {
        printf("没有学生\n");
        return;
    }
    pFile = fopen("date.txt", "wb+");//打开文件
    if (NULL == pFile)
    {
        printf("文件打开失败！\n");
        return;
    }
    while (NULL != pTemp)//操作文件指针
    {
        strcpy(strBuf, pTemp->number);//学号赋值进去
        strcat(strBuf, ",");
        strcat(strBuf, pTemp->name);//姓名
        strcat(strBuf, ",");
        strcat(strBuf, pTemp->sex);//性别
        strcat(strBuf, ",");
        snprintf(strScore, 30, "%d,%d,%d,%f", pTemp->chinese,pTemp->math,pTemp->english,pTemp->average);  //分数
        //拼接字符串
        strcat(strBuf, strScore);
        fwrite(strBuf, 1, strlen(strBuf), pFile);
        fwrite("\r\n", 1, strlen("\r\n"), pFile);
        pTemp = pTemp->pNext;
    }
    //关闭文件
    fclose(pFile);
}
void readfile()//读取文件中的学生信息
{
    FILE* pFile = fopen("date.txt", "rb+");
    char strBuf[30] = {0};
    char strStuNum[10] = {0};
    char strStuName[10] = {0};
    char strsex[10]= {0};
    char strchinese[10]= {0};
    char strmath[10]= {0};
    char strenglish[10]= {0};
    char straverage[10]= {0};
    int nCount = 0;
    int chinese;
    int math;
    int english;
    int average;
    if (NULL == pFile)
    {
        printf("文件打开失败\n");
        return;
    }
    //从文件中读取
    while (NULL != fgets(strBuf, 30, pFile))
    {
        int i = 0;
        int j = 0;
        int nCount = 0;
        for (i = 0; strBuf[i] != '\r'; i++)
        {
            //没到.
            if (0 == nCount)
            {
                strStuNum[i] = strBuf[i];
                if (',' == strBuf[i])
                {
                    strStuNum[i] = '\0';
                    nCount++;
                }
            }
            else if (1 == nCount)
            {
                if (',' != strBuf[i])
                {
                    strStuName[j] = strBuf[i];
                    j++;
                }
                if (',' == strBuf[i])
                {
                    strStuName[j] = '\0';
                    nCount++;
                    j = 0;
                }

            }
            else if (2== nCount)
            {
                if (',' != strBuf[i])
                {
                    strsex[j] = strBuf[i];
                    j++;
                }
                if (',' == strBuf[i])
                {
                    strsex[j] = '\0';
                    nCount++;
                    j = 0;
                }
            }
            else if (3== nCount)
            {
                if (',' != strBuf[i])
                {
                    strchinese[j] = strBuf[i];
                    j++;
                }
                if (',' == strBuf[i])
                {
                    strchinese[j] = '\0';
                    nCount++;
                    j = 0;
                }
            }
            else if (4== nCount)
            {
                if (',' != strBuf[i])
                {
                    strmath[j] = strBuf[i];
                    j++;
                }
                if (',' == strBuf[i])
                {
                    strmath[j] = '\0';
                    nCount++;
                    j = 0;
                }
            }
            else if (5== nCount)
            {
                if (',' != strBuf[i])
                {
                    strenglish[j] = strBuf[i];
                    j++;
                }
                if (',' == strBuf[i])
                {
                    strenglish[j] = '\0';
                    nCount++;
                    j = 0;
                }
            }
            else
            {
                straverage[j] = strBuf[i];
                int n;//输入学生的数目
                j++;
            }
        }
        //分数转化为int类型
        chinese = strtol(strchinese, NULL, 10);
        math = strtol(strmath, NULL, 10);
        english = strtol(strenglish, NULL, 10);
        average = strtol(straverage, NULL, 10);
        addnote(strStuNum, strStuName, strsex, chinese, math, english, average);
    }
    fclose(pFile);
}
stunote *Copylist(stunote *head)//复制先前列表
{
    stunote *newlist,*s,*p;
    int i=0,j;
    while(head!=NULL)
    {
        i++;
        s=(stunote *)malloc(sizeof(stunote));
        strcpy(s->number,head->number);
        strcpy(s->name,head->name);
        strcpy(s->sex,head->sex);
        s->chinese=head->chinese;
        s->math=head->math;
        s->english=head->english;
        s->average=head->average;
        if(i==1)
        {
            newlist=s;
            s->pNext=NULL;
        }
        else   p->pNext=s;
        p=s;
        head=head->pNext;
    }
    p->pNext=NULL;
    printf("---复制链表成功！---\n");
    return newlist;
}

stunote *paixu(stunote *head)
{
    fflush(stdin);
    char ch;
    stunote *tail,*p_front,*min,*p,*copyhead,*phead;
    if(head==NULL)
    {
        printf("---空链表!请先新建链表或文件读取---\n");
        return head;
    }
//先复制链表，以作备份
    copyhead=Copylist(head);

    tail=NULL;
    while(head!=NULL)
    {
        for(p=head,min=head; p->pNext!=NULL; p=p->pNext)
        {
            if((min->average)>(p->pNext->average))//p->next->average比较小
            {
                p_front=p;       //保存最小节点的前一个节点
                min=p->pNext;     //保存此时链表最小的节点值
            }
        }
        //将得到的值放入有序链表中；
        //原链表指针后移
        if(min==head)
            head=head->pNext;
        else
            p_front->pNext = min->pNext;
        if(tail==NULL)
        {
            tail=min;
            phead=min;
        }
        else           //有序链表中已经有节点
        {
            min->pNext=phead;
            phead=min;
        }

    }
    tail->pNext=NULL;
//完成总分排序
    printf("---排序成功!排序如下--\n");
    showdata(phead);
    return copyhead;
}
