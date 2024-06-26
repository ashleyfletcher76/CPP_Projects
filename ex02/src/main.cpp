#include "Array.hpp"
#include "Array.tpp"

void	stringArray()
{
	std::cout << "STRING ARRAY TEST" << std::endl;
	Array<std::string> stringArray(4);
	stringArray[0] = "Hello!";
	stringArray[1] = "Potato's are so flexible. ";
	stringArray[2] = "They can be both. ";
	stringArray[3] = "Fries and chips!";
	Array<std::string> stringArrayCopy = stringArray;
	try
	{
		for (size_t i = 0; i < stringArray.size() + 1; i++)
			std::cout << stringArray[i] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "TEST COPY CONSTRUCTOR" << std::endl;
	try
	{
		for (size_t i = 0; i < stringArrayCopy.size() + 1; i++)
			std::cout << stringArrayCopy[i] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "TEST COPY ASIGNMENT" << std::endl;
	std::cout << "Try to run" << std::endl;
	Array<std::string> stringArrayAsignment;
	try
	{
		for (size_t i = 0; i < stringArrayAsignment.size(); i++)
			std::cout << stringArrayAsignment[i] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "COPY ASIGN" << std::endl;
	stringArrayAsignment = stringArray;
	try
	{
		for (size_t i = 0; i < stringArrayAsignment.size(); i++)
			std::cout << stringArrayAsignment[i] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	charArray()
{
	std::cout << "CHAR ARRAY TEST" << std::endl;
	Array<char> charArray(4);
	for (size_t i = 0; i < charArray.size(); i++)
		charArray[i] = 97 + i;
	try
	{
		for (size_t i = 0; i < charArray.size() + 1; i++)
			std::cout << charArray[i] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	intArray()
{
	std::cout << "INT ARRAY TEST" << std::endl;
	Array<int> intArray(5);
	for (size_t i = 0; i < intArray.size(); i++)
		intArray[i] = (i + 1) * 10;
	for (size_t i = 0; i < intArray.size(); i++)
		std::cout << intArray[i] << std::endl;
}

int	main()
{
	std::cout << "--------" << std::endl;
	intArray();
	std::cout << "--------" << std::endl;
	charArray();
	std::cout << "--------" << std::endl;
	stringArray();
	std::cout << "--------" << std::endl;
}

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }
