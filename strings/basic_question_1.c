#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printString(char str[]);
void concatenateStrings(char str1[], char str2[]);
int compareStrings(char str1[], char str2[]);
char *trim(const char *str);
char *replace(const char *str, char oldChar, char newChar);

int main()
{
	return 0;
}

void printString(char str[])
{
	printf("Input string: %s.\n", str);
}

void concatenateStrings(char str1[], char str2[])
{
	int i = 0, j = 0, length = strlen(str1) + strlen(str2);
	char str[length + 1];
	while (str1[i] != '\0')
	{
		str[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
	{
		str[i] = str2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	printf("Final string: %s\n", str);
}

int compareStrings(char str1[], char str2[])
{
	int length1 = strlen(str1), length2 = strlen(str2), i = 0;
	if (length1 != length2)
	{
		fprintf(stderr, "Provided strings are of different length.\n");
		exit(0);
	}
	while (str1[i] != '\0')
	{
		if (str1[i] == str2[i])
			i++;
		else
			return 0;
	}
	return 1;
}

char *trim(const char *str)
{
	int length = strlen(str);
	char *newStr = (char *)malloc((length + 1) * sizeof(char));
	int startIndex = 0, endIndex = 0, i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && startIndex == 0)
		{
			i++;
			continue;
		}
		else if (startIndex == 0)
		{
			startIndex = i;
		}
		if (str[i + 1] != '\0' && (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\n') && endIndex == 0)
			endIndex = i;
		i++;
	}
	i = 0;
	while (startIndex <= endIndex)
	{
		newStr[i] = str[startIndex];
		startIndex++;
		i++;
	}
	return newStr;
}

char *replace(const char *str, char oldChar, char newChar)
{
	int length = strlen(str);
	char *newStr = (char *)malloc((length + 1) * sizeof(char));
	int i = 0, found = 0;
	while (str[i] != '\0')
	{
		if (str[i] == oldChar && found == 0)
		{
			newStr[i] = newChar;
			found = 1;
		}
		else
		{
			newStr[i] = str[i];
		}
		i++;
	}
	newStr[i] = '\0';
	return newStr;
}
