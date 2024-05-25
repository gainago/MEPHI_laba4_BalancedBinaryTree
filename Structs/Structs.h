#pragma once
#include "string.cpp"
#include "functions_for_Funk.h"
class Complex{
    int x_;
    int y_;
    public:
    Complex(int x = 0, int y = 0) : x_(x) , y_(y){}
    bool operator==(Complex const & c2)
    {
        if(this->x_ == c2.x_ && this->y_ == c2.y_)
            return true;
        return false;

    }
    
    Complex operator+(Complex const & c2)
    {
            return Complex (c2.x_ + this->x_, c2.y_ + this->y_);

    }
    Complex operator+(int a)
    {
            return Complex (a + this->x_, a + this->y_);

    }
    Complex operator*(Complex const & c2)
    {
            return Complex (c2.x_ * this->x_, c2.y_ * this->y_);

    }
    Complex operator*(int a)
    {
            return Complex (a* this->x_, a * this->y_);

    }
    bool operator>(Complex comp2)
    {
        return this->x_ > comp2.x_;
    }
    bool operator<(Complex comp2)
    {
        return this->x_ < comp2.x_;
    }
    bool operator!=(Complex comp2)
    {
        return !(this->operator==(comp2));
    }
    bool operator<=(Complex comp2)
    {
        return !(*this > comp2);
    }
    bool operator%(int a)
    {
        return (this->x_ % a ) || (this->y_ % a);
    }
   friend std::ostream& operator<<(std::ostream & ost, Complex comp)
    {
        ost << comp.x_ << " " << comp.y_ << "   ";
        return ost;
    }
    friend std::istream& operator>>(std::istream& ist, Complex &  comp)
    {
        ist >> comp.x_ >> comp.y_;
        return ist;
    }
};
class Char1{
   unsigned char ch_;
    public:
    Char1(unsigned char ch) : ch_(ch){}
     Char1(int ch = 0) : ch_((int)ch){}
    bool operator==(Char1 const & c2)
    {
        if(ch_ == c2.ch_)
            return true;
        return false;

    }
    Char1 operator+(Char1 const & ch)
    {
            return Char1 ((int)ch.ch_ + 1);

    }
    Char1 operator+(int a)
    {
            return Char1 ((int)ch_ + a);

    }
    Char1 operator*(Char1 const & ch)
    {
            return Char1((int)this->ch_ * (int)ch.ch_);

    }
    Char1 operator*(int a)
    {
            return Char1 ((int)this->ch_ * a);

    }
    bool operator%(int a)
    {
        return ((int)this->ch_ % a);
    }
    bool operator<(Char1 comp)
    {
        return this->ch_ < comp.ch_;
    }
    bool operator>(Char1 comp)
    {
        return (!this->operator<(comp))&&(!this->operator==(comp));
    }
    bool operator<=(Char1 comp)
    {
        return this->ch_ <= comp.ch_;
    }
    bool operator!=(Char1 char1)
    {
        return !(this->operator==(char1));
    }
   friend std::ostream& operator<<(std::ostream & ost, Char1 comp)
    {
        ost << comp.ch_ <<  "   ";
        return ost;
    }
    friend std::istream& operator>>(std::istream& ist, Char1 &  comp)
    {
        ist >> comp.ch_;
        return ist;
    }
};
class Funk{
   int (*foo_)(int);
    public:
    Funk(int (*foo)(int) = foo_default) : foo_(foo){}
    
