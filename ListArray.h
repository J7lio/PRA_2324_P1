#include <ostream>
#include <stdexcept>

#include "List.h"


template <typename T>
class ListArray : public List<T>{

	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE = 2;

		void resize(int new_size){
			T* new_arr = new T[new_size];

			for(int i = 0; i < std::min(max, new_size); i++){
				new_arr[i] = arr[i];
			}

			delete[] arr;
			arr = new_arr;
			max = new_size;
		}

	public:
		void insert(int pos, T e){
			if(pos < 0 || pos > n) throw std::out_of_range("Posicion fuera de rango");

			if(n >= max) resize(max*2);

			if(n == 0){
				arr[0] = e;
			}else if(pos == n){
				arr[pos] = e;
			}else{
				for(int i=n; i>=pos; i--){
					arr[i] = arr[i-1];
				}
			}
			arr[pos] = e;
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

			T temp = arr[pos];

			for(int i = pos; i < n-1; i++){
				arr[pos] = arr[pos+1];
			}
			n--;
			return temp;
		}

		T get(int pos){
			if(pos < 0 || pos >= n) throw std::out_of_range("Posicion fuera de rango");
			return arr[pos];
		}

		int search(T e){
			for(int i = 0; i < n; i++){
				if(arr[i] == e) return i;
			}
			return -1;
		}

		bool empty(){
			return n==0;
		}

		int size(){
			return n;
		}

		ListArray(){
			arr = new T[MINSIZE];
			max = MINSIZE;
			n = 0;
		}

		~ListArray(){
			delete[] arr;
		}

		T operator[](int pos){
			return get(pos);
		}

		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
			out << "Array [";
			for(int i = 0; i < list.n; i++){
				out << "\n" << list.arr[i];
				//Falta arreglar la coma alfinal del array
			}

			if(list.n>0) out << "\n";

			out << "]";
			return out;
		}

};

