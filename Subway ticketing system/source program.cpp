#include<iostream>
#include<fstream>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<sstream>
using namespace std;

class lines;class trains;		//��ǰʹ��˵�� 
class users						//�����û��� 
{	
	friend ostream & operator << (ostream &,users &);
	friend istream & operator >> (istream &,users &);
	public:
		void log_in();			//��¼ 
		void registering();		//ע���û�
		void home();			//��ҳ 
		void account();			//�˻����� 
		void in_charge();		//��ֵ 
		void out_charge();		//���� 
		void up_grade();        //�����Ա
		void destroy(); 		//����
		void search(lines &l);	//������ѯ 
		void search_query();	//��ѯ�˻���Ϣ
		void search_other();	//��ѯ�����˻���Ϣ 
		void buy_1();			//��Ʊ ��·ѡ��
		void buy_2(string x);	//��Ʊ ����ѡ��
		void buy_3(string x);	//��Ʊ ȷ��֧��
		void buy_4(string x,float y);//��Ʊ ֧���ɹ�
		void buy_4(string x,int y);//�������� 
		void buy_5();			//��Ʊ ֧��ʧ�� 
		void buy_6(string x);	//��Ʊ ��ʾ���г���
		void refund_1();		//��Ʊ ѡ��Ʊ
		void refund_2(string x,float y);//��Ʊ ȷ����Ʊ
		void refund_3();		//��Ʊ ��Ʊ�ɹ�
		void search_tickt();	//�鿴�ѹ���Ʊ 
	protected:
		static string login_card;//(��̬���ݳ�Ա)��¼���� 
		long card;		        //����
		string key;				//����
		string name;			//�ֿ���
		string id_card;			//���֤��
		string type;		    //��Ա����
		float balance;			//���
		string tickt_name[20];	//��Ʊ ����
		int tickt_hour[20];		//��Ʊ ����ʱ��
		int tickt_minute[20];	//��Ʊ ����ʱ��
		float tickt_type[20];	//��Ʊ ��Ʊ����0.5/1
		int tickt_number[20];	//��Ʊ ��Ʊ���� 
};
string users::login_card="0";	//��̬���ݳ�Ա�����ʼ�� 
class lines 					//������·�� 
{
	friend void users::search(lines &l);
	
	public:
		void statistics();		//������Ա�鿴ͳ������
		void line_information_1();//��ʾ��·վ����Ϣ
		void line_information_2();//��ʾ��ǰ������ 
	protected:
	    string line_name[4];	//��·���
		int passengers[4]; 		//�˿�����
		int run_number[4];		//��������
		double income[4];		//���� 
};
class managers					//����������Ա�� 
{
	public:
		void log_in();			//��¼
		void home(trains &t);			//������Ա��ҳ 
	protected:
		long card;
		string key; 
};
class trains:public lines		//���������� 
{ 
	friend void managers::home(trains &t);
	
	public:
		void add();				//��ӳ���
		void deleting();		//ɾ������
		void search();			//��ʾ�������еĳ��� 
	protected:
		string train_name[20];	//����
		int set_hour[20];		//����ʱ��(Сʱ)
		int set_minute[20];		//����ʱ��(����)
		int passengers[20];		//�˿���
		double in_come[20];		//����
};



void users::log_in()			//�û���¼
{
	system("cls");				//����
	string m;
						//�����м����
loop_start:	
	cout<<endl
		<<"                    �� ���ݵ���ͨ  ��"<<endl<<endl
		<<"  �û����¼��"<<endl<<endl
		<<"  ***************************************************"<<endl<<endl
		<<"                    ���ţ�";	cin>>login_card;	login_card=login_card+".txt";	//���뿨�Ų�ת��Ϊ�ļ��� 

	cout<<"                    ���룺";	cin>>m;	    //�����¼����
	cout<<endl;
	cout<<"  ***************************************************"<<endl<<endl;
	
	ifstream user(login_card.c_str(),ios::in);        //���ļ�,ifstreamֻ�������ļ� 
	if(!user)					//�û������ڵ���� 
	{
		cout<<"                     �û������ڣ�"<<endl<<endl
		<<"                                       ���س����Է���";
		getchar();	getchar();
		system("cls");			//����
		goto loop_start;		//�ص���ʼ���� 
	}
	
	user>>card>>key>>name>>id_card>>type>>balance;
	for(int i=0;i<20;i++)	user>>tickt_name[i]>>tickt_hour[i]>>tickt_minute[i]>>tickt_type[i]>>tickt_number[i];
	user.seekg(0, ios::beg);
	if(m!=key)					//����������� 
	{
		cout<<"                     �������"<<endl<<endl
			<<"                                       ���س����Է���"; 
		getchar();	getchar();
		system("cls");			//����
		goto loop_start;		//�ص���ʼ���� 
	}
	
	cout<<"                      ��¼�ɹ���";
	getchar();getchar();
	
	system("cls");				//����
	home();
}
string f(long x)				//��������ת��
{	
	stringstream ss;
	ss<<x;
	return ss.str();
}
void users::registering() 		//���û�ע�� 
{	
	system("cls");			//����
	balance=0;type="Normal";	//��ʼ���������� 
	cout<<endl
		<<" ���û�ע��"<<endl<<endl<<endl
	    <<"     ���ã���ӭʹ�����ݵ���ͨ�������룺"<<endl<<endl
	    <<"         *************************************"<<endl<<endl
		<<"                     �ֿ���: ";
	cin>>name;										  //����ֿ������� 
	cout<<"                   ���֤�ţ�" ;
	cin>>id_card;                                      //�������֤��
	cout<<"                 ���������룺" ;
	cin>>key;cout<<endl;                                             //��������
	cout<<"         *************************************"<<endl;
	srand((unsigned)time(NULL));                          //��ʼ����������� 
	for(int i=0;;i++)                                     //������ɿ��� 
	{
	    card=10*rand();                
		if(card>=100000&&card<=999999) break;	
	}
	cout<<endl
	    <<"                       ע��ɹ���"<<endl<<endl 
		<<"                  ���Ŀ���Ϊ��"<<card<<endl
		<<"                           ";
	
	login_card=f(card)+".txt"; 		//���ø���������cardת��Ϊstring�� 
	fstream user(login_card.c_str(),ios::out);	  //�����ļ�(���ļ��Ѵ������滻)
	if(!user){cout<<"open erro!"<<endl;exit(1);}
	user<<card<<endl<<key<<endl<<name<<endl<<id_card<<endl<<type<<endl<<balance<<endl;      //д���ļ� 
	for(int i=0;i<100;i++)	user<<"0"<<endl;
							user<<"END";
	user.close();
	
	getchar();getchar();
	home();
}
void users::home()				//�û���ҳ
{
	system("cls");				//����
	char m;					//�����м����
	
	fstream user(login_card.c_str(),ios::in|ios::out);        //���ļ�
	if(!user){cout<<"open erro!"<<endl;exit(1);}
	user>>card>>key>>name>>id_card>>type>>balance;
	for(int i=0;i<20;i++)	user>>tickt_name[i]>>tickt_hour[i]>>tickt_minute[i]>>tickt_type[i]>>tickt_number[i];
	user.seekg(0, ios::beg);
	
	cout<<endl
		<<" ��ҳ"<<endl<<endl<<endl
		<<"     "<<name<<" ���ã���ѡ�������Ŀ��" <<endl<<endl
		<<"         **************************************"<<endl<<endl
		<<"                       A.������Ʊ"<<endl
		<<"                       B.��Ʊ����"<<endl
		<<"                       C.������ѯ"<<endl
		<<"                       D.�˻�����"<<endl
		<<"                                     E.�˳�ϵͳ"<<endl
		<<"         **************************************"<<endl<<endl
		<<"                             ";cin>>m;
	
	lines l;	
	
	switch(m)
	{
		case'A':buy_1();break;
		case'B':refund_1();break;
		case'C':search(l);break;
		case'D':account();break;
		case'E':exit(1);break;
	}
} 

