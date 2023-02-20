#include <iostream>
#include <string>
#define MAX 3000
#define E 3
using namespace std;

struct Person
{
	string Name;
	int Sex;
	string Phone;
	string Addr;
	int group;
};

struct contact
{
	struct Person Array[MAX];
	struct Person emergency[E];
	int sum;
	int e_size;
};



void add(contact* abs)
{
	int n;
	do
	{
		
		if (abs->sum == MAX)
		{
			cout << "----------------------" << endl;
			cout << "通讯录已满，无法添加！" << endl;
			return;
		}
		else
		{
			string name;
			cout << "------------" << endl;
			cout << "请输入姓名：" << endl;
			cin >> name;
			abs->Array[abs->sum].Name = name;

			cout << "-------------" << endl;
			cout << "请输入性别： " << endl;
			cout << "1---男" << endl;
			cout << "2---女" << endl;
			int sex = 0;
			while (true)
			{
				cin >> sex;
				if (sex == 1 || sex == 2)
				{
					abs->Array[abs->sum].Sex = sex;
					break;
				}
				cout << "-----------------------" << endl;
				cout << "输入有误，请重新输入： " << endl;
			}

			
			cout << "-----------------" << endl;
			cout << "请输入联系电话： " << endl;
			string phone;
			cin >> phone;
			abs->Array[abs->sum].Phone = phone;

			cout << "-----------------" << endl;
			cout << "请输入家庭住址： " << endl;
			string addr;
			cin >> addr;
			abs->Array[abs->sum].Addr = addr;

			cout << "-------------------" << endl;
			cout << "请输入联系人类别： " << endl;
			cout << "1---亲友" << endl;
			cout << "2---同事" << endl;
			int group = 0;
			while (true)
			{
				cin >> group;
				if (group == 1 || group == 2)
				{
					abs->Array[abs->sum].group = group;
					break;
				}
				cout << "-----------------------" << endl;
				cout << "输入有误，请重新输入： " << endl;
			}

			abs->sum++;

			cout << "----------" << endl;
			cout << "* 添加成功！*" << endl;
			
		}

		cout << "-------------------" << endl;
		cout << "按1可继续添加联系人" << endl;
		cout << "按0停止添加联系人" << endl;

		cin >> n;
		
	}while (n == 1);

		system("pause");
		system("cls");
	
}



void display(contact*abs)
{
	int select;
	cout << "-------------------" << endl;
	cout << "1--显示所有联系人"<<endl;
	cout << "2--显示亲友组联系人" << endl;
	cout << "3--显示同事组联系人" << endl;
	cout << "您的选择是： " << endl;
	cin >> select;

	if (select == 1)
	{
		if (abs->sum == 0)
		{
			cout << "--------------" << endl;
			cout << "当前联系人为空" << endl;

		}
		else
		{
			for (int i = 0; i < abs->sum; i++)
			{
				cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "姓名： " << abs->Array[i].Name << "\t";
				cout << "性别： " << (abs->Array[i].Sex == 1 ? "男" : "女") << "\t";
				cout << "电话： " << abs->Array[i].Phone << "\t";
				cout << "住址： " << abs->Array[i].Addr << "\t";
				cout << "分组： " << (abs->Array[i].group == 1 ? "亲友" : "同事") << endl;
			}
			cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "共有" << abs->sum<< "位联系人" << endl;
		}
	}
	else if (select == 2)
	{
		int n1 = 0;
		for (int i = 0; i < abs->sum; i++)
		{
			if (abs->Array[i].group == 1)
			{
				cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "姓名： " << abs->Array[i].Name << "\t";
				cout << "性别： " << (abs->Array[i].Sex == 1 ? "男" : "女") << "\t";
				cout << "电话： " << abs->Array[i].Phone << "\t";
				cout << "住址： " << abs->Array[i].Addr << "\t";
				cout << "分组： " << (abs->Array[i].group == 1 ? "亲友" : "同事") << endl;
				n1++;
			}
		}
		cout << "-------------------------------" << endl;
		cout << "亲友组共有" << n1 << "位联系人" << endl;
	}

	else if (select == 3)
	{
		int n2 = 0;
		for (int i = 0; i < abs->sum; i++)
		{
			if (abs->Array[i].group == 2)
			{
				cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "姓名： " << abs->Array[i].Name << "\t";
				cout << "性别： " << (abs->Array[i].Sex == 1 ? "男" : "女") << "\t";
				cout << "电话： " << abs->Array[i].Phone << "\t";
				cout << "住址： " << abs->Array[i].Addr << "\t";
				cout << "分组： " << (abs->Array[i].group == 1 ? "亲友" : "同事") << endl;
				n2++;
			}
		}
		cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "同事组共有" << n2 << "位联系人" << endl;
	}

	system("pause");
	system("cls");

}


