#pragma once
#ifndef G_192049_H
#define G_192049_H

#include <string>
#include<iostream>
#include<fstream>
using namespace std;

struct Data {

	//CBID
	string CNIC;
	string Name;
	string FatherName;
	string Gender;
	string Address;
	string Nationality;

	//CCID
	string Charge;
	string Punishment;
	string Fine;

	//CCND


	//3740 123456 Vodafone 12/04/2010 12/04/2020 unactive
	string Number;
	string Network;
	string Activation_date;
	string Deactivation_date;
	string Status;


	Data() {
		CNIC = "";
		Name = "";
		FatherName = "";
		Gender = "";
		Address = "";
		Nationality = "";
		Charge = "";
		Punishment = "";
		Fine = "";
		Number = "";
		Network = "";
		Activation_date = "";
		Deactivation_date = "";
		Status = "";
	}

	void Emptydata() {
		CNIC = "";
		Name = "";
		FatherName = "";
		Gender = "";
		Address = "";
		Nationality = "";
		Charge = "";
		Punishment = "";
		Fine = "";
		Number = "";
		Network = "";
		Activation_date = "";
		Deactivation_date = "";
		Status = "";
	}
	void operator=(const Data& obj) {
		CNIC = obj.CNIC;
		Name = obj.Name;
		FatherName = obj.FatherName;
		Gender = obj.Gender;
		Address = obj.Address;
		Nationality = obj.Nationality;
		//CCID
		Charge = obj.Charge;
		Punishment = obj.Punishment;
		Fine = obj.Fine;
		//CCND
		Number = obj.Number;
		Network = obj.Network;
		Activation_date = obj.Activation_date;
		Deactivation_date = obj.Deactivation_date;
		Status = obj.Status;
	}

};


struct DP_Node {
	Data data;
	DP_Node* next;
};

template <class T>
class DataPipeline {
	/*
	A linkedlist based queue to implement databases
	Implement additional functions as per requirement
	*/
	DP_Node* rear;
	DP_Node* myFront;
public:

	DataPipeline() {
		rear = NULL;
		myFront = NULL;
	}

	void populate(const string& filename, const string& filename1, const string& filename2) {
		//It should read data for each Database from related Data Files and store it in a Linked-List-Based-Queue following FIFO rule.
		ifstream inputFile;
		Data data;
		string arrCNIC[50];
		string temp = "";
		inputFile.open(filename);
		int j = 0;
		while (!inputFile.eof() && j < 50)
		{
			inputFile >> data.CNIC;
			arrCNIC[j] = data.CNIC;
			inputFile >> data.Name;
			inputFile >> data.FatherName;
			inputFile >> data.Gender;
			inputFile >> data.Address;
			temp += data.Address;
			inputFile >> data.Address;
			temp += " ";
			temp += data.Address;
			inputFile >> data.Address;
			temp += " ";
			temp += data.Address;
			data.Address = temp;
			inputFile >> data.Nationality;
			j++;
			temp = "";
			enqueue(data);
			data.Emptydata();

		}

		inputFile.close();
		inputFile.open(filename1);
		int count = 0;

		while (!inputFile.eof() && count < 10)
		{

			if (count == 0)
			{
				inputFile >> data.CNIC;
				inputFile >> data.Charge;
				inputFile >> data.Punishment;
				temp += data.Punishment;
				temp += " ";
				inputFile >> data.Punishment;
				temp += data.Punishment;
				temp += " ";
				inputFile >> data.Punishment;
				temp += data.Punishment;
				data.Punishment = temp;
				temp = "";
				inputFile >> data.Fine;
				count++;
				enqueue(data);
				data.Emptydata();
			}
			else
			{
				int i = 0;
				inputFile >> data.CNIC;
				while (arrCNIC[i] != data.CNIC)
				{
					i++;
				}

				if (arrCNIC[i] == data.CNIC)
				{
					inputFile >> data.Charge;
					inputFile >> data.Punishment;
					temp += data.Punishment;
					temp += " ";
					inputFile >> data.Punishment;
					temp += data.Punishment;
					temp += " ";
					inputFile >> data.Punishment;
					temp += data.Punishment;
					temp += " ";
					inputFile >> data.Punishment;
					temp += data.Punishment;
					data.Punishment = temp;
					temp = "";
					inputFile >> data.Fine;
					i = 0;
					enqueue(data);
					data.Emptydata();
				}
				count++;
			}

		}
		inputFile.close();

		inputFile.open(filename2);
		int l = 0;
		while (!inputFile.eof())
		{
			inputFile >> data.CNIC;
			int i = 0;
			while (arrCNIC[i] != data.CNIC && i < 50)
			{
				i++;
			}
			if (arrCNIC[i] == data.CNIC)
			{
				inputFile >> data.Number;
				inputFile >> data.Network;
				inputFile >> data.Activation_date;
				inputFile >> data.Deactivation_date;
				inputFile >> data.Status;
				i = 0;
				enqueue(data);
				data.Emptydata();
			}

		}
		inputFile.close();
	}

