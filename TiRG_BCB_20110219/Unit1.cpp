#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include <jpeg.hpp>
#include "trg.hpp"

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1* Form1;
__fastcall TForm1::TForm1(TComponent* Owner): TForm(Owner) {}

std::vector<std::vector<trg::Rgb> > a;
int H, W;

void __fastcall TForm1::Button1Click(TObject* Sender) {
    if (!OpenPictureDialog1->Execute()) return;
    Graphics::TBitmap* Bmp = new Graphics::TBitmap();
    TJPEGImage* Jpg = new TJPEGImage;
    try {
        Jpg->LoadFromFile(OpenPictureDialog1->FileName);
        Bmp->Assign(Jpg);
        H = Bmp->Height;
        W = Bmp->Width;
        a.resize(H);
        for (int y = 0; y < H; ++y) {
            TRGBTriple* BmpLine = (TRGBTriple*)Bmp->ScanLine[y];
            a[y].resize(W);
            for (int x = 0; x < W; ++x) {
                a[y][x].r = BmpLine[x].rgbtRed;
                a[y][x].g = BmpLine[x].rgbtGreen;
                a[y][x].b = BmpLine[x].rgbtBlue;
            }
        }
        Image1->Picture->Graphic = Bmp;
        Memo1->Text = OpenPictureDialog1->FileName;
        Memo1->Lines->Add("===================");
        Memo1->Lines->Add("Width: " + String(W));
        Memo1->Lines->Add("Height: " + String(H));
        Button2->Enabled = true;
    }
    catch (...) {
        ShowMessage("Could not load or alter bitmap");
    }
    delete Jpg;
    delete Bmp;
}

void __fastcall TForm1::Button2Click(TObject* Sender) {
    Button2->Enabled = false;
    std::vector<trg::Rect> r = trg::get_textlike_regions(a);
    Memo1->Lines->Add("===================");
    ////Memo1->Lines->Add("sr: " + String((int)trg::sr));
    ////Memo1->Lines->Add("c: " + String(trg::c));
    Memo1->Lines->Add("Detected: " + String(r.size()) + " region(s)");
    if (!r.empty()) {
        TCanvas* Cnv = Image1->Canvas;
        Cnv->Brush->Color = clRed;
        for (size_t i = 0; i < r.size(); ++i) {
            Cnv->FrameRect(Rect(r[i].x1-1, r[i].y1-1, r[i].x2+1, r[i].y2+1));
            Cnv->FrameRect(Rect(r[i].x1-2, r[i].y1-2, r[i].x2+2, r[i].y2+2));
        }
        ////Image1->Picture->SaveToFile(OpenPictureDialog1->FileName + "_detected.bmp");
    }
}


