#pragma once
#include <iostream>
#include <assert.h>
using namespace std;
namespace geometrie {
	template<class T >
	class Vector
	{
	private:
		T vect[3];
	public:
		Vector(T a = 0.0, T b = 0.0, T c = 0.0);
		//imposible d'utiliser cette methode et meme le constructeur de recopie par defaut
		Vector(const Vector&) = delete;
		Vector& operator=(const Vector) = delete;
		void print() const;
		T at(unsigned int indice) const;
		bool operator==(const Vector& v)const;
		bool operator!=(const Vector& v) const;
		T& operator[](unsigned int indice);
	//	friend  void displayb(Vector& v);
		//a ne pas utiliser les methodes friend ===>> -5
	//void display(Vector c);//erreur car on a un passage par valleur qui est interdit
	//void displayb(geometrie::Vector& v);
};

template<class T >
T geometrie::Vector<T>::at(unsigned int indice) const
{
    assert(indice >= 0 && indice < 3);//debug
    try//release
    {
        if (indice < 0 || indice >= 3) throw"rang error";
        return this->vect[indice];
    }
    catch (char* e) {
        cout << e << endl;
    }

}
template<class T >
bool geometrie::Vector<T>::operator==(const Vector& v) const
{
    bool res = true;
    for (int i = 0; i < 3; i++)
    {
        res = res && (this->at(i) == v.at(i));
    }
    return res;
}
template<class T >
bool geometrie::Vector<T>::operator!=(const Vector& v) const
{
    bool res = !(*this == v);

    return res;
}
template<class T >
T& geometrie::Vector<T>::operator[](unsigned int indice)
{
    assert(indice >= 0 && indice < 3);//debug
    try//release
    {
        if (indice < 0 || indice >= 3) throw"rang error";
        return this->vect[indice];
    }
    catch (char* e) {
        cout << e << endl;
    }
}
template<typename T >
geometrie::Vector<T>::Vector(T a, T b, T c)
{
    this->vect[0] = a;
    this->vect[1] = b;
    this->vect[2] = c;
}
template<class T >
void geometrie::Vector<T>::print() const
{
    for (int i = 0; i < 3; i++) {
        cout << "vecteur[" << i << "]=" << this->at(i) << endl;
    }
}



};