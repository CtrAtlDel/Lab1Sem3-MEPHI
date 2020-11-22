#include"Header.h"
#include"Sequence.hpp"
#include"func.hpp"

template<typename T>
void Swap(Sequence<T>* seq, const int& index1, const int& index2)
{
	T item = seq->Get(index1);
	seq->Set(index1, seq->Get(index2));
	seq->Set(index2, item);
}

template<class T>
class ISorter
{
public:
	virtual void Sort(Sequence<T>* seq, int (*compare)(T, T)) = 0;
public:
	virtual ~ISorter() {};
};

template<class T>
class InsertionSort: public ISorter<T> 
{
public:
	virtual void Sort(Sequence<T>* seq, int (*cmp)(T, T)) override
	{
		T temp;
		int item;
		for (int i = 1; i < seq->GetLength(); i++)
		{
			temp = seq->Get(i);
			item = i - 1;
			while (item >= 0 && seq->Get(item) > temp)
			{
				seq->Set(seq->Get(item), item + 1);
				seq->Set(temp, item);
				item--;
			}
		}
	}
};


template<class T>
class ShellSort : public ISorter<T>
{
public:
public:
	virtual void Sort(Sequence<T>* seq, int (*cmp)(T, T)) override
	{
		int length = seq->GetLength();
		int d = length / 2;


		while (d >= 1)
		{
			bool IsSwaped = false;
			for (int i = 0; i < length - d; i++)
			{
				if (cmp(seq->Get(i), seq->Get(i + d)) == 1)
				{
					seq->Swap(i, i + d);
					IsSwaped = true;
				}
			}

			if (IsSwaped == false)
			{
				d = d / 2;
			}
		}

	}
};

template<class T>
class QuikSort : public ISorter<T> 
{
public:
	virtual void  Sort(Sequence<T>* seq, int (*cmp)(T, T)) override
	{
		 Sort_Base(seq, cmp, 0, seq->GetLength() - 1);
	}
	void Sort_Base(Sequence<T> * seq, int (*cmp)(T, T), int StartIndex, int EndIndex)
	{
		int left = StartIndex;
		int right = EndIndex;
		//половинка
		T mid = seq->Get((EndIndex + StartIndex) / 2);

		while (left <= right)
		{
			while (cmp(seq->Get(left), mid) == -1)
			{
				left++;
			}

			while (cmp(mid, seq->Get(right)) == -1)
			{
				right--;
			}

			if (left <= right)
			{
				seq->Swap(left, right);
				left++;
				right--;
			}
		}

		if (right > StartIndex)
		{
			Sort_Base(seq, cmp, StartIndex, right);
		}

		if (left < EndIndex)
		{
			Sort_Base(seq, cmp, left, EndIndex);
		}
	}
};