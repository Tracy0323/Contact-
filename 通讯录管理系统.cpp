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
			cout << "ͨѶ¼�������޷���ӣ�" << endl;
			return;
		}
		else
		{
			string name;
			cout << "------------" << endl;
			cout << "������������" << endl;
			cin >> name;
			abs->Array[abs->sum].Name = name;

			cout << "-------------" << endl;
			cout << "�������Ա� " << endl;
			cout << "1---��" << endl;
			cout << "2---Ů" << endl;
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
				cout << "�����������������룺 " << endl;
			}

			
			cout << "-----------------" << endl;
			cout << "��������ϵ�绰�� " << endl;
			string phone;
			cin >> phone;
			abs->Array[abs->sum].Phone = phone;

			cout << "-----------------" << endl;
			cout << "�������ͥסַ�� " << endl;
			string addr;
			cin >> addr;
			abs->Array[abs->sum].Addr = addr;

			cout << "-------------------" << endl;
			cout << "��������ϵ����� " << endl;
			cout << "1---����" << endl;
			cout << "2---ͬ��" << endl;
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
				cout << "�����������������룺 " << endl;
			}

			abs->sum++;

			cout << "----------" << endl;
			cout << "* ��ӳɹ���*" << endl;
			
		}

		cout << "-------------------" << endl;
		cout << "��1�ɼ��������ϵ��" << endl;
		cout << "��0ֹͣ�����ϵ��" << endl;

		cin >> n;
		
	}while (n == 1);

		system("pause");
		system("cls");
	
}



void display(contact*abs)
{
	int select;
	cout << "-------------------" << endl;
	cout << "1--��ʾ������ϵ��"<<endl;
	cout << "2--��ʾ��������ϵ��" << endl;
	cout << "3--��ʾͬ������ϵ��" << endl;
	cout << "����ѡ���ǣ� " << endl;
	cin >> select;

	if (select == 1)
	{
		if (abs->sum == 0)
		{
			cout << "--------------" << endl;
			cout << "��ǰ��ϵ��Ϊ��" << endl;

		}
		else
		{
			for (int i = 0; i < abs->sum; i++)
			{
				cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "������ " << abs->Array[i].Name << "\t";
				cout << "�Ա� " << (abs->Array[i].Sex == 1 ? "��" : "Ů") << "\t";
				cout << "�绰�� " << abs->Array[i].Phone << "\t";
				cout << "סַ�� " << abs->Array[i].Addr << "\t";
				cout << "���飺 " << (abs->Array[i].group == 1 ? "����" : "ͬ��") << endl;
			}
			cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "����" << abs->sum<< "λ��ϵ��" << endl;
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
				cout << "������ " << abs->Array[i].Name << "\t";
				cout << "�Ա� " << (abs->Array[i].Sex == 1 ? "��" : "Ů") << "\t";
				cout << "�绰�� " << abs->Array[i].Phone << "\t";
				cout << "סַ�� " << abs->Array[i].Addr << "\t";
				cout << "���飺 " << (abs->Array[i].group == 1 ? "����" : "ͬ��") << endl;
				n1++;
			}
		}
		cout << "-------------------------------" << endl;
		cout << "�����鹲��" << n1 << "λ��ϵ��" << endl;
	}

	else if (select == 3)
	{
		int n2 = 0;
		for (int i = 0; i < abs->sum; i++)
		{
			if (abs->Array[i].group == 2)
			{
				cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "������ " << abs->Array[i].Name << "\t";
				cout << "�Ա� " << (abs->Array[i].Sex == 1 ? "��" : "Ů") << "\t";
				cout << "�绰�� " << abs->Array[i].Phone << "\t";
				cout << "סַ�� " << abs->Array[i].Addr << "\t";
				cout << "���飺 " << (abs->Array[i].group == 1 ? "����" : "ͬ��") << endl;
				n2++;
			}
		}
		cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "ͬ���鹲��" << n2 << "λ��ϵ��" << endl;
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
	cout << "��������Ҫɾ������ϵ�ˣ� "<<endl;

	string name;
	cin >> name;

	cout << "------------" << endl;
	cout << "ȷ��ɾ����" << endl;
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
			cout << "* ɾ���ɹ���*" << endl;
		}
		else
		{
			cout << "--------------" << endl;
			cout << "* ���޴��� *" << endl;
		}
	}
	
	system("pause");
	system("cls");

}


