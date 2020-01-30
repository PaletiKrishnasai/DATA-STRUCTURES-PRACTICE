#include<stdio.h>
#define hsize 10
int HashTable[hsize];
void insert(int data);
int hash(int key);
void delete(int data);
int search(int data);
void main()
{
	for(int i = 0; i< hsize;++i)
		HashTable[i]= 0;
	insert(2);
	insert(1);
	insert(56);
	insert(5);
	insert(63);
	insert(6);
	insert(9);
	insert(9);
	insert(6);
	insert(9);
	insert(9);
	insert(79);
	insert(119);	
	printf("%d\n",search(12));
	printf("%d\n",search(11));
	printf("%d\n",search(56));
	
	for(int i = 0; i< hsize;++i)
		printf("%d ",HashTable[i]);
}
int hash(int key)
{
	return key % hsize;
}
void insert(int data)
{
	int i = 0;
	while((HashTable[(hash(data) + i) % hsize] != 0) && (i < hsize))
	{
		++i;
		if(i == hsize)
			break;
	}	
	if(HashTable[(hash(data) + i) % hsize] == 0)
		HashTable[(hash(data) + i) % hsize] = data;
}
void delete(int data)
{
	HashTable[hash(data)] = 0;
}
int search(int data)
{
	if(HashTable[hash(data)] != 0)
		return 1;
	else 
		return 0;
}
