#include <iostream>
#include <cstdlib>

using namespace std;

class InvalidIndexException{};

template<typename T>
class ListNode{
public:
	T value;
	ListNode<T> *next;
	
	ListNode<T>(): next(nullptr){}
	ListNode<T>(T value1, ListNode<T> *next1): value(value1), next(next1){}
};
template<typename T>
class LinkedList{
public:
	int size;
	ListNode<T> *head;
	
	LinkedList<T>(): size(0), head(nullptr){}
	
	~LinkedList<T>(){
		ListNode<T> *t1 = head, *t2;
		while(t1 != nullptr){
			t1 = t1->next;
			delete t1;
			t1 = t2;
		}
	}
	
	void insert(int k, T value){
		try{
			if(k < 0 || k > size) throw InvalidIndexException();
			if(k == 0){
				head = new ListNode<T>(value, head);
			}
			else {
				ListNode<T> *dest = head;
				for(int i=0; i<k-1; i++) dest = dest->next;
				dest->next = new ListNode<T>(value, dest->next);
			}
			size++;
		}
		catch(InvalidIndexException e){
			cerr << "�߸��� �ε���" << endl;
			exit(1);
		}
	}
	
	void erase(int k){
		try{
			if(k < 0 || k>= size) throw InvalidIndexException();
			if(k==0){
				ListNode<T> *temp = head->next;
				delete head;
				head = temp;
			}
			else {
				ListNode<T> *dest = head, *temp;
				for(int i=0; i<k-1; i++) dest = dest->next;
				temp = dest->next->next;
				delete dest->next;
				dest->next = temp;
			}
			size--;
		}
		catch(InvalidIndexException e){
			cerr << "�߸��� �ε���" << endl;
			exit(2);
		}
	}
	
	int search(T value){ // ���� ã�� ù��° �ε��� ����, ������ -1 ����
        ListNode<T> *temp = head;
        for(int i=0; i<size; i++){
            if(temp->value == value) return i;
            temp = temp->next;
        }
        return -1; // �� ã��
    }
};
 
template<typename T>
ostream& operator <<(ostream &out, const LinkedList<T> &LL){ // ���ҵ��� �� �ٿ� ���ʴ�� ���
    ListNode<T> *temp = LL.head;
    out << '[';
    for(int i=0; i<LL.size; i++){
        out << temp->value;
        temp = temp->next;
        if(i < LL.size-1) out << ", ";
    }
    out << ']';
    return out;
}
 
int main(){
    LinkedList<int> LL;
    LL.insert(0, 1); cout << LL << endl;
    LL.insert(1, 2); cout << LL << endl;
    LL.insert(2, 3); cout << LL << endl;
    LL.insert(0, 4); cout << LL << endl;
    LL.insert(0, 5); cout << LL << endl;
    LL.insert(5, 6); cout << LL << endl;
    LL.insert(4, 7); cout << LL << endl;
    LL.insert(1, 8); cout << LL << endl;
    LL.erase(4); cout << LL << endl;
    LL.erase(0); cout << LL << endl;
    LL.erase(5); cout << LL << endl;
    LL.insert(3, 9); cout << LL << endl;
    LL.erase(1); cout << LL << endl;
    LL.insert(1, 10); cout << LL << endl;
}

