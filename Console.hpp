#include"Header.h"
#include"TestSorter.hpp"

Sequence<int>* Generation_of_int_seq(const int choice) 
{
	if (choice == 1)
	{
		ArraySequence<int>* array = new ArraySequence<int>();
		for (size_t i = 0; i < 10; i++)
		{
			array->Append(1 + rand() % 200);
		}

		return array;
	}
	if (choice == 0)
	{
		ListSequence<int>* list = new ListSequence<int>();
		for (size_t i = 0; i < 10; i++)
		{
			list->Append(1 + rand() % 200);
		}

		return list;
	}

	return NULL;
}

Sequence<double>* Generation_of_double_seq(const int choice) 
{
	if (choice == 1)
	{
		ArraySequence<double>* array = new ArraySequence<double>();
		for (size_t i = 0; i < 10; i++)
		{
			array->Append(double(1 + rand() % 200));
		}

		return array;
	}
	if (choice == 0)
	{
		ListSequence<double>* list = new ListSequence<double>();
		for (size_t i = 0; i < 10; i++)
		{
			list->Append(double(1 + rand() % 200));
		}

		return list;
	}
	
	return NULL;

}

Sequence<char>* Generation_of_char_seq(const int choice)
{
	if (choice == 1)
	{
		ArraySequence<char>* array = new ArraySequence<char>();
		for (size_t i = 0; i < 10; i++)
		{
			array->Append(char(rand() % 26 + 0x61));
		}

		return array;
	}
	if (choice == 0)
	{
		ListSequence<char>* list = new ListSequence<char>();
		for (size_t i = 0; i < 10; i++)
		{
			list->Append(char(rand() % 26 + 0x61));
		}

		return list;
	}

	return NULL;

}

void Menu() 
{
	cout << "Hi! This sorter can sort all you want" << endl;
	cout << " Select what you want " << endl;
	cout << "1. Time of differen sorts " << endl;
	cout << "2. Test of random sequince 10000 elements" << endl;
	cout << "3. Input sequince for sorting " << endl;
	cout << "4. Exit " << endl;
}

void Console() 
{
	size_t flag = 0;
	int choice = -1;
	ListSequence<int>* list = new ListSequence<int>();
	Menu();
	cin >> choice;

	while (true)
	{
		int temp = 0;
		switch (choice)
		{
		case 1:
			Point_1();
			break;
		case 2:
			cout << "Input type of sequince (1 - int, 2 - double, 3 - char) " << endl;
			int k;
			cin >> k;
			cout << " Input list or array (1 - array, 0 - list)" << endl;
			int t;
			cin >> t;
			Sequence<int>* seq_int;
			Sequence<double>* seq_double;
			Sequence<char>* seq_char;
			seq_int = Generation_of_int_seq(t);
			ISorter<int>* sort;
			if (t == 1)
			{
				switch (k) 
				{
				case 1:
					 seq_int = Generation_of_int_seq(t);
					 cout << "This is random seq" << endl;
					 for (size_t i = 0; i < seq_int->GetLength(); i++)
					 {
						 cout << seq_int->Get(i) << " ";
					 }
					 cout << endl;
					 sort = new QuikSort<int>();
					 sort->Sort(seq_int, compare);
					 cout << " This is sorted seq " << endl;
					 for (size_t i = 0; i < seq_int->GetLength(); i++)
					 {
						 cout << seq_int->Get(i) << " ";
					 }
					 cout << endl;
					break;
				case 2:
					ISorter<double>* sort_double;
					seq_double = Generation_of_double_seq(t);
					cout << "This is random seq" << endl;
					for (size_t i = 0; i < seq_double->GetLength(); i++)
					{
						cout << seq_double->Get(i) << " ";
					}
					sort_double = new QuikSort<double>();
					sort_double->Sort(seq_double, compare);
					cout << " This is sorted seq " << endl;
					for (size_t i = 0; i < seq_double->GetLength(); i++)
					{
						cout << seq_double->Get(i) << " ";
					}
					cout << endl;
					break;
				case 3:
					ISorter<char>* sort_char;
					seq_char = Generation_of_char_seq(t);
					cout << "This is random seq" << endl;
					for (size_t i = 0; i < seq_char->GetLength(); i++)
					{
						cout << seq_char->Get(i) << " ";
					}
					sort_char = new QuikSort<char>();
					sort_char->Sort(seq_char, compare);
					cout << " This is sorted seq " << endl;
					for (size_t i = 0; i < seq_char->GetLength(); i++)
					{
						cout << seq_char->Get(i) << " ";
					}
					cout << endl;
				default:
					break;
				}
			}
			else 
			{
				switch (k)
				{
				case 1:
					 seq_int =  Generation_of_int_seq(t);
					break;
				case 2:
					 seq_double = Generation_of_double_seq(t);
					break;
				case 3:
					 seq_char = Generation_of_char_seq(t);
				default:
					break;
				}
			}
			break;
		case 3:
			cout << "Input your int length" << endl;
			int length;
			cin >> length;
			for (size_t i = 0; i < length; i++)
			{
				cin >> temp;
				list->Prepend(temp);
			}

			cout << "This is your seq " << endl;
			for (size_t i = 0; i < length; i++)
			{
				cout << list->Get(i) << " ";
			}
			cout << endl;
			break;
		default:
			cout << "ERROR incorrect value. Try again..." << endl;
			break;
		}
		break;
	}
}