/*
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

Mat img(500, 700, CV_8U, Scalar(255, 255, 255));
Mat img_size(500 / 5, 200, CV_8UC3, Scalar(255, 255, 255));
string fname;
Point PtOld;
void on_mouse(int event, int x, int y, int flags, void*);
void UI(Mat& img);
int main()
{
	UI(img);
	namedWindow("img");
	setMouseCallback("img", on_mouse);
	waitKey();
}

void UI(Mat&img)
{
	line(img, Point(500, 0), Point(500, 500), Scalar(0, 0, 0), 2);
	for (int i = 1; i < 5; i++)
	{
		line(img, Point(500, 500 * i / 5), Point(700, 500 * i / 5), Scalar(0, 0, 0), 2);
	}
	rectangle(img, Rect(0, 0, 700, 500), Scalar(0, 0, 0), 2);

	string text[] = { "Save", "Load", "Clear", "Run", "Exit" };
	int fontface = FONT_HERSHEY_SCRIPT_COMPLEX;
	double fontscale = 1;
	int thick = 2;

	for (int i = 0; i < 5; i++) {
		Size sizetext = getTextSize(text[i], fontface, fontscale, thick, 0);
		Size sizeimg = img_size.size();
		Point org(500 + (sizeimg.width - sizetext.width) / 2,
			500 * i / 5 + (sizeimg.height + sizetext.height) / 2);
		putText(img, text[i], org, fontface, fontscale, Scalar(0, 0, 0), thick);
	}
}

void on_mouse(int event, int x, int y, int flags, void*)
{
	Rect rect_area[] =
	{
		Rect(0, 0, 495, 495),
		Rect(501, 0, 199, 99),
		Rect(501, 500 / 5 + 1, 199, 99),
		Rect(501, 500 * 2 / 5 + 1, 199, 99),
		Rect(501, 500 * 3 / 5 + 1, 199, 99),
		Rect(501, 500 * 4 / 5 + 1, 199, 99)

	};
	switch (event) {
	case EVENT_LBUTTONDOWN:
		PtOld = Point(x, y);
			if (rect_area[1].contains(PtOld))
			{
				cout << " name to save : ";
				getline(cin, fname);
				imwrite(fname+".jpg", img);
			}
			else if (rect_area[2].contains(PtOld))
			{
				while (true) {
					cout << "load file name(.jpg) : ";
					getline(cin, fname);
					img = imread(fname);
					if (!img.data) {
						cout << "Could not find the image. Make sure you write .jpg" << endl;
					}
					else {
						imshow("img", img);
						break;
					}
				}
			}
			else if (rect_area[3].contains(PtOld))
			{
				rectangle(img, Rect(2, 2, 497, 496), Scalar(255, 255, 255), -1);
				imshow("img", img);
			}
			else if (rect_area[4].contains(PtOld))
			{

			}
			else if (rect_area[5].contains(PtOld))
			{
				cout << "exit" << endl;
				exit(0);
			}
			break;
		case EVENT_MOUSEMOVE:
			if (rect_area[0].contains(Point(x, y)))
			{
				if (flags & EVENT_FLAG_LBUTTON)
				{
					line(img, PtOld, Point(x, y), Scalar(0, 0, 0), 10);
					imshow("img", img);
					PtOld = Point(x, y);
				}
			}
			break;
		}
	imshow("img", img);
}
*/


#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

// �̹����� ���� �̸��� ������ �������� ���� ������ ����
Mat img(500, 700, CV_8U, Scalar(255, 255, 255)); // 500x700 ũ���� ��� �̹���
Mat img_size(500 / 5, 200, CV_8UC3, Scalar(255, 255, 255)); // �̹��� ������
string fname; // ���� �̸�
Point PtOld; // ���콺 �̺�Ʈ ó���� ���� ���� ��ǥ

// ���콺 �̺�Ʈ�� ó���ϴ� �Լ�
void on_mouse(int event, int x, int y, int flags, void*);

// UI ��Ҹ� �׸��� �Լ�
void UI(Mat& img);