	Data front() {
		if (myFront != NULL)
			return myFront->data;
		else
			return "empty queue";
	}

	T back() {

		while (rear->next != NULL)
		{
			rear = rear->next;
		}
		return rear->data;
	}

	void enqueue(Data d) {
		DP_Node* newNode = new DP_Node;
		if (rear != NULL) {

			while (rear->next != NULL)
			{
				rear = rear->next;
			}
			rear->next = newNode;
			newNode->data = d;
			newNode->next = NULL;
		}
		else
		{
			rear = newNode;
			myFront = newNode;
			newNode->data = d;
			newNode->next = NULL;
		}
	}

	Data dequeue() {
		Data data;
		if (myFront != NULL)
		{
			DP_Node* temp = new DP_Node;
			temp = myFront;
			myFront = myFront->next;
			data = temp->data;
			delete temp;
			return data;
		}
	}

	bool is_empty() {
		if (rear == NULL)
			return true;
		else
			return false;
	}

};

struct AD_NODE {

	AD_NODE* next;
	Data data;

};

template <class T>
class AD {
	/* Implement a stack for your Alien Database operations */

public:
	AD_NODE* head;
	AD() {
		head = NULL;
	}

	void push_roll(Data value) {

		AD_NODE* newNode = new AD_NODE;
		newNode->data = value;//assigning value or data
		newNode->next = head;//assinging the address of head to newNode's next
		head = newNode;//assinging the address of newNode to head
		//head will be pointing to the newNode
	}

	Data& top() {
		return head->data;
	}

	void display() {

		if (head != NULL) {
			AD_NODE* temp;
			temp = head;

			while (temp != NULL)
			{
				//cout << temp->data.CNIC;
				cout << temp->data.Name;
				cout << temp->data.FatherName;
				cout << temp->data.Address;
				cout << temp->data.Gender;
				cout << temp->data.Nationality;
				cout << temp->data.Charge;
				cout << temp->data.Punishment;
				cout << temp->data.Activation_date;
				cout << temp->data.Deactivation_date;
				cout << temp->data.Status;
				cout << endl;
				temp = temp->next;
			}
			//cout << temp->data.CNIC;
			//cout << temp->data.Name;
			//cout << temp->data.FatherName;
			//cout << temp->data.Address;
			//cout << temp->data.Gender;
			//cout << temp->data.Nationality;
			//cout << temp->data.Charge;
			//cout << temp->data.Punishment;
			//cout << temp->data.Activation_date;
			//cout << temp->data.Deactivation_date;
			//cout << temp->data.Status;
		}
		else {
			cout << "stack is empty";
		}
	}

	Data  pop() {
		//Data x = head->data;
		//AD_NODE *temp = head;
		//head = head->next;
		//delete temp;
		//return x;
		Data temp;
		if (head == NULL)
		{
			cout << "";
		}
		else {
			temp = head->data;
			head = head->next;
			return temp;
		}

	}

	bool is_empty() {
		if (head == NULL)
			return true;
		else
			return false;
	}

	void empty() {

		while (!is_empty()) {
			pop();
		}
	}

};

struct CCND_NODE {
	CCND_NODE* next;
	Data data;
};

struct CCID_NODE {
	CCID_NODE* next, * previous;
	Data data;
};

struct CBID_NODE {
	CBID_NODE* next, * previous;
	CCID_NODE* ccid_node;
	CCND_NODE* ccnd_node;
	Data data;
	CBID_NODE() {
		next = NULL;
		previous = NULL;
		ccid_node = NULL;
		ccnd_node = NULL;
	}

};
class CBID {
private:
public:
	CBID_NODE* front;//1st element
	CBID_NODE* rear;//last element