void users::buy_1()				//������Ʊ>>��·ѡ��
{
	system("cls");				//����
	string m;					//�����м���� 
	
	cout<<endl;
	cout<<" ������Ʊ>>��·ѡ��"<<endl<<endl<<endl
		<<"         ��·��Ϣ��"<<endl<<endl
		<<"           *******************************************************************"<<endl
		<<"              ��·     ʼ����      Ŀ�ĵ�    ���Ʊ��  ȫ��Ʊ��    ����ʱ��" <<endl<<endl 
		<<"             line1      ľ��       ���Ͻ�      3        6      06:30-23:00"<<endl
		<<"             line2      ���       ɣ�ﵺ       3        6      06:30-23:00"<<endl
		<<"             line4 ����������վ   Ψͤ        3        6      06:30-23:00"<<endl
		<<"             maglev    ����վ      ����վ       10       20      07:00-22:30"<<endl<<endl
		<<"                              ��·վ����ϸ��Ϣ��ʹ�� ������ѯ "<<endl
		<<"           *******************************************************************"<<endl<<endl
		<<"                                   ��ѡ��������·��";	cin>>m;		getchar();
	system("cls");				//����
	buy_2(m);					//������һ�� 
} 
void users::buy_2(string x)		//������Ʊ>>��·ѡ��>>����ѡ��
{
	string n;	int now,time[20];			//�����м����
	string train_name[20];	int set_hour[20];	int set_minute[20];		int passengers[20];		double in_come[20];		//�����м����
	
	fstream train((x+".txt").c_str());		//����m�򿪶�Ӧline���ļ�
	if(!train){cout<<"open erro!"<<endl;exit(1);}
	for(int i=0;i<20;i++)	train>>train_name[i]>>set_hour[i]>>set_minute[i]>>passengers[i]>>in_come[i];
	train.seekg(0, ios::beg);				//���ļ�

	SYSTEMTIME sysTime;    
	ZeroMemory(&sysTime, sizeof(sysTime));     
	GetLocalTime(&sysTime); 	//��ȡϵͳʱ��
	now=sysTime.wHour*60+sysTime.wMinute;
	for(int i=0;i<20;i++)	
	{
		time[i]=set_hour[i]*60+set_minute[i];
		if(time[i]==0) time[i]=9999;		//��֤0���ݲ������ 
	}
	
	cout<<endl
		<<" ������Ʊ>>��·ѡ��>>����ѡ��"<<endl<<endl<<endl
		<<"     ������Σ�"<<endl<<endl
		<<"         **************************************"<<endl
		<<"            ����     ����ʱ��    ���г˿���"<<endl<<endl;
	for(int i=0;i<20;i++)		//�������Сʱ�ڵĳ��� 
	if((time[i]-now)>=0&&(time[i]-now)<=120)	cout<<"            "<<train_name[i]<<"      "<<set_hour[i]<<"��"<<set_minute[i]<<"        "<<passengers[i]<<endl;
	cout<<endl;
	cout<<"                              A��ʾ������Ч����"<<endl 
		<<"         **************************************"<<endl<<endl
		<<"                    ��ѡ�񳵴Σ�";cin>>n;cout<<endl<<endl;
	
	system("cls");				//����
	if(n!="A"&&n!="B")	buy_3(n);					//������һ�� 
	if(n=="A")			buy_6(x);					//��ʾ���г��� 
}
void users::buy_6(string x)		//������Ʊ>>��·ѡ��>>����ѡ��>>��ʾ���г��� 
{
	string n;	int now,time[20];			//�����м����
	string train_name[20];	int set_hour[20];	int set_minute[20];		int passengers[20];		double in_come[20];		//�����м����
	
	fstream train((x+".txt").c_str());		//����x�򿪶�Ӧline���ļ�
	if(!train){cout<<"open erro!"<<endl;exit(1);}
	for(int i=0;i<20;i++)	train>>train_name[i]>>set_hour[i]>>set_minute[i]>>passengers[i]>>in_come[i];
	train.seekg(0, ios::beg);				//���ļ�
	
	SYSTEMTIME sysTime;    
	ZeroMemory(&sysTime, sizeof(sysTime));     
	GetLocalTime(&sysTime); 	//��ȡϵͳʱ��
	now=sysTime.wHour*60+sysTime.wMinute;
	for(int i=0;i<20;i++)	
	{
		time[i]=set_hour[i]*60+set_minute[i];
		if(time[i]==0) time[i]=9999;		//��֤0���ݲ������ 
	}
	
	cout<<endl
		<<" ������Ʊ>>��·ѡ��>>����ѡ��"<<endl<<endl<<endl
		<<"     ������Σ�"<<endl<<endl
		<<"         **************************************"<<endl
		<<"            ����     ����ʱ��     ���г˿���"<<endl<<endl;
	for(int i=0;i<20;i++)		//���������Ч���� 
	if((time[i]-now)>=0&&(time[i]-now)<=1440)	cout<<"            "<<train_name[i]<<"      "<<set_hour[i]<<"��"<<set_minute[i]<<"         "<<passengers[i]<<endl;
	cout<<"         **************************************"<<endl<<endl
		<<"                    ��ѡ�񳵴Σ�";cin>>n;cout<<endl<<endl;
		
	system("cls");				//����
	buy_3(n);			//������һ�� 
}
void users::buy_3(string x) 	//������Ʊ>>��·ѡ��>>����ѡ��>>ȷ��֧�� 
{
	string u=x;	float price;	string m;		//�����м����
	string e1;	int e2,e3,e5;	float e4,e6;	//�����м���� 
	string train_name[20];	int set_hour[20];	int set_minute[20];		int passengers[20];		double in_come[20];		//�����м����
	
	const char *p=x.c_str();
	switch(*p)
	{
		case'A':u="line1";price=6;break;
		case'B':u="line2";price=6;break;
		case'C':u="line4";price=6;break;
		case'D':u="maglev";price=20;break;
	} 
	
	fstream train((u+".txt").c_str());					//�򿪶�Ӧ�����ļ�
	if(!train)	{cout<<"open erro!"<<endl;exit(1);}
	for(int i=0;i<20;i++)	train>>train_name[i]>>set_hour[i]>>set_minute[i]>>passengers[i]>>in_come[i];
	train.seekg(0, ios::beg);	
	
	fstream user(login_card.c_str(),ios::in|ios::out);	//�򿪶�Ӧ�û��ļ�	     
	if(!user){cout<<"open erro!"<<endl;exit(1);} 
	user>>card>>key>>name>>id_card>>type>>balance;
	for(int i=0;i<20;i++)	user>>tickt_name[i]>>tickt_hour[i]>>tickt_minute[i]>>tickt_type[i]>>tickt_number[i];
	user.seekg(0, ios::beg);

	if(type=="Year")	e6=0.7;			//���ݻ�Ա����ȷ���ۿ� 
	if(type=="Month")	e6=0.8;
	if(type=="Normal")	e6=1;
	
	int ii;
	for(ii=0;ii<20;ii++)	if(train_name[ii]==x)	break; 		//��ii��λ��Ӧ���� 
	
	cout<<endl
		<<" ������Ʊ>>·��ѡ��>>����ѡ��>>ȷ��֧��"<<endl<<endl<<endl
		<<"     ��˶����Ĺ�Ʊ��Ϣ��" <<endl<<endl
		<<"         **********************************************"<<endl
		<<"            ����    ����ʱ��    ���Ʊ��   ȫ��Ʊ��"<<endl
		<<"            "<<x<<"     "<<set_hour[ii]<<"��"<<set_minute[ii]<<"         "<<price*0.5<<"         "<<price<<endl
		<<"         **********************************************"<<endl<<endl
		<<"                 �����빺Ʊ������";cin>>e5;cout<<endl;
	cout<<"                 ��ѡ��Ʊ���ͣ�  A.���  B.ȫ��    ";	cin>>m;		if(m=="A")	e4=0.5;		if(m=="B")	e4=1; 
	cout<<endl 
		<<"                 ȷ��֧��"<<price*e4*e5*e6<<"Ԫ��   A.ȷ��  B.ȡ��    ";	cin>>m;	cout<<endl<<endl;
	
	if(m=="A"&&(balance>=price*e4*e5*e6))	//֧���ɹ��󣬿۳����д�복Ʊ��Ϣ 
	{
		passengers[ii]+=e5;					//�򳵴���Ϣ��д�� 
		in_come[ii]+=price*e4*e5*e6;
		
		balance-=price*e4*e5*e6;
		for(int i=0;i<20;i++)
			if(tickt_name[i]=="0"||(tickt_name[i]==x&&tickt_type[i]==e4))	//���û���Ϣ��д�� 
			{
				tickt_name[i]=x;
				tickt_hour[i]=set_hour[ii];
				tickt_minute[i]=set_minute[ii];
				tickt_type[i]=e4;
				tickt_number[i]+=e5;
				
				for(int i=0;i<20;i++)	train<<train_name[i]<<endl<<set_hour[i]<<endl<<set_minute[i]<<endl<<passengers[i]<<endl<<in_come[i]<<endl;
										train<<"END"; 
				train.close();		//д�ļ� 
	
				user<<card<<endl<<key<<endl<<name<<endl<<id_card<<endl<<type<<endl<<balance<<endl;  
				for(int i=0;i<20;i++)	user<<tickt_name[i]<<endl<<tickt_hour[i]<<endl<<tickt_minute[i]<<endl<<tickt_type[i]<<endl<<tickt_number[i]<<endl;
										user<<"END";
				user.close();		//д�ļ� 
				break;	
			}
	}
	system("cls");				//����
	if(m=="A"&&(balance>=price*e4*e5*e6))	buy_4(x,e4);			//����֧���ɹ�ҳ��
	if(m=="A"&&(balance<price*e4*e5*e6))	buy_5();				//���빺Ʊʧ��ҳ�� 
}
void users::buy_4(string x,float y)//������Ʊ>>��·ѡ��>>����ѡ��>>ȷ��֧��>>֧���ɹ�
{
	fstream user(login_card.c_str(),ios::in|ios::out);	//���ļ� 
	if(!user){cout<<"open erro!"<<endl;exit(1);} 
	user>>card>>key>>name>>id_card>>type>>balance;
	for(int i=0;i<20;i++)	user>>tickt_name[i]>>tickt_hour[i]>>tickt_minute[i]>>tickt_type[i]>>tickt_number[i];
	user.seekg(0, ios::beg);
	
	int ii;						//�����м����
	for(ii=0;ii<20;ii++) 	if(tickt_name[ii]==x&&tickt_type[ii]==y)	break;
	
	cout<<endl
		<<" ������Ʊ>>·��ѡ��>>����ѡ��>>ȷ��֧��>>��Ʊ�ɹ�"<<endl<<endl<<endl
		<<"     *****************************************"<<endl
		<<"                     ��Ʊ�ɹ�!"<<endl
		<<"     *****************************************"<<endl<<endl
		<<"     ��Ʊ��Ϣ��"<<endl<<endl
		<<"         ����  ����ʱ��  ��Ʊ����  ��Ʊ����"<<endl
		<<"         "<<x<<"   "<<tickt_hour[ii]<<"��"<<tickt_minute[ii];
		if(tickt_type[ii]==0.5)	cout<<"    "<<"���Ʊ";
		if(tickt_type[ii]==1)	cout<<"    "<<"ȫ��Ʊ";
		cout<<"      "<<tickt_number[ii]<<endl<<endl<<endl 
		<<"                                    E.������ҳ"<<endl<<endl
		<<"                         "; 
	
	user.close();
	getchar();getchar();
	system("cls");				//����
	home();
} 
void users::buy_4(string x,int y)//(��������)
{
	fstream user(login_card.c_str(),ios::in|ios::out);	//���ļ� 
	if(!user){cout<<"open erro!"<<endl;exit(1);} 
	user>>card>>key>>name>>id_card>>type>>balance;
	for(int i=0;i<20;i++)	user>>tickt_name[i]>>tickt_hour[i]>>tickt_minute[i]>>tickt_type[i]>>tickt_number[i];
	user.seekg(0, ios::beg);
	
	int ii;						//�����м����
	for(ii=0;ii<20;ii++) 	if(tickt_name[ii]==x&&tickt_type[ii]==y)	break;
	
	cout<<endl
		<<" ������Ʊ>>·��ѡ��>>����ѡ��>>ȷ��֧��>>��Ʊ�ɹ�"<<endl<<endl<<endl
		<<"     *****************************************"<<endl
		<<"                     ��Ʊ�ɹ�!"<<endl
		<<"     *****************************************"<<endl<<endl
		<<"     ��Ʊ��Ϣ��"<<endl<<endl
		<<"         ����  ����ʱ��  ��Ʊ����  ��Ʊ����"<<endl
		<<"         "<<x<<"   "<<tickt_hour[ii]<<"��"<<tickt_minute[ii];
		if(tickt_type[ii]==0.5)	cout<<"    "<<"���Ʊ";
		if(tickt_type[ii]==1)	cout<<"    "<<"ȫ��Ʊ";
		cout<<"      "<<tickt_number[ii]<<endl<<endl<<endl 
		<<"                                    E.������ҳ"<<endl<<endl
		<<"                         "; 
	
	user.close();
	getchar();getchar();
	system("cls");				//����
	home();
} 
void users::buy_5()				//������Ʊ>>��·ѡ��>>����ѡ��>>ȷ��֧��>>��Ʊʧ�� 
{
	char m; 
	
	cout<<endl
		<<" ������Ʊ>>·��ѡ��>>����ѡ��>>ȷ��֧��>>��Ʊʧ��"<<endl<<endl<<endl
		<<"     ************************************************"<<endl
		<<"                         ��Ʊʧ�ܣ�"<<endl
		<<"     ************************************************"<<endl<<endl
		<<"                 ��������Ѳ��㣬�뼰ʱ��ֵ"<<endl<<endl
		<<"                                         F.ǰ����ֵ"<<endl
		<<"                                         E.������ҳ"<<endl
		<<"                              ";cin>>m;
	switch(m)
	{
		case'F':in_charge();break;
		case'E':home();break;
	}
	
} 