int find(contact* abs, string name)
{
	for(int i=0;i<abs->sum;i++)
	{
		if (abs->Array[i].Name == name)
		{
			return i;
		}

	}
	return -1;
}


int Find(contact* abs, string name)
{
	for (int i = 0; i < abs->e_size; i++)
	{
		if (abs->emergency[i].Name == name)
		{
			return i;
		}

	}
	return -1;
}



void del(contact* abs)
{
	cout << "------------------------" << endl;
	cout << "请输入您要删除的联系人： "<<endl;

	string name;
	cin >> name;

	cout << "------------" << endl;
	cout << "确认删除吗？" << endl;
	cout << "1--yes" << endl;
	cout << "2--no" << endl;
	int ret = find(abs, name);
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		if (ret != -1)
		{
			for (int i = ret; i < abs->sum; i++)
			{
				abs->Array[i] = abs->Array[i + 1];
			}
			abs->sum--;

			cout << "--------------" << endl;
			cout << "* 删除成功！*" << endl;
		}
		else
		{
			cout << "--------------" << endl;
			cout << "* 查无此人 *" << endl;
		}
	}
	
	system("pause");
	system("cls");

}


void search(contact* abs)
{
	cout << "-----------------------------" << endl;
	cout << "请输入您要查找的联系人姓名： " << endl;
	string name;
	cin >> name;

	int ret = find(abs, name);

	if (ret != -1)
	{
		cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "姓名： " << abs->Array[ret].Name << "\t";
		cout << "性别： " << (abs->Array[ret].Sex == 1 ? "男" : "女") << "\t";
		cout << "电话： " << abs->Array[ret].Phone << "\t";
		cout << "住址： " << abs->Array[ret].Addr << "\t";
		cout << "分组： " << (abs->Array[ret].group == 1 ? "亲友" : "同事") << endl;
	}
	else
	{
		cout << "-------------" << endl;
		cout << "* 查无此人！*" << endl;
	}

	system("pause");
	system("cls");


}