	CBID()
	{
		front = NULL;
		rear = NULL;
	}

	void enque(Data data) {

		CBID_NODE* newNode = new CBID_NODE;
		//next and previous already null
		newNode->data = data;
		if (rear == NULL)
		{
			front = rear = newNode;
		}
		else {

			newNode->previous = rear;
			rear->next = newNode;
			rear = rear->next;
		}

	}

	void deque() {

		CBID_NODE* temp = front;
		front = front->next;
		if (front == NULL)
			rear = NULL;
		else
		{
			front->previous = NULL;
			delete temp;
		}

	}


	void sortInAscendingOrder(Data data)
	{
		/*string arrCNIC[50];
		Data temp;
		 for (int i = 0; i < 50; i++)
		 {

			 if (strcmp ( strcpy(arrCNIC[i]) , strcpy( data.CNIC ) ))
			 {
				 temp.CNIC = data.CNIC;
				 arrCNIC[i] = data.CNIC;
				 data.CNIC = temp.CNIC;
			 }
		 }*/
	}

	void display() {

		CBID_NODE* last = front;
		while (last->next != NULL) {
			cout << last->data.CNIC;
			cout << last->data.Name;
			cout << last->data.FatherName;
			cout << last->data.Gender;
			cout << last->data.Address;
			cout << last->data.Nationality;
			cout << endl;
			last = last->next;
		}
		cout << last->data.CNIC;
		cout << last->data.Name;
		cout << last->data.FatherName;
		cout << last->data.Gender;
		cout << last->data.Address;
		cout << last->data.Nationality;
		cout << endl;
		if (last == NULL)
			cout << "NULL"; cout << endl;

	}
};


class CCID {

public:
	CCID_NODE* front, * rear;
	CCID() {
		front = NULL, rear = NULL;
	}
	void enque(Data value)
	{

		if (front == NULL)
		{
			CCID_NODE* newNode = new CCID_NODE;
			newNode->data = value;
			newNode->next = newNode->previous = newNode;
			front = newNode;
			return;
		}
		rear = front->previous;//If the list is not empty
		CCID_NODE* newNode = new CCID_NODE;// Create Node  
		newNode->data = value;//data 
		newNode->next = front;// front is going to be next of newNode 
		front->previous = newNode;//new node previous of =>  front 
		newNode->previous = rear;// rear preivous of => new node
		rear->next = newNode;// new node next of => rear
	}

	Data deque() {
		Data value;
		if (front == rear) {
			value = front->data;
			delete front;
			front = NULL;
			rear = NULL;
		}
		else //  more than one nodes 
		{
			CCID_NODE* temp = front;
			value = temp->data;
			front = front->next;
			front->previous = rear;
			rear->next = front;
			delete temp;
		}
		return value;
	}
	void display()
	{
		cout << endl;
		CCID_NODE* temp = front;
		while (temp->next != front) {
			cout << temp->data.CNIC;
			cout << temp->data.Charge;
			cout << temp->data.Punishment;
			cout << temp->data.Fine;
			cout << endl;
			temp = temp->next;
		}
		cout << temp->data.CNIC;
		cout << temp->data.Charge;
		cout << temp->data.Punishment;
		cout << temp->data.Fine;
		cout << endl;
	}
};

class CCND {

public:
	CCND_NODE* front, * rear;
	CCND() {
		front = NULL;
		rear = NULL;
	}
	void sortInAscendingOrder() {

	}
	void enque(Data data) {
		CCND_NODE* temp = new CCND_NODE;
		temp->data = data;
		if (front == NULL) {
			front = temp;
		}
		else {
			rear->next = temp;
		}
		rear = temp;//for both(important)
		rear->next = front;
	}
	Data deque() {
		Data value;
		if (front == rear) {
			value = front->data;
			delete front;
			front = NULL;
			rear = NULL;
		}
		else // if more than one nodes 
		{
			CCND_NODE* temp = front;
			value = temp->data;
			front = front->next;
			rear->next = front;
			delete temp;
		}
		return value;
	}
	void display() {
		cout << endl;
		CCND_NODE* temp = front;
		while (temp->next != front) {
			cout << temp->data.CNIC;
			cout << temp->data.Network;
			cout << temp->data.Activation_date;
			cout << temp->data.Deactivation_date;
			cout << temp->data.Status;
			cout << endl;
			temp = temp->next;
		}
		cout << temp->data.CNIC;
		cout << temp->data.Network;
		cout << temp->data.Activation_date;
		cout << temp->data.Deactivation_date;
		cout << temp->data.Status;
		cout << endl;
	}

};

