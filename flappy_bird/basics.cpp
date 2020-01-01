//This file contains basics which even 10th std child know! 
//Sounds Funny  :)  It was always

// Implement shape class with specific data type 
// As we don't know what data-type people goinf to use so templates
// As we do't know what people are going to do so getters and setters

//library called 
#include<iostream>
#include<cmath>

using namespace std;
//Rectangle Calss //Inheritataed from shape
namespace overengineered_lib_2d //namespace to prevent name collison
{
	//Base object - Abstarct 
	template<class T>
	class cShape2D
	{
	public: 
		//get permiter and area of the defined shape
		virtual T GetPerimeter() = 0;
		virtual T GetArea() = 0;
		// run time polymorphism 
		// so yyou can get access in child also 
	};

	// base class 
	// reactangle class in which height and width is required 
	// this class is inheritated from the shape class
	template<class T>
	class cRectangle : public cShape2D<T>
	{
	public:
		//constructor
		cRectangle(T w,T h) 
		{ 	
			SetWidth(w);
			SetHeight(h);
		}
	private:
		T mWidth; //width of the rectangle
		T mHeight; //height of the rectangle
	public:

		//fuction returns width
		T GetWidth()
		{	
			//cout<<"mWidth"<<mWidth<<endl;
			return mWidth;
		}

		//fuction returns Height
		T GetHeight()
		{ 	
			//cout<<"mHeight"<<mHeight<<endl;
			return mHeight;
		}
	
		//function let user sets the width
		bool SetWidth(T value)
		{ 
			mWidth = value;
			return  GetWidth() > 0 ? true : false;
		}
		//function let user sets the height
		bool SetHeight(T value)
		{
			mHeight = value;
			return GetHeight() > 0 ? true : false;
		}

		//function return the perimeter of the rectangle 
		T GetPerimeter()
		{
			return 2*(GetWidth() + GetHeight());
		}

		//function return the area of the rectangle 
		T GetArea()
		{ 	
			//cout<<"calculating area"<<endl;
			//cout << GetWidth() * GetHeight() <<endl;
			return GetWidth() * GetHeight();
		}
	};

	//circle class //Inheritated from shape
	template<class T>
	class cCircle : public cShape2D<T>
	{
	public:
		//constructor
		cCircle(T r)
		{ 
			SetRadius(r);
		}
	private:
		T mRadius; //radius of cicle

	public:
		//func gets radius of the circle
		T GetRadius()	
		{
			return  mRadius;
		}

		//This function let user to set radius
		bool SetRadius(T value)
		{
			mRadius=value;
			return mRadius > 0 ? true : false;
		}
	
		//fucntion gets perimeter
		T GetPerimeter()
		{
			return 2 * 3.14159f * GetRadius();
		}

		//function gets the area
		T GetArea()
		{
		return 3.14159f * GetRadius() * GetRadius();
		}
	};
}


int main()
{
	overengineered_lib_2d :: cShape2D<float> *shapes[2]; //base class
	//polymorphism  shape can be circle and rectangle
	
	shapes[0] = new overengineered_lib_2d :: cRectangle<float> (10,15.0f); //derived class
	shapes[1] = new overengineered_lib_2d :: cCircle<float>(5.0f);
	
	for(int n=0;n<2;n++)
		cout << "shapes[" <<n<<"]P=" << shapes[n] -> GetPerimeter() <<  " A=" << shapes[n]->GetArea() << endl;;
	return 0;
}
