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

// Macro para implementar a aplicação principal
wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    MyFrame* frame = new MyFrame("Image Carousel");
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title), currentIndex(0) {
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    // Inicializa lista de caminhos de imagens (substitua com os seus caminhos)
    imagePaths     = {"/workspace/wxwidgets/03/image1.jpg",
                      "/workspace/wxwidgets/03/image2.jpg",
                      "/workspace/wxwidgets/03/image3.jpg"};

    // Cria e posiciona os botões
    wxButton* btnPrev =
        new wxButton(panel, wxID_ANY, "Anterior", wxPoint(20, 20));
    wxButton* btnNext =
        new wxButton(panel, wxID_ANY, "Próximo", wxPoint(120, 20));

    // Associa eventos aos botões
    btnPrev->Bind(wxEVT_BUTTON, &MyFrame::OnPrevious, this);
    btnNext->Bind(wxEVT_BUTTON, &MyFrame::OnNext, this);

    // Área para exibir as imagens
    imageDisplay = new wxStaticBitmap(panel, wxID_ANY, wxBitmap(imagePaths[0]),
                                      wxPoint(20, 80), wxSize(400, 300));

    // Configura o tamanho do painel principal
    SetSize(wxSize(500, 500));
}

void MyFrame::OnPrevious(wxCommandEvent& event) {
    // Retrocede no índice da lista de imagens
    currentIndex =
        (currentIndex == 0) ? imagePaths.size() - 1 : currentIndex - 1;
    UpdateImage();
}

void MyFrame::OnNext(wxCommandEvent& event) {
    // Avança no índice da lista de imagens
    currentIndex =
        (currentIndex == imagePaths.size() - 1) ? 0 : currentIndex + 1;
    UpdateImage();
}

void MyFrame::UpdateImage() {
    // Atualiza a imagem exibida
    imageDisplay->SetBitmap(wxBitmap(imagePaths[currentIndex]));
    Refresh();  // Redesenha a tela
}
