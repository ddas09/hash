#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//size of hash table, will be provided as command line argument 
int size;

int hash(char *str)
{
    unsigned int hash = 0;
    int c;

    while (c = *str++)
    {
    	hash = c + (hash << 6) + (hash << 16) - hash;
    }	
    return hash % size;
}

int main(int argc, char const *argv[])
{
	//invalid no of arguments
	if (argc != 2)
	{
		printf("Usage: ./sdbm size_of_table\n");
		exit(-1);
	}	

	//extract size of table
	size = strtol(argv[1], NULL, 10);

	//initialising hash table
	int *table = calloc(size, sizeof(int));

	int collision = 0, word_count = 0, max_bucket_size = 0;
	FILE *fp = fopen("./large.txt", "r");
	if (fp == NULL)
	{
		printf("Couldn't open file\n");
		exit(-1);
	}

	char word[46] = {'\0'};
	int idx = 0;
	while (fscanf(fp, "%s", word) != EOF)
	{
		idx = hash(word);
		word_count++;
		if (table[idx] > 0)
		{
			if (table[idx] > max_bucket_size)
			{
				max_bucket_size = table[idx];
			}
			collision++; 
		}	
		table[idx]++;
	}

	//calculate avg bucket size	
	int avg_bucket = 0;	
	for (int i = 0; i < size; ++i)
	{
		avg_bucket += table[i];
	}

	//deallocate memory for hash table
	free(table);

	//print data
	printf("hash table size = %d\n", size);
	printf("total collision = %d\n", collision);
	printf("dict_word_count = %d\n", word_count);
	printf("max_bucket_size = %d\n", max_bucket_size);
	printf("avg_bucket_size = %d\n", avg_bucket / size);
	fclose(fp);
	return 0;
}

