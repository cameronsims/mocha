/* pair.h
 * * mocha::pair()
 */
#pragma once
#include "mocha.h"
namespace mocha {
	/* mocha::pair()
	 * * template: {
	 * * * "T1": typename of first element
	 * * * "T2": typename of second element
	 * * } 
	 */
	template<typename T1, typename T2>
	struct pair {
		// VARIABLES & FUNCTIONS
		T1* first;
		T2* second;

		/* mocha::pair::swap() */
		pair<T2, T1> swap() const {
			return pair(second, first);
		}
		
		// CONSTRUCTORS & DESTRUCTORS

		/* mocha::pair::pair() 
		 * "x": First value
		 * "y": Second value
		 */
		pair(		     )                       { }
		pair(T1 x,  T2 y ) : first(x), second(y) { }
		pair(T1& x, T2& y) : first(x), second(y) { }
		~pair() {
			delete[] first,
				     second;
		}
	};

	/* mocha::tuple()
	 * * template: {
	 * * * "T1": typename of first element
	 * * * "T2": typename of second element
	 * * }
	 */
	template<typename T1, typename T2>
	using tuple = pair<T1, T2>;
}