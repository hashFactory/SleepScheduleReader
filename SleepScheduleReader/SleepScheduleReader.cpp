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

string * split(string & input, string & delimiter)
{

}

int main()
{
	if (fs::exists(filename))
		sleep_schedule.open(filename, ios::binary | ios::in);
	else
		return 12;

	uint32_t filesize = fs::file_size(filename);

	char* _file_contents = new char[filesize];

	read(_file_contents, filesize);

	string file_contents(_file_contents);

	for (int i = 0; i < filesize; i++)
		cout << file_contents[i];

	system("pause");

    return 0;
}

