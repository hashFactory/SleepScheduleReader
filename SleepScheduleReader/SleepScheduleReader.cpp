// SleepScheduleReader.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;
namespace fs = experimental::filesystem;

fs::path filename = "C:/Users/tristan/Downloads/sleep_schedule.csv";

fstream sleep_schedule;

char * read(char * buffer, uint32_t num_of_chars)
{
	char c;
	for (int i = 0; i < num_of_chars; i++)
	{
		sleep_schedule.get(c);
		buffer[i] = c;
	}
	return buffer;
}

string * split(string input, string delimiter)
{
	size_t n = count(input.begin(), input.end(), '\n');
	string * split_string = new string[n];
	size_t position = 0;
	string token;
	for (int i = 0; i < n; i++)
	{
		position = input.find(delimiter);
		split_string[i] = input.substr(0, position);
		input.erase(0, position + delimiter.length());
	}

	return split_string;
}

int init_file()
{
	if (fs::exists(filename))
		sleep_schedule.open(filename, ios::binary | ios::in);
	else
		return 12;
	return 0;
}

int main()
{
	init_file();

	uintmax_t filesize = fs::file_size(filename);
	char* _file_contents = new char[filesize];
	read(_file_contents, filesize);
	string file_contents(_file_contents);

	string * _split_file = split(file_contents, "\n");

	vector<vector<string> > split_file;

	for (int i = 0; i < _split_file->length; i++)
	{
		size_t n = count(_split_file[i].begin(), _split_file[i].end(), ',');
		for (int j = 0; j < n; j++)
		{
			size_t position = 0;
			string token;
			for (int i = 0; i < n; i++)
			{
				position = _split_file[i].find(',');
				split_file.push_back(input.substr(0, position));
				input.erase(0, position + delimiter.length());
			}
		}
	}
	// Line 1: Dates
	// Line 2: Sleep time
	// Line 3: 

	for (uint32_t i = 0; i < 7; i++)
		cout << split_file[i] << "\n";

	system("pause");

    return 0;
}

