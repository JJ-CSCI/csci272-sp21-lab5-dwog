//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Write the assignment code here







class Real
{
protected:
    double real;

public:
    explicit Real(const double real = 0.0);
    double GetReal() const;
    Real& operator*(const double) const;
};

class Complex : public Real
{
protected:
double imaginary;
public:
    Complex(
    const double real = 0.0,
    const double imaginary = 0.0);
    double GetImaginary() const;
    Complex& operator*(const double) const;
};

class Surreal : public Complex
{
private:
    double surreal;
public:
    Surreal(
    const double real = 0.0,
    const double imaginary = 0.0,
    const double surreal = 0.0);
    double GetSurreal() const;
    Surreal& operator*(const double) const;
};



// Real class implementation;
Real::Real(const double real)
{
    this->real = real;
    }

double Real::GetReal() const
{
    return real;
}

Real& Real::operator*(const double real) const
{
    Real Obj{ (this->real * real) };
return Obj;
}


// Complex class implementation;
Complex::Complex(const double real, const double imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
}

double Complex::GetImaginary() const
{
    return imaginary;
}

Complex& Complex::operator*(const double real) const
{
    Complex Obj{ (this->real * real), (this->imaginary * real) };
    return Obj;
}


// Surreal class implementation;
Surreal::Surreal(const double real, const double imaginary, const double surreal)
{
    this->real = real;
    this->imaginary = imaginary;
    this->surreal = surreal;
}

double Surreal::GetSurreal() const
{
    return surreal;
}

Surreal& Surreal::operator*(const double real) const
{
    Surreal Obj{ (this->real * real), (this->imaginary * real), (this->surreal * real) };
    return Obj;
}



//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Real n{10.0};
        REQUIRE( n.GetReal() == 10.0 );
    }
    SECTION( "c2" ) {
        Complex n{10.0, 20.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
    }
    SECTION( "c3" ) {
        Surreal n{10.0, 20.0, 30.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
        REQUIRE( n.GetSurreal() == 30.0 );
    }
    SECTION( "a1" ) {
        Real n{10.0};
        Real r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
    }
    SECTION( "a2" ) {
        Complex n{10.0, 20.0};
        Complex r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
        REQUIRE( r.GetImaginary() == 40.0 );
    }
    SECTION( "a3" ) {
        Surreal n{10.0, 20.0, 30.0};
        Surreal r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
        REQUIRE( r.GetImaginary() == 40.0 );
        REQUIRE( r.GetSurreal() == 60.0 );
    }
}
//------------------------------