void users::refund_1()			//��Ʊ����>>ѡ��Ʊ 
{
	system("cls");				//����
	int time[20],now;	string u,m;//�����м���� 
	
	fstream user(login_card.c_str(),ios::in|ios::out);	//�򿪶�Ӧ�û��ļ�	     
	if(!user){cout<<"open erro!"<<endl;exit(1);} 
	user>>card>>key>>name>>id_card>>type>>balance;
	for(int i=0;i<20;i++)	user>>tickt_name[i]>>tickt_hour[i]>>tickt_minute[i]>>tickt_type[i]>>tickt_number[i];
	user.seekg(0, ios::beg);
	
	SYSTEMTIME sysTime;    
	ZeroMemory(&sysTime, sizeof(sysTime));     
	GetLocalTime(&sysTime); 	//��ȡϵͳʱ��
	now=sysTime.wHour*60+sysTime.wMinute;
	for(int i=0;i<20;i++)	
	{
		time[i]=tickt_hour[i]*60+tickt_minute[i];
		if(time[i]==0) time[i]=9999;		//��֤0���ݲ������ 
	}
	
	cout<<endl
		<<" ��Ʊ����>>ѡ��Ʊ"<<endl<<endl<<endl
		<<"     ��ѡ����Ҫ�˶��ĳ�Ʊ��"<<endl<<endl
		<<"         ******************************************************"<<endl
		<<"            ���    ����    ����ʱ��    ��Ʊ����    ��Ʊ����"<<endl<<endl;
	int i;	float n;
	for(int i=0;i<20;i++)
	if(time[i]>=now&&time[i]<=1440)
	{
		cout<<"             "<<i<<"      "<<tickt_name[i]<<"     "<<tickt_hour[i]<<"��"<<tickt_minute[i];
		if(tickt_type[i]==0.5)	cout<<"      "<<"���Ʊ";
		if(tickt_type[i]==1)	cout<<"      "<<"ȫ��Ʊ";
		cout<<"         "<<tickt_number[i]<<endl;
	}
	cout<<endl;
	cout<<"         ******************************************************"<<endl<<endl
		<<"                            �����복Ʊ��ţ�";cin>>i;cout<<endl<<endl; 
	
	m=tickt_name[i];	n=tickt_type[i];
	user.close();
	system("cls");				//����
	refund_2(m,n);				//������һ�� 
}
void users::refund_2(string x,float y)	//��Ʊ����>>ѡ��Ʊ>>ȷ����Ʊ 
{
	string u=x,n;		float m,price;
	string train_name[20];	int set_hour[20];	int set_minute[20];		int passengers[20];		double in_come[20];		//�����м����
	
	fstream user(login_card.c_str(),ios::in|ios::out);	//�򿪶�Ӧ�û��ļ�	     
	if(!user){cout<<"open erro!"<<endl;exit(1);} 
	user>>card>>key>>name>>id_card>>type>>balance;
	for(int i=0;i<20;i++)	user>>tickt_name[i]>>tickt_hour[i]>>tickt_minute[i]>>tickt_type[i]>>tickt_number[i];
	user.seekg(0, ios::beg);
	
	const char *q=x.c_str();
	switch(*q)
	{
		case'A':u="line1";price=6;break;
		case'B':u="line2";price=6;break;
		case'C':u="line4";price=6;break;
		case'D':u="maglev";price=20;break;
	} 
	
	fstream train((u+".txt").c_str());					//�򿪶�Ӧ�����ļ�
	if(!train)	{cout<<"open erro!"<<endl;exit(1);}
	for(int i=0;i<20;i++)	train>>train_name[i]>>set_hour[i]>>set_minute[i]>>passengers[i]>>in_come[i];
	train.seekg(0, ios::beg);	
	
	if(type=="Year")	m=0.7;			//���ݻ�Ա����ȷ���ۿ� 
	if(type=="Month")	m=0.8;
	if(type=="Normal")	m=1;
	
	int ii;
	for(ii=0;ii<20;ii++)	if(tickt_name[ii]==x&&tickt_type[ii]==y)	break;
	
	cout<<endl
		<<" ��Ʊ����>>ѡ��Ʊ>>ȷ����Ʊ"<<endl<<endl<<endl
		<<"     ��˶�������Ʊ��Ϣ��"<<endl<<endl
		<<"         ******************************************************************"<<endl
		<<"            ��·    ����    ����ʱ��    ��Ʊ����    ��Ʊ����    Ӧ�˽��"<<endl<<endl
		<<"            "<<u<<"   "<<x<<"     "<<tickt_hour[ii]<<"��"<<tickt_minute[ii];
		if(tickt_type[ii]==0.5)	cout<<"      "<<"���Ʊ";
		if(tickt_type[ii]==1)	cout<<"      "<<"ȫ��Ʊ";
	cout<<"        "<<tickt_number[ii]<<"          "<<price*tickt_type[ii]*tickt_number[ii]*m<<endl
		<<"         ******************************************************************"<<endl<<endl
		<<"                              ȷ����Ʊ��   A.ȷ��   B.ȡ��     ";cin>>n;cout<<endl<<endl;
	
	if(n=="A")	
	{
		for(int i=0;i<20;i++)
		if(train_name[i]==x)
		{
			passengers[i]-=tickt_number[ii];					//�򳵴���Ϣ��д�� 
			in_come[i]-=price*tickt_type[ii]*tickt_number[ii]*m;
			break;
		}
		balance+=price*tickt_type[ii]*tickt_number[ii]*m;
		tickt_name[ii]="0";
		tickt_hour[ii]=0;
		tickt_minute[ii]=0;
		tickt_type[ii]=0;
		tickt_number[ii]=0;
				
		for(int i=0;i<20;i++)	train<<train_name[i]<<endl<<set_hour[i]<<endl<<set_minute[i]<<endl<<passengers[i]<<endl<<in_come[i]<<endl;
								train<<"END"; 
		train.close();		//д�ļ� 
	
		int time[20];	string e1;	int e2,e3,e5,e6;	float e4;			//�����м���� 
		for(int i=0;i<20;i++)	
		{
			time[i]=tickt_hour[i]*60+tickt_minute[i];
			if(time[i]==0) time[i]=1440;
		}
		for(int i=0;i<19;++i)
		for(int j=0;j<19-i;++j)
		if(time[j]>time[j+1])			//д��ǰ���򣬰�ʱ��˳������ 
		{
			e1=tickt_name[j];tickt_name[j]=tickt_name[j+1];tickt_name[j+1]=e1;
			e2=tickt_hour[j];tickt_hour[j]=tickt_hour[j+1];tickt_hour[j+1]=e2;
			e3=tickt_minute[j];tickt_minute[j]=tickt_minute[j+1];tickt_minute[j+1]=e3;
			e4=tickt_type[j];tickt_type[j]=tickt_type[j+1];tickt_type[j+1]=e4;
			e5=tickt_number[j];tickt_number[j]=tickt_number[j+1];tickt_number[j+1]=e5;
			e6=time[j];time[j]=time[j+1];time[j+1]=e6;
		}
		
		user<<card<<endl<<key<<endl<<name<<endl<<id_card<<endl<<type<<endl<<balance<<endl;  
		for(int i=0;i<20;i++)	user<<tickt_name[i]<<endl<<tickt_hour[i]<<endl<<tickt_minute[i]<<endl<<tickt_type[i]<<endl<<tickt_number[i]<<endl;
								user<<"END";
		user.close();		//д�ļ� 
		
		system("cls");				//����
		refund_3();					//������һ�� 
   }
} 
void users::refund_3()			//��Ʊ����>>ѡ��Ʊ>>��Ʊ�ɹ�
{
	cout<<endl
		<<" ��Ʊ����>>ѡ��Ʊ>>ȷ����Ʊ>>��Ʊ�ɹ�"<<endl<<endl<<endl
		<<"     ***************************************"<<endl
		<<"                     ��Ʊ�ɹ���" <<endl
		<<"     ***************************************"<<endl<<endl
		<<"               Ӧ�˽���ѷ��������˻�"<<endl<<endl
		<<"                                  E.������ҳ"<<endl
		<<"                         "; 
	getchar();getchar();
	system("cls");				//����
	home(); 
} 
void users::search(lines &l)	//������ѯ
{
	system("cls");				  //����
	char m;
	
	cout<<endl
		<<" ������ѯ>>ѡ�����"<<endl<<endl<<endl
		<<"      ��ѡ���ѯ���ݣ�"<<endl<<endl
		<<"          **********************************"<<endl
		<<"                    A.��ѯ�ѹ���Ʊ"<<endl
		<<"                    B.��ѯ��·;��վ��"<<endl
		<<"                    C.��ѯ��·������"<<endl
		<<"          **********************************"<<endl<<endl
		<<"                            ";cin>>m;
		
	switch(m)
	{
		case'A':search_tickt();break;
		case'B':l.line_information_1();home();break;
		case'C':l.line_information_2();home();break;
	} 
} 
void users::search_tickt()		//������ѯ>>��ѯ�ѹ���Ʊ 
{
	system("cls");				  //����
	string u[20];		float m,price[20];			const char *t[20];		int now,time[20];//�����м���� 
	
	fstream user(login_card.c_str(),ios::in|ios::out);	//�򿪶�Ӧ�û��ļ�	     
	if(!user){cout<<"open erro!"<<endl;exit(1);} 
	user>>card>>key>>name>>id_card>>type>>balance;
	for(int i=0;i<20;i++)	user>>tickt_name[i]>>tickt_hour[i]>>tickt_minute[i]>>tickt_type[i]>>tickt_number[i];
	user.seekg(0, ios::beg);
	
	SYSTEMTIME sysTime;    
	ZeroMemory(&sysTime, sizeof(sysTime));     
	GetLocalTime(&sysTime); 	//��ȡϵͳʱ��
	now=sysTime.wHour*60+sysTime.wMinute;
	
	for(int i=0;i<20;i++)	
	{
		time[i]=tickt_hour[i]*60+tickt_minute[i];
		if(time[i]==0) time[i]=9999;		//��֤0���ݲ������
		
		t[i]=tickt_name[i].c_str();
		switch(*t[i])
	{
		case'A':u[i]="line1";price[i]=6;break;
		case'B':u[i]="line2";price[i]=6;break;
		case'C':u[i]="line4";price[i]=6;break;
		case'D':u[i]="maglev";price[i]=20;break;
	}  
	}

	if(type=="Year")	m=0.7;			//���ݻ�Ա����ȷ���ۿ� 
	if(type=="Month")	m=0.8;
	if(type=="Normal")	m=1;
	
	cout<<endl
		<<" ������ѯ>>ѡ�����>>�ѹ���Ʊ"<<endl<<endl<<endl
		<<"     �ҵĳ�Ʊ��Ϣ��"<<endl<<endl
		<<"         ***********************************************************************"<<endl
		<<"            ��·   ����   ����ʱ��   ��Ʊ����   ��Ʊ����   ֧�����   �Ƿ���Ч"<<endl<<endl;
	for(int i=0;i<20;i++)
	if(tickt_name[i]!="0")
	{
		cout<<"            "<<u[i]<<"  "<<tickt_name[i]<<"    "<<tickt_hour[i]<<"��"<<tickt_minute[i]; 
		if(tickt_type[i]==0.5)	cout<<"     "<<"���Ʊ";
		if(tickt_type[i]==1)	cout<<"     "<<"ȫ��Ʊ";
		cout<<"        "<<tickt_number[i]<<"        "<<price[i]*tickt_type[i]*tickt_number[i]*m;
		if(now>time[i]) 	cout<<"      "<<"�ѹ���"<<endl;
		if(now<=time[i])	cout<<"      "<<" ��Ч"<<endl; 
	}
	cout<<"         ***********************************************************************"<<endl<<endl
		<<"                                                                     E.������ҳ"<<endl
		<<"                                              ";
	
	user.close();
	getchar();getchar();
	home();
}
void lines::line_information_1()//������ѯ>>��ѯ��·վ�� 
{
	system("cls");				//����
	cout<<endl;
	cout<<" ������ѯ>>ѡ�����>>��·վ��"<<endl<<endl<<endl
		<<"       ����·;��վ�㣺"<<endl<<endl
		<<"           *****************************************************************"<<endl
		<<"              ��·      վ��1      վ��2      վ��3      վ��4      վ��5"<<endl<<endl
		<<"             line1      ʨ��ɽ     ����·     ������    ���빫԰   ʱ���㳡"<<endl
		<<"             line2      ����·   ���ݻ�վ  �����·   ʯ����·   ��������"<<endl
		<<"             line4       ��ͤ      ʨ��ɽ     ����·    ����֮��     Ψͤ"<<endl
		<<"             maglev         �Ÿ�����վ      �Ÿ�����վ      �Ÿ�����վ"<<endl 
		<<"           *****************************************************************"<<endl<<endl
		<<"               �������Ѷ�����https://baike.baidu.com/item/���ݹ����ͨ"<<endl<<endl
		<<"                                                                  E.������ҳ"<<endl
		<<"                                             ";
	getchar();getchar();
} 
void lines::line_information_2()//������ѯ>>��ѯ��ǰ������ 
{
	system("cls");				//����
	int now,n=0;					//�����м���� 
	string train_name[20];	int set_hour[20],set_minute[20],train_passengers[20];	double in_come[20];
				
	SYSTEMTIME sysTime;    		//��ȡϵͳʱ�� 
	ZeroMemory(&sysTime, sizeof(sysTime));     
	GetLocalTime(&sysTime);
	now=sysTime.wHour*60+sysTime.wMinute;
				
	fstream train1("line1.txt");
	if(!train1)	{cout<<"open erro!"<<endl;exit(1);}
	for(int i=0;i<20;i++)	train1>>train_name[i]>>set_hour[i]>>set_minute[i]>>train_passengers[i]>>in_come[i];
	train1.seekg(0, ios::beg);				//���ļ�
	for(int i=0;i<20;i++)
	if(train_name[i]!="0"&&((now-set_hour[i]*60-set_minute[i])>=0&&(now-set_hour[i]*60-set_minute[i])<=120))
	{
		n+=train_passengers[i];
	}
	train1.close();
	
	fstream train2("line2.txt");
	if(!train1)	{cout<<"open erro!"<<endl;exit(1);}
	for(int i=0;i<20;i++)	train2>>train_name[i]>>set_hour[i]>>set_minute[i]>>train_passengers[i]>>in_come[i];
	train2.seekg(0, ios::beg);				//���ļ�
	for(int i=0;i<20;i++)
	if(train_name[i]!="0"&&((now-set_hour[i]*60-set_minute[i])>=0&&(now-set_hour[i]*60-set_minute[i])<=120))
	{
		n+=train_passengers[i];
	}
	train2.close();
	
	fstream train3("line4.txt");
	if(!train3)	{cout<<"open erro!"<<endl;exit(1);}
	for(int i=0;i<20;i++)	train3>>train_name[i]>>set_hour[i]>>set_minute[i]>>train_passengers[i]>>in_come[i];
	train3.seekg(0, ios::beg);				//���ļ�
	for(int i=0;i<20;i++)
	if(train_name[i]!="0"&&((now-set_hour[i]*60-set_minute[i])>=0&&(now-set_hour[i]*60-set_minute[i])<=120))
	{
		n+=train_passengers[i];
	}
	train3.close();
	
	fstream train4("maglev.txt");
	if(!train4)	{cout<<"open erro!"<<endl;exit(1);}
	for(int i=0;i<20;i++)	train4>>train_name[i]>>set_hour[i]>>set_minute[i]>>train_passengers[i]>>in_come[i];
	train4.seekg(0, ios::beg);				//���ļ�
	for(int i=0;i<20;i++)
	if(train_name[i]!="0"&&((now-set_hour[i]*60-set_minute[i])>=0&&(now-set_hour[i]*60-set_minute[i])<=120))
	{
		n+=train_passengers[i];
	}
	train4.close();
	
	cout<<endl;
	cout<<" ������ѯ>>ѡ�����>>��ѯ��·������"<<endl<<endl<<endl
		<<"      ����ʱ�� "<<sysTime.wHour<<":"<<sysTime.wMinute<<endl<<endl
		<<"          *****************************************"<<endl
		<<"              ���մ�ʱ����������"<<n<<endl
		<<"                ����Ԥ����������"<<(n+141)<<endl 
		<<"              ����Ԥ��ӵ�������";
	if(n<=6600) cout<<"����"<<endl;
	else cout<<"ӵ��"<<endl; 
	cout<<"                      ������ʾ��";
	if(n<=6600) cout<<"��·ͨ�������Գ���"<<endl;
	else cout<<"����ӵ�£��������"<<endl;
	cout<<"          *****************************************"<<endl<<endl
		<<"                                         E.������ҳ"<<endl
		<<"                               ";
	getchar();getchar();
}

