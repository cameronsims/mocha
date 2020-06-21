/* map.h
 * * mocha::map()
 */
#pragma once
#include "mocha.h"
#include "pair.h"
namespace mocha {
	/* mocha::map()
	 * * TEMPLATE: {
	 * * * "T1" : typename of first element
	 * * * "T2": typename of second element
	 * * }
	 */
	template<typename T1, typename T2>
	class map {
		// VARIABLES & FUNCTIONS
		unsigned int size = 0;
      public:
		pair<T1, T2>* data;
		
		/* mocha::map()::get()
		 * * "findex": Index to look through
		 */
		size_t get(T1  findex) const {
			int i = 0,
				n = size(data);
			while (i < n) {
				if (data[i].second == findex) {
					return i;
				}
				i++;
			}
			return -1;
		}
		size_t get(T1& findex) const {
			int i = 0,
				n = size(data);
			while (i < n) {
				if (data[i].second == findex) {
					return i;
				}
				i++;
			}
			return -1;
		}
		
		/* mocha::map()::size() */
		size_t size() const { return size;  }

		/* mocha::map()::count()
		 * * "needle": Variable to count through
		 */
		size_t count(T1  needle) const {
			int i = 0,
				amount = 0,
				n = size(data);
			while (i < n) {
				if (data[i].second == needle) {
					amount++;
				}
				i++;
			}
			return amount;
		}
		size_t count(T1& needle) const {
			int i = 0,
				amount = 0,
				n = size(data);
			while (i < n) {
				if (data[i].second == needle) {
					amount++;
				}
				i++;
			}
			return amount;
		}

		/* mocha::map()::replace()
		 * * "rep": Variable to replace with 
		 */
		void replace(T2  rep) const {
			int i = 0,
				n = sizeof(dataOne) / sizeof(dataOne[0]);
			while (i < n) {
				data[i].second = rep;
			}
		}
		void replace(T2& rep) const {
			int i = 0,
				n = sizeof(dataOne) / sizeof(dataOne[0]);
			while(i < n) {
				data[i].second = rep;
			}
		}
		
		/* mocha::clear() */
		void clear() {
			size = 0;
			delete[] data;
		}
	
	  protected:
		// CONSTRUCTORS & DESTRUCTORS
		map(const unsigned int size) : size(size), data(new pair<T1, T2>[size]) { }
		~map() { clear(); }

		template<typename _T1, typename _T2>
		void operator= (const map<_T1, _T2>& m)		{ delete[] data; data = m.data; size = m.size; }

		template<typename _T1, typename _T2>
		void operator()(const map<_T1, _T2>& m)		{ this = m; }
		void operator()(const unsigned int   s)		{ delete[] data;  size = s; }

		T2 operator[](const T1			     f) const { return data[get(f)].second; };
		T2 operator[](const T1&              f) const { return data[get(f)].second; };
		T2 operator[](const unsigned int     i) const { return data[i].second; };
	};

	/* mocha::size()
	 * * TEMPLATE: {
	 * * * "T1": "Typename to use" 
	 * * * "T2": "Typename to use"
	 * * }
	 * * "arr": "Get size of"
	 */
	template<typename T1, typename T2>
	size_t size(mocha::map<T1, T2>& arr) {
		return arr.size;
	}
}