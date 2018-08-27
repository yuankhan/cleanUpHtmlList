#include <iostream>
#include <fstream>
#include <string>

#define NUMBER_OF_TEACHERS 4407

using namespace std;
int main()
{
	ifstream input;
	input.open("teacherList.txt", ios::in);
	if (!input.is_open())
	{
		cout << "Could not open input file.\n";
		return -1;
	}
	int iii = 0;
	string buffer;
	string teacherArray[NUMBER_OF_TEACHERS][2];
	while (getline(input, buffer))
	{
		buffer.erase(0, 4);
		buffer.erase(buffer.length() - 5, 5);
		
		string delimiter = "</td> <td>";
		size_t pos = 0;
		string token;
		while ((pos = buffer.find(delimiter)) != string::npos)
		{
			token = buffer.substr(0, pos);
			if (teacherArray[iii][0].empty())
			teacherArray[iii][0] = token;
			buffer.erase(0, pos + delimiter.length());
		}
		teacherArray[iii][1] = buffer;
		++iii;
	}

	input.close();

	ofstream output;
	output.open("finalTeacherList.txt", ios::out);
	if (!output.is_open())
	{
		cout << "Could not open output file.\n";
		return -2;
	}

	for (int jjj = 0; jjj < NUMBER_OF_TEACHERS; ++jjj)
	{
		output << teacherArray[jjj][0] << "\t\t" << teacherArray[jjj][1] << endl;
	}

	output.close();

	return 0;
}