void users::account()			//�˻�����
{
	system("cls");				//����
	char m;
	
	cout<<endl
		<<" �˻�����>>ѡ�����"<<endl<<endl<<endl
		<<"     ��ѡ�������Ŀ��"<<endl<<endl
		<<"         *********************************"<<endl<<endl 
		<<"                    A.�˻���Ϣ"<<endl
		<<"                    B.����ֵ"<<endl
		<<"                    C.�������"<<endl
		<<"                    D.�����Ա"<<endl
		<<"                    F.�����˻�"<<endl
		<<"                                E.������ҳ"<<endl 
		<<"         *********************************"<<endl<<endl
		<<"                          ";cin>>m;
	switch(m)
	{
		case'A':search_query();	break;
		case'B':in_charge();	break;
		case'C':out_charge();	break;
		case'D':up_grade();		break;
		case'F':destroy();		break;
		case'E':home();			break;
	}
} 
void users::search_query()		//�˻�����>>��ѯ�˻���Ϣ 
{
	system("cls");				//����
	string m;					//�����м���� 
	
	fstream user(login_card.c_str(),ios::in|ios::out);        //���ļ�
	if(!user){cout<<"open erro!"<<endl;exit(1);}
	user>>card>>key>>name>>id_card>>type>>balance;
	for(int i=0;i<20;i++)	user>>tickt_name[i]>>tickt_hour[i]>>tickt_minute[i]>>tickt_type[i]>>tickt_number[i];
	user.seekg(0, ios::beg);
	
	cout<<endl
		<<" �˻�����>>ѡ�����>>��ѯ" <<endl<<endl<<endl
		<<"     �ҵ��˻���Ϣ��"<<endl<<endl
		<<"         **********************************"<<endl
		<<"                    �ֿ��ˣ�"<<name<<endl
		<<"                      ���ţ�"<<card<<endl
		<<"                  ��Ա���ͣ�"<<type<<endl
		<<"                      ��"<<balance<<endl
		<<"         **********************************"<<endl<<endl
		<<"                         F.��ѯ����������Ϣ"<<endl
		<<"                             E.�����˻����� "<<endl
		<<"                         ";cin>>m; 
	
	user.close(); 
	
	if(m=="F")	 search_other();
	if(m=="E")   account(); 
}
void users::search_other()		//�˻�����>>��ѯ�����˻���Ϣ
{
	system("cls");				//����
	long m;   string n;
	
	cout<<endl
		<<" �˻�����>>ѡ�����>>��ѯ>>��ѯ����������Ϣ"<<endl<<endl<<endl
		<<"     ��������飺"<<endl<<endl
		<<"           ���ţ�";cin>>m;
	cout<<"           ���룺";cin>>n;cout<<endl<<endl;
	
	fstream user((f(m)+".txt").c_str(),ios::in|ios::out);        //���ļ�
	if(!user){cout<<"open erro!"<<endl;exit(1);}
	user>>card>>key>>name>>id_card>>type>>balance;
	for(int i=0;i<20;i++)	user>>tickt_name[i]>>tickt_hour[i]>>tickt_minute[i]>>tickt_type[i]>>tickt_number[i];
	
	if(key==n)
	{
		cout<<"     �˻���Ϣ��"<<endl<<endl
			<<"         **********************************"<<endl
			<<"                    �ֿ��ˣ�"<<name<<endl
			<<"                      ���ţ�"<<card<<endl
			<<"                  ��Ա���ͣ�"<<type<<endl
			<<"                      ��"<<balance<<endl
			<<"         **********************************"<<endl<<endl
			<<"                             E.�����˻�����"<<endl
			<<"                          ";
		getchar();getchar();
		account();
	}
	if(key!=n)		{cout<<"              �������!";getchar();getchar();account();}
} 
void users::in_charge()			//�˻�����>>����ֵ 
{
	fstream user(login_card.c_str(),ios::in|ios::out);        //���ļ�
	if(!user){cout<<"open erro!"<<endl;exit(1);}
	user>>card>>key>>name>>id_card>>type>>balance;
	for(int i=0;i<20;i++)	user>>tickt_name[i]>>tickt_hour[i]>>tickt_minute[i]>>tickt_type[i]>>tickt_number[i];
	user.seekg(0, ios::beg);					    
	          
	system("cls");				  //����
	float m=0;string n="0";                           //�����м���� 
	cout<<endl
	    <<" �˻�����>>ѡ�����>>��ֵ"<<endl<<endl<<endl
	    <<"     ��ȷ�������˻���Ϣ��"<<endl<<endl
		<<"         **********************************"<<endl
		<<"                    �ֿ��ˣ�"<<name<<endl
		<<"                      ���ţ�"<<card<<endl
		<<"                  ��Ա���ͣ�"<<type<<endl
		<<"                      ��"<<balance<<endl
		<<"         **********************************"<<endl<<endl;
	cout<<"     �������ֵ��";
	cin>>m;cout<<endl;
	cout<<"     ���������п�/΢���˻���";
	cin>>n;cout<<endl;
	cout<<"     ������֧�����룺";
	cin>>n;cout<<endl;
	cout<<"     ȷ�ϳ�ֵ��   Aȷ��   Bȡ��    "; 
	cin>>n;
	if(n=="A")  balance+=m;
	user<<card<<endl<<key<<endl<<name<<endl<<id_card<<endl<<type<<endl<<balance<<endl;      //д���ļ�
	for(int i=0;i<20;i++)	user<<tickt_name[i]<<endl<<tickt_hour[i]<<endl<<tickt_minute[i]<<endl<<tickt_type[i]<<endl<<tickt_number[i]<<endl;
							user<<"END"; 
	user.close();
	system("cls");				  //���� 
	cout<<endl
	    <<" �˻�����>>ѡ�����>>��ֵ>>��ֵ�ɹ�"<<endl<<endl<<endl
	    <<"      ���ţ�"<<card<<endl<<endl
	    <<"      **********************************"<<endl
	    <<"                   ��ֵ�ɹ���"<<endl
		<<"      **********************************"<<endl<<endl
		<<"      ��ǰ��"<<balance<<endl
		<<"                          E.�����˻�����"<<endl
		<<"                       ";
	getchar();getchar();
	account();
} 
void users::out_charge()		//�˻�����>>�������
{
	fstream user(login_card.c_str(),ios::in|ios::out);        //���ļ�
	if(!user){cout<<"open erro!"<<endl;exit(1);}
	user>>card>>key>>name>>id_card>>type>>balance;
	for(int i=0;i<20;i++)	user>>tickt_name[i]>>tickt_hour[i]>>tickt_minute[i]>>tickt_type[i]>>tickt_number[i];
	user.seekg(0, ios::beg);					   
	          
	system("cls");				  //����
	float m;	string n="0";                           //�����м���� 
	cout<<endl
	    <<" �˻�����>>ѡ�����>>����"<<endl<<endl<<endl
	    <<"     ��ȷ�������˻���Ϣ��"<<endl<<endl
		<<"         **********************************"<<endl
		<<"                    �ֿ��ˣ�"<<name<<endl
		<<"                      ���ţ�"<<card<<endl
		<<"                  ��Ա���ͣ�"<<type<<endl
		<<"                      ��"<<balance<<endl
		<<"         **********************************"<<endl<<endl;
	cout<<"     ���������ֽ�";
	cin>>m;cout<<endl;
	cout<<"     ���������п�/΢���˻���";
	cin>>n;cout<<endl;
	cout<<"     ȷ�����֣�  Aȷ��   Bȡ��    "; 
	cin>>n;
	if(n=="A")  balance-=m; 
	user<<card<<endl<<key<<endl<<name<<endl<<id_card<<endl<<type<<endl<<balance<<endl;      //д���ļ� 
	for(int i=0;i<20;i++)	user<<tickt_name[i]<<endl<<tickt_hour[i]<<endl<<tickt_minute[i]<<endl<<tickt_type[i]<<endl<<tickt_number[i]<<endl;
							user<<"END";
	user.close();
	system("cls");				  //���� 
	cout<<endl
	    <<" �˻�����>>ѡ�����>>����>>���ֳɹ�"<<endl<<endl<<endl
	    <<"     ���ţ�"<<card<<endl<<endl
	    <<"         **********************************"<<endl
	    <<"                      ���ֳɹ���"<<endl
		<<"         **********************************"<<endl<<endl
		<<"     ��ǰ��"<<balance<<endl
		<<"                             E.�����˻�����"<<endl
		<<"                          ";
	getchar();getchar();
	account();
} 
void users::up_grade()			//�˻�����>>�����Ա
{
	system("cls");				  //����
	fstream user(login_card.c_str(),ios::in|ios::out);          //���ļ� 
	if(!user){cout<<"open erro!"<<endl;exit(1);}
	user>>card>>key>>name>>id_card>>type>>balance;
	for(int i=0;i<20;i++)	user>>tickt_name[i]>>tickt_hour[i]>>tickt_minute[i]>>tickt_type[i]>>tickt_number[i];
	user.seekg(0, ios::beg);      
	
	string m,n;                     //�����м���� 
	cout<<endl;
	cout<<" �˻�����>>ѡ�����>>�����Ա" <<endl<<endl<<endl
		<<"     ��ѡ���Ա���ͣ�"<<endl<<endl
		<<"         ***********************************"<<endl
		<<"           A.Month"<<endl
		<<"             �¿���Ա:���³˳�����0.8����"<<endl
		<<"             �ݡ������Ա�ѵ��³˳������"<<endl
		<<"             ��20Ԫ����20������20Ԫ�շ�"<<endl<<endl
		<<"           B.Year"<<endl
		<<"             �꿨��Ա:����˳�����0.7����"<<endl
		<<"             �ݡ������Ա�ѱ���˳������"<<endl
		<<"             ��240Ԫ����240������240Ԫ�շ�"<<endl
	 	<<"         ************************************"<<endl<<endl
	 	<<"     ��ѡ���Ա���ͣ� A.Month  B.Year     ";
	cin>>m;
	cout<<"     ȷ�ϰ���       Y.ȷ��   N.ȡ��     "; 
	cin>>n;
	if(m=="A"&&n=="Y")  {type="Month";cout<<endl<<"                   ����ɹ���";} 
	if(m=="B"&&n=="Y")  {type="Year";cout<<endl<<"                   ����ɹ���";}
	cout<<endl
		<<"                               E.�����˻�����"<<endl
		<<"                        "; 
	user<<card<<endl<<key<<endl<<name<<endl<<id_card<<endl<<type<<endl<<balance;      //д 
	for(int i=0;i<20;i++)	user<<tickt_name[i]<<endl<<tickt_hour[i]<<endl<<tickt_minute[i]<<endl<<tickt_type[i]<<endl<<tickt_number[i]<<endl;
							user<<"END";
	user.close(); 
	getchar();getchar();
	account();
}
void users::destroy() 			//�˻�����>>�����˻� 
{
	system("cls");				  //����
	fstream user(login_card.c_str(),ios::in|ios::out);          //���ļ� 
	if(!user){cout<<"open erro!"<<endl;exit(1);}
	user>>card>>key>>name>>id_card>>type>>balance;
	for(int i=0;i<20;i++)	user>>tickt_name[i]>>tickt_hour[i]>>tickt_minute[i]>>tickt_type[i]>>tickt_number[i];
	user.seekg(0, ios::beg);
	
	string m;
	cout<<endl;
	cout<<" �˻�����>>ѡ�����>>�����˻�"<<endl<<endl<<endl
		<<"     ��ȷ���˻���Ϣ��"<<endl<<endl
		<<"         ****************************************"<<endl
		<<"                      �ֿ��ˣ�"<<name<<endl
		<<"                        ���ţ�"<<card<<endl
		<<"                    ��Ա���ͣ�"<<type<<endl
		<<"                        ��"<<balance<<endl 
		<<"         ****************************************"<<endl<<endl
		<<"     ���������������˻��������Ķ���ͬ������Э�飺"<<endl<<endl
		<<"         ****************************************"<<endl
		<<"                  ���ݵ���ͨ�û�����Э��"<<endl<<endl
		<<"            �𾴵� "<<name<<" :"<<endl
		<<"                ��л���������������ݵ���ͨ��֧"<<endl
		<<"            �֣�������ΪĳЩԭ����Ҫ����������"<<endl
		<<"            �����Ƚ����ȫ�����֡��˻����ٺ�"<<endl
		<<"            ϵͳ��ɾ������һ�����ݲ����޷��һ�"<<endl
		<<"            δ�˻ص����ᱻ��ա�"<<endl
		<<"         ****************************************"<<endl<<endl
		<<"     �Ƿ������   A.����,�����Ķ���ͬ���Э��"<<endl
		<<"                  B.����"<<endl
		<<"                              "; 
	cin>>m;
if(m=="A") 
{
	system("cls");				  //����
	cout<<endl;
	cout<<" �˻�����>>ѡ�����>>�����˻�>>ȷ������"<<endl<<endl<<endl
	    <<"     ���ٴ�ȷ���˻���Ϣ��"<<endl<<endl
		<<"         **********************************"<<endl
		<<"                   �ֿ��ˣ�"<<name<<endl
		<<"                     ���ţ�"<<card<<endl
		<<"                 ��Ա���ͣ�"<<type<<endl
		<<"                     ��"<<balance<<endl 
		<<"         **********************************"<<endl<<endl
		<<"     ���棡�Ƿ�������    A.����   B.����"<<endl<<endl
		<<"                         ";
	cin>>m;
if(m=="A")
{
	system("cls");
	cout<<endl;
	cout<<"�˻�����>>ѡ�����>>�����˻�>>ȷ������>>�����ɹ�"<<endl<<endl<<endl
		<<"     ���ţ�"<<card<<endl<<endl
		<<"      **********************************"<<endl
		<<"                   �����ɹ���"<<endl
		<<"      **********************************"<<endl<<endl
		<<"                              E.�˳�����"<<endl
		<<"                       "; 
	user.close();
	
	ofstream user(login_card.c_str(),ios::trunc);          //���ļ� 
	if(!user){cout<<"open erro!"<<endl;exit(1);}
	user.close();
	getchar();getchar();
	exit(1); 
}
} 	
}

