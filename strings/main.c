#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct count
{
	int numOfDigits;
	int numOfUpperCaseChars;
	int numOfLowerCaseChars;
	int numOfSpecialChars;
} Count;

Count countNumOfDigitsAndChars(const char *str);
int countOccurrence(const char *str, char ch);
int countOccurrenceOfSubString(const char *str, const char *subString);
int lastIndexOfSubString(const char *str, const char *subString);
void *reverseArrayOfStrings(char *strArr[], int length);
char *appendItselfInReverse(const char *str);
int *paragraphIndexes(const char *str);
char *insert(const char *str, const char *subString, int pos);
char *deleteSemiColonsAndReplacePeriod(const char *str);
void showLineNumber(const char *str);

int main()
{

	return 0;
}

Count countNumOfDigitsAndChars(const char *str)
{
	Count count = {.numOfDigits = 0, .numOfUpperCaseChars = 0, .numOfLowerCaseChars = 0, .numOfSpecialChars = 0};
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
			count.numOfDigits++;
		if (str[i] >= 65 && str[i] <= 90)
			count.numOfUpperCaseChars++;
		if (str[i] >= 97 && str[i] <= 122)
			count.numOfLowerCaseChars++;
		if ((str[i] >= 33 && str[i] <= 47) || (str[i] >= 58 && str[i] <= 64))
			count.numOfSpecialChars++;
		if ((str[i] >= 91 && str[i] <= 96) || (str[i] >= 123 && str[i] <= 126))
			count.numOfSpecialChars++;
		i++;
	}
	return count;
}

int countOccurrence(const char *str, char ch)
{
	int i = 0, count = 0;
	while (str[i] != '\0')
	{

		if (str[i] == ch)
		{
			count++;
		}
		i++;
	}
	return count;
}

int countOccurrenceOfSubString(const char *str, const char *subString)
{
	int lengthString = strlen(str);
	int lengthSubString = strlen(subString);
	int i = 0, j = 0, k = 0, count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == subString[0])
		{
			j = 0;
			k = i;
			while (j <= lengthSubString)
			{
				if (str[k] == subString[j])
				{
					j++;
					k++;
				}
				else
					break;
				if (j == lengthSubString)
				{
					count++;
					break;
				}
			}
		}
		i++;
	}
	return count;
}

int lastIndexOfSubString(const char *str, const char *subString)
{
	int lengthString = strlen(str);
	int lengthSubString = strlen(subString);
	int i = 0, j = 0, k = 0, lastIndex = 0, count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == subString[0])
		{
			j = 0;
			k = i;
			while (j <= lengthSubString)
			{
				if (str[k] == subString[j])
				{
					j++;
					k++;
				}
				else
					break;
				if (j == lengthSubString)
				{
					lastIndex = i;
					count++;
					break;
				}
			}
		}
		i++;
	}
	return lastIndex;
}

void *reverseArrayOfStrings(char *strArr[], int length)
{
	int i = length;
	while (i >= 0)
	{
		printf("%s ", strArr[i]);
		i--;
	}
	printf("\n");
}

char *appendItselfInReverse(const char *str)
{
	int length = strlen(str), i = 0, j = 0;
	char *newStr = (char *)malloc(((length * 2) + 2) * sizeof(char));
	while (str[i] != '\0')
	{
		newStr[i] = str[i];
		if (str[i] == ' ')
			j = i;
		i++;
	}
	newStr[i] = ' ';
	i++;
	j++;
	while (str[j] != '\0')
	{
		newStr[i] = str[j];
		i++;
		j++;
	}
	newStr[i] = ' ';
	i++;
	j = 0;
	while (str[j] != ' ')
	{
		newStr[i] = str[j];
		i++;
		j++;
	}
	newStr[i] = '\0';
	return newStr;
}

int *paragraphIndexes(const char *str)
{
	int length = strlen(str), i = 0, paragraphs = 0;
	int *par = (int *)malloc(6 * sizeof(int));
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && i < length && str[i + 1] == '\n')
		{
			par[paragraphs] = i;
			paragraphs++;
		}
		i++;
	}
	return par;
}

char *insert(const char *str, const char *subString, int pos)
{
	int lengthString = strlen(str), lengthSubString = strlen(subString);
	int length = (lengthString + lengthSubString) + 2, i = 0, j = 0, k = 0;
	char *newStr = (char *)malloc((length * sizeof(char)));
	while (i != (length - 1))
	{
		if (i == pos)
		{
			k = i;
			while (j != lengthSubString)
			{
				newStr[k] = subString[j];
				k++;
				j++;
			}
		}
		else if (k == 0)
			newStr[i] = str[i];
		else
		{
			newStr[k] = str[i];
			k++;
		}
		i++;
	}
	newStr[i] = '\0';
	return newStr;
}

char *deleteSemiColonsAndReplacePeriod(const char *str)
{
	int length = strlen(str), i = 0, j = 0;
	char *newStr = (char *)malloc((length * sizeof(char)) + 1);

	while (str[i] != '\0')
	{
		if (str[i] == ';')
		{
			i++;
			continue;
		}
		if (str[i] == '.')
		{
			newStr[j] = ',';
		}
		else
		{
			newStr[j] = str[i];
		}
		i++;
		j++;
	}
	newStr[j] = '\0';
	return newStr;
}

void showLineNumber(const char *str)
{
	int i = 0, line = 1;
	while (str[i] != '\0')
	{
		if (i == 0)
		{
			printf("%d.", line);
		}
		if (str[i] == '\n')
		{
			line++;
			printf("\n%d.", line);
			i++;
			continue;
		}
		printf("%c", str[i]);
		i++;
	}
	printf("\n");
}
