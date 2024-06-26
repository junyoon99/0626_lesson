#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

class MyClass 
{
public:
	int mValue;

	MyClass(int val) : mValue{ val } {}

	friend std::ostream& operator << (std::ostream& os, const MyClass& param) 
	{
		os << param.mValue;
		return os;
	}
};
//bool MyCompare(const MyClass& a, const MyClass& b)
//{
//	return a.mValue < b.mValue;
//}

int main() 
{
	{
		std::array<int, 5> container{ 5,2,1,3,4 };

		std::array<int, 5>::iterator itr = container.begin();
		while (itr != container.end())
		{
			std::cout << *itr << std::endl;
			itr++;
		}

		int min{ container[0] };
		for (auto e : container)
		{
			if (min > e)
			{
				min = e;
			}
		}
		std::cout << min << std::endl;

		auto result = std::min_element(container.begin(), container.end());
		std::cout << *result << std::endl;

		int sum = std::accumulate(container.begin(), container.end(), 0);
		std::cout << sum / container.size() << std::endl;
	}
	std::array<MyClass, 4> container{ MyClass(4),MyClass(3) ,MyClass(2) ,MyClass(1) };

	for (const auto& e : container) 
	{
		std::cout << e << std::endl;
	}

	auto itr = std::min_element(container.begin(),container.end(), 
		[] (const MyClass& a, const MyClass& b) -> bool // 람다함수
		{
			return a.mValue < b.mValue;
		});

	std::cout << *itr << std::endl;

	std::for_each(container.begin(), container.end(),
		[] (const MyClass& a)// -> void 반환 타입이 없으면 안써도 댐
		{
			std::cout << a.mValue << std::endl;
		} );
}