void managers::log_in()			//������Ա��¼ 
{
	system("cls");			//����
	long m; string n;
	
loop_start: 
	cout<<endl
		<<" ������Ա��¼" <<endl<<endl<<endl
		<<"     ������Ա���¼��" <<endl<<endl
		<<"         *************************************"<<endl<<endl
		<<"                      �˺ţ�";cin>>m;
	cout<<"                      ���룺";cin>>n;cout<<endl;
	cout<<"         *************************************"<<endl<<endl; 
	
	ifstream manager(("Manager"+f(m)+".txt").c_str(),ios::in);        //���ļ�,ifstreamֻ�������ļ� 
	if(!manager)					//�û������ڵ���� 
	{
		cout<<"                       �˺Ų����ڣ�"<<endl<<endl
		<<"                                ���س����Է���";
		getchar();	getchar();
		system("cls");			//����
		goto loop_start;		//�ص���ʼ���� 
	}
	
	manager>>card>>key;
	manager.seekg(0, ios::beg);
	if(n!=key)					//����������� 
	{
		cout<<"                        �������"<<endl<<endl
			<<"                                ���س����Է���"; 
		getchar();	getchar();
		system("cls");			//����
		goto loop_start;		//�ص���ʼ���� 
	}
	
	cout<<"                        ��¼�ɹ���";
	getchar();getchar();
	system("cls");				//����
	trains t;
	home(t); 

} 
void managers::home(trains &t)	//������Ա��ҳ 
{
	system("cls");				//����
	char m;
	
	cout<<endl
		<<" ������Ա��ҳ"<<endl<<endl<<endl
		<<"     ��ѡ����ִ�еĲ�����"<<endl<<endl
		<<"         ***************************************"<<endl<<endl
		<<"                     A.��ӳ���"<<endl
		<<"                     B.ɾ������"<<endl
		<<"                     C.��ʾ��ǰ���еĳ���"<<endl
		<<"                     D.�鿴ͳ������"<<endl
		<<"                                      E.�˳�ϵͳ"<<endl
		<<"         ***************************************"<<endl<<endl
		<<"                             ";cin>>m;
	switch(m)
	{
		case'A':t.add();		break;
		case'B':t.deleting();	break;
		case'C':t.search();		break;
		case'D':t.statistics();	break;
		case'E':exit(1);		break;
	}
}
void trains::add()				//��ӳ���
{
	system("cls");				//����
	string xline,m1;	int m2,m3;	//�����м����
	
	cout<<endl
		<<" ��ӳ���"<<endl<<endl<<endl
		<<"     �������³�����Ϣ��"<<endl<<endl
		<<"       *****************************************"<<endl<<endl
		<<"                        ��·��";cin>>xline;
	cout<<"                        ���Σ�";cin>>m1;
	cout<<"              ����ʱ��(hour)��";cin>>m2;
	cout<<"            ����ʱ��(minute)��";cin>>m3;cout<<endl;
	cout<<"       *****************************************"<<endl<<endl;
	cout<<"                        ��ӳɹ���"<<endl
		<<"                                      E.������ҳ"<<endl
		<<"                            ";
	 
	fstream train((xline+".txt").c_str());		//����xline�򿪶�Ӧ��·���ļ�
	if(!train){cout<<"open erro!"<<endl;exit(1);}
	for(int i=0;i<20;i++)	train>>train_name[i]>>set_hour[i]>>set_minute[i]>>passengers[i]>>in_come[i];
	train.seekg(0, ios::beg);				//���ļ� 
	
	for(int i=0;i<20;i++)			//����ǰ����0���θ��� 
	if(train_name[i]=="0")	{ train_name[i]=m1;set_hour[i]=m2;set_minute[i]=m3;break; }
	
	int time[20];	string e1;	int e2,e3,e4,e6;	double e5;			//�����м���� 
	for(int i=0;i<20;i++)	
	{
		time[i]=set_hour[i]*60+set_minute[i];
		if(time[i]==0) time[i]=1440;
	}
	for(int i=0;i<19;++i)
	for(int j=0;j<19-i;++j)
		if(time[j]>time[j+1])			//д��ǰ���򣬰�ʱ��˳������ 
		{
			e1=train_name[j];train_name[j]=train_name[j+1];train_name[j+1]=e1;
			e2=set_hour[j];set_hour[j]=set_hour[j+1];set_hour[j+1]=e2;
			e3=set_minute[j];set_minute[j]=set_minute[j+1];set_minute[j+1]=e3;
			e4=passengers[j];passengers[j]=passengers[j+1];passengers[j+1]=e4;
			e5=in_come[j];in_come[j]=in_come[j+1];in_come[j+1]=e5;
			e6=time[j];time[j]=time[j+1];time[j+1]=e6;
		}
	for(int i=0;i<20;i++)	train<<train_name[i]<<endl<<set_hour[i]<<endl<<set_minute[i]<<endl<<passengers[i]<<endl<<in_come[i]<<endl;
							train<<"END";
	train.close();		//д�ļ� 
	
	getchar();getchar();
	managers m;trains t;
	m.home(t);
} 
void trains::deleting()			//ɾ������
{
	system("cls");				//����
	string m,u;	int n=0;		//�����м���� 
	cout<<endl
		<<" ɾ������"<<endl<<endl<<endl
		<<"     ���Ȳ�ѯ�ó��Σ�";	cin>>m;	cout<<endl<<endl;
	cout<<"         ************************************************************"<<endl<<endl
		<<"          ��ѯ�����"<<endl<<endl;
	const char *p=m.c_str();

	switch(*p)
	{
		case'A':u="line1";break;
		case'B':u="line2";break;
		case'C':u="line4";break;
		case'D':u="maglev";break;
		default:cout<<"                                  �޴˳��Σ�"<<endl<<endl
					<<"         ************************************************************"<<endl
					<<"                                                           E.������ҳ"<<endl
					<<"                                      ";
				getchar();getchar();
				managers mmm;trains tt;
				mmm.home(tt);
				break;
	} 
 
	fstream train((u+".txt").c_str());
	if(!train)	{cout<<"open erro!"<<endl;exit(1);}
	for(int i=0;i<20;i++)	train>>train_name[i]>>set_hour[i]>>set_minute[i]>>passengers[i]>>in_come[i];
	train.seekg(0, ios::beg);				//���ļ� 
	
	int ii=0;		//�����м���� 
	for(ii=0;ii<20;ii++)
	if(m==train_name[ii])	{n=1;/*��ʾ�д˳���*/	break;} 
	
	if(n==1)
	{
	cout<<"              ��·      ����      ����ʱ��      �˿���    ����"<<endl<<endl
		<<"             "<<u<<"      "<<train_name[ii]<<"        "<<set_hour[ii]<<"��"<<set_minute[ii]<<"         "<<passengers[ii]<<"        "<<in_come[ii]<<endl;
	cout<<"         ************************************************************"<<endl<<endl
		<<"                       �Ƿ�ɾ���ó��Σ�   A.ɾ��   B.����    ";cin>>u;cout<<endl;
		if(u=="A")
		{
			cout<<"                                   ɾ���ɹ���"<<endl
				<<"                                                           E.������ҳ"<<endl
				<<"                                       ";
	        train_name[ii]="0";set_hour[ii]=0;set_minute[ii]=0;passengers[ii]=0;in_come[ii]=0;
	    }
	}
	if(n==0)	cout<<"                                  �޴˳��Σ�"<<endl<<endl<<"         ************************************************************"<<endl
					<<"                                                           E.������ҳ"<<endl
					<<"                                      ";
	
	int time[20];	string e1;	int e2,e3,e4,e6;	double e5;			//�����м���� 
	for(int i=0;i<20;i++)	
	{
		time[i]=set_hour[i]*60+set_minute[i];
		if(time[i]==0) time[i]=1440;
	}
	for(int i=0;i<19;++i)
	for(int j=0;j<19-i;++j)
		if(time[j]>time[j+1])			//д��ǰ���򣬰�ʱ��˳������ 
		{
			e1=train_name[j];train_name[j]=train_name[j+1];train_name[j+1]=e1;
			e2=set_hour[j];set_hour[j]=set_hour[j+1];set_hour[j+1]=e2;
			e3=set_minute[j];set_minute[j]=set_minute[j+1];set_minute[j+1]=e3;
			e4=passengers[j];passengers[j]=passengers[j+1];passengers[j+1]=e4;
			e5=in_come[j];in_come[j]=in_come[j+1];in_come[j+1]=e5;
			e6=time[j];time[j]=time[j+1];time[j+1]=e6;
		}
	for(int i=0;i<19;i++)	train<<train_name[i]<<endl<<set_hour[i]<<endl<<set_minute[i]<<endl<<passengers[i]<<endl<<in_come[i]<<endl;
							train<<"END";
	train.close();		//д�ļ�
	
	getchar();getchar();
	managers mm;trains t;
	mm.home(t);
} 
void trains::search()			//��ʾ�������еĳ���
{
	system("cls");				//����
	string m;	int now,time[20];	//�����м���� 
	
	SYSTEMTIME sysTime;    
	ZeroMemory(&sysTime, sizeof(sysTime));     
	GetLocalTime(&sysTime); 	//��ȡϵͳʱ�� 
	
	cout<<endl
		<<" �������еĳ���"<<endl<<endl<<endl
		<<"     ����ʱ�� "<<sysTime.wHour<<":"<<sysTime.wMinute<<endl<<endl 
		<<"     ������Ҫ��ѯ����·��"; cin>>m;cout<<endl;
	cout<<"         *********************************************"<<endl
		<<"           ��ѯ�����"<<endl<<endl
		<<"               ��·     ����    ����ʱ��   ��������"<<endl<<endl; 
	
	fstream train((m+".txt").c_str());
	if(!train)	{cout<<"open erro!"<<endl;exit(1);}
	for(int i=0;i<20;i++)	train>>train_name[i]>>set_hour[i]>>set_minute[i]>>passengers[i]>>in_come[i];
	train.seekg(0, ios::beg);				//���ļ�
	
	now=sysTime.wHour*60+sysTime.wMinute;
	for(int i=0;i<20;i++)	
	{
		time[i]=set_hour[i]*60+set_minute[i];
		if(time[i]==0) time[i]=9999;		//��֤0���ݲ������ 
	}
	for(int i=0;i<20;i++)		//��ǰһСʱ�ڷ����ĳ��ε��� 
	if((now-time[i])<=60&&(now-time[i])>=0)		cout<<"               "<<m<<"    "<<train_name[i]<<"     "<<set_hour[i]<<"��"<<set_minute[i]<<"        "<<passengers[i]<<endl;
	cout<<endl
		<<"         *********************************************"<<endl
		<<"                                            E.������ҳ"<<endl
		<<"                                ";
	
	train.close();
	
	getchar();getchar();
	managers a;trains r;
	a.home(r);
}
void lines::statistics()		//�鿴ͳ������
{
	system("cls");				//����
	string train_name[20];	int set_hour[20],set_minute[20],train_passengers[20];	double in_come[20];
	
	fstream line("lines.txt",ios::in|ios::out);      	//���ļ�  
	if(!line){cout<<"open erro!"<<endl;exit(1);}
	line>>line_name[0]>>passengers[0]>>run_number[0]>>income[0] 
		>>line_name[1]>>passengers[1]>>run_number[1]>>income[1]
		>>line_name[2]>>passengers[2]>>run_number[2]>>income[2]
		>>line_name[3]>>passengers[3]>>run_number[3]>>income[3];
	line.seekg(0, ios::beg);

	fstream train1("line1.txt");
	if(!train1)	{cout<<"open erro!"<<endl;exit(1);}
	for(int i=0;i<20;i++)	train1>>train_name[i]>>set_hour[i]>>set_minute[i]>>train_passengers[i]>>in_come[i];
	train1.seekg(0, ios::beg);				//���ļ�
	for(int i=0;i<20;i++)
	if(train_name[i]!="0")
	{
		run_number[0]+=1;
		passengers[0]+=train_passengers[i];
		income[0]+=in_come[i];
	}
	train1.close();
	
	fstream train2("line2.txt");
	if(!train2)	{cout<<"open erro!"<<endl;exit(1);}
	for(int i=0;i<20;i++)	train2>>train_name[i]>>set_hour[i]>>set_minute[i]>>train_passengers[i]>>in_come[i];
	train2.seekg(0, ios::beg);				//���ļ�
	for(int i=0;i<20;i++)
	if(train_name[i]!="0")
	{
		run_number[1]+=1;
		passengers[1]+=train_passengers[i];
		income[1]+=in_come[i];
	}
	train2.close();
	
	fstream train3("line4.txt");
	if(!train3)	{cout<<"open erro!"<<endl;exit(1);}
	for(int i=0;i<20;i++)	train3>>train_name[i]>>set_hour[i]>>set_minute[i]>>train_passengers[i]>>in_come[i];
	train3.seekg(0, ios::beg);				//���ļ�
	for(int i=0;i<20;i++)
	if(train_name[i]!="0")
	{
		run_number[2]+=1;
		passengers[2]+=train_passengers[i];
		income[2]+=in_come[i];
	}
	train3.close();
	
	fstream train4("maglev.txt");
	if(!train4)	{cout<<"open erro!"<<endl;exit(1);}
	for(int i=0;i<20;i++)	train4>>train_name[i]>>set_hour[i]>>set_minute[i]>>train_passengers[i]>>in_come[i];
	train4.seekg(0, ios::beg);				//���ļ�
	for(int i=0;i<20;i++)
	if(train_name[i]!="0")
	{
		run_number[3]+=1;
		passengers[3]+=train_passengers[i];
		income[3]+=in_come[i];
	}
	train4.close();
	
	float aver_1[4],aver_2[4];							//�����м���� 
	cout<<endl;
	cout<<" �鿴ͳ������" <<endl<<endl<<endl;
	cout<<"        ��ѯ�����"<<endl<<endl;
	cout<<"            ******************************************************************************"<<endl
		<<"               ��·    ��������    �˿���    ��������    ���η�������    ���η����˿���" <<endl;
	for(int i=0;i<4;i++)
	{
	aver_1[i]=(float)income[i]/(float)run_number[i];
	aver_2[i]=(float)passengers[i]/(float)run_number[i];
	cout<<"              "<<line_name[i]<<"       "<<run_number[i]<<"       "<<passengers[i]<<"     "<<income[i]<<"       "<<aver_1[i]<<"         "<<aver_2[i]<<endl;
	} 
	cout<<"            ******************************************************************************"<<endl
		<<"                                                                                E.������ҳ"<<endl
		<<"                                                     ";
	
	for(int i=0;i<4;i++)
	{
		line<<line_name[i]<<endl<<passengers[i]<<endl<<run_number[i]<<endl<<income[i]<<endl; 
	}
	line.close();
	
	getchar();getchar();
	managers a;trains r;
	a.home(r);
}

char log_in()					//��ʼ��¼���� 
{
	char m;
	
	cout<<endl
	<<"                    �� ���ݵ���ͨ  ��"<<endl<<endl
	<<"  ��ѡ���¼��ʽ��"<<endl<<endl
	<<"  ***************************************************"<<endl<<endl
	<<"                     A.�û���¼"<<endl
	<<"                     B.���û�ע��"<<endl
	<<"                     C.������Ա��¼"<<endl
	<<"                                           E.�˳�ϵͳ"<<endl
	<<"  ***************************************************"<<endl<<endl
	<<"                            ";cin>>m;
	
	return m;
}
int main()						//������ 
{
	trains train;
	managers manager;
	lines line;
	users user;
	char m;
	
	m=log_in();
	switch(m)
	{
		case'A':user.log_in();break;
		case'B':user.registering();break;
		case'C':manager.log_in();break;
		case'E':exit(1);break;
	} 
	
	return 0;
}