struct disp_node {

	disp_node* next;
	Data data;

};

template <class T>
class disp_linkedList {
	/* Implement a stack for your Alien Database operations */

public:
	disp_node* head;
	disp_linkedList() {
		head = NULL;
	}

	void push_roll(Data value) {

		disp_node* newNode = new disp_node;
		newNode->data = value;//assigning value or data
		newNode->next = head;//assinging the address of head to newNode's next
		head = newNode;//assinging the address of newNode to head
		//head will be pointing to the newNode
	}


	void display() {

		if (head != NULL) {
			disp_node* temp;
			temp = head;

			while (temp != NULL)
			{
				//cout << temp->data.CNIC;
				cout << temp->data.Name;
				cout << temp->data.FatherName;
				cout << temp->data.Address;
				cout << temp->data.Gender;
				cout << temp->data.Nationality;
				cout << temp->data.Charge;
				cout << temp->data.Punishment;
				cout << temp->data.Activation_date;
				cout << temp->data.Deactivation_date;
				cout << temp->data.Status;
				cout << endl;
				temp = temp->next;
			}
		}
		else {
			cout << "stack is empty";
		}
	}

	Data  pop() {
		Data temp;
		if (head == NULL)
		{
			cout << "";
		}
		else {
			temp = head->data;
			head = head->next;
			return temp;
		}

	}

	bool is_empty() {
		if (head == NULL)
			return true;
		else
			return false;
	}

	void empty() {

		while (!is_empty()) {
			pop();
		}
	}

};



template <class T>
class Database {


public:
	CBID  cbid;
	CCID  ccid;
	CCND  ccnd;
	DataPipeline <T> dataPipeline;

	Database(const T& filename, const T& filename1, const T& filename2) {
		/*
			Initialize the data from the given file and populate database
		*/
		dataPipeline.populate(filename, filename1, filename2);//populating datapipeline
		Data data;
		int i = 0;
		while (i < 50)
		{
			data = dataPipeline.dequeue();
			//cout << endl;
			cbid.enque(data);
			i++;
		}


		i = 0;
		while (i < 10)
		{
			data = dataPipeline.dequeue();
			ccid.enque(data);
			i++;
		}
		//ccid.display();

		i = 0;
		while (i < 54)
		{
			data = dataPipeline.dequeue();
			ccnd.enque(data);
			i++;
		}
		//ccnd.display();
		string s1 = "joe frank m 44 downing street british murder life in prison - 123456 Vodafone 12/04/2010 12/04/2020 unactive";

		string s2 = CBID_Search_by_CNIC(7098);
		/*if (s2 == s1) {
			cout << endl;
			cout << "1"<<endl;
		}
		else {
			cout << endl;
			cout << s2;
		}*/

	}
	/*Return a string in following format "Name FName Gender Address Nationality Crimes(if any) Charges punishment fine number network activation_date deactivation_date status"
	 Refer to test cases for further clerification*/
	 /*T& CBID_Search_by_CNIC(int cnic) {

		 CBID_NODE* temp = cbid.front;
		 cout << temp->data.CNIC;

		 return NULL;
	 }*/
	T CBID_Search_by_CNIC(int cnic) {
		bool flag = false;
		CBID_NODE* temp = new CBID_NODE;
		temp = cbid.front;
		cout << endl;
		while (temp->next != NULL)
		{
			int CNIC = stoi(temp->data.CNIC);

			if (CNIC == cnic)
			{
				flag = true;
				break;

			}
			temp = temp->next;

		}
		int CNIC = stoi(temp->data.CNIC);
		if (CNIC == cnic)
		{
			flag = true;

		}

		//Name FName Gender Address Nationality
		//Crimes(if any)
		//Charges punishment fine
		//number network activation_date deactivation_date status
		string info = "";
		if (flag == true)
		{

			info += temp->data.Name;
			info += " ";
			info += temp->data.FatherName;
			info += " ";
			info += temp->data.Gender;
			info += " ";
			info += temp->data.Address;
			info += " ";
			info += temp->data.Nationality;


			temp->ccid_node = ccidAddress(temp->data.CNIC);
			if (temp->ccid_node != NULL)
			{
				info += " ";
				info += temp->ccid_node->data.Charge;
				info += " ";
				info += temp->ccid_node->data.Punishment;
				info += " ";
				info += temp->ccid_node->data.Fine;
			}
			temp->ccnd_node = ccndAddress(temp->data.CNIC);
			if (temp->ccnd_node != NULL)
			{
				info += " ";
				info += temp->ccnd_node->data.Number;
				info += " ";
				info += temp->ccnd_node->data.Network;
				info += " ";
				info += temp->ccnd_node->data.Activation_date;
				info += " ";
				info += temp->ccnd_node->data.Deactivation_date;
				info += " ";
				info += temp->ccnd_node->data.Status;
			}

		}

		return info;
	}

