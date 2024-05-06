#include <wx/wx.h>

class MyApp : public wxApp {
    public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame {
    public:
    MyFrame(const wxString& title);

    private:
    void OnButtonClicked(wxCommandEvent& event);
};

// Macro que implementa a aplicação principal
wxIMPLEMENT_APP(MyApp);

// Inicializa a aplicação
bool MyApp::OnInit() {
    MyFrame* frame = new MyFrame("Hello wxWidgets");
    frame->Show(true);
    return true;
}

// Construtor da janela principal
MyFrame::MyFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title) {
    wxPanel* panel = new wxPanel(this, wxID_ANY);
    wxButton* button =
        new wxButton(panel, wxID_ANY, "Click Me", wxPoint(20, 20));

    // Associa o evento de clique ao método `OnButtonClicked`
    button->Bind(wxEVT_BUTTON, &MyFrame::OnButtonClicked, this);
}

// Método chamado quando o botão é clicado
void MyFrame::OnButtonClicked(wxCommandEvent& event) {
    wxMessageBox("Clicked", "Button Event", wxOK | wxICON_INFORMATION);
}
