#include<stdio.h>
#include<stdlib.h>

static int i = 0;

struct node{
	void* data;
	unsigned char type;	
	struct node* next;
};

struct node* head = NULL;

void init(){
	struct node* head = NULL;
//	head = (struct node*)malloc(sizeof(struct node));
}

void insertData(int *ptr){
	struct node* current = (struct node*)malloc(sizeof(struct node));
	current->type = 0;
	current->data = (int *)malloc(sizeof(int));
	current->data = ptr;
	current->next = NULL;
	
//	struct node* temp = NULL;
	if(head == NULL){
	head = current;	
	i++;	
	return;
	//current->data = 1;
	//current->next =NULL;
	}
	
	struct node* temp = NULL;
	temp = head;
	while(1){
		if(temp->next == NULL){
			temp->next = current;
			break;
		}
		temp = temp->next;
	
	
	}
i++;
}

void displayData(){
	if(head == NULL){
		printf("There are no nodes except the head pointer!!!!\n");
						
	}
	else{
		struct node* temp = head;
		while(head!=NULL){
			printf("Data = %d\n",*(int *)(head->data));
			head = head->next;
		}
		head = temp;
	}
}

int displayLen(){
	
	int count = 0;
	struct node* temp = NULL;
	temp = head;
	if(head == NULL){
		printf("There are no nodes except the head pointer!!!!\n");
		return count;
						
	}
	else{
		
		while(head!=NULL){
			count = count + 1;
			head = head->next;
		}
	printf("length of thw list is = %d\n",count);
	}
 	head = temp;
	
	
	
	return count;
}

void deleteNode(int num){
	struct node* temp = NULL;
	struct node* temp1 = NULL;
	temp = head;
	int count = 0;
	if(temp==NULL){
		printf("There are no nodes except the head node for deletion...!!!!!\n");
	}
	else{
		if(num == 1){
			if(temp->next == NULL)
			{
				free(temp);
				head = NULL;
				return;
				
			}
			head = temp->next;
			free(temp);
			return;
		}
		while(temp!=NULL){
			count = count + 1;
			if((count+1)==num){
				temp1 = temp;
				temp = temp->next;
				temp1->next = temp->next;
				free(temp);
			}
			temp = temp->next;	
		}
	}
return;
}

/*
void insertNodeafter(int num){
	int count = displayLen();
	printf("length of data = %d\n",count);
	if(count<num){
		printf("Sorry there are less elements in the list!!!!!\n");
		return;
	}	
	
	struct node* temp1 = head; //stores the address pointed to by the head pointer in it;
	struct node* temp2 = NULL;
	struct node* current = (struct node*)malloc(sizeof(struct node));
	current->data = 1000;
	current->next = NULL;
	int offset = 0;
	while(offset!=(num-1)){
		head = head->next;
		offset = offset + 1;
	}
	temp2 = head->next;
	head->next = current;
	current->next = temp2;
	head = temp1;
	
		
}
*/

void displayMiddleNode(){
	if((displayLen()%2)==0){
		printf("even number of nodes are present in the list.....!!!!!!!!!!!\n");
		return ;
	}
	else	
	{
		struct node* temp = head;
		temp = head;	
		printf("odd number of nodes are present in the list.....!!!!!!!!!\n");
			
		if(temp->next == NULL || temp == NULL){
			printf("Either no nodes or zero nodes are present in the list.....!!!!!!!!!!!!!!\n");
			return;

			
		}
		int count=0,index = (displayLen()/2);
		while(temp!=NULL){
			count = count+1;
			if(count == (index+1)){
				printf("data at this node is %d\n",*(int *)(temp->data));
				return;
			}
			temp = temp->next;
		}
		
		
	}
}

void insertNodeAt(int index){
	if((index-displayLen())>1){
		printf("Not possible to insert node at the %d in the list....!!!!!!!!!!!!!",index);	
		return;
		
	}
	struct node * current = (struct node*)malloc(sizeof(struct node));
//	current->(*data) = 53;
	current->next = NULL;
	if(index == 1){
		if(head == NULL){
			head = current;
		}
		else{
			struct node* temp;
			temp = NULL;
			temp = head;
			head = current;
			current->next = temp;
		}
	}
	else{
		struct node* temp = head;
		int count = 0;
		while(temp!=NULL){
			count = count + 1;
			if((count+1) == index){
				struct node* temp1 = temp->next;
				temp->next = current;
				current->next = temp1;
				return;
			}
			temp = temp->next;
		}
		return;
	}
}

//Only 1 node present in the list, delete node 1 and displayData
void test1(){
//	insertData();
	displayData();
	deleteNode(1);
	displayData();
	exit(0);
}

//More then 1 node is present in the list, delete node 1 and displayData
void test2(){
//	insertData();
//	insertData();
//	displayData();
	deleteNode(1);
	printf("-----------------------------\n");
	displayData();
	exit(0);
}


//3 nodes are present in the list,delete the 3 i.e the last node
void test3(){
//	insertData();
//	insertData();
//	insertData();
	displayData();
	deleteNode(3);
	displayData();
	exit(0);
}


//3 nodes are present in the list. To deermine the value of middle node
void test4(){
//	insertData();
//	insertData();
//	insertData();
//	insertData();
//	insertData();
//	insertData();
//	insertData();
	displayData();
	displayMiddleNode();
	exit(0);
}

void test5(){

//	insertData();
//	insertData();
//	insertData();
	insertNodeAt(2);
	displayData();
	exit(0);
}
void test6(){
//	insertData();
//	insertData();
//	insertData();
	displayData();
}







int main(){
	printf("Welcome !!!\n");
	int a=3,b=4,c=5;
	insertData(&a);
	insertData(&b);
	insertData(&c);
	displayData();
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();	
	test6();
	return ;
}