void update(contact* abs)
{
	cout << "-----------------------------" << endl;
	cout << "请输入您要修改的联系人姓名： " << endl;

	string name;
	cin >> name;

	int ret = find(abs, name);

	if (ret != -1)
	{
		cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "姓名： " << abs->Array[ret].Name << "\t";
		cout << "性别： " << (abs->Array[ret].Sex == 1 ? "男" : "女") << "\t";
		cout << "电话： " << abs->Array[ret].Phone << "\t";
		cout << "住址： " << abs->Array[ret].Addr << "\t";
		cout << "分组： " << (abs->Array[ret].group == 1 ? "亲友" : "同事") << endl;

		cout << "-----------------------" << endl;
		cout << "请选择您要修改的内容： " << endl;
		cout << "1--姓名" << endl;
		cout << "2--性别" << endl;
		cout << "3--电话" << endl;
		cout << "4--住址" << endl;
		cout << "5--分组" << endl;
		cout << "6--全部信息" << endl;

		int m;
		cin >> m;

		if (m ==1)
		{
			string name;
			cout << "----------------" << endl;
			cout << "请输入新姓名： " << endl;
			cin >> name;
			abs->Array[ret].Name = name;
		}
		else if (m ==2)
		{
			cout << "----------------" << endl;
			cout << "请输入性别： " << endl;
			cout << "1---男" << endl;
			cout << "2---女" << endl;
			int sex = 0;
			while (true)
			{
				cin >> sex;
				if (sex == 1 || sex == 2)
				{
					abs->Array[ret].Sex = sex;
					break;
				}
				cout << "------------------------" << endl;
				cout << "输入有误，请重新输入： " << endl;
			}
		}

	
		else if (m == 3)
		{
			cout << "----------------------" << endl;
			cout << "请输入新的联系电话： " << endl;
			string phone;
			cin >> phone;
			abs->Array[ret].Phone = phone;

		}

		else if (m == 4)
		{
			cout << "------------------------" << endl;
			cout << "请输入新的家庭住址： " << endl;
			string addr;
			cin >> addr;
			abs->Array[ret].Addr = addr;

		}


		else if (m == 5)
		{
			cout << "--------------------" << endl;
			cout << "请输入联系人类别： " << endl;
			cout << "1---亲友" << endl;
			cout << "2---同事" << endl;
			int group = 0;
			while (true)
			{
				cin >> group;
				if (group == 1 || group == 2)
				{
					abs->Array[ret].group = group;
					break;
				}
				cout << "-----------------------" << endl;
				cout << "输入有误，请重新输入： " << endl;
			}
		}

		else if (m == 6)
		{

			string name;
			cout << "---------------" << endl;
			cout << "请输入新姓名： " << endl;
			cin >> name;
			abs->Array[ret].Name = name;


			cout << "----------------" << endl;
			cout << "请输入性别： " << endl;
			cout << "1---男" << endl;
			cout << "2---女" << endl;
			int sex = 0;
			while (true)
			{
				cin >> sex;
				if (sex == 1 || sex == 2)
				{
					abs->Array[ret].Sex = sex;
					break;
				}
				cout << "------------------------" << endl;
				cout << "输入有误，请重新输入： " << endl;
			}

			

			cout << "---------------------" << endl;
			cout << "请输入新的联系电话： " << endl;
			string phone;
			cin >> phone;
			abs->Array[ret].Phone = phone;


			cout << "-----------------------" << endl;
			cout << "请输入新的家庭住址： " << endl;
			string addr;
			cin >> addr;
			abs->Array[ret].Addr = addr;

			cout << "------------------------" << endl;
			cout << "请输入新的联系人类别： " << endl;
			cout << "1---亲友" << endl;
			cout << "2---同事" << endl;
			int group = 0;
			while (true)
			{
				cin >> group;
				if (group == 1 || group == 2)
				{
					abs->Array[ret].group = group;
					break;
				}
				cout << "------------------------" << endl;
				cout << "输入有误，请重新输入： " << endl;
			}

		}
		cout << "-------------" << endl;
		cout << "* 修改成功！*" << endl;
	}

	else
	{
	    cout << "----------" << endl;
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");

}


void clean(contact* abs)
{
	cout << "-------------" << endl;
	cout << "确认清空吗？" << endl;
	cout << "1--yes" << endl;
	cout << "2--no" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		abs->sum = 0;
		cout << "----------------" << endl;
		cout << "* 通讯录已清空 *" << endl;
	}
	system("pause");
	system("cls");
}