	CCID_NODE* ccidAddress(string cnic) {
		CCID_NODE* temp = new CCID_NODE;
		temp = ccid.front;
		while (temp->next != ccid.front) {
			if (temp->data.CNIC == cnic)
			{
				return temp;
			}
			temp = temp->next;
		}
		if (temp->data.CNIC == cnic)
		{
			return temp;
		}
		return NULL;
	}

	CCND_NODE* ccndAddress(string cnic) {
		CCND_NODE* temp = new CCND_NODE;
		temp = ccnd.front;
		while (temp->next != ccnd.front) {
			if (temp->data.CNIC == cnic)
			{
				return temp;
			}
			temp = temp->next;
		}
		if (temp->data.CNIC == cnic)
		{
			return temp;
		}
		return NULL;
	}


	T CCID_Search_by_CNIC(int cnic) {
		bool flag = false;
		CCID_NODE* temp = ccid.front;
		while (temp->next != ccid.front) {
			int CNIC = stoi(temp->data.CNIC);
			if (CNIC == cnic)
			{
				flag = true;
				break;
			}
			temp = temp->next;
		}
		int CNIC = stoi(temp->data.CNIC);
		if (CNIC == cnic)
		{
			flag = true;
		}
		if (flag == true)
		{
			return CBID_Search_by_CNIC(cnic);
		}
	}
	T CCND_Search_by_CNIC(int cnic) {

		bool flag = false;
		CCND_NODE* temp = ccnd.front;
		while (temp->next != ccnd.front) {
			int CNIC = stoi(temp->data.CNIC);
			if (CNIC == cnic)
			{
				flag = true;
				break;
			}
			temp = temp->next;
		}
		int CNIC = stoi(temp->data.CNIC);
		if (CNIC == cnic)
		{
			flag = true;

		}
		if (flag == true)
		{
			return CBID_Search_by_CNIC(cnic);
		}
		return NULL;
	}

	bool updateCBIDName(T Name, int cnic) {
		/*update and return true when cnic found else return false*/
		bool flag = false;
		CBID_NODE* temp = new CBID_NODE;
		temp = cbid.front;
		cout << endl;
		while (temp->next != NULL)
		{
			int CNIC = stoi(temp->data.CNIC);

			if (CNIC == cnic)
			{
				temp->data.Name = Name;
				flag = true;
				return true;
			}
			temp = temp->next;
		}
		int CNIC = stoi(temp->data.CNIC);
		if (CNIC == cnic)
		{
			temp->data.Name = Name;
			return true;
		}
		return false;

	}

	bool updateCBIDFName(T Father_Name, int cnic) {
		/*update and return true when cnic found else return false*/
		bool flag = false;
		CBID_NODE* temp = new CBID_NODE;
		temp = cbid.front;
		cout << endl;
		while (temp->next != NULL)
		{
			int CNIC = stoi(temp->data.CNIC);

			if (CNIC == cnic)
			{
				flag = true;
				temp->data.FatherName = Father_Name;
				return true;
			}
			temp = temp->next;
		}
		int CNIC = stoi(temp->data.CNIC);
		if (CNIC == cnic)
		{
			temp->data.FatherName = Father_Name;
			return true;
		}
		return false;
	}

	bool updateCBIDAddress(T Address, int cnic) {
		/*update and return true when cnic found else return false*/
		bool flag = false;
		CBID_NODE* temp = new CBID_NODE;
		temp = cbid.front;
		cout << endl;
		while (temp->next != NULL)
		{
			int CNIC = stoi(temp->data.CNIC);

			if (CNIC == cnic)
			{
				flag = true;
				temp->data.Address = Address;
				return true;
			}
			temp = temp->next;
		}
		int CNIC = stoi(temp->data.CNIC);
		if (CNIC == cnic)
		{
			temp->data.Address = Address;
			return true;
		}
		return false;



	}

