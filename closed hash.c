#include<stdio.h>
#define hsize 100
int HashTable[hsize];
void insert(int data);
int hash(int key);
void delete(int data);
int search(int data);
void main()
{
	for(int i = 0; i< hsize;++i)
		HashTable[i]= 0;
	insert(12);
	insert(11);
	insert(56);
	delete(1);
	delete(2);
	delete(56);
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

	HashTable[hash(data)] = data;
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
