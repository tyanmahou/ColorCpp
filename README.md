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