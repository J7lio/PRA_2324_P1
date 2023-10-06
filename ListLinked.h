#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
	private:
		Node<T>* first;
		int n;
	public:
		void insert(int pos, T e){
			if(pos < 0 || pos > n) throw std::out_of_range("Posicion fuera de rango");

			if(n == 0){
				first = new Node<T>*;
				first->data = e;
				first->next = nullptr;
			}else if(pos == 0){
				Node<T>* aux = new Node<T>*;
				aux->next = first;
				aux->data = e;
				first = aux;
			}else{
				Node<T>* aux = new Node<T>*;
				aux->next = this[pos];
				aux->data = e;
				this[pos-1]->next = aux;
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

			this[pos-1]->next = this[pos]->next;
			T datoEliminado = this[pos]->data;
			delete this[pos];

			return datoEliminado;
		}

		T get(int pos){
			if(pos < 0 || pos >= n) throw std::out_of_range("Posicion fuera de rango");

			return this[pos]->data;
		}

		int search(T e){
			Node<T>* aux = first;
			int i = 0;
			while(aux != nullptr){
				if(aux->data == e) return i;
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
		}

		~ListLinked(){
			while(first!=nullptr){
				Node<T>* aux = first->next;
				delete first;
				first = aux;
			}
		}

		T operator[](int pos){
			if(pos >= n) throw("Posicion fuera de rango");

			Node<T>* aux = first;
			for(int i = 0; i < pos; i++){
				aux = aux->next;
			}
			return aux;
		}

		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
			out << "List [";

			Node<T>* aux = list.first;
			for(int i = 0; i < list.n; i++){
				out << "\n" << aux.data;
				aux = aux->next;
			}

			if(list.n>0) out << "\n";

			out << "]";
			return out;
		}


};
