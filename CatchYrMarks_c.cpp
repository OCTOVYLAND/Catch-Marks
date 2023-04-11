//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CatchYrMarks_c.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmGrabbing *frmGrabbing;
//---------------------------------------------------------------------------
__fastcall TfrmGrabbing::TfrmGrabbing(TComponent* Owner): TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmGrabbing::edtDisappExit(TObject *Sender)
{
	if (edtDisapp->Text.ToInt() < 100)       // 100 - 400 ms allowed  VALIDATE!
		edtDisapp->Text = "100";
	if (edtDisapp->Text.ToInt() > 400)
		edtDisapp->Text = "400";
}
//---------------------------------------------------------------------------
void __fastcall TfrmGrabbing::btbGoClick(TObject *Sender)
{
	// RESET items!!!!!
	tmrFall->Interval = edtDisapp->Text.ToInt();
	edtDisapp->ReadOnly = true;
	prgbTime->Max = 30000 /tmrFall->Interval;   // calculate 30s game duration

	TotInFavour = 0;
	AgainstTotal = 0;
	prgbTime->Position = 0;
	countSeq = 1;

	pnlMark1->Show();
	pnlMark2->Show();
	pnlMark3->Show();
	tmrFall->Enabled = true;
  btbGo->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmGrabbing::tmrFallTimer(TObject *Sender)
{
	prgbTime->Position++;
	//========================= Mark1 ==============================
	if (pnlMark1->Caption.ToInt() > 1 )   // mark is up for grabs
	{
		pnlMark1->Width--;
		pnlMark1->Height--;
		pnlMark1->Caption = pnlMark1->Caption - Random(7);  // dec by rnd(7)
	}
	else              // mark vanished OR was clicked on
	{
		// must work even if form is dragged larger!
		int mark1S = Random(20)+40; 		    // pnl Size: 40 - 60 pixel
		pnlMark1->Width = mark1S;
		pnlMark1->Height = mark1S;
		pnlMark1->Top = Random(pnlMarks->Height - mark1S); // initial
		pnlMark1->Left = Random(pnlMarks->Width - mark1S-17); //    position

		mark1Orig = Random(20)+80;                // starting mark: 80-100%
		pnlMark1->Caption = IntToStr(mark1Orig);  // class data member
	}
	//======================== Mark 3 == (similar to Mark 1) ==================
	if (pnlMark3->Caption.ToInt() > 1 )
	{
		pnlMark3->Width--;
		pnlMark3->Height--;
		pnlMark3->Caption = pnlMark3->Caption - random(7);
	}
	else
	{
		int mark3S = random(20)+40;
		pnlMark3->Width = mark3S;
		pnlMark3->Height = mark3S;
		pnlMark3->Top = Random(pnlMarks->Height - mark3S); // initial
		pnlMark3->Left = Random(pnlMarks->Width - mark3S-17); //    position

		mark3Orig = Random(20)+80;                // starting mark: 80-100%
		pnlMark3->Caption = IntToStr(mark3Orig);
	}
	// ============== Mark2 dropping down ========================
	if (pnlMark2->Caption.ToInt() > 1 )
	{
		pnlMark2->Top = pnlMark2->Top + 3;
		pnlMark2->Left = pnlMark2->Left + 1;
		pnlMark2->Width = pnlMark2->Width - 1;
		pnlMark2->Height = pnlMark2->Height - 1;
		pnlMark2->Caption = pnlMark2->Caption - 2;
	}
	else
	{
		pnlMark2->Top = random(60)+50;
		pnlMark2->Left = random(120) + 20;
		pnlMark2->Width = random(10)+40;
		pnlMark2->Height = pnlMark2->Width;
		pnlMark2->Caption = random(20)+80;
	}
	//-------------------------------------------------------------------
	if (prgbTime->Position >= prgbTime->Max)
	{
		tmrFall->Enabled = false;
		lblTimeUp->Show();
	}
}
//---------------------------------------------------------------------------
//--- Self-defined class method -------------------------------
void TfrmGrabbing::updateWithClick(int initialMark, AnsiString capturedMark)
{                              //      mark1Orig  , pnlMark1->Caption
	int gainedMark = StrToInt(capturedMark);
	TotInFavour = TotInFavour + gainedMark;
	int missedMark = mark1Orig - gainedMark;
	AgainstTotal = AgainstTotal + missedMark;

	// FINAL mark -> paste into list box:
	lblFound->Caption = IntToStr((TotInFavour - AgainstTotal)/countSeq) +"%";

	AnsiString ln = IntToStr(countSeq++) + "\t" + IntToStr(mark1Orig) + "%\t"
		+ IntToStr(gainedMark) +"%\t"+ IntToStr(TotInFavour) +"\t"+ IntToStr(AgainstTotal);
	lstMarks->Items->Add(ln);
}
//=============================================================

void __fastcall TfrmGrabbing::pnlMark1Click(TObject *Sender)
{
	updateWithClick(mark1Orig, pnlMark1->Caption);
	pnlMark1->Caption = "1";           // reset mark - indicates to create new one
}
//---------------------------------------------------------------------------

void __fastcall TfrmGrabbing::pnlMark3Click(TObject *Sender)
{
	updateWithClick(mark1Orig, pnlMark3->Caption);
	pnlMark3->Caption = "1";
}
//---------------------------------------------------------------------------
void __fastcall TfrmGrabbing::pnlMark2Click(TObject *Sender)
{
	updateWithClick(mark1Orig, pnlMark2->Caption);
	pnlMark2->Caption = "1";
}
//---------------------------------------------------------------------------


