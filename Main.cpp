//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "TPointContainer.h"
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

	city = new TPointContainer(Memo1);
	city->fillRand();
	city->traceRoads();
	city->drawRoads(Image1->Canvas);
	city->drawCrossroads(Image1->Canvas);

	delete city;
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
