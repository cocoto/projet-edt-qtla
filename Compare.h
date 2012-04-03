/*
 * compare.h
 *
 *  Created on: 14 mars 2012
 *      Author: cocoto
 */

#ifndef COMPARE_H_
#define COMPARE_H_

template<typename T>
class compare {
	public:
		bool operator()(const T* a,const T* b) const{
            return *a<*b;
        }
        compare(){}
        ~compare(){}
};

#endif /* COMPARE_H_ */