int main()
{
    // UI �ʱ�ȭ
    UI(img);

    // â ���� �� ���콺 �ݹ� �Լ� ���
    namedWindow("img");
    setMouseCallback("img", on_mouse);

    // Ű �Է� ���
    waitKey();
}

// UI ��Ҹ� �׸��� �Լ�
void UI(Mat& img)
{
    // ���� �׸���
    line(img, Point(500, 0), Point(500, 500), Scalar(0, 0, 0), 2);
    // ������ �׸���
    for (int i = 1; i < 5; i++)
    {
        line(img, Point(500, 500 * i / 5), Point(700, 500 * i / 5), Scalar(0, 0, 0), 2);
    }
    // �簢�� �׸���
    rectangle(img, Rect(0, 0, 700, 500), Scalar(0, 0, 0), 2);

    // ��ư �ؽ�Ʈ
    string text[] = { "Save", "Load", "Clear", "Run", "Exit" };
    int fontface = FONT_HERSHEY_SCRIPT_COMPLEX;
    double fontscale = 1;
    int thick = 2;

    // �� ��ư �ؽ�Ʈ�� �̹��� ���� �׸���
    for (int i = 0; i < 5; i++) {
        Size sizetext = getTextSize(text[i], fontface, fontscale, thick, 0);
        Size sizeimg = img_size.size();
        Point org(500 + (sizeimg.width - sizetext.width) / 2,
            500 * i / 5 + (sizeimg.height + sizetext.height) / 2);
        putText(img, text[i], org, fontface, fontscale, Scalar(0, 0, 0), thick);
    }
}


// ���콺 �̺�Ʈ�� ó���ϴ� �Լ�
void on_mouse(int event, int x, int y, int flags, void*)
{
    // ��ư ������ �����ϴ� �簢�� �迭
    Rect rect_area[] =
    {
        Rect(0, 0, 495, 495),
        Rect(501, 0, 199, 99),
        Rect(501, 500 / 5 + 1, 199, 99),
        Rect(501, 500 * 2 / 5 + 1, 199, 99),
        Rect(501, 500 * 3 / 5 + 1, 199, 99),
        Rect(501, 500 * 4 / 5 + 1, 199, 99)
    };

    switch (event) {
    case EVENT_LBUTTONDOWN:
        // ���� ���콺 ��ư�� ���� ���
        PtOld = Point(x, y);
        if (rect_area[1].contains(PtOld))
        {
            // "Save" ��ư�� Ŭ���� ���
            cout << " name to save : ";
            getline(cin, fname);
            imwrite(fname+".jpg", img);
        }
        else if (rect_area[2].contains(PtOld))
        {
            // "Load" ��ư�� Ŭ���� ���
            while (true) {
                cout << "load file name(.jpg) : ";
                getline(cin, fname);
                img = imread(fname);
                if (!img.data) {
                    // �̹����� ã�� �� ���ų� �̸��� �߸� �Է��� ���
                    cout << "Could not find the image. Make sure you write .jpg" << endl;
                }
                else {
                    // �ùٸ� �̹����� �ε��� ���
                    imshow("img", img);
                    break;
                }
            }
        }
        else if (rect_area[3].contains(PtOld))
        {
            // "Clear" ��ư�� Ŭ���� ���
            rectangle(img, Rect(2, 2, 497, 496), Scalar(255, 255, 255), -1);
            imshow("img", img);
        }
        else if (rect_area[4].contains(PtOld))
        {
            // "Run" ��ư�� Ŭ���� ��� (�������� ����)
        }
        else if (rect_area[5].contains(PtOld))
        {
            // "Exit" ��ư�� Ŭ���� ���
            cout << "exit" << endl;
            exit(0);
        }
        break;
    case EVENT_MOUSEMOVE:
			if (rect_area[0].contains(Point(x, y))) 
			{
				if (flags & EVENT_FLAG_LBUTTON) 
				{
					line(img, PtOld, Point(x, y), Scalar(0, 0, 0), 10);
					imshow("img", img);
					PtOld = Point(x, y);
				}
			}
			break;
		}
	imshow("img", img);
}
	