void search(contact* abs)
{
	cout << "-----------------------------" << endl;
	cout << "��������Ҫ���ҵ���ϵ�������� " << endl;
	string name;
	cin >> name;

	int ret = find(abs, name);

	if (ret != -1)
	{
		cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "������ " << abs->Array[ret].Name << "\t";
		cout << "�Ա� " << (abs->Array[ret].Sex == 1 ? "��" : "Ů") << "\t";
		cout << "�绰�� " << abs->Array[ret].Phone << "\t";
		cout << "סַ�� " << abs->Array[ret].Addr << "\t";
		cout << "���飺 " << (abs->Array[ret].group == 1 ? "����" : "ͬ��") << endl;
	}
	else
	{
		cout << "-------------" << endl;
		cout << "* ���޴��ˣ�*" << endl;
	}

	system("pause");
	system("cls");


}


void update(contact* abs)
{
	cout << "-----------------------------" << endl;
	cout << "��������Ҫ�޸ĵ���ϵ�������� " << endl;

	string name;
	cin >> name;

	int ret = find(abs, name);

	if (ret != -1)
	{
		cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "������ " << abs->Array[ret].Name << "\t";
		cout << "�Ա� " << (abs->Array[ret].Sex == 1 ? "��" : "Ů") << "\t";
		cout << "�绰�� " << abs->Array[ret].Phone << "\t";
		cout << "סַ�� " << abs->Array[ret].Addr << "\t";
		cout << "���飺 " << (abs->Array[ret].group == 1 ? "����" : "ͬ��") << endl;

		cout << "-----------------------" << endl;
		cout << "��ѡ����Ҫ�޸ĵ����ݣ� " << endl;
		cout << "1--����" << endl;
		cout << "2--�Ա�" << endl;
		cout << "3--�绰" << endl;
		cout << "4--סַ" << endl;
		cout << "5--����" << endl;
		cout << "6--ȫ����Ϣ" << endl;

		int m;
		cin >> m;

		if (m ==1)
		{
			string name;
			cout << "----------------" << endl;
			cout << "�������������� " << endl;
			cin >> name;
			abs->Array[ret].Name = name;
		}
		else if (m ==2)
		{
			cout << "----------------" << endl;
			cout << "�������Ա� " << endl;
			cout << "1---��" << endl;
			cout << "2---Ů" << endl;
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
				cout << "�����������������룺 " << endl;
			}
		}

	
		else if (m == 3)
		{
			cout << "----------------------" << endl;
			cout << "�������µ���ϵ�绰�� " << endl;
			string phone;
			cin >> phone;
			abs->Array[ret].Phone = phone;

		}

		else if (m == 4)
		{
			cout << "------------------------" << endl;
			cout << "�������µļ�ͥסַ�� " << endl;
			string addr;
			cin >> addr;
			abs->Array[ret].Addr = addr;

		}


		else if (m == 5)
		{
			cout << "--------------------" << endl;
			cout << "��������ϵ����� " << endl;
			cout << "1---����" << endl;
			cout << "2---ͬ��" << endl;
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
				cout << "�����������������룺 " << endl;
			}
		}

		else if (m == 6)
		{

			string name;
			cout << "---------------" << endl;
			cout << "�������������� " << endl;
			cin >> name;
			abs->Array[ret].Name = name;


			cout << "----------------" << endl;
			cout << "�������Ա� " << endl;
			cout << "1---��" << endl;
			cout << "2---Ů" << endl;
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
				cout << "�����������������룺 " << endl;
			}

			

			cout << "---------------------" << endl;
			cout << "�������µ���ϵ�绰�� " << endl;
			string phone;
			cin >> phone;
			abs->Array[ret].Phone = phone;


			cout << "-----------------------" << endl;
			cout << "�������µļ�ͥסַ�� " << endl;
			string addr;
			cin >> addr;
			abs->Array[ret].Addr = addr;

			cout << "------------------------" << endl;
			cout << "�������µ���ϵ����� " << endl;
			cout << "1---����" << endl;
			cout << "2---ͬ��" << endl;
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
				cout << "�����������������룺 " << endl;
			}

		}
		cout << "-------------" << endl;
		cout << "* �޸ĳɹ���*" << endl;
	}

	else
	{
	    cout << "----------" << endl;
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");

}


