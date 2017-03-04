#include "header.h"

void Todo1()
{
    Todo2();
}
void Todo2()
{
	static int s_iLocalStatic = 0;
	printf("Foo: called %d\n",
		s_iLocalStatic++);
}
void Swap(int &x, int &y)
{
	x = x + y;
	y = x - y;
	x = x - y;
}
void Print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << " " << arr[i];
	cout << endl;
}
void BubbleSort2(int arr[], int offset, int count)
{
	int start = offset;
	int end = offset + count;
	bool swapped = true;
	while (swapped)
	{
		swapped = false;
		for (int i = start + 1; i < end; i++)
		{
			if (arr[i - 1] > arr[i])
			{
				Swap(arr[i - 1], arr[i]);
				swapped = true;
			}
		}
	}
}
int CheckBigger(int a, int b) { return a > b; }
int CheckSmaller(int a, int b) { return a < b; }
void BubbleSort1(int arr[], int offset, int count, int (*order)(int, int))
{
	int start = offset;
	int end = offset + count;
	int numberoffor = 0;
	for (int i = start; i < end; i++)
	{
		for (int k = start + 1; k < end - numberoffor; k++)
		{
			if ((*order)(arr[k - 1], arr[k]))
			{
				Swap(arr[k - 1], arr[k]);
			}
		}
		numberoffor++;
	}
}
//void Invert(int input[], int num_element)
//{
//	for (int i = 0; i < num_element / 2; i++)
//	{
//		Swap(input[i], input[num_element - 1 - i]);
//	}
//}
void Invert(int input[], int num_element, int output[])
{
	for (int i = num_element - 1; i >= 0; i--)
	{
		output[num_element - i - 1] = input[i];
	}
}
void SayHello()
{
	printf("Hello world\n");
}
void SayHello(char *str)
{
	printf("Hello world - %s\n", str);
}
void SayHello2(char *str, bool b = false)
{
	if (b)
	{
		/*int i = 0;
		while (str[i])
		{
			str[i] = toupper(str[i]);
			i++;
		}*/
		printf("Hello worldddd - %s\n", str);
	}
	else
		printf("H - %s\n", str);
}
class ClassA
{
  public:
	ClassA(int val = 0) {m_pVal = val;}
	int m_pVal;
};
void Todo1(ClassA *A, ClassA *B)
{
	ClassA *tmp = A;
	A = B;
	B = tmp;
}
void Todo2(ClassA &A, ClassA &B)
{
	ClassA tmp = A;
	A = B;
	B = tmp;
}
void Todo3(ClassA A, ClassA B)
{
	ClassA tmp = A;
	A = B;
	B = tmp;
}
void Todo4(ClassA *&A, ClassA *&B)
{
	ClassA *tmp = A;
	A = B;
	B = tmp;
}

typedef struct __Date__
{
	unsigned char DayOfWeek;
	unsigned char Day;
	unsigned char Month;
	unsigned int Year;
	__Date__();
	void PrintDate(char *strFormat);
}Date;

class People
{
protected:
	char *_name;
	int _id;
	//Date _birthDay;
public:
	People(char *name, int id)
	{
		_name = name;
		_id = id;
	}
	virtual ~People()
	{
		if (!_name) delete[] _name;
		printf ("Destroy people id: %d\n", _id);
	}
	virtual void PrintInfo()
	{
		printf ("People id: %d, name: %s\n", _id, _name);
	}
	void SetName(char *name)
	{
		if (!_name) delete _name;
		_name = name;
	}
	char* GetName();
	void SetID(int id)
	{
		_id = id;
	}
	int GetID();
};

class Staff : public People
{
protected:
	int _departmentID;
	int _level;
	//Date _joinedDate;
public:
	Staff(char *name, int id, int depID, int lv) : People(name, id)
	{
		_departmentID = depID;
		_level = lv;
	}
	virtual ~Staff()
	{
		printf ("Destroy staff id: %d\n", _id);
	}
	virtual void PrintInfo()
	{
		People::PrintInfo();
		printf ("Staff id: %d, departmentid: %d, level: %d\n", _id, _departmentID, _level);
	}
	void SetDepartmentID(int departmentID)
	{
		_departmentID = departmentID;
	}
	int GetDepartmentID();
	void SetLevel(int level)
	{
		_level = level;
	}
	int GetLevel();
};

class Student : public People
{
private:
	int _grade;
	int _numberOfProject;
	float *_scoreOfEachProject;
public:
	Student(char *name, int id, int grade, int numOfProject, float* scoreOfEachProject) : People(name, id)
	{
		_grade = grade;
		_numberOfProject = numOfProject;
		_scoreOfEachProject = scoreOfEachProject;
	}
	virtual ~Student()
	{
		if (!_scoreOfEachProject) delete[] _scoreOfEachProject;
		printf ("Destroy student id: %d\n", _id);
	}
	void PrintInfo()
	{
		People::PrintInfo();
		printf ("Student id: %d, grade: %d, numOfProject: %d\n", _id, _grade, _numberOfProject);
		for (int i = 0; i < _numberOfProject; i++)
		{
			printf ("Score of project %d: %.2f\n", i + 1, _scoreOfEachProject[i]);
		}
	}
	void SetGrade(int grade)
	{
		_grade = grade;
	}
	int GetGrade();
	int GetNumberOfProject();
	void SetScore(int numberOfProject, float *score)
	{
		if (!score) delete[] score;
		_numberOfProject = numberOfProject;
		_scoreOfEachProject = score;
	}
	float* GetScore();
	float GetAverageScore();
};

