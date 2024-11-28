# ColorCpp
C++20 ColorSpace Module

## About
"ColorCpp" is color spaces library by C++20 module.

We support the following color spaces.

- A98
- CMY
- CMYK
- DisplayP3
- Hex
- HSI
- HSL
- HSV
- HunterLab
- HWB
- ITP
- Lab
- LCH
- LRGB
- Luv
- OkLab
- OkLCH
- Prophoto
- Rec2020
- RGB
- RGB24
- RGBA
- RGBA32
- RYB
- XyY
- XYZ
- YIQ

and the color difference.

- CIE76
- CIE94
- CIE2000
- CMC
- Euclidean

## Example

import module
```
import ColorCpp;
```


color space conversion

```cpp
constexpr RGB rgb{ 1.0, 1.0, 1.0 };
HSV hsv = ColorCast<HSV>(rgb);
```

color difference

```cpp
constexpr RGB a{ 1.0, 0.0, 1.0 };
constexpr RGB b{ 0, 1.0, 0 };

double diff = ColorDiff::Euclidean<RGB>(a, b);
```

## Customaization Point

You can introduce user-defined types by template specialization of function objects.

```cpp
struct MyRGB
{
    float r;
    float g;
    float b;
};

// Customaization Point
namespace colorcpp
{
    // Color Cast
    template<>
    struct ColorCastDependency<MyRGB>
    {
        // By defining a mutually convertible depend_type,
        // casting from any type is made possible.
        using depend_type = RGB;
    };
    template<>
    struct ColorCastTraits<MyRGB, RGB>
    {
        [[nodiscard]] constexpr static MyRGB Cast(const RGB& from)
        {
            const auto& [r, g, b] = from;
            return {
                static_cast<float>(r),
                static_cast<float>(g),
                static_cast<float>(b),
            };
        }
    };
    template<>
    struct ColorCastTraits<RGB, MyRGB>
    {
        [[nodiscard]] constexpr static RGB Cast(const MyRGB& from)
        {
            const auto& [r, g, b] = from;
            return {
                static_cast<double>(r),
                static_cast<double>(g),
                static_cast<double>(b),
            };
        }
    };

    // Euclidean Diff
    template<>
    struct ColorDiffTrait<MyRGB>
    {
        [[nodiscard]] static double Diff(const MyRGB& left, const MyRGB& right)
        {
            const float r = left.r - right.r;
            const float g = left.g - right.g;
            const float b = left.b - right.b;
            return std::sqrt(static_cast<double>(r * r + g * g + b * b));
        }
    };
}

```

```cpp
{
    constexpr RGB src{};
    MyRGB dst = ColorCast<MyRGB>(src);
}
{
    constexpr MyRGB a{ 1, 0, 1 };
    constexpr MyRGB b{ 0, 1, 0 };

    double diff = ColorDiff::Euclidean<MyRGB>(a, b);
}
```

### Siv3D Support

[SivColorCpp.hpp](https://github.com/tyanmahou/ColorCpp/blob/main/Siv3D/SivColorCpp.hpp)