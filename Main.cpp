//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "TRoadmap.h"
#include "TEnitymap.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	//city = new TPointContainer(Memo1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Image1->Canvas->FillRect(TRect(0,0,Image1->Height, Image1->Width));
	int coeff = 25;
	city = new TRoadmap(Memo1);

		city->addCrossroad(coeff*1,coeff*7);                             //0
		city->addCrossroad(coeff*1,coeff*1);                             //1
		city->addCrossroad(coeff*6,coeff*1);                             //2
		city->addCrossroad(coeff*11,coeff*4);                            //3
		city->addCrossroad(coeff*6,coeff*7);                             //4
		city->addCrossroad(coeff*6,coeff*11);                            //5
    	city->addCrossroad(coeff*11,coeff*9);                            //6
    	city->addCrossroad(coeff*13,coeff*12);                           //7
    	city->addCrossroad(coeff*10,coeff*17);                           //8
    	city->addCrossroad(coeff*12,coeff*19);                           //9
    	city->addCrossroad(coeff*6,coeff*19);                            //10
		city->addCrossroad(coeff*2,coeff*15);                            //11
    	city->addCrossroad(coeff*14,coeff*21);                            //12
    	city->addCrossroad(coeff*16,coeff*8);                           //13
    	city->addCrossroad(coeff*17,coeff*17);                           //14
    	city->addCrossroad(coeff*20,coeff*13);                           //15
    	city->addCrossroad(coeff*23,coeff*16);                           //16
		city->addCrossroad(coeff*21,coeff*21);                           //16
		city->addConnection(0,1);
		city->addConnection(1,2);
		city->addConnection(2,3);
		city->addConnection(4,3);
    	city->addConnection(4,0);
    	city->addConnection(4,5);
    	city->addConnection(5,11);
    	city->addConnection(11,10);
    	city->addConnection(10,6);
		city->addConnection(6,3);
    	city->addConnection(6,7);
    	city->addConnection(7,8);
    	city->addConnection(7,13);
    	city->addConnection(13,15);
		city->addConnection(15,14);
		city->addConnection(14,12);
		city->addConnection(14,17);
		city->addConnection(15,16);
		city->addConnection(16,17);
		city->addConnection(8,9);
		city->addConnection(9,10);
		city->addConnection(9,12);



//	city->addCrossroad(coeff*2,coeff*2);                             //0
//	city->addCrossroad(coeff*22,coeff*2);                             //1
//	city->addCrossroad(coeff*22,coeff*22);                             //2
//	city->addCrossroad(coeff*2,coeff*22);
//	city->addCrossroad(coeff*10,coeff*10);							//3
//	city->addConnection(0,1);
//	city->addConnection(1,2);
//	city->addConnection(2,3);
//	city->addConnection(3,0);
//	city->addConnection(0,4);
//	city->addConnection(1,4);
//	city->addConnection(2,4);
//	city->addConnection(3,4);

	city->traceRoads();
	city->drawRoads(Image1->Canvas);
	city->drawCrossroads(Image1->Canvas);
	//Image1->Canvas->MoveTo(0,0);
	//Image1->Canvas->LineTo(100,200);
	//delete city;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	city->addCrossroad(X,Y);
	if(city->listCrossroad.size() > 1) city->addConnection(city->listCrossroad.size()-1, city->listCrossroad.size()-2);
	city->traceRoads();
	city->drawRoads(Image1->Canvas);
	city->drawCrossroads(Image1->Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	 TEnitymap* enitymap = new TEnitymap(Image1->Canvas);
	 enitymap->createEnity(city->listRoad[5],25.0, true);
	 enitymap->drawEnities();

	 enitymap->listEnity[0]->move(-250);
	 enitymap->drawEnities();

	 delete enitymap;
}
//---------------------------------------------------------------------------

