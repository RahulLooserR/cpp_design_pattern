/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 01_single_responsiility.cpp
 * Created on    : Wednesday 18 March 2020 09:49:31 PM IST
 * Last modified : Thursday 19 March 2020 07:55:23 PM IST
 * Description   : A class should have single responsibility
 * 				   for example: a programmer has responsibility 
 * 				   of programming stuff.
 * ***********************************************************************/

#include <iostream>
#include "boost/lexical_cast.hpp"
#include <vector>
#include <fstream>

using namespace std;
using namespace boost;

// class jurnal having title and entries
struct Journal
{
	string title;
	vector<string> entries;

	// constructor 
	Journal(const string &title) : title(title){}

	//method to add entries
	void add_entry(const string &entry)
	{
		static int count = 1;
		// typecasting count to string using lexical cast
		// boost::lexical_cast, since we are using namespace
		entries.push_back(lexical_cast<string>(count++) + ": " + entry);
	}

	// if we want to save the entries in file
	// then we can have below function
	// but the problem is,for every journal/other object
	// we need to have persistent manager for each different 
	// type of object
	/*
	 void save(const string &filename)
	 {
		ofstream ofs(filename);   // std::ofstream
		for(auto &e : entries)
			ofs << e << endl;
	 }
	 */
};

// a class to save the journal, single purpose
struct PersistenceManager
{
	static void save(const Journal& j, const string& filename)
	{
		ofstream ofs{filename};
		for (auto& e : j.entries)
			ofs << e << endl;
	}
};

int main()
{
	Journal j{"New Diary"};
	j.add_entry("This is new diary");
	j.add_entry("This diary is created by me");

	// j.save("newDiary.txt");
	PersistenceManager pm;
	pm.save(j, "newDiary.txt");

	return 0;
}