enum SUBJECT { MATHS, PHYS, ENGLISH };

class Teacher : public People, public Staff
{
private:
	int _class;
	SUBJECT _subject;
	SUBJECT _secondSubject;
public:
	Teacher(char *name, int id, int depID, int lv, int cls, SUBJECT sbj, SUBJECT sndSbj) :
		People(name, id), Staff(name, id, depID, lv)
	{
		  _class = cls;
		  _subject = sbj;
		  _secondSubject = sndSbj;
	}
	virtual ~Teacher()
	{
		printf ("Destroy teacher id: %d\n", People::_id);
	}
	void PrintInfo()
	{
		People::PrintInfo();
		Staff::PrintInfo();
		printf ("Teacher id: %d, class: %d, subject: %d, second subject: %d\n", People::_id, _class, _subject, _secondSubject);
	}
	void SetClass(int cls);
	int GetClass();
	void SetSubject(SUBJECT subject);
	SUBJECT GetSubject();
	void SetSecondSubject(SUBJECT secondSubject);
	SUBJECT GetSecondSubject();
};
//---------------------------------
class Node
{
public:
	People* data;
	Node* next;
	void SetInfo(People *dt)
	{
		data = dt;
	}
	void PrintInfo()
	{
		if (!data)
			data->PrintInfo();
		else
			printf ("Data empty\n");
	}
};
//---------------------------------
template <class T> class LinkedList
{
private:
	int count;
	T* pHead;
public:
	LinkedList() { count=0; pHead = NULL; }
	void Print();
	void AddNode(People *pp);
	void RemoveNode(int index);
	void RemoveAllNode();
	bool CheckDuplicateID(int id);
	void SortListByScore();
	void RemoveStudentGetScoreLessThan5();
};
//---------------------------------
template <class T> void LinkedList<T>::Print()
{
	printf ("Linked list: %d elements\n", count);
	T* temp = pHead;
	while (temp != NULL)
	{
		temp->PrintInfo();
		temp = temp->next;
	};
	printf ("\n");
};
template <class T> void LinkedList<T>::AddNode(People *pp)
{
	T *n = new T();
	n->SetInfo(pp);
	if (pHead == NULL)
	{
		pHead = n;
	}
	else
	{
		T* nTemp = pHead;
		while(nTemp->next != NULL)
			nTemp = nTemp->next;
		nTemp->next = n;
	}
	count++;
};
template <class T> void LinkedList<T>::RemoveNode(int index)
{
	T* nTemp = pHead;
	if (nTemp == NULL)
	{
		printf ("Linked list empty\n");
		return;
	}
	if (index < 0 || index >= count)
	{
		printf ("Index out of range\n");
		return;
	}
	if (index == 0)
	{
		pHead = pHead->next;
		delete nTemp;
	}
	else
	{
		int i = 0;
		while (i < index - 1)
		{
			nTemp = nTemp->next;
			i++;
		}
		T* nTemp2 = NULL;
		if (nTemp->next->next != NULL)
			nTemp2 = nTemp->next->next;
		delete nTemp->next;
		nTemp->next = nTemp2;
	}
	count--;
}
template <class T> void LinkedList<T>::RemoveAllNode()
{
	T* nTemp = NULL;
	while(pHead != NULL)
	{
		nTemp = pHead;
		pHead = pHead->next;
		delete nTemp;
		count--;
	}
}
template <class T> void LinkedList<T>::SortListByScore()	// BubleSort, ascending
{
	for (int i = 0; i < count; i++)
	{
		int onlyneedxTime = count - i;
		T* pTemp = pHead->next;
		if (pTemp != NULL && pTemp->Score < pHead->Score)
		{
			T* pTemp2 = pHead;
			pHead = pTemp;
			pTemp = pTemp2;
			pTemp->next = pHead->next;
			pHead->next = pTemp;
		}
		T* pBefore = pHead;
		//-----------------------------
		// pTemp now is in second position
		// pBefore now is in first position
		//-----------------------------
		while (pTemp->next != NULL && onlyneedxTime > 0)
		{
			T* pTemp2 = pTemp->next;
			if (pTemp2->Score < pTemp->Score)
			{
				pBefore->next = pTemp2;
				pTemp->next = pTemp2->next;
				pTemp2->next = pTemp;
				pBefore = pTemp2;
			}
			else
			{
				pBefore = pTemp;
				pTemp = pTemp->next;
			}
			onlyneedxTime--;
		}
	}
}
//--------------------------------

int main()
{
	
}