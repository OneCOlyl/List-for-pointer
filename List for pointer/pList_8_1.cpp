#include <iostream>

using namespace std;

//структура состо€ща€ из пол€ вещественных чисел и пол€ указателей на следующий элемент этой структуры
struct listOfPointer
{
	double listItem;
	listOfPointer* pointTheNextListItem;
};

int main()
{
	listOfPointer* intermediateElement, * firstElement, * lastElement;
	double sumAverage = 0, numberEnter;
	int isFiveElements = 1; //счЄтчик


	//выдел€ем пам€ть дл€ элемента типа struct 
	firstElement = new listOfPointer;
	//ввожу число помощью операции выбора
	cin >> firstElement->listItem;
	sumAverage += firstElement->listItem;//присваиваем к сумме первый элемент
	lastElement = firstElement;//перекидываем указатель
	//пока ввожу числа
	while (cin >> numberEnter)
	{
		//выдел€ю пам€ть 
		intermediateElement = new listOfPointer;
		//хапоминаю элемент использу€ операцию выбора
		intermediateElement->listItem = numberEnter;
		//считаю сумму
		sumAverage += numberEnter;
		//присваиваю указатель на следующий элемент
		lastElement->pointTheNextListItem = intermediateElement;
		//перекинул указатель
		lastElement = intermediateElement;
		//считаю кол-во чисел
		isFiveElements++;

		//если кол-во чисел равно п€ти
		//то высчитываем их среднее ариф.значение
		//и добавл€ем полученный результат после каждой п€терки элементов
		if (isFiveElements == 5)
		{
			sumAverage /= isFiveElements;
			intermediateElement = new listOfPointer;
			intermediateElement->listItem = sumAverage;
			lastElement->pointTheNextListItem = intermediateElement;
			lastElement = intermediateElement;

			//занул€ем счЄтчики
			sumAverage = 0;
			isFiveElements = 0;
		}
	}

	//если не образовалась полна€ п€тЄрка
	//то добавл€ем среднее ариф этих чисел
	if (sumAverage != 0)
	{
		sumAverage /= isFiveElements;
		intermediateElement = new listOfPointer;
		intermediateElement->listItem = sumAverage;
		lastElement->pointTheNextListItem = intermediateElement;
		lastElement = intermediateElement;
	}

	//присваиваю последнему элементу нулевой указатель
	//и перекидываю указатель на начало
	lastElement->pointTheNextListItem = nullptr;
	intermediateElement = firstElement;

	//пока не нулевой указатель
	//вывожу элементы
	while (intermediateElement)
	{
		cout << intermediateElement->listItem << ' ';
		intermediateElement = intermediateElement->pointTheNextListItem;
	}
}