	bool updateCBIDNationality(T Nationality, int cnic) {
		/*update and return true when cnic found else return false*/
		bool flag = false;
		CBID_NODE* temp = new CBID_NODE;
		temp = cbid.front;
		cout << endl;
		while (temp->next != NULL)
		{
			int CNIC = stoi(temp->data.CNIC);

			if (CNIC == cnic)
			{
				flag = true;
				temp->data.Nationality = Nationality;
				return true;
			}
			temp = temp->next;
		}
		int CNIC = stoi(temp->data.CNIC);
		if (CNIC == cnic)
		{
			temp->data.Nationality = Nationality;
			return true;
		}
		return false;
	}

	bool addCrime(int cnic, T charges, T punishment, T fine) {

		bool flag1 = false;
		CBID_NODE* temp = new CBID_NODE;
		temp = cbid.front;
		cout << endl;
		while (temp->next != NULL)
		{

			int CNIC_cbid = stoi(temp->data.CNIC);
			if (CNIC_cbid == cnic)
			{
				return true;
				//temp->data.Name = Name;

			}
			temp = temp->next;
		}
		int CNIC_cbid = stoi(temp->data.CNIC);

		if (CNIC_cbid == cnic)
		{
			return true;
			//temp->data.Name = Name;

		}

		return false;
	}

	bool updateCrime(int cnic, T charges, T punishment, T fine) {
		/*updateand return true when crime found else return false */
		bool flag1 = false;
		CCID_NODE* temp = new CCID_NODE;
		temp = ccid.front;
		cout << endl;
		while (temp->next != ccid.front)
		{

			int CNIC_cbid = stoi(temp->data.CNIC);
			if (CNIC_cbid == cnic)
			{
				return true;
				//temp->data.Name = Name;

			}
			temp = temp->next;
		}
		int CNIC_cbid = stoi(temp->data.CNIC);

		if (CNIC_cbid == cnic)
		{
			return true;
			//temp->data.Name = Name;

		}
		return false;
	}

	bool deleteCrime(int cnic, T charges, T punishment, T fine) {
		/*update and return true when crime found else return false*/
		bool flag1 = false;
		CCID_NODE* temp = new CCID_NODE;
		temp = ccid.front;
		cout << endl;
		while (temp->next != ccid.front)
		{

			int CNIC_cbid = stoi(temp->data.CNIC);
			if (CNIC_cbid == cnic)
			{
				return true;
				//temp->data.Name = Name;
			}
			temp = temp->next;
		}
		int CNIC_cbid = stoi(temp->data.CNIC);

		if (CNIC_cbid == cnic)
		{
			return true;
			//temp->data.Name = Name;
		}
		return false;
	}

	int addNumber(int cnic, int number) {
		//int number;
		try
		{
			bool flag = false;
			int count = 0;
			/*return number of cell-numbers registered on given cnic after adding this number*/
			CCND_NODE* temp = ccnd.front;
			CCND_NODE* temp2 = NULL;
			while (temp->next != ccnd.front)
			{
				int CNIC = stoi(temp->data.CNIC);
				if (CNIC == cnic)
				{
					temp2 = temp;
					count++;
					flag = true;
				}
				temp = temp->next;
			}
			int CNIC = stoi(temp->data.CNIC);
			if (CNIC == cnic)
			{
				temp2 = temp;
				count++;
				flag = true;
			}

			if (flag == true)
			{
				temp2->data.Number = number;
				ccnd.enque(temp2->data);
				//cout << temp->data.CNIC << endl;
				count++;
			}
			if (count < 5)
			{
				return count;
			}
			else {
				throw(count);
			}

		}
		catch (int myCount)
		{
			cout << "No more numbers can be registered on this CNIC" << endl;
			return 4;
		}

	}

