#pragma once

namespace Math
{
	template <typename T>
	class Point2
	{
	public:
		T x,y;
		Point2(T x,T y): x(x),y(y) {}
	};

	/*class Point2f : Point2<float>
	{
	public:
		Point2f(float x,float y): Point2(x,y) {}

	};*/
	typedef Point2<float> Point2f;
}