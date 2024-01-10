#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
	private:
		Node<T>* first;
		int n;
	public:
		//Funcion para ayudar en otras partes del codigo.
		Node<T>* getNode(int pos){
			Node<T>* aux = first;
			for(int i = 0; i < pos; i++){
				aux = aux->next;
			}
			return aux;
		}

		void insert(int pos, T e){
			if(pos < 0 || pos > n) throw std::out_of_range("Posicion fuera de rango");

			if(n == 0){
				first = new Node<T>(e);
				first->next = nullptr;
			}else if(pos == 0){
				Node<T>* aux = new Node<T>(e);
				aux->next = first;
				first = aux;
			}else{
				Node<T>* aux = new Node<T>(e);
				aux->next = getNode(pos);
				getNode(pos-1)->next = aux;
			}
			n++;
		}

		void append(T e){
			insert(n, e);
		}

		void prepend(T e){
			insert(0, e);
		}

		T remove(int pos){
			if(pos < 0 || pos >= n) throw std::out_of_range("Posicion fuera de rango");

			Node<T>* NodoaBorrar = getNode(pos);
			if(pos==0){
				first = NodoaBorrar->next;
			}else{
			    Node<T>* prev = getNode(pos-1);
			    prev->next = NodoaBorrar->next;
			}

			T d = NodoaBorrar->data;
			delete NodoaBorrar;

			n--;

			return d;
		}

		T get(int pos){
			if(pos < 0 || pos >= n) throw std::out_of_range("Posicion fuera de rango");

			Node<T>* aux = first;
			for(int i = 0; i < pos; i++){
				aux = aux->next;
			}
			return aux->data;
		}

		int search(T e){
			Node<T>* aux = first;
			int i = 0;
			while(aux != nullptr){
				if(aux->data == e) return i;
				aux = aux->next;
			}
			return -1;
		}

		bool empty(){
			return n==0;
		}

		int size(){
			return n;
		}

		ListLinked(){
			first = nullptr;
			n = 0;
		}

		~ListLinked(){
			while(first!=nullptr){
				Node<T>* aux = first->next;
				delete first;
				first = aux;
			}
		}

		T operator[](int pos){
			return get(pos);
		}

		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
			out << "List => [";

			Node<T>* aux = list.first;
			for(int i = 0; i < list.n; i++){
				out << "\n  " << aux->data;
				aux = aux->next;
			}

			if(list.n>0) out << "\n";

			out << "]";
			return out;
		}

};
