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
				new_arr[i] == arr[i];
			}

			delete[] arr;
			arr = new_arr;
			max = new_size;
		}

	public:
			ListArray(){
				arr = new T[MINSIZE];
				max = MINSIZE;
				n = 0;
			}

			~ListArray(){
				delete[] arr;
			}

			T operator[](int pos){
				if(pos < 0 || pos >= max) throw std::out_of_range("Posicion fuera de rango");
				return arr[pos];
			}

			friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
				out << "Array [";
				for(int i = 0; i < list.n; i++){
					out << list.arr[i] << ", ";
					//Falta arreglar la coma alfinal del array
				}

				out << "]";
				return out;
			}

};