    bool operator==(Funk const & funk1)
    {
        if(this->foo_ == funk1.foo_)
            return true;
        return false;

    }
    Funk operator+(Funk const & ch)
    {
        foo_ = foo_default;
            return foo_;

    }
    Funk operator+(int a)
    {
            return foo_;

    }
    Funk operator*(Funk const & ch)
    {
        foo_ = foo_default;
            return foo_;

    }
    Funk operator*(int a)
    {   
        foo_ = foo_default;
            return foo_;

    }
    bool operator%(int a)
    {
        return foo_(a);
    }
   friend std::ostream& operator<<(std::ostream & ost, Funk funk)
    {
        ost << funk.foo_ <<  "   ";
        return ost;
    }
    friend std::istream& operator>>(std::istream& ist, Funk &  comp)
    {
        std::cout << "\n вы вводите адрес а это потенциально может нарушить работу программы поэтому после ввода значение изменится на адрес функции по умолчанию\n";
        
        int a;
        ist >> a;
        comp.foo_ = foo_default;
        return ist;
    }
};
class Person{
   //private:
   public:
   struct PersonID{
    PersonID(int series = 0, int number = 0) : series_(series) , number_(number)
    {spetial = count;
    count++;
    }
    PersonID(PersonID const & per) : series_(per.series_) , number_(per.number_)
    {
        spetial = count;
    count++;
    }
    bool operator==(PersonID id)
    {
        if(this->number_ == id.number_ && this->series_ == id.series_)
            return true;
        return false;
    }
    int series_{0};
    int number_{0};
    int spetial{0};
    static inline int count{0};
   };
   PersonID id_;
   char* firstName_;
   char* middleName_;
   char* lastName_;
    public:
    PersonID GetID() const
    {
        return id_;
    };
    char* GetFirstName() const
    {
        return firstName_;
    }
    Person(Person const & per)
    {   
        this->id_ =  PersonID(per.id_.series_,per.id_.number_);
        this->firstName_ = strcat(per.firstName_,0);
        this->middleName_ = strcat(per.middleName_,0);
        this->lastName_ = strcat(per.lastName_,0);
    }
    //Funk(int (*foo)(int) = foo_default) : foo_(foo){}
    Person(int series = 0,int number = 0,char* firstName = nullptr,char* middleName = nullptr,char* lastName = nullptr) : id_(series,number), firstName_(firstName), 
    middleName_(middleName) , lastName_(lastName) 
    {}
    //Person() : id_(){}
    bool operator==(Person const & per)
    {
        if(this->id_ == per.id_)
            return true;
        return false;

    }
    Person operator+(Person const & ch)
    {
        
        Person p1(this->id_.series_ + ch.id_.series_,this->id_.number_ + ch.id_.number_);
        p1.firstName_ = strcat(this->firstName_ , ch.firstName_);
        p1.middleName_ = strcat(this->middleName_ , ch.middleName_);
        p1.lastName_ = strcat(this->lastName_ , ch.lastName_);
            /*return Person(this->id_.series_ + ch.id_.series_,this->id_.number_ + ch.id_.number_,strcat(this->firstName_ , ch.firstName_), 
            strcat(this->middleName_ , ch.middleName_),strcat(this->lastName_ , ch.lastName_));*/
            return p1;

    }
    Person operator+(int a)
    {       
        Person p1(*this);
        p1.id_.number_ += a;

            return p1;

    }
    Person operator*(Person const & ch)
    {
        Person p1(*this);
        p1.id_.number_ *= ch.id_.number_;
        p1.id_.series_ *= ch.id_.series_;
            return p1;

    }
    Person operator*(int a)
    {   
        
        this->id_.number_ *=a;
        this->id_.series_ *=a;
            return *this;

    }
    bool operator%(int a)
    {
        return this->id_.number_ % a || this->id_.series_ % a;
    }
    bool operator<(Person p2)
    {
        return this->id_.series_ < p2.id_.series_;
    }
    bool operator>(Person p2)
    {
        return (!(this->operator<(p2)))&&(!this->operator==(p2));
    }
    bool operator<=(Person p2)
    {
        return !(this->operator>(p2));
    }
    bool operator!=(Person p2)
    {
        return !this->operator==(p2);
    }
   friend std::ostream& operator<<(std::ostream & ost, Person per)
    {
        ost << "Person  "<< per.id_.series_ <<"  " << per.id_.number_  <<  "\n";
        ost << per.firstName_ << "\n";
        ost << per.middleName_ << "\n";
        ost << per.lastName_ << "\n";
        return ost;
    }
    friend std::istream& operator>>(std::istream& ist, Person &  comp)
    {
        std::cout << "\n  введите два числа и три строки. Имя второе имя и фамилию\n";
        
        comp.middleName_ = new char[50];
        comp.firstName_ = new char[50];
        comp.lastName_ = new char[50];
        ist >> comp.id_.series_ >> comp.id_.series_ >> comp.firstName_ >> comp.middleName_ >> comp.lastName_;
        
        return ist;
    }
};
