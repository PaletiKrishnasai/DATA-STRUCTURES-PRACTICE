#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	struct node *lcptr;
	char word[100];
	char map[200];
	int height;
	struct node *rcptr;
};
//create empty  AVL tree 
struct node *rptr = NULL;
struct node *insert(char x[],char m[],struct node * ptr);
void inorder(struct node *ptr);
int Height(struct node *ptr);
struct node *RotateRight(struct node *ptr);
struct node *RotateLeft(struct node *ptr);
struct node *RotateRightLeft(struct node *ptr);
struct node *RotateLeftRight(struct node *ptr);
void search(char w[],struct node * ptr)
{
	if(ptr)
	{
		search(w,ptr->lcptr);
		if(strcmp(w,ptr->word)==0)
		{
		puts(ptr->map);
		return;
		}
		search(w,ptr->rcptr);
	}
}
void main()
{
	int n;
	printf("How many words :");
	scanf("%d",&n);
	getchar();
	while(n--){
		char word[100];
		char map[200];
		printf("Enter the word :");
		fgets(word,sizeof(word),stdin);
		printf("Enter the meaning :");
		fgets(map,sizeof(map),stdin);
		rptr = insert(word,map,rptr);
	}
	char find[100];	
	printf("Enter the word to be searched :");
	fgets(find,sizeof(find),stdin);
	search(find,rptr);
}
void inorder(struct node *ptr)
{
	if(ptr)
	{
		inorder(ptr->lcptr);
		puts(ptr->word);
		puts(ptr->map);
		printf("\n");
		inorder(ptr->rcptr);
	}
}
int Height(struct node *ptr)
{
	int lh,rh;
	if(ptr == NULL)
		return -1;
	else 
	{
		if(ptr->lcptr == NULL)
			lh = -1;
		else
			lh = ptr->lcptr->height;
//		
		if(ptr->rcptr == NULL)
			rh = -1;
		else
			rh = ptr->rcptr->height;
	}

	if(lh < rh)
		return rh + 1;
	else
		return lh + 1;
}
struct node *insert(char x[],char m[],struct node * ptr)
{
	if(ptr == NULL)
	{
		ptr = (struct node*)malloc(sizeof(struct node));
		strcpy(ptr->word, x);
		strcpy(ptr->map, m);
		ptr->height = 0;
		ptr->lcptr = ptr->rcptr = NULL;
	}
	else
	{
		if(strcmp(x , ptr->word) < 0)
		{
			ptr->lcptr = insert(x,m,ptr->lcptr);
			
		}
		else
		{
			ptr->rcptr = insert(x,m,ptr->rcptr);
		}
		ptr->height = Height(ptr);
		if((Height(ptr->lcptr) - Height(ptr->rcptr) == -2) || (Height(ptr->lcptr) - Height(ptr->rcptr) == 2))
		{
			if(strcmp(x , ptr->word) < 0)
			{
				if(strcmp(x , ptr->lcptr->word) < 0)  //case 1
					ptr = RotateRight(ptr);
            else  //case 2
               ptr=RotateLeftRight(ptr); 
			}
			else
			{
            if(strcmp(x , ptr->rcptr->word) < 0) //case 3
					ptr = RotateRightLeft(ptr);
            else  //case 4
               ptr=RotateLeft(ptr);
				
			}
		}
	}
	return ptr;
}
struct node *RotateRight(struct node *ptr)// case 1
{
	struct node *xptr = ptr;
	struct node *yptr = ptr->lcptr;
	xptr->lcptr = yptr->rcptr;
	yptr->rcptr = xptr;
   
  //update height
    xptr->height=Height(xptr);
    yptr->height=Height(yptr);
   
	return yptr;
}
struct node *RotateLeft(struct node *ptr)// case 4 
{
	struct node *xptr = ptr;
	struct node *yptr = ptr->rcptr;
	xptr->rcptr = yptr->lcptr;
	yptr->lcptr = xptr;

   //update height
    xptr->height=Height(xptr);
    yptr->height=Height(yptr);

	return yptr;
}
struct node *RotateRightLeft(struct node *ptr)//case 3
{
	ptr->rcptr = RotateRight(ptr->rcptr);
	return RotateLeft(ptr);
}
struct node *RotateLeftRight(struct node *ptr)//case 2
{
	ptr->lcptr = RotateLeft(ptr->lcptr);
	return RotateRight(ptr);
}
