#pragma once
#include <iostream>
#include <time.h>
using namespace std;
template <class T>
struct TLink
{
	T val;
	TLink* pNext;
};
template <class T>
class TList
{
	TLink <T>* pFirst, * pLast, * pCurr, * pPrev, * pStop;
	int size;
	int pos;
public:
	TList()
	{
		pFirst = pPrev = pLast = pCurr = pStop = NULL;
		size = 0;
		pos = -1;
	}
	void InsFirst(T a)
	{
		TLink <T>* tmp = new TLink <T>;
		tmp->val = a;
		if (size == 0)
		{
			pFirst = pLast = pCurr = tmp;
			tmp->pNext = pStop;
			pos = 0;
		}
		else
		{
			tmp->pNext = pFirst;
			pFirst = tmp;
			pos++;
		}
		size++;
	}
	void InsCurr(T a)
	{
		if (pCurr == pFirst)
		{
			InsFirst(a);
		}
		else
		{
			TLink <T>* tmp = new TLink <T>;
			tmp->val = a;
			tmp->pNext = pCurr;
			pPrev->pNext = tmp;
			pCurr = tmp;
			size++;
		}
	}
	void InsLast(T a)
	{
		if (size == 0)
		{
			InsFirst(a);
		}
		else
		{
			TLink <T>* tmp = new TLink <T>;
			tmp->val = a;
			for (Reset(); !IsEnd(); GoNext())
			{
				if (pCurr->pNext == pStop)
					pLast = pCurr;
			}
			pLast->pNext = tmp;
			tmp->pNext = pStop;
			pLast = tmp;
			pos++;
		}
		size++;
	}
	void InsPos(T a, int N)
	{
		if (size == 0)
		{
			InsFirst(a);
		}
		else
		{
			TLink <T>* tmp = new TLink <T>;
			tmp->val = a;
			Reset();
			while (pos != N - 1)
				GoNext();
			tmp->pNext = pCurr->pNext;
			pCurr->pNext = tmp;
			pCurr = tmp;
			pos++;
		}
		size++;
	}
	void DelFirst()
	{
		if (size == 1)
		{
			delete pFirst;
			pFirst = pPrev = pLast = pStop;
		}
		else
		{
			TLink <T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
		size--;
		pos--;
	}
	void DelCurr()
	{
		if (pCurr == pFirst)
		{
			DelFirst();
		}
		else
		{
			pCurr = pCurr->pNext;
			delete pPrev->pNext;
			pPrev->pNext = pCurr;
			size--;
		}
	}
	T GetCurrVal()
	{
		return pCurr->val;
	}
	void Reset()
	{
		pCurr = pFirst;
		pos = 0;
		pPrev = pStop;
	}
	void GoNext()
	{
		pPrev = pCurr;
		pCurr = pCurr->pNext;
		pos++;
	}
	bool IsEnd()
	{
		if (pCurr == pStop) return true;
		else return false;
	}
	void Print()
	{
		for (Reset(); !IsEnd(); GoNext())
		{
			cout << pCurr->val << ' ';
		}
		cout << '\n';
	}
	void CreateList(int N)
	{
		srand(time(NULL));
		T tmp;
		for (int i = 0; i < N; i++)
		{
			tmp = rand() % 100;
			Reset();
			while (!IsEnd())
				GoNext();
			InsCurr(tmp);
		}
	}
	T FindMin()
	{
		T min = pFirst->val;
		for (Reset(); !IsEnd(); GoNext())
		{
			if (GetCurrVal() < min)
				min = pCurr->val;
		}
		cout << '\n' << "Min is " << min << ' ';
		return min;
	}
	T FindMax()
	{
		T max = pFirst->val;
		for (Reset(); !IsEnd(); GoNext())
		{
			if (GetCurrVal() > max)
				max = pCurr->val;
		}
		cout << '\n' << "Max is " << max << ' ';
		return max;
	}
};
