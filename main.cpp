#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<ctime>

using namespace std;

void Display();//菜单
void Register();//人员录入程序
void Enter();//人员登录程序

int main()//主函数
{
    Display();
    cin.get();
    return 0;
}

void Display()
{
    cout<<"1.人员录入     2.人员登录\n";
    cout<<"3.退出\n";
    int choice;
    cin>>choice;

    switch(choice)
    {
    case 1:
        Register();
       // call function;调用函数
        break;
    case 2:
        Enter();
       // call function;调用函数
        break;
    case 3:
        system("exit");
    }

}

void Register()
{
    ofstream outFile;
    outFile.open("person.txt",ios_base::out|ios_base::app);//将登记的人员信息储存到persen文件中以person.txt的文件形式保存到本地
    if(!outFile.is_open())//如果person文件未被打开
    {
        cout<<"很遗憾与服务文件失去连接,请稍后重试"<<endl;
        cout<<"程序结束";
        cin.get();
        system("exit");
    }
    string name;
    string year,month,day;
    cout<<"请输入人员姓名：";
    cin.get();//消除空字符
    getline(cin,name);//占位，假设输入的人员名称过长或过段
    outFile<<name<<endl;//将输入人员姓名放到person文件中
    cout<<"请输入人员生日；"<<endl;
    cout<<"年"<<year;
    getline(cin,year);
    outFile<<year<<endl;
    cout<<"月"<<month;
    getline(cin,month);
    outFile<<month<<endl;
    cout<<"天"<<day;
    getline(cin,day);
    outFile<<day<<endl;
    cout<<"人员登记成功成功";
    outFile.close();
    Display();

}

void Enter()//登录程序
{
    cin.get();
    ifstream inFile;//定义iftream对象
    inFile.open("person.txt");//读取person.txt中的数据
    if(!inFile.is_open())//如果程序没有成功打开
    {
        cout<<"很遗憾与服务文件失去连接,请稍后重试";
        system("exit");
    }
    string name;
    string temp;
    string year;
    string month;
    string day;
    cout<<"请输入人员姓名：";
    getline(cin,name);
    while(getline(inFile,temp))//匹配人员姓名
    {
        if(temp==name)
            {
                cout<<"验证成功"<<endl;
                getline(inFile,year);
                getline(inFile,month);
                getline(inFile,day);
                cout<<"该人员生日为："<<endl;
                cout<<year<<"年"<<month<<"月"<<day<<"日"<<endl;
            }
        else
            {
                cout<<"未查询到相关信息";
                Display();//返回到主菜单
            }
    }
}
