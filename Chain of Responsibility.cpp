
//�a�cuch zobowi�za� (ang. Chain of responsibility, niekiedy t�umaczony tak�e jako �a�cuch odpowiedzialno�ci)
// � czynno�ciowy wzorzec projektowy, w kt�rym ��danie mo�e by� przetwarzane przez r�ne obiekty, w zale�no�ci od jego typu. 

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Image
{
public:
	Image(string s) : mTitle(s)
	{
		cout << "Processing " << mTitle << " ...\n";
	}

private:
	string mTitle;
};

class ImageProcessor
{
public:
	ImageProcessor() : mNextProcessor(0) { }

public:
	void process(Image &p) {
		processImplementation(p);
		if (mNextProcessor != 0)
			mNextProcessor->process(p);
	}

	virtual ~ImageProcessor() { }

	void setNextProcessor(ImageProcessor *p) {
		mNextProcessor = p;
	}

protected:
	virtual void processImplementation(Image &a) = 0;

private:
	ImageProcessor * mNextProcessor;
};

class Scale : public ImageProcessor
{
public:
	enum SCALE { S50, S100, S200, S300, S500 };
	Scale(SCALE s) : mSCALE(s) { }

private:
	void processImplementation(Image &a) {
		cout << "Scaling Image\n";
	}

	SCALE mSCALE;
};

class RedEye : public ImageProcessor
{
private:
	void processImplementation(Image &a) {
		cout << "Removing red eye\n";
	}
};

class Filter : public ImageProcessor
{
private:
	void processImplementation(Image &a) {
		cout << "Applying filters\n";
	}
};

class ColorMatch : public ImageProcessor
{
private:
	void processImplementation(Image &a)
	{
		cout << "Matching colors\n";
	}
};

void processImage(Image &image)
{
	ColorMatch match;
	RedEye eye;
	Filter filter;
	Scale scale(Scale::S200);
	scale.setNextProcessor(&eye);
	eye.setNextProcessor(&match);
	match.setNextProcessor(&filter);
	scale.process(image);
}

int main()
{
	Image *p = new Image("Y2013 Image");
	processImage(*p);

	cin.ignore();
	return 0;
}
