#include "stdio.h"
#include "stdlib.h"

////////////////////////// TASK 1 //////////////////////////

int Task_1(char* str)
{
	int brackets = 0;

	int position = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '(')
		{
			if (brackets >= 0)
				brackets++;
		}
		if (str[i] == ')')
		{
			if(brackets >= 0)
				brackets--;
		}

		if (brackets < 0 && position == 0)
			position = i + 1;
	}

	if (brackets > 0)
		return -1;
	if (brackets == 0)
		return 0;
	if (brackets < 0)
	{
		printf("There is an extra closing bracket at this place (count from 1):\n");
		return position;
	}

}

////////////////////////// TASK 2 //////////////////////////

int numberCount(FILE* input)
{
	int counter = 0;

	while (1)
	{
		int value;

		if (fscanf_s(input, "%d", &value, 1) == 1)
			counter++;

		if (feof(input))
			break;
	}

	printf("%d\n", counter);

	return counter;
}

void print_array(char* numbers, int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%c", numbers[i]);
	}
	printf("\n");
}

void Task_2(char* FileName)
{
	FILE* Dates, Answer;

	fopen_s(&Dates, FileName, "r");

	fopen_s(&Answer, "Answer.txt", "w");

	int size = numberCount(Dates);

	char* numbers = (char*)malloc(sizeof(char) * size);

	for (int i = 0; i < size; ++i)
	{
		fscanf_s(Dates, "%c", &numbers[i], 1);
	}

	print_array(numbers, size);
}

////////////////////////// MAIN //////////////////////////

int main()
{
	char* word = "This is a test text, you can put brackets wherever you like.";

	printf("%d", Task_1(word));

//	char* FileName = "13.txt";

//	Task_2(FileName);

	return 0;
}