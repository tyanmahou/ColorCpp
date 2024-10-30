export module ColorCpp:ITP;

export namespace colorcpp
{
    /// <summary>
    /// ITP(ICtCp)色空間
    /// </summary>
    struct ITP
    {
        double i;
        double t;
        double p;

        constexpr ITP operator +(const ITP& other) const noexcept
        {
            return { (i + other.i), (t + other.t), (p + other.p) };
        }
        constexpr ITP& operator +=(const ITP& other) noexcept
        {
            i += other.i;
            t += other.t;
            p += other.p;
            return *this;
        }
        constexpr ITP operator -(const ITP& other) const noexcept
        {
            return{ (i - other.i), (t - other.t), (p - other.p) };
        }
        constexpr ITP& operator -=(const ITP& other) noexcept
        {
            i -= other.i;
            t -= other.t;
            p -= other.p;
            return *this;
        }
        constexpr ITP operator *(double s) const noexcept
        {
            return{ i * s, t * s, p * s };
        }
        constexpr ITP& operator *=(double s) noexcept
        {
            i *= s;
            t *= s;
            p *= s;
            return *this;
        }
        constexpr ITP operator *(const ITP& other) const noexcept
        {
            return{ i * other.i, t * other.t, p * other.p };
        }
        constexpr ITP& operator *=(const ITP& other) noexcept
        {
            i *= other.i;
            t *= other.t;
            p *= other.p;
            return *this;
        }
        constexpr ITP operator /(double s) const noexcept
        {
            return{ i / s, t / s, p / s };
        }
        constexpr ITP& operator /=(double s) noexcept
        {
            i /= s;
            t /= s;
            p /= s;
            return *this;
        }
        constexpr ITP operator /(const ITP& other) const noexcept
        {
            return{ i / other.i, t / other.t, p / other.p };
        }
        constexpr ITP& operator /=(const ITP& other) noexcept
        {
            i /= other.i;
            t /= other.t;
            p /= other.p;
            return *this;
        }

        friend constexpr bool operator==(const ITP& a, const ITP& b) = default;
    };
}
