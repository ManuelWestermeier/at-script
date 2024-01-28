#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <thread>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void writeFile(string fileName, string data)
{
	ofstream MyFile(fileName);
	MyFile << data;
	MyFile.close();
}

string readFile(string fileName)
{
	ifstream file;
	string data;
	file.open(fileName.c_str());
	while (!file.eof())
	{
		string chunk;
		file >> chunk;
		data += chunk;
	}
	file.close();
	return data;
}

string print(string out)
{
	cout << out;
	return out;
}

string readLine(string header)
{
	cout << "\n"
		 << header;
	string line;
	getline(cin, line);
	return line;
}

string replace(string original, char find, string replacer)
{

	string new_str;

	for (int i = 0; i < original.length(); i++)
	{
		if (original.at(i) == find)
			new_str += replacer;
		else
			new_str += original[i];
	}

	return new_str;
}

string join(vector<string> &_array, string split)
{
	string out;

	for (string &_item : _array)
	{
		out += _item + split;
	}

	for (int i = 0; i < split.length(); i++)
		out.pop_back();

	return out;
}

vector<string> split(string s, string delimiter)
{
	vector<string> out;
	size_t pos = 0;
	string token;
	while ((pos = s.find(delimiter)) != string::npos)
	{
		token = s.substr(0, pos);
		out.push_back(token);
		s.erase(0, pos + delimiter.length());
	}
	return out;
}

int str2int(const string &str)
{
	stringstream ss(str);
	int num;
	if ((ss >> num).fail())
	{
		return 0;
	}
	return num;
}
int main()
{
	string path = "Hallo TXTX";
	writeFile(path, "Hallo Welt\nHallo");
	print(readFile(path));
	vector<string> Tarray;
	for (int index = 0; index < 10; index++)
	{
		Tarray.push_back("Hallo Welt\n");
	}
	for (auto &item : Tarray)
	{
		item.append("GA");
	}
	for (auto &_item : Tarray)
	{
		print(_item);
	}

	system("pause");
	vector<string> items = split("1 2 3 4", " ");
	for (auto &item : items)
	{
		print(item + "\n");
	}
	print("\n");
	print(join(items, " "));
	system("pause");
	return 0;
}

string nx(int x, string y)
{
	
}