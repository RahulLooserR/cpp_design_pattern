/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 02_open_close_principle.cpp
 * Created on    : Thursday 19 March 2020 08:23:39 PM IST
 * Last modified : Thursday 19 March 2020 09:26:37 PM IST
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

struct ProductFilter
{
	// filtering product by color
	vector<Product*> by_color(vector<Product*> items, Color color)
	{
		vector<Product*> result;
		for(auto& item : items)
			if(item->color == color)
				result.push_back(item);
		return result;
	}

	// further filtering product by size
	vector<Product*> by_size(vector<Product*> items, Size size)
	{
		vector<Product*> result;
		for(auto& item : items)
			if(item->size == size)
				result.push_back(item);
		return result;
	}

	// further filtering by size and color
	vector<Product*> by_color_size(vector<Product*> items, Color color, Size size)
	{
		vector<Product*> result;
		for(auto& item : items)
			if(item->color == color && item->size == size)
				result.push_back(item);
		return result;
	}	
};

int main()
{
	Product apple{"Apple", Color::green, Size::small};
	Product car{"Car", Color::blue, Size::medium};
	Product mobile{"Mobile", Color::red, Size::small};

	vector<Product*> items{&apple, &car, &mobile};
	vector<Product*> result;

	ProductFilter pf;
	result = pf.by_color(items, Color::red);

	for(auto item : result)
		cout << item->name << endl;

	return 0;
}
