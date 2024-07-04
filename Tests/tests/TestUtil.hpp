#pragma once
#include <cmath>


struct NearlyDouble
{
    inline static constexpr double Epsilon = 0.000001;

    static constexpr bool Equals(double a, double b, double e = Epsilon)
    {
        // return std::abs(a - b) <= e;
        return (a >= b ? a - b : b - a) <= e;
    }

    double value;
    double e;

    explicit constexpr NearlyDouble(double v_, double e_ = Epsilon)
    {
        value = v_;
        e = e_;
    }

    constexpr NearlyDouble operator()(double e_)
    {
        return NearlyDouble{ value, e_ };
    }

    friend constexpr NearlyDouble operator +(const NearlyDouble& a, const NearlyDouble& b)
    {
        return NearlyDouble{ a.value + b.value, std::max(a.e, b.e)};
    }
    friend constexpr NearlyDouble operator +(const NearlyDouble& a, double b)
    {
        return NearlyDouble{ a.value + b, a.e };
    }
    friend constexpr NearlyDouble operator +(double a, const NearlyDouble& b)
    {
        return NearlyDouble{ a + b.value, b.e };
    }

    friend constexpr NearlyDouble operator -(const NearlyDouble& a, const NearlyDouble& b)
    {
        return NearlyDouble{ a.value - b.value, std::max(a.e, b.e) };
    }
    friend constexpr NearlyDouble operator -(const NearlyDouble& a, double b)
    {
        return NearlyDouble{ a.value - b, a.e };
    }
    friend constexpr NearlyDouble operator -(double a, const NearlyDouble& b)
    {
        return NearlyDouble{ a - b.value, b.e };
    }

    friend constexpr NearlyDouble operator *(const NearlyDouble& a, const NearlyDouble& b)
    {
        return NearlyDouble{ a.value * b.value, std::max(a.e, b.e) };
    }
    friend constexpr NearlyDouble operator *(const NearlyDouble& a, double b)
    {
        return NearlyDouble{ a.value * b, a.e };
    }
    friend constexpr NearlyDouble operator *(double a, const NearlyDouble& b)
    {
        return NearlyDouble{ a * b.value, b.e };
    }

    friend constexpr NearlyDouble operator /(const NearlyDouble& a, const NearlyDouble& b)
    {
        return NearlyDouble{ a.value / b.value, std::max(a.e, b.e) };
    }
    friend constexpr NearlyDouble operator /(const NearlyDouble& a, double b)
    {
        return NearlyDouble{ a.value / b, a.e };
    }
    friend constexpr NearlyDouble operator /(double a, const NearlyDouble& b)
    {
        return NearlyDouble{ a / b.value, b.e };
    }

    friend constexpr bool operator == (const NearlyDouble& a, const NearlyDouble& b)
    {
        return Equals(a.value, b.value, a.e + b.e);
    }
    friend constexpr bool operator == (const NearlyDouble& a, double b)
    {
        return Equals(a.value, b, a.e);
    }
    friend constexpr bool operator == (double a, const NearlyDouble& b)
    {
        return Equals(a, b.value, b.e);
    }
    friend constexpr bool operator != (const NearlyDouble& a, const NearlyDouble& b)
    {
        return !Equals(a.value, b.value, a.e + b.e);
    }
    friend constexpr bool operator != (const NearlyDouble& a, double b)
    {
        return !Equals(a.value, b, a.e);
    }
    friend constexpr bool operator != (double a, const NearlyDouble& b)
    {
        return !Equals(a, b.value, b.e);
    }

    template <class CharType>
    friend std::basic_ostream<CharType>& operator <<(std::basic_ostream<CharType>& output, const NearlyDouble& value)
    {
        return output << value.value;
    }
};

constexpr NearlyDouble operator ""_nearly(long double v)
{
    return NearlyDouble{ static_cast<double>(v)};
}
constexpr NearlyDouble operator ""_nearly(unsigned long long v)
{
    return NearlyDouble{ static_cast<double>(v)};
}
