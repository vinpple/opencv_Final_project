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

// 이미지와 파일 이름을 저장할 변수들을 전역 변수로 선언
Mat img(500, 700, CV_8U, Scalar(255, 255, 255)); // 500x700 크기의 흰색 이미지
Mat img_size(500 / 5, 200, CV_8UC3, Scalar(255, 255, 255)); // 이미지 사이즈
string fname; // 파일 이름
Point PtOld; // 마우스 이벤트 처리에 사용될 이전 좌표

// 마우스 이벤트를 처리하는 함수
void on_mouse(int event, int x, int y, int flags, void*);

// UI 요소를 그리는 함수
void UI(Mat& img);

int main()
{
    // UI 초기화
    UI(img);

    // 창 생성 및 마우스 콜백 함수 등록
    namedWindow("img");
    setMouseCallback("img", on_mouse);

    // 키 입력 대기
    waitKey();
}

// UI 요소를 그리는 함수
void UI(Mat& img)
{
    // 수평선 그리기
    line(img, Point(500, 0), Point(500, 500), Scalar(0, 0, 0), 2);
    // 수직선 그리기
    for (int i = 1; i < 5; i++)
    {
        line(img, Point(500, 500 * i / 5), Point(700, 500 * i / 5), Scalar(0, 0, 0), 2);
    }
    // 사각형 그리기
    rectangle(img, Rect(0, 0, 700, 500), Scalar(0, 0, 0), 2);

    // 버튼 텍스트
    string text[] = { "Save", "Load", "Clear", "Run", "Exit" };
    int fontface = FONT_HERSHEY_SCRIPT_COMPLEX;
    double fontscale = 1;
    int thick = 2;

    // 각 버튼 텍스트를 이미지 위에 그리기
    for (int i = 0; i < 5; i++) {
        Size sizetext = getTextSize(text[i], fontface, fontscale, thick, 0);
        Size sizeimg = img_size.size();
        Point org(500 + (sizeimg.width - sizetext.width) / 2,
            500 * i / 5 + (sizeimg.height + sizetext.height) / 2);
        putText(img, text[i], org, fontface, fontscale, Scalar(0, 0, 0), thick);
    }
}


// 마우스 이벤트를 처리하는 함수
void on_mouse(int event, int x, int y, int flags, void*)
{
    // 버튼 영역을 정의하는 사각형 배열
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
        // 왼쪽 마우스 버튼이 눌린 경우
        PtOld = Point(x, y);
        if (rect_area[1].contains(PtOld))
        {
            // "Save" 버튼이 클릭된 경우
            cout << " name to save : ";
            getline(cin, fname);
            imwrite(fname+".jpg", img);
        }
        else if (rect_area[2].contains(PtOld))
        {
            // "Load" 버튼이 클릭된 경우
            while (true) {
                cout << "load file name(.jpg) : ";
                getline(cin, fname);
                img = imread(fname);
                if (!img.data) {
                    // 이미지를 찾을 수 없거나 이름을 잘못 입력한 경우
                    cout << "Could not find the image. Make sure you write .jpg" << endl;
                }
                else {
                    // 올바른 이미지를 로드한 경우
                    imshow("img", img);
                    break;
                }
            }
        }
        else if (rect_area[3].contains(PtOld))
        {
            // "Clear" 버튼이 클릭된 경우
            rectangle(img, Rect(2, 2, 497, 496), Scalar(255, 255, 255), -1);
            imshow("img", img);
        }
        else if (rect_area[4].contains(PtOld))
        {
            // "Run" 버튼이 클릭된 경우 (구현되지 않음)
        }
        else if (rect_area[5].contains(PtOld))
        {
            // "Exit" 버튼이 클릭된 경우
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
	