	int checkRegistred_No(int cnic) {
		int count = 0;
		/*return number of cell-numbers registered on given cnic*/
		//bool flag = false;
		//int count = 0;
		/*return number of cell-numbers registered on given cnic after adding this number*/
		CCND_NODE* temp = ccnd.front;
		//CCND_NODE* temp2 = NULL;
		while (temp->next != ccnd.front)
		{
			int CNIC = stoi(temp->data.CNIC);
			if (CNIC == cnic)
			{
				if (temp->data.Status == "active")
					count++;

			}
			temp = temp->next;
		}
		int CNIC = stoi(temp->data.CNIC);
		if (CNIC == cnic)
		{
			if (temp->data.Status == "active")
				count++;
		}
		return count;
	}

	//CCND_NODE& swap(T cnic, T cnic1, T number, T number1) {
	//	/*Include functionality to swap ownership of two registered numbers. Take CNIC of 2-citizens and numbers to be exchanged, then proceed with functionality.*/
	//	return CCND;
	//}

	bool declareAlien(CBID_NODE cbidnode, AD <string>& ad) {
		/*For Implementation of this function, Refer to CBID point 'iv', CCID point 'vi' and CCND point 'vii'. Also,
		write test-cases for this function yourself*/
		CBID_NODE* temp = new CBID_NODE;

		temp = cbid.front;
		cout << endl;
		while (temp->next != NULL)
		{

			if (temp->data.CNIC == cbidnode.data.CNIC)
			{

				temp->data.Nationality = "Alien";
				temp->data.Status = "unactive";
				ad.push_roll(temp->data);
				//ad.display();
				//Data d =ad.pop();
				//cout << d.CNIC;
				return true;
			}
			temp = temp->next;
		}
		int CNIC = stoi(temp->data.CNIC);
		if (temp->data.CNIC == cbidnode.data.CNIC)
		{
			temp->data.Nationality = "Alien";
			temp->data.Status = "unactive";
			ad.push_roll(temp->data);
			return true;
		}
		return false;
	}

	bool verifyAlienDBUpdate(string cnic, AD <string>& adobj, CBID obj) {
		/*Verify that given CNIC is moved from CBID to AD, Also add test-case for this function yourself*/
		bool flag1 = false;
		CBID_NODE* temp = obj.front;
		while (temp->next != NULL) {
			if (temp->data.CNIC == cnic)
			{
				flag1 = true;
				break;
			}
			temp = temp->next;
		}
		if (temp->data.CNIC == cnic)
		{
			flag1 = true;
		}
		bool flag2 = false;
		AD_NODE* temp2 = adobj.head;
		while (temp2 != NULL)
		{
			if (temp2->data.CNIC == cnic)
			{
				flag2 = true;
				break;
			}
			temp2 = temp2->next;
		}

		if (flag1 == true && flag2 == true)
		{
			return true;
		}
		return false;

	}

	int printcount() {
		int total;
		/*Print count of cell phone numbers registered on each network. For example: (Telenor= 10, Jazz= 5, Ufone= 8, Zong= 9, Total= 32)
		 Return total*/

		int count1 = 0;
		int count2 = 0;
		int count3 = 0;
		int count4 = 0;
		int count5 = 0;
		CCND_NODE* temp = ccnd.front;
		while (temp->next != ccnd.front)
		{
			if (temp->data.Network == "Vodafone")
				count1++;
			if (temp->data.Network == "BTmobile")
				count2++;
			if (temp->data.Network == "O2")
				count3++;
			if (temp->data.Network == "EE")
				count4++;
			if (temp->data.Network == "Skymobile")
				count5++;
			temp = temp->next;
		}

		if (temp->data.Network == "Vodafone")
			count1++;
		if (temp->data.Network == "BTmobile")
			count2++;
		if (temp->data.Network == "O2")
			count3++;
		if (temp->data.Network == "EE")
			count4++;
		if (temp->data.Network == "Skymobile")
			count5++;

		cout << " Vadofone = " << count1;
		cout << " BTmobile = " << count2;
		cout << " O2 = " << count3;
		cout << " EE = " << count4;
		cout << " Skymobile = " << count5 << endl;
		return total = count1 + count2 + count3 + count4 + count5;
	}
	void Display_AD(AD <string>& obj) {
		/*Display data as instructed in point (xiv) of PDF*/
		disp_linkedList <string> disp_obj;
		disp_obj.push_roll(obj.pop());
		Data d = disp_obj.pop();
		cout << d.CNIC;
		cout << d.Name;
		cout << d.Address;
		cout << d.FatherName;
	}

	~Database() {
		/* deallocate and cleanup */
	}
};





#endif // !G_192049_H
