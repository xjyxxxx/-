#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<ctime>

using namespace std;

void Display();//�˵�
void Register();//��Ա¼�����
void Enter();//��Ա��¼����

int main()//������
{
    Display();
    cin.get();
    return 0;
}

void Display()
{
    cout<<"1.��Ա¼��     2.��Ա��¼\n";
    cout<<"3.�˳�\n";
    int choice;
    cin>>choice;

    switch(choice)
    {
    case 1:
        Register();
       // call function;���ú���
        break;
    case 2:
        Enter();
       // call function;���ú���
        break;
    case 3:
        system("exit");
    }

}

void Register()
{
    ofstream outFile;
    outFile.open("person.txt",ios_base::out|ios_base::app);//���Ǽǵ���Ա��Ϣ���浽persen�ļ�����person.txt���ļ���ʽ���浽����
    if(!outFile.is_open())//���person�ļ�δ����
    {
        cout<<"���ź�������ļ�ʧȥ����,���Ժ�����"<<endl;
        cout<<"�������";
        cin.get();
        system("exit");
    }
    string name;
    string year,month,day;
    cout<<"��������Ա������";
    cin.get();//�������ַ�
    getline(cin,name);//ռλ�������������Ա���ƹ��������
    outFile<<name<<endl;//��������Ա�����ŵ�person�ļ���
    cout<<"��������Ա���գ�"<<endl;
    cout<<"��"<<year;
    getline(cin,year);
    outFile<<year<<endl;
    cout<<"��"<<month;
    getline(cin,month);
    outFile<<month<<endl;
    cout<<"��"<<day;
    getline(cin,day);
    outFile<<day<<endl;
    cout<<"��Ա�Ǽǳɹ��ɹ�";
    outFile.close();
    Display();

}

void Enter()//��¼����
{
    cin.get();
    ifstream inFile;//����iftream����
    inFile.open("person.txt");//��ȡperson.txt�е�����
    if(!inFile.is_open())//�������û�гɹ���
    {
        cout<<"���ź�������ļ�ʧȥ����,���Ժ�����";
        system("exit");
    }
    string name;
    string temp;
    string year;
    string month;
    string day;
    cout<<"��������Ա������";
    getline(cin,name);
    while(getline(inFile,temp))//ƥ����Ա����
    {
        if(temp==name)
            {
                cout<<"��֤�ɹ�"<<endl;
                getline(inFile,year);
                getline(inFile,month);
                getline(inFile,day);
                cout<<"����Ա����Ϊ��"<<endl;
                cout<<year<<"��"<<month<<"��"<<day<<"��"<<endl;
            }
        else
            {
                cout<<"δ��ѯ�������Ϣ";
                Display();//���ص����˵�
            }
    }
}
