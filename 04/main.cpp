#include <wx/image.h>
#include <wx/wx.h>
#include <vector>

class MyApp : public wxApp {
    public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame {
    public:
    MyFrame(const wxString& title);

    private:
    void OnPrevious(wxCommandEvent& event);
    void OnNext(wxCommandEvent& event);
    void UpdateImage();

    wxStaticBitmap* imageDisplay;
    std::vector<wxString> imagePaths;
    int currentIndex;
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    MyFrame* frame = new MyFrame("Image Carousel");
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(500, 400)),
      currentIndex(0) {
    wxPanel* panel    = new wxPanel(this, wxID_ANY);

    // Lista de caminhos das imagens (adicione seus próprios caminhos aqui)

    // Inicializa lista de caminhos de imagens (substitua com os seus caminhos)
    imagePaths        = {"/workspace/wxwidgets/03/image1.jpg",
                         "/workspace/wxwidgets/03/image2.jpg",
                         "/workspace/wxwidgets/03/image3.jpg"};
    // Botões de navegação
    wxButton* btnPrev = new wxButton(panel, wxID_ANY, "< Previos",
                                     wxPoint(10, 320), wxSize(100, 30));
    wxButton* btnNext = new wxButton(panel, wxID_ANY, "Next >",
                                     wxPoint(390, 320), wxSize(100, 30));

    // Vincula eventos aos botões
    btnPrev->Bind(wxEVT_BUTTON, &MyFrame::OnPrevious, this);
    btnNext->Bind(wxEVT_BUTTON, &MyFrame::OnNext, this);

    // Área para exibir as imagens, centralizada na janela
    imageDisplay = new wxStaticBitmap(
        panel, wxID_ANY, wxBitmap(imagePaths[0], wxBITMAP_TYPE_ANY),
        wxPoint(100, 50), wxSize(300, 250));

    // Ajusta o tamanho da janela para conter todos os controles
    this->SetClientSize(500, 360);
}

void MyFrame::OnPrevious(wxCommandEvent& event) {
    currentIndex =
        (currentIndex == 0) ? imagePaths.size() - 1 : currentIndex - 1;
    UpdateImage();
}

void MyFrame::OnNext(wxCommandEvent& event) {
    currentIndex =
        (currentIndex == imagePaths.size() - 1) ? 0 : currentIndex + 1;
    UpdateImage();
}

void MyFrame::UpdateImage() {
    imageDisplay->SetBitmap(
        wxBitmap(imagePaths[currentIndex], wxBITMAP_TYPE_ANY));
    imageDisplay->Center();
    Refresh();  // Redesenha a tela para refletir a mudança
}
