/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 02_improved_open_close_principle.cpp
 * Created on    : Thursday 19 March 2020 08:23:39 PM IST
 * Last modified : Saturday 21 March 2020 01:40:52 PM IST
 * Description   : open for extension and closed for modification
 * ***********************************************************************/

#include <iostream>
#include <vector>

using namespace std;

enum class Color{ red, green, blue };
enum class Size{ small, medium, large };

struct Product
{
	string name;
	Color color;
	Size size;
};

// check item satisfied particular specification
template <typename T> struct Specification
{
	virtual bool is_satisfied(T* item) = 0;
};

// filter of item or product
template <typename T> struct Filter
{
	virtual vector<T*> filter(vector<T*> items, Specification<T>& spec) = 0;
};

struct BetterFilter : Filter<Product>
{
	vector<Product*> filter(vector<Product*> items, Specification<Product>& spec) override
	{
		vector<Product*> result;
		for(auto& item : items)
			if(spec.is_satisfied(item))
				result.push_back(item);
		return result;
	}
};

struct ColorSpec : Specification<Product>
{
	Color color;
	ColorSpec(Color color) : color(color) {}
	bool is_satisfied(Product* item) override
	{
		return item->color == color;
	}
};

int main()
{
	Product apple{"Apple", Color::green, Size::small};
	Product car{"Car", Color::blue, Size::medium};
	Product mobile{"Mobile", Color::red, Size::small};

	vector<Product*> items{&apple, &car, &mobile};
	vector<Product*> result;

//	ProductFilter pf;
//	result = pf.by_color(items, Color::red);

//	for(auto item : result)
//		cout << item->name << endl;

	BetterFilter bf;
	ColorSpec cspec(Color::red);
	result = bf.filter(items, cspec);
	for(auto item : result)
		cout << item->name << endl;


	return 0;
}
