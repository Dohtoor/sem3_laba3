// sem3_laba3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include "string.h"

#pragma warning(disable:4996)

void changeLine(char* Buffer);

int main()
{
	FILE *inFile;
	inFile = fopen("file_in.txt", "r");
	FILE *outFile;
	outFile = fopen("file_out.txt", "w");

	char buffer[256];

	while (fgets(buffer, 256, inFile) != NULL)
	{
		changeLine(buffer);
		fputs(buffer, outFile);
	}

	fclose(inFile);
	fclose(outFile);
    return 0;
}

void changeLine (char* Buffer)
{
	int i, b = 0;
	char Buffer_out[256];

	for (i = 0; i < 256; i++)
	{
		if (*(Buffer + i) == '\0')
		{
			*(Buffer_out + b) = '\0';
			break;
		}

		if ((*(Buffer + i) < 48) || (*(Buffer + i) > 57))
		{
			if ((*(Buffer + i) < 65) || (*(Buffer + i) > 122))
			{
				if (*(Buffer + i) == 46)
				{
					*(Buffer_out + b) = *(Buffer + i);
					*(Buffer_out + b + 1) = ' ';
					b = b + 2;

					if (*(Buffer + i + 1) != '\0')
					{
						if ((*(Buffer + i + 1) > 96) && (*(Buffer + i + 1) < 123))
						{
							*(Buffer_out + b) = *(Buffer + i + 1) - 32;
							b++;
							i++;
						}
					}

					continue;
				} else 
				{
					*(Buffer_out + b) = *(Buffer + i);
					*(Buffer_out + b + 1) = ' ';
					b = b + 2;
					continue;
				}
			} else
				*(Buffer_out + b) = *(Buffer + i);
				b++;
				continue;
		}			
		*(Buffer_out + b) = *(Buffer + i);
		b++;
	}

	for (i = 0; i < 256; i++)
		*(Buffer + i) = *(Buffer_out + i);

	return;
}
