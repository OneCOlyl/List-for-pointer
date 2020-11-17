#include <iostream>

using namespace std;

//��������� ��������� �� ���� ������������ ����� � ���� ���������� �� ��������� ������� ���� ���������
struct listOfPointer
{
	double listItem;
	listOfPointer* pointTheNextListItem;
};

int main()
{
	listOfPointer* intermediateElement, * firstElement, * lastElement;
	double sumAverage = 0, numberEnter;
	int isFiveElements = 1; //�������


	//�������� ������ ��� �������� ���� struct 
	firstElement = new listOfPointer;
	//����� ����� ������� �������� ������
	cin >> firstElement->listItem;
	sumAverage += firstElement->listItem;//����������� � ����� ������ �������
	lastElement = firstElement;//������������ ���������
	//���� ����� �����
	while (cin >> numberEnter)
	{
		//������� ������ 
		intermediateElement = new listOfPointer;
		//��������� ������� ��������� �������� ������
		intermediateElement->listItem = numberEnter;
		//������ �����
		sumAverage += numberEnter;
		//���������� ��������� �� ��������� �������
		lastElement->pointTheNextListItem = intermediateElement;
		//��������� ���������
		lastElement = intermediateElement;
		//������ ���-�� �����
		isFiveElements++;

		//���� ���-�� ����� ����� ����
		//�� ����������� �� ������� ����.��������
		//� ��������� ���������� ��������� ����� ������ ������� ���������
		if (isFiveElements == 5)
		{
			sumAverage /= isFiveElements;
			intermediateElement = new listOfPointer;
			intermediateElement->listItem = sumAverage;
			lastElement->pointTheNextListItem = intermediateElement;
			lastElement = intermediateElement;

			//�������� ��������
			sumAverage = 0;
			isFiveElements = 0;
		}
	}

	//���� �� ������������ ������ ������
	//�� ��������� ������� ���� ���� �����
	if (sumAverage != 0)
	{
		sumAverage /= isFiveElements;
		intermediateElement = new listOfPointer;
		intermediateElement->listItem = sumAverage;
		lastElement->pointTheNextListItem = intermediateElement;
		lastElement = intermediateElement;
	}

	//���������� ���������� �������� ������� ���������
	//� ����������� ��������� �� ������
	lastElement->pointTheNextListItem = nullptr;
	intermediateElement = firstElement;

	//���� �� ������� ���������
	//������ ��������
	while (intermediateElement)
	{
		cout << intermediateElement->listItem << ' ';
		intermediateElement = intermediateElement->pointTheNextListItem;
	}
}