//@avtor Мирошин В. И.
//Абстрактный класс итератора
template <class T>
class Iterator
{
protected:
	int iterComplete;
public:
	Iterator();
	virtual void Next() = 0;
	virtual void Reset() = 0;

	virtual T& Data() = 0;
};
template <class T>
Iterator<T>::Iterator() : iterComplete(0) {};