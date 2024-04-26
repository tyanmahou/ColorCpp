# include <Siv3D.hpp>
import ColorPlus2;

void Main()
{
	using namespace cp2;
	RYB ryb{ 0.0, 1.0, 0.0 };
	RGB rgb = ColorCast<RGB>(ryb);

	while (System::Update())
	{
		Rect{ 0, 0, 100, 100 }.draw(ColorF(rgb.r, rgb.g, rgb.b));
	}
}
