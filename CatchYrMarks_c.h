//---------------------------------------------------------------------------

#ifndef CatchYrMarks_cH
#define CatchYrMarks_cH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <Graphics.hpp>
#include <ComCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TfrmGrabbing : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label1;
	TEdit *edtDisapp;
	TLabel *Label2;
	TTimer *tmrFall;
	TBitBtn *btbGo;
	TPanel *Panel2;
	TProgressBar *prgbTime;
	TLabel *lblFound;
	TLabel *Label6;
	TLabel *Label7;
	TListBox *lstMarks;
	TPanel *pnlMarks;
	TPanel *pnlMark2;
	TPanel *pnlMark1;
	TPanel *pnlMark3;
	TLabel *lblTimeUp;
	void __fastcall btbGoClick(TObject *Sender);
	void __fastcall tmrFallTimer(TObject *Sender);
	void __fastcall pnlMark1Click(TObject *Sender);
	void __fastcall pnlMark3Click(TObject *Sender);
	void __fastcall edtDisappExit(TObject *Sender);
	void __fastcall pnlMark2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmGrabbing(TComponent* Owner);
	void updateWithClick(int initialMark, AnsiString capturedMark);

	int countSeq;     // sequence counter (for list box) & how many marks logged!
	int TotInFavour;
	int AgainstTotal;
	int mark1Orig, mark2Orig, mark3Orig;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmGrabbing *frmGrabbing;
//---------------------------------------------------------------------------
#endif
