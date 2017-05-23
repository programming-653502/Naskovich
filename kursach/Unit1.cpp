//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Forms.hpp"

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
AnsiString MyFName = "";
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
   RichEdit1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender) {
// Application->Terminate();
TCloseAction Action;
Action = caFree;
FormClose(Sender,Action);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N5Click(TObject *Sender) {
  if (OpenDialog1->Execute())
	if (FileExists(OpenDialog1->FileName)) {
	  MyFName = OpenDialog1->FileName;
	  RichEdit1->Lines->LoadFromFile(OpenDialog1->FileName);
	  Form1->Caption = MyFName;
	  RichEdit1->Modified = false;	
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N3Click(TObject *Sender) {
  if( SaveDialog1->Execute() ) {
	RichEdit1->Lines->SaveToFile( SaveDialog1->FileName );
	RichEdit1->Modified = false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N6Click(TObject *Sender) {
  if (PanelButton->Visible)
	PanelButton->Visible=false;
  else
	PanelButton->Visible=true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N1AdvancedDrawItem(TObject *Sender, TCanvas *ACanvas, TRect &ARect,
		  TOwnerDrawState State) {
  N6->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N1Click(TObject *Sender) {
  PanelButton->Visible=false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N4Click(TObject *Sender) {
  PrintDialog1->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender) {
  FontDialog1->Execute();
  RichEdit1->SelAttributes->Assign(FontDialog1->Font);
  RichEdit1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1Click(TObject *Sender) { 
  if (SpeedButton1->OnClick) {
	if (RichEdit1->Paragraph->Numbering == nsNone)
	  RichEdit1->Paragraph->Numbering = nsBullet;
	else
	  RichEdit1->Paragraph->Numbering = nsNone;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn3Click(TObject *Sender) {
  RichEdit1->Paragraph->Alignment = taLeftJustify;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn4Click(TObject *Sender) {
  RichEdit1->Paragraph->Alignment = taCenter;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn5Click(TObject *Sender) {
  RichEdit1->Paragraph->Alignment = taRightJustify;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
   RichEdit1->CopyToClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn2Click(TObject *Sender) {
  RichEdit1->CutToClipboard();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action) {
  if (RichEdit1->Modified) {  
	int resMessage;
	resMessage=MessageBox(Form1->Handle, L"�� ������ ��������� ���������?", L"", 3);
	switch (resMessage) {
	  case IDYES : N7Click(Sender);  Application->Terminate();break;
	  case IDNO : Action = caFree; Application->Terminate(); break;
	  case IDCANCEL : Action = caNone; 
	}
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N7Click(TObject *Sender) { 
  if (MyFName != "") {
	RichEdit1->Lines->SaveToFile(MyFName);
	RichEdit1->Modified = false;
  }
  else {
	N3Click(Sender);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn6Click(TObject *Sender) {
	RichEdit1->PasteFromClipboard();
}
//---------------------------------------------------------------------------

