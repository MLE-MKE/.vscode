#include <wx/wx.h>
#include <wx/listbox.h>

class ToDoFrame : public wxFrame
{
public:
    ToDoFrame(const wxString& title);

private:
    wxListBox* taskList; // List of tasks
    wxTextCtrl* taskInput; // Input box for adding tasks
    wxButton* addButton; // Button to add tasks
    wxButton* removeButton; // Button to remove tasks
    
    void OnAddTask(wxCommandEvent& event);
    void OnRemoveTask(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(ToDoFrame, wxFrame)
    EVT_BUTTON(1001, ToDoFrame::OnAddTask)
    EVT_BUTTON(1002, ToDoFrame::OnRemoveTask)
wxEND_EVENT_TABLE()

class ToDoApp : public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(ToDoApp);

bool ToDoApp::OnInit()
{
    ToDoFrame* frame = new ToDoFrame("To-Do List Application");
    frame->Show(true);
    return true;
}

ToDoFrame::ToDoFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 300))
{
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    taskList = new wxListBox(panel, wxID_ANY, wxPoint(10, 10), wxSize(200, 200));
    taskInput = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(220, 10), wxSize(150, 30));

    addButton = new wxButton(panel, 1001, "Add Task", wxPoint(220, 50));
    removeButton = new wxButton(panel, 1002, "Remove Task", wxPoint(220, 90));
}

void ToDoFrame::OnAddTask(wxCommandEvent& event)
{
    wxString task = taskInput->GetValue();
    if (!task.IsEmpty())
    {
        taskList->Append(task);  // Add the task to the list
        taskInput->Clear();  // Clear the input box
    }
}

void ToDoFrame::OnRemoveTask(wxCommandEvent& event)
{
    int selectedIndex = taskList->GetSelection();
    if (selectedIndex != wxNOT_FOUND)
    {
        taskList->Delete(selectedIndex);  // Remove the selected task
    }
}
