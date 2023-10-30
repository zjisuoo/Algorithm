#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdio.h>

using namespace std;

#define MAX 100

class node{
private:
	char data;
	node *left;
	node *right;
	node (char val){
		data = val;
		left=NULL;
		right=NULL;
	}
	friend class tree;
} ;

class tree{
public:
	node *head;
public:
	tree()
	{head=0;}
	~tree();
	void garbage(node*);
	void buildtree(char);
	void insert_node(node*, char);
	node* search_node(node*, char);
	void preorder_traverse(node*);
	void inorder_traverse(node*);
	void postorder_traverse(node*);
	void init_queue();
	node* put(node*);
	node* get();
	int is_queue_empty();
	void levelorder_traverse(node *);
	void print(node *);
};

node *queue[MAX];
int front, rear;

tree::~tree() {
	garbage(head);
}

void tree::garbage(node* p)
{
	if(p != NULL)
	{
		garbage(p->left);
		garbage(p->right);
		delete(p);
	}
}

void tree::buildtree(char i){
	node *temp = new node(i);
	head = temp;
}

void tree::insert_node(node* p, char i){
	int select;
	char child;
	

	p = search_node(p, i);

	if(p == NULL)
		cout << "The Node is not Found!!!" << endl;

	else if(p->left == NULL && p->right == NULL){
		cout << "1.Leftchild" << endl; 
		cout << "2.Rightchild" << endl;
		cout << "Choose menu: ";
		cin >> select;
		cout << "Input Character: ";
		cin >> child;

		if(select == 1){
			node *temp = new node(child);
			p->left = temp;
			temp->left = NULL;
			temp->right = NULL;
		}

		else if(select == 2){
			node *temp = new node(child);
			p->right = temp;
			temp->left = NULL;
			temp->right = NULL;
		}

		else
			cout << "Command Error!!!" << endl;
	}

	else if(p->left == NULL && p->right != NULL){
		cout << "Rightchild is ";
		cout << p->right->data << endl;
		cout << "Input Leftchild Character: ";
		cin >> child;
		node *temp = new node(child);
		p->left = temp;
		temp->left = NULL;
		temp->right = NULL;
	}

	else if(p->left != NULL && p->right == NULL){
		cout << "Leftchild is ";
		cout << p->left->data << endl;
		cout << "Input Rightchild Character: ";
		cin >> child;
		node *temp = new node(child);
		p->right = temp;
		temp->left = NULL;
		temp->right = NULL;
	}

	else if(p->left != NULL && p->right !=NULL)
		cout << "Left & Right child is being on this node" << endl;

	else
		cout << "The node is not Found!!!" << endl;		
}

node* tree::search_node(node* p, char i){
	node* temp;
	if(p != NULL) {
		if(p->data == i)
			return p;

		else {
			temp = search_node(p->left,i);
			if(temp != NULL)
				return temp;
			
			temp = search_node(p->right,i);
			if(temp != NULL)
				return temp;
		}
	}

	return NULL;
}

void tree::preorder_traverse(node* p)
{
	if(p != NULL)
	{
		cout << p->data << " ";
		preorder_traverse(p->left);
		preorder_traverse(p->right);
	}
}

void tree::inorder_traverse(node* p)
{
	if(p != NULL)
	{
		inorder_traverse(p->left);
		cout << p->data << " ";
		inorder_traverse(p->right);
	}
}

void tree::postorder_traverse(node* p)
{
	if(p != NULL)
	{
		postorder_traverse(p->left);
		postorder_traverse(p->right);
		cout << p->data << " ";
	}
}

void tree::init_queue()
{
	front = rear = 0;	
}

node* tree::put(node *p)
{
	if((rear + 1) % MAX == front){ // 큐가 꽉찼으면
		cout << "Queue overflow!!!" << endl;
		return NULL;
	}

	queue[rear] = p;
	rear = ++rear % MAX;
	return p;
}

node* tree::get()
{
	node *i;
	if(front == rear){ // 큐가 비었으면
		cout << "Queue underflow!!!" << endl;
		return NULL;
	}

	i = queue[front];
	front = ++front % MAX;

	return i;
}

int tree::is_queue_empty()
{
	return (front == rear);
}

void tree::levelorder_traverse(node *p)
{
	put(p);
	while(!is_queue_empty()){
		p = get();
		cout << p->data << " ";
		if(p->left != NULL)
			put(p->left);
		if(p->right != NULL)
			put(p->right);
	}
	cout << endl;
}

void tree::print(node *p)
{
	/*char array[MAX] = {0, };
	int ar_p = -1;
	int i;

	put(p);
	while(!is_queue_empty()){
		p = get();
		if(p->data != NULL)
			array[++ar_p] = p->data;
		else
			array[++ar_p] = 0;
		if(p->left != NULL)
			put(p->left);
		if(p->right != NULL)
			put(p->right);
	}
	
	for(i=0;i<=ar_p;i++){
		cout << array[i] << " ";
	}

	cout << endl;*/

  static int n = 0;
  static char buf[16];
  if (!p) return;
  n++; print(p->left); n--;

  sprintf(buf, "%%%dc%%s\n", n * 4);
  printf(buf, '|', p->data);

  n++; print(p->right); n--;

}

int main(){
	tree d1;
	char root, temp;
	int select=0;

	cout << "Input Root: ";
	cin >> root;

	d1.buildtree(root);

	do{
		cout << "1.Insert" << endl;
		cout << "2.Search" << endl;
		cout << "3.Preorder" << endl;
		cout << "4.Inorder" << endl;
		cout << "5.Postorder" << endl;
		cout << "6.Levelorder" << endl;
		cout << "7.Print Tree" << endl;
		cout << "Choose Menu(QUIT = -1): ";
		cin >> select;

		if(select == 1) {
			cout << "Input parent character: ";
			cin >> temp;
			d1.insert_node(d1.head, temp);
			cout << endl;
		}
			
		else if(select == 2) {
			cout << "Choose Search character: ";
			cin >> temp;
			if(d1.search_node(d1.head, temp) != NULL)
				cout << temp << " is in the Tree~!!!" << endl;
			else
				cout << temp << " is not in the Tree~!!!" << endl;
			
			cout << endl;
		}

		else if(select == 3) {
			cout << "PreOrder: ";
			d1.preorder_traverse(d1.head);
			cout << endl;
			cout << endl;
		}

		else if(select == 4) {
			cout << "InOrder: ";
			d1.inorder_traverse(d1.head);
			cout << endl;
			cout << endl;
		}
		
		else if(select == 5) {
			cout << "PostOrder: ";
			d1.postorder_traverse(d1.head);
			cout << endl;
			cout << endl;
		}

		else if(select == 6) {
			cout << "LevelOrder: ";
			d1.levelorder_traverse(d1.head);
			cout << endl;
			cout << endl;
		}
		
		else if(select == 7) {
			cout << "Print Tree" << endl;
			d1.print(d1.head);
			cout << endl;
		}

		else if(select == -1)
			cout << "Program quit!!!" << endl;

		else
			cout << "Bad Command~!!!" << endl;
		
	}while(select != -1);

	cout << endl;
}