void clean(contact* abs)
{
	cout << "-------------" << endl;
	cout << "ȷ�������" << endl;
	cout << "1--yes" << endl;
	cout << "2--no" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		abs->sum = 0;
		cout << "----------------" << endl;
		cout << "* ͨѶ¼����� *" << endl;
	}
	system("pause");
	system("cls");
}


void emergencyPerson(contact* abs)
{
	cout << "------------------" << endl;
	cout << "1--���ý�����ϵ��" << endl;
	cout << "2--��ʾ������ϵ��" << endl;
	cout << "3--ɾ��������ϵ��" << endl;
	int e;
	cin >> e;
	if (e == 1)
	{
		cout << "------------------------------------" << endl;
		cout << "��������Ҫ����Ϊ������ϵ�˵������� " << endl;

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
				cout << "* ��ӳɹ� *" << endl;
			}
			else
			{
				cout << "---------------------------" << endl;
				cout << "������ϵ���������޷���ӣ�" << endl;
			}
		}
		else
		{
			cout << "----------" << endl;
			cout << "���޴���" << endl;
		}

		system("pause");
		system("cls");
	}


	else if (e == 2)
	{
		if (abs->e_size == 0)
		{
			cout << "-------------------" << endl;
			cout << "��ǰ������ϵ��Ϊ��" << endl;

		}
		else
		{
			for (int i = 0; i < abs->e_size; i++)
			{
				cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "������ " << abs->emergency[i].Name << "\t";
				cout << "�Ա� " << (abs->emergency[i].Sex == 1 ? "��" : "Ů") << "\t";
				cout << "�绰�� " << abs->emergency[i].Phone << "\t";
				cout << "סַ�� " << abs->emergency[i].Addr << "\t";
				cout << "���飺 " << (abs->emergency[i].group == 1 ? "����" : "ͬ��") << endl;
			}
		}
		system("pause");
		system("cls");

	}
	

	else if (e == 3)
	{
		cout << "-----------------------------" << endl;
		cout << "��������Ҫɾ���Ľ�����ϵ�ˣ� " << endl;

		string name;
		cin >> name;

		cout<<"---------------"<<endl;
		cout << "ȷ��ɾ����" << endl;
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
				cout << "* ɾ���ɹ���*" << endl;
			}
			else
			{
				cout << "---------" << endl;
				cout << "���޴���" << endl;
			}
		}

		system("pause");
		system("cls");

	}




}


void Menu()
{
	cout << "******************************************" << endl;
	cout << "**-------  ��ӭʹ��ͨѶ¼ϵͳ�� --------**" << endl;
	cout << "**-----------  1.�����ϵ��  -----------**" << endl;
	cout << "**-----------  2.��ʾ��ϵ��  -----------**" << endl;
	cout << "**-----------  3.ɾ����ϵ��  -----------**" << endl;
	cout << "**-----------  4.������ϵ��  -----------**" << endl;
	cout << "**-----------  5.�޸���ϵ��  -----------**" << endl;
	cout << "**-----------  6.�����ϵ��  -----------**" << endl;
	cout << "**-----------  7.������ϵ��  -----------**" << endl;
	cout << "**-----------  0.�˳�ͨѶ¼  -----------**" << endl;
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
			cout << "* ��ӭ�´�ʹ�ã�*" << endl;
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