//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <FileCtrl.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TFileListBox *FileListBox1;
        TFileListBox *FileListBox2;
        TFilterComboBox *FilterComboBox1;
        TEdit *Edit3;
        TButton *Button3;
        TFilterComboBox *FilterComboBox2;
        TLabel *Label1;
        TDirectoryListBox *DirectoryListBox1;
        TDirectoryListBox *DirectoryListBox2;
        TDriveComboBox *DriveComboBox1;
        TDriveComboBox *DriveComboBox2;
        TLabel *Label2;
        TEdit *Edit1;
        TButton *Button1;
        TEdit *Edit2;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *Edit4;
        TLabel *Label5;
        TLabel *Label6;
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Edit1Change(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