void emergencyPerson(contact* abs)
{
	cout << "------------------" << endl;
	cout << "1--设置紧急联系人" << endl;
	cout << "2--显示紧急联系人" << endl;
	cout << "3--删除紧急联系人" << endl;
	int e;
	cin >> e;
	if (e == 1)
	{
		cout << "------------------------------------" << endl;
		cout << "请输入您要设置为紧急联系人的姓名： " << endl;

		string name;
		cin >> name;

		int ret = find(abs, name);

		if (ret != -1)
		{
			if (abs->e_size < E)
			{
				abs->emergency[abs->e_size].Name = abs->Array[ret].Name;
				abs->emergency[abs->e_size].Sex = abs->Array[ret].Sex;
				abs->emergency[abs->e_size].Phone = abs->Array[ret].Phone;
				abs->emergency[abs->e_size].Addr = abs->Array[ret].Addr;
				abs->emergency[abs->e_size].group = abs->Array[ret].group;
				abs->e_size++;

				cout << "-------------" << endl;
				cout << "* 添加成功 *" << endl;
			}
			else
			{
				cout << "---------------------------" << endl;
				cout << "紧急联系人已满，无法添加！" << endl;
			}
		}
		else
		{
			cout << "----------" << endl;
			cout << "查无此人" << endl;
		}

		system("pause");
		system("cls");
	}


	else if (e == 2)
	{
		if (abs->e_size == 0)
		{
			cout << "-------------------" << endl;
			cout << "当前紧急联系人为空" << endl;

		}
		else
		{
			for (int i = 0; i < abs->e_size; i++)
			{
				cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "姓名： " << abs->emergency[i].Name << "\t";
				cout << "性别： " << (abs->emergency[i].Sex == 1 ? "男" : "女") << "\t";
				cout << "电话： " << abs->emergency[i].Phone << "\t";
				cout << "住址： " << abs->emergency[i].Addr << "\t";
				cout << "分组： " << (abs->emergency[i].group == 1 ? "亲友" : "同事") << endl;
			}
		}
		system("pause");
		system("cls");

	}
	

	else if (e == 3)
	{
		cout << "-----------------------------" << endl;
		cout << "请输入您要删除的紧急联系人： " << endl;

		string name;
		cin >> name;

		cout<<"---------------"<<endl;
		cout << "确认删除吗？" << endl;
		cout << "1--yes" << endl;
		cout << "2--no" << endl;
		int ret = Find(abs, name);
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			if (ret != -1)
			{
				for (int i = ret; i < abs->e_size; i++)
				{
					abs->emergency[i] = abs->emergency[i + 1];
				}
				abs->e_size--;
				cout << "-------------" << endl;
				cout << "* 删除成功！*" << endl;
			}
			else
			{
				cout << "---------" << endl;
				cout << "查无此人" << endl;
			}
		}

		system("pause");
		system("cls");

	}




}


void Menu()
{
	cout << "******************************************" << endl;
	cout << "**-------  欢迎使用通讯录系统！ --------**" << endl;
	cout << "**-----------  1.添加联系人  -----------**" << endl;
	cout << "**-----------  2.显示联系人  -----------**" << endl;
	cout << "**-----------  3.删除联系人  -----------**" << endl;
	cout << "**-----------  4.查找联系人  -----------**" << endl;
	cout << "**-----------  5.修改联系人  -----------**" << endl;
	cout << "**-----------  6.清空联系人  -----------**" << endl;
	cout << "**-----------  7.紧急联系人  -----------**" << endl;
	cout << "**-----------  0.退出通讯录  -----------**" << endl;
	cout << "******************************************" << endl;
	cout << endl;
}


int main()
{
	
	contact abs;
	abs.sum = 0;
	abs.e_size = 0;

	int select;
	
	while (true)
	{
		Menu();
		cin >> select;

		switch (select)
		{
		case 0:
			cout << "* 欢迎下次使用！*" << endl;
			system("pause");
			break;

		case 1:
			add(&abs);
			break;

		case 2:
			display(&abs);
			break;

		case 3:
			del(&abs);
			break;

		case 4:
			search(&abs);
			break;

		case 5:
			update(&abs);
			break;

		case 6:
			clean(&abs);
			break;

		case 7:
			emergencyPerson(&abs);
			break;

		default:
			break;

		}
	}


	
	
	system("pause");
	return 0;
}