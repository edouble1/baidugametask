#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stu//ѧ���ڵ�
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
stunote* head=NULL;//��������ͷ
stunote* end=NULL;//��������β
void addnote(char number[20],char name[20],char sex[10],int chinese,int math,int english,float average);//���ѧ����Ϣ
void addhead(char number[20],char name[20],char sex[10],int chinese,int math,int english,float average);//��ͷ�����ѧ����Ϣ
void addend(char number[20],char name[20],char sex[10],int chinese,int math,int english,float average);//��β�����ѧ����Ϣ
void add(stunote* pTemp,char number[20],char name[20],char sex[10],int chinese,int math,int english,float average);//��ָ��λ�����ѧ����Ϣ
void freelinkdata();//�������
void showdata(stunote *);//��ӡ����
void showorder();//��ʾָ��
stunote* findstu(char* number);//����ָ��ѧ��
void deletestunote(stunote* pNode);//ɾ��ָ����ѧ��
void savetofile();//������Ϣ���ļ���
void readfile();//��ȡ�ļ��е�ѧ����Ϣ
void paixumeun();
stunote *paixu(stunote *head);                       //����
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
    int n;//����ѧ������Ŀ
    int i=1;//iΪ�ڼ���ѧ��
    struct stunote * prev, * pTemp;
    printf("      ѧ������ϵͳ\n");
    printf("        �������\n");
    //printf("1.����ѧ����Ϣ\n");
    printf("  1.��β������һ��ѧ����Ϣ\n");
    printf("   11.����ʼλ������һ��ѧ����Ϣ\n");
    printf("   111.��ָ��λ�����һ��ѧ����Ϣ\n");
    printf("  2.����ָ��ѧ������Ϣ������/ѧ�ţ�\n");
    printf("  3.ɾ��ָ��ѧ������Ϣ\n");
    printf("  4.�޸�ָ��ѧ������Ϣ\n");
    printf("  5.��ʾ����ѧ������Ϣ\n");
    printf("  6.��ƽ���ɼ����򣨽���\n");
    //printf("7.��ȡָ���ļ����ѧ����Ϣ\n");
    printf("  7.����ѧ������Ϣ���ļ���\n");
    printf("  8.�ָ�ɾ����ѧ������Ϣ\n");
    printf("  0.�˳�ϵͳ\n\n");
    readfile();//��ȡ�ļ�
    while (nFlag)
    {
        printf("������ָ��(10�鿴ָ��):\n");
        scanf("%d", &nOrder);
        switch (nOrder)
        {

        /*case 1://����ѧ����Ϣ
            printf("��Ҫ�������ѧ������Ϣ��");
            scanf("%d",&n);
            if (n>0)
            {
                printf("�����%d��ѧ����ѧ�š��������Ա����ķ�������ѧ������Ӣ�����\n",i);
                scanf("%s %s %s %d %d %d",number,name,sex,&chinese,&math,&english);
                average=(chinese+math+english)/3;
                addnote(number,name,sex,chinese,math,english,average);
                prev = pTemp;
                i++;
                n--;
            }
            break;*/
        case 1://����ѧ����Ϣ��β����
            printf("����ѧ����ѧ�š��������Ա����ķ�������ѧ������Ӣ�����\n");
            scanf("%s %s %s %d %d %d",number,name,sex,&chinese,&math,&english);
            average=(chinese+math+english)/3;
            addnote(number,name,sex,chinese,math,english,average);//����addnote
            break;
        case 11://���һ��ѧ����Ϣ���ڿ�ʼ��
            printf("����ѧ����ѧ�š��������Ա����ķ�������ѧ������Ӣ�����\n");
            scanf("%s %s %s %d %d %d",number,name,sex,&chinese,&math,&english);
            average=(chinese+math+english)/3;
            addhead(number,name,sex,chinese,math,english,average);//����addhead
            break;
        case 111://ָ��λ�����ѧ����Ϣ
            printf("������봦��ѧ��ѧ��");
            scanf("%s",number);
            stunote* pTemp;
            pTemp = findstu(number);
            if (NULL != pTemp)
            {
                printf("����ѧ����ѧ�š��������Ա����ķ�������ѧ������Ӣ�����\n");
                scanf("%s %s %s %d %d %d",number,name,sex,&chinese,&math,&english);
                average=(chinese+math+english)/3;
                add(pTemp,number,name,sex,chinese,math,english,average);
            }
            break;
        case 2://����ָ��ѧ��
            printf("����ָ��ѧ��\n");
            scanf("%s",number);
            pTemp = findstu(number);
            if (NULL != pTemp) //���ѧ����Ϣ
            {
                printf("ѧ��:%s, ����:%s, �Ա�:%s, ���ķ���:%d�� ��ѧ����:%d, Ӣ�����:%d, ƽ������:%f\n", pTemp->number, pTemp->name, pTemp->sex,pTemp->chinese, pTemp->math,pTemp->english,pTemp->average);
            }
            break;
        case 3://ɾ��ָ��ѧ������Ϣ
            printf("����Ҫɾ����ѧ����ѧ��\n");
            scanf("%s", number);
            pTemp = findstu(number);//����
            if (NULL != pTemp) //ɾ��һ���ڵ�
            {
                deletestunote(pTemp);
            }
            break;
        case 4://�޸�ָ��ѧ����Ϣ
            printf("����ָ��ѧ����ѧ��\n");//����ָ��ѧ������Ϣ
            scanf("%s", number);
            pTemp = findstu(number);//����
            if (NULL != pTemp) //��ӡ
            {
                printf("������ѧ��\n");//�޸�ѧ��
                scanf("%s", number);
                strcpy(pTemp->number, number);
                printf("����������\n");//�޸�����
                scanf("%s", name);
                strcpy(pTemp->name, name);
                printf("�������Ա�\n");//�޸�����
                scanf("%s", sex);
                strcpy(pTemp->sex,sex);
                printf("���������ķ���\n");//�޸����ķ���
                scanf("%d", &chinese);
                pTemp->chinese = chinese;
                printf("��������ѧ����\n");//�޸���ѧ����
                scanf("%d", &math);
                pTemp->math = math;
                printf("������Ӣ�����\n");//�޸�Ӣ�����
                scanf("%d", &english);
                pTemp->english = english;
                average=(chinese+math+english)/3;//ƽ���ָ���
                pTemp->average = average;
            }
            break;
        case 5://��ʾ����ѧ������Ϣ
            showdata(head);
            break;
        case 6://��ƽ���ɼ����򣨽���
            //printf("��δʵ��_(:�٩f��)_\n");
            //system("cls");
            //paixumeun();

            head=paixu(head);
            printf("������ָ��(10�鿴ָ��):\n");
            getchar();
            break;
        //case 7://��ȡ�ļ����ѧ����Ϣ
        //printf("��δʵ��_(:�٩f��)_\n");
        //break;
        case 7://����ѧ������Ϣ���ļ���
            savetofile();
            break;
        case 8://�ָ�ɾ����ѧ������Ϣ
            freelinkdata();
            head = NULL;
            end = NULL;
            readfile();
            break;
        case 10://�鿴ָ��
            showorder();
            break;
        case 0:
            nFlag = 0;
            break;
        default:
            printf("not right\n");
        }
    }
    savetofile();//����ѧ����Ϣ
    freelinkdata();//�ͷ�����
    return 0;
}
void addnote(char number[20],char name[20],char sex[10],int chinese,int math,int english,float average)//���ѧ����Ϣ
{
    stunote* pTemp = (stunote*)malloc (sizeof (stunote));//����һ���ڵ�

    if (NULL == number || NULL == name || NULL ==sex|| chinese < 0|| math<0|| english<0)//��������ĺϷ���
    {
        printf("ѧ����Ϣ�������\n");
        return;
    }
    //��ֵ
    strcpy(pTemp->number, number);
    strcpy(pTemp->name, name);
    strcpy(pTemp->sex, sex);
    pTemp->chinese = chinese;
    pTemp->math = math;
    pTemp->english=english;
    pTemp->average=average;
    pTemp->pNext = NULL;
    //����������
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
void addhead(char number[20],char name[20],char sex[10],int chinese,int math,int english,float average)//��ͷ�����ѧ����Ϣ
{
    stunote* pTemp = (stunote*)malloc(sizeof(stunote));//����һ���ڵ�
    if (NULL == number || NULL == name || chinese < 0||math<0||english<0)//��������ĺϷ���
    {
        printf("ѧ����Ϣ�������\n");
        return;
    }
    strcpy(pTemp->number, number);//�����ַ�
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
void add(stunote* pTemp,char number[20],char name[20],char sex[20],int chinese,int math,int english,float average)//��ָ��λ�����ѧ����Ϣ
{
    stunote* pNewTemp = (stunote*)malloc(sizeof(stunote));//�����ڵ�
    strcpy(pNewTemp->number, number);//��ֵ
    strcpy(pNewTemp->name, name);
    strcpy(pNewTemp->sex,sex);
    pNewTemp->chinese = chinese;
    pNewTemp->math = math;
    pNewTemp->english = english;
    pNewTemp->pNext = NULL;
    //�жϲ���λ���Ƿ�Ϊδ���
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
void freelinkdata()//�������
{
    stunote* pTemp = head;
    while (head != NULL)
    {
        //��¼���
        pTemp = head;
        //����ƶ�һ��
        head = head->pNext;
        //ɾ���ڵ�
        free(pTemp);
    }
}
void showdata(stunote *phead)//��ӡ����
{
    stunote* pTemp = phead;
    while (NULL != pTemp)
    {
        printf("ѧ��:%s, ����:%s, �Ա�:%s���ķ���:%d�� ��ѧ����:%d, Ӣ�����:%d, ƽ������:%f\n",pTemp->number, pTemp->name, pTemp->sex,pTemp->chinese, pTemp->math,pTemp->english,pTemp->average);
        pTemp = pTemp->pNext;//������һ��
    }
}
void showorder()//��ʾָ��
{
    printf("�������\n");
    printf(" 1.��β������һ��ѧ����Ϣ\n");
    printf("  11.����ʼλ������һ��ѧ����Ϣ\n");
    printf("  111.��ָ��λ�����һ��ѧ����Ϣ\n");
    printf("2.����ָ��ѧ������Ϣ������/ѧ�ţ�\n");
    printf("3.ɾ��ָ��ѧ������Ϣ\n");
    printf("4.�޸�ָ��ѧ������Ϣ\n");
    printf("5.��ʾ����ѧ������Ϣ\n");
    printf("6.��ƽ���ɼ����򣨽���\n");
    //printf("7.��ȡ�ļ����ѧ����Ϣ\n");
    printf("7.����ѧ������Ϣ���ļ���\n");
    printf("8.�ָ�ɾ����ѧ������Ϣ\n");
    printf("0.�˳�ϵͳ\n");
    printf("������ָ��(10�鿴ָ��):\n");
}
stunote* findstu(char* number)//����ָ��ѧ��
{
    stunote* pTemp = head;
    //�жϲ����ĺϷ���
    if (NULL == number)
    {
        printf("ѧ���������\n");
        return NULL;
    }
    //�ж������Ƿ�Ϊ��
    if (NULL == head || NULL ==end)
    {
        printf("����ΪNULL��\n");
        return NULL;
    }
    //��������
    while (NULL != pTemp)
    {
        if (0 == strcmp(pTemp->number, number))
        {
            return pTemp;
        }
        pTemp = pTemp->pNext;
    }
    printf("���޴˽ڵ㣡\n");
    return NULL;
}
void deletestunote(stunote* pNode)//ɾ��ָ����ѧ��
{
    //ֻ��һ���ڵ�
    if (head == end)
    {
        free(head);
        head = NULL;
        end = NULL;
        return;
    }
    //������׽ڵ�
    if (head == pNode)
    {
        free(head);
        head = head->pNext;
        return;
    }
    //�����β�ڵ�
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
    //������м�ڵ�
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
void savetofile()//������Ϣ���ļ���
{
    FILE* pFile = NULL;
    stunote* pTemp = head;
    char strBuf[30] = {0};
    char strScore[30] = {0};
    //�ж��������Ƿ�Ϊnull
    if (head == NULL)
    {
        printf("û��ѧ��\n");
        return;
    }
    pFile = fopen("date.txt", "wb+");//���ļ�
    if (NULL == pFile)
    {
        printf("�ļ���ʧ�ܣ�\n");
        return;
    }
    while (NULL != pTemp)//�����ļ�ָ��
    {
        strcpy(strBuf, pTemp->number);//ѧ�Ÿ�ֵ��ȥ
        strcat(strBuf, ",");
        strcat(strBuf, pTemp->name);//����
        strcat(strBuf, ",");
        strcat(strBuf, pTemp->sex);//�Ա�
        strcat(strBuf, ",");
        snprintf(strScore, 30, "%d,%d,%d,%f", pTemp->chinese,pTemp->math,pTemp->english,pTemp->average);  //����
        //ƴ���ַ���
        strcat(strBuf, strScore);
        fwrite(strBuf, 1, strlen(strBuf), pFile);
        fwrite("\r\n", 1, strlen("\r\n"), pFile);
        pTemp = pTemp->pNext;
    }
    //�ر��ļ�
    fclose(pFile);
}
void readfile()//��ȡ�ļ��е�ѧ����Ϣ
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
        printf("�ļ���ʧ��\n");
        return;
    }
    //���ļ��ж�ȡ
    while (NULL != fgets(strBuf, 30, pFile))
    {
        int i = 0;
        int j = 0;
        int nCount = 0;
        for (i = 0; strBuf[i] != '\r'; i++)
        {
            //û��.
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
                int n;//����ѧ������Ŀ
                j++;
            }
        }
        //����ת��Ϊint����
        chinese = strtol(strchinese, NULL, 10);
        math = strtol(strmath, NULL, 10);
        english = strtol(strenglish, NULL, 10);
        average = strtol(straverage, NULL, 10);
        addnote(strStuNum, strStuName, strsex, chinese, math, english, average);
    }
    fclose(pFile);
}
stunote *Copylist(stunote *head)//������ǰ�б�
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
    printf("---��������ɹ���---\n");
    return newlist;
}

stunote *paixu(stunote *head)
{
    fflush(stdin);
    char ch;
    stunote *tail,*p_front,*min,*p,*copyhead,*phead;
    if(head==NULL)
    {
        printf("---������!�����½�������ļ���ȡ---\n");
        return head;
    }
//�ȸ���������������
    copyhead=Copylist(head);

    tail=NULL;
    while(head!=NULL)
    {
        for(p=head,min=head; p->pNext!=NULL; p=p->pNext)
        {
            if((min->average)>(p->pNext->average))//p->next->average�Ƚ�С
            {
                p_front=p;       //������С�ڵ��ǰһ���ڵ�
                min=p->pNext;     //�����ʱ������С�Ľڵ�ֵ
            }
        }
        //���õ���ֵ�������������У�
        //ԭ����ָ�����
        if(min==head)
            head=head->pNext;
        else
            p_front->pNext = min->pNext;
        if(tail==NULL)
        {
            tail=min;
            phead=min;
        }
        else           //�����������Ѿ��нڵ�
        {
            min->pNext=phead;
            phead=min;
        }

    }
    tail->pNext=NULL;
//����ܷ�����
    printf("---����ɹ�!��������--\n");
    showdata(phead);
    return copyhead;
}
