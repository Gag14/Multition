#include <iostream>
class Multiton 
{
	public:
		static Multiton* Instance();
		static int i;
		~Multiton();
	protected:
		Multiton();
	private:
		static Multiton* _instance;

		static Multiton* _instance2;
};
int Multiton::i = 0;
Multiton::Multiton() 
{
	std::cout << "Object created" << std::endl;
}
Multiton::~Multiton() 
{
	delete _instance;
	delete _instance2;
	_instance = nullptr;
	_instance2 = nullptr;
}
Multiton* Multiton::_instance = 0;
Multiton* Multiton::_instance2 = 0;
Multiton* Multiton::Instance () 
{
	if (i == 0) 
	{
		_instance = new Multiton;
		std::cout << "Instance 1" << std::endl;
	}
	
	if (i == 1) 
	{
		_instance2 = new Multiton;
		std::cout << "Instance 2" << std::endl; 
	}
	++i;
	if (i % 2 == 0) {return _instance2;}
	return _instance;
}
int main () 
{
	Multiton* ptr = Multiton::Instance();
	Multiton* str = Multiton::Instance();
	bool a = (ptr == str);
	std::cout << a << std::endl;
	
	Multiton* ptr1 = Multiton::Instance();
	Multiton* str2 = Multiton::Instance();
	bool b = ptr1 == str2;
	std::cout << b << std::endl;
return 0;
}
