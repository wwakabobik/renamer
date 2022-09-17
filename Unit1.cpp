//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <string.h>
#include "SysUtils.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
AnsiString path_folder;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


AnsiString fileCorrector(AnsiString S)
{
char filename_tmp[1024];
strcpy(filename_tmp,S.c_str());
//ShowMessage(AnsiString(filename_tmp[S.Length()-5]));
filename_tmp[S.Length()-5]='\0';
return AnsiString(filename_tmp);
//return 0;
}


void __fastcall TForm1::Button3Click(TObject *Sender)
{
if (Edit1->Text!="")
FileListBox1->Mask=Edit1->Text;
else
FileListBox1->Update();
FileListBox1->Refresh();
if (FileListBox1->Items->Count)
{
AnsiString FilterBuf=FileListBox1->Mask;
int i=0,j=1;
try {j=StrToInt(Edit2->Text);}
catch ( EConvertError& ) { ShowMessage("Неверное число! Введите целое число!");}
int k=9999;
if (Edit4->Text!="")
{
try {k=StrToInt(Edit4->Text);}
catch ( EConvertError& ) { ShowMessage("Неверное число! Введите целое число или оставьте поле пустым!");}
}
//k=StrToInt(Edit4->Text);
//ShowMessage(AnsiString(FileListBox1->Items->Count));
//ShowMessage(FileListBox1->Directory+"\\"+FileListBox1->Items->Strings[0]);
//
//while (FileListBox1->Items->Count)
//{
for(i=0;i<=k;i++)
{
//RenameFile(FileListBox1->Directory+"\\"+FileListBox1->Items->Strings[0],FileListBox2->Directory+"\\"+Edit3->Text+AnsiString(j)+"."+FilterComboBox1->Text);
RenameFile(FileListBox1->Directory+"\\"+FileListBox1->Items->Strings[0],FileListBox1->Directory+"\\"+Edit3->Text+AnsiString(j)+".rtmp");
j++;
FileListBox1->Refresh();
FileListBox1->Update();
if (FileListBox1->Items->Count==0)
break;
//if (j==2)
//break;
}
FileListBox1->Mask="*.rtmp";
FileListBox1->Refresh();
FileListBox1->Update();
for(;;)
{
RenameFile(FileListBox1->Directory+"\\"+FileListBox1->Items->Strings[0],FileListBox2->Directory+"\\"+fileCorrector(ExtractFileName(FileListBox1->Items->Strings[0]))+ExtractFileExt(FilterBuf));
//fileCorrector(ExtractFileName(FileListBox1->Items->Strings[0]));
FileListBox1->Refresh();
FileListBox1->Update();
if (FileListBox1->Items->Count==0)
break;
//if (j==2)
//break;
}
FileListBox1->Mask=FilterBuf;
FileListBox1->Refresh();
FileListBox1->Update();
FileListBox2->Refresh();
FileListBox2->Update();
//}
//ShowMessage(FileListBox1->Directory+"\\"+FileListBox1->Items->Strings[0]);
//ShowMessage(FileListBox2->Directory+"\\"+Edit3->Text+AnsiString(j)+"."+FilterComboBox1->Text);
//j++;
//} */
}
else ShowMessage("Нет файлов для переименования!");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
int i=0;
FilterComboBox1->Filter="";
FilterComboBox1->Filter="";
FilterComboBox1->Items->LoadFromFile("filters.txt");
FilterComboBox1->Filter=FilterComboBox1->Items->Strings[0];
FilterComboBox2->Items->LoadFromFile("filters.txt");
FilterComboBox2->Filter=FilterComboBox2->Items->Strings[0];
path_folder=FileListBox1->Directory;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
FileListBox2->Directory=path_folder;
FileListBox1->Directory=path_folder;
FilterComboBox1->Items->Clear();
FilterComboBox1->Items->LoadFromFile("filters.txt");
FilterComboBox1->Items->SaveToFile("filters.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Change(TObject *Sender)
{
FileListBox1->Mask=Edit1->Text;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
Edit1->Text="";
Edit3->Text="FILE";
Edit2->Text="1";
Edit4->Text="";
FileListBox1->Directory=path_folder;
DirectoryListBox1->Directory=path_folder;
FileListBox2->Directory=path_folder;
DirectoryListBox2->Directory=path_folder;
DirectoryListBox1->Update();
DirectoryListBox1->Refresh();
DirectoryListBox2->Update();
DirectoryListBox2->Refresh();
FileListBox1->Update();
FileListBox1->Refresh();
FileListBox2->Update();
FileListBox2->Refresh();
}
//---------------------------------------------------------------------------

