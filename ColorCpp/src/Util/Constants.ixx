export module ColorCpp:Constants;

export namespace colorcpp
{
    inline constexpr double Epsilon = 0.008856451679;
    inline constexpr double Kappa = 903.296296296;

    inline constexpr double AdobeGammaInv = 2.19921875;
    inline constexpr double AdobeGamma = 1.0 / AdobeGammaInv;
}
