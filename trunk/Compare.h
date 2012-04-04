/*
 * Classe permettant la comparaison d'objet à travers des pointeur
 * Nécéssaire dans l'utilisation des Sets
 */

#ifndef COMPARE_H_
#define COMPARE_H_

template<typename T>
class compare {
	public:
        //operateur indispensable aux set
		bool operator()(const T* a,const T* b) const{
            return *a<*b;
        }

        //Constructeurs et destructeurs
        compare(){}
        ~compare(){}
};

#endif /* COMPARE_H_ */
