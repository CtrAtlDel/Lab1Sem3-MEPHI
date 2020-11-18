#include"Header.h"
#include <iostream>
#include<chrono>
using namespace std;

void It_is_work() 
{
	ShellSort<int>* sorter = new ShellSort<int>();

	ListSequence<int>* list = new ListSequence<int>();

	for (size_t i = 0; i < 10; i++)
	{
		list->Append(1 + rand() % 200);
	}
	for (size_t i = 0; i < 10; i++)
	{
		cout << list->Get(i) << endl;
	}
	sorter->Sort(list, compare);
	for (size_t i = 0; i < 10; i++)
	{
		cout << list->Get(i) << endl;
	}

	ArraySequence<int>* array = new ArraySequence<int>();

	for (size_t i = 0; i < 10; i++)
	{
		array->Append(1 + rand() % 200);
	}
	for (size_t i = 0; i < 10; i++)
	{
		cout << array->Get(i) << endl;
	}
	sorter->Sort(array, compare);
	for (size_t i = 0; i < 10; i++)
	{
		cout << array->Get(i) << endl;
	}
}

void ShellSort_test_of_time() 
{
	////////////////////array
	cout << "Test Shellsort " << endl;

	ShellSort<int>* sorter = new ShellSort<int>();

	ArraySequence<int>* array = new ArraySequence<int>();

	for (int i = 0; i < 10000; i++)
	{
		array->Append(1 + rand() % 200);
	}
	auto start = std::chrono::high_resolution_clock::now();
	sorter->Sort(array, compare);
	auto end = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	double time_of_sort = duration.count();

	cout << "Time shellsort of array ========= "<< time_of_sort << endl;

	//////////////////list

	ListSequence<int>* list = new ListSequence<int>();

	for (size_t i = 0; i < 10000; i++)
	{
		list->Append(1 + rand() % 200);
	}

	auto startlist = std::chrono::high_resolution_clock::now();
	sorter->Sort(array, compare);
	auto endlist = std::chrono::high_resolution_clock::now();

	auto durationlist = std::chrono::duration_cast<std::chrono::microseconds>(end - startlist);

	double time_of_sortlist = duration.count();

	cout << "Time shellsort of list ========= " << time_of_sortlist << endl;
}

void InsertionSort_test_of_time() 
{
	cout << "Test InsertionSort" << endl;

	InsertionSort<int>* sorter = new InsertionSort<int>();

	ArraySequence<int>* array = new ArraySequence<int>();

	for (int i = 0; i < 10000; i++)
	{
		array->Append(1 + rand() % 200);
	}
	auto start = std::chrono::high_resolution_clock::now();
	sorter->Sort(array, compare);
	auto end = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	double time_of_sort = duration.count();

	cout << "Time shellsort of array ========= " << time_of_sort << endl;

	//////////////////list

	ListSequence<int> * list = new ListSequence<int>();

	for (size_t i = 0; i < 10000; i++)
	{
		list->Append(1 + rand() % 200);
	}

	auto startlist = std::chrono::high_resolution_clock::now();
	sorter->Sort(array, compare);
	auto endlist = std::chrono::high_resolution_clock::now();

	auto durationlist = std::chrono::duration_cast<std::chrono::microseconds>(end - startlist);

	double time_of_sortlist = duration.count();

	cout << "Time shellsort of list ========= " << time_of_sortlist << endl;
}

void QuikSort_test_of_time() 
{
	cout << "Test InsertionSort" << endl;

	QuikSort<int>* sorter = new QuikSort<int>();

	ArraySequence<int>* array = new ArraySequence<int>();

	for (int i = 0; i < 10000; i++)
	{
		array->Append(1 + rand() % 200);
	}
	auto start = std::chrono::high_resolution_clock::now();
	sorter->Sort(array, compare);
	auto end = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	double time_of_sort = duration.count();

	cout << "Time shellsort of array ========= " << time_of_sort << endl;

	//////////////////list

	ListSequence<int> * list = new ListSequence<int>();

	for (size_t i = 0; i < 10000; i++)
	{
		list->Append(1 + rand() % 200);
	}

	auto startlist = std::chrono::high_resolution_clock::now();
	sorter->Sort(array, compare);
	auto endlist = std::chrono::high_resolution_clock::now();

	auto durationlist = std::chrono::duration_cast<std::chrono::microseconds>(end - startlist);

	double time_of_sortlist = duration.count();

	cout << "Time shellsort of list ========= " << time_of_sortlist << endl;
}

void Point_1()
{
	ShellSort_test_of_time();
	InsertionSort_test_of_time();
	QuikSort_test_of_time();
}