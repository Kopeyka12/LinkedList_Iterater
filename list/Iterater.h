//@avtor Мирошин В. И.
//Абстрактный класс итератора
template <class T>
class Iterator
{
protected:
	//флажок, проказывающий, достиг ли итератор конца списка
	//должен поддерживаться производными классами
	int iterComplete;
public:
	//конструктор
	Iterator();

	//обязательные методы итератора
	virtual void Next() = 0;
	virtual void Reset() = 0;

	//методы для выборки/модификации данных
	virtual T& Data() = 0;
};
//конструтор который не имеет реализации (абстрактный метод)
template <class T>
Iterator<T>::Iterator() : iterComplete